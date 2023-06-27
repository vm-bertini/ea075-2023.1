/****************************************************************************
 * File name:        main.c
 * File description: Nessa versao do SUENV-R todas as tasks foram criadas,
 *		     ha o sincronismo com semaforo binario no canal I2C,mas
 *		     existe erro com o watch dog em alguns casos (foi visto
 *		     com periodo de leitura pequeno).
 *		     As tasks de Display no LCD e de reiniciar estados usam
 * 		     vetores setados nas tasks de leituras com defesa de
 *		     regioes criticas.
 *                   e janelas.
 * Author name:      -Rafael Ifanger Ribeiro
 *		     -Vicente Jose Campitelli Real
 * Creation date:    21mai2023
 * Revision date:    23mai2023
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include <math.h>

//https://github.com/WifWaf/ADS1115_IDF <-creditos do componente do ADS1115 bem como sua inicializacao
#include <driver/i2c.h>
#include "ADS1115.h"

#define SDA_IO (21)                      /*!< gpio number for I2C master data  */
#define SCL_IO (22)                      /*!< gpio number for I2C master clock */

#define FREQ_HZ (100000)                 /*!< I2C master clock frequency */
#define TX_BUF_DISABLE (0)               /*!< I2C master doesn't need buffer */
#define RX_BUF_DISABLE (0)               /*!< I2C master doesn't need buffer */

#define I2C_NUM I2C_NUM_0                /*!< I2C number */
#define I2C_MODE I2C_MODE_MASTER         /*!< I2C mode to act as */
#define I2C_RX_BUF_STATE RX_BUF_DISABLE  /*!< I2C set rx buffer status */
#define I2C_TX_BUF_STATE TX_BUF_DISABLE  /*!< I2C set tx buffer status */
#define I2C_INTR_ALOC_FLAG (0)           /*!< I2C set interrupt allocation flag */

static const char *TAG = "Main";

/* i2c setup ----------------------------------------- */
// Config profile for espressif I2C lib
i2c_config_t i2c_cfg = {                     
  .mode = I2C_MODE_MASTER, 
  .sda_io_num = SDA_IO,
  .scl_io_num = SCL_IO,
  .sda_pullup_en = GPIO_PULLUP_DISABLE,
  .scl_pullup_en = GPIO_PULLUP_DISABLE,
  .master.clk_speed = FREQ_HZ,
};

/* ADS1115 setup ------------------------------------- */
// Below uses the default values speficied by the datasheet
ads1115_t ads1115_cfg = {
  .reg_cfg =  ADS1115_CFG_LS_COMP_MODE_TRAD | // Comparator is traditional
              ADS1115_CFG_LS_COMP_LAT_NON |   // Comparator is non-latching
              ADS1115_CFG_LS_COMP_POL_LOW |   // Alert is active low
              ADS1115_CFG_LS_COMP_QUE_DIS |   // Compator is disabled
              ADS1115_CFG_LS_DR_1600SPS |     // No. of samples to take
              ADS1115_CFG_MS_MODE_SS,         // Mode is set to single-shot
  .dev_addr = 0x48,
};
//

//https://esp32tutorials.com/oled-esp32-esp-idf-tutorial/ 
//e https://github.com/nopnop2002/esp-idf-ssd1306/tree/master/components <- Fonte componente ssd1306.h e codigo de inicializacao
#include "ssd1306.h"
/*
 You have to set this config value with menuconfig
 CONFIG_INTERFACE
 for i2c
 CONFIG_MODEL
 CONFIG_SDA_GPIO
 CONFIG_SCL_GPIO
 CONFIG_RESET_GPIO
fonte: https://esp32tutorials.com/oled-esp32-esp-idf-tutorial/
*/
#define tag "SSD1306"

#define I2C_NODES_NUMBER 4
#define STEP_WINDOW 600
#define READING_WINDOW 300
#define STEP_DELAY 150
//

typedef enum {
	ESPERA,
	RETORNO,
	DELAY,
	SUSPENSO
}sensor_state;

typedef enum {
	TERMOPAR_K,
	PH,
	GAS,
	TURBIDEZ
}tipo_sensor;

typedef struct {
	char * code;
	uint8_t id;
	uint32_t * value;
	uint8_t addr;
	uint32_t measurement_period;
	sensor_state * state;
	int BITx;
	uint8_t * new;
	tipo_sensor tipo;
}sensor_info;

typedef struct {
	uint8_t * newState;
	uint32_t * valueList;
} display_param_struct;

static EventGroupHandle_t event_group_sensor_state;
static EventGroupHandle_t event_group_sensor_display;
const static int MOV_BIT1 = BIT1;
const static int MOV_BIT2 = BIT2;
const static int MOV_BIT3 = BIT3;
const static int MOV_BIT4 = BIT4;

static SemaphoreHandle_t xBinarySemaphore_I2C;
static SemaphoreHandle_t xBinarySemaphore_estados;
static SemaphoreHandle_t xBinarySemaphore_new;
static SemaphoreHandle_t xBinarySemaphore_leituras;

/****************************************************************************
 * Function name:        xSensorInit
 * Function description: Inicializa struct associada ao sensor
 * Input parameters:     entradas relativas ao sensor:
			 -codigo 		(code	 	char *)
			 -id			(id		uint8_t)
			 -valor da leitura	(value		uint_t*)
			 -endereco		(addr		uint8_t)
			 -periodo de leitura	(period		uint32_t)
			 -estado de leitura	(estado		sensor_state)
			 -BIT (EventGroup)	(BITx		int)
			 -flag de valor novo	(new		uint8_t*)
			 -tipo			(tipo		tipo_sensor)	
 * Output parameters:    ponteiro para struct sensor_info
 ****************************************************************************/
sensor_info* xSensorInit(char * code, uint8_t id, uint32_t * value, uint8_t addr, uint32_t period, sensor_state * estado, int BITx, uint8_t * new, tipo_sensor tipo);

/****************************************************************************
 * Function name:        vDisplaySensorInfo
 * Function description: Faz o print das informacoes do sensor
 * Input parameters:     ponteiro para struct sensor_info (sensor sensor_info*)	
 * Output parameters:    void
 ****************************************************************************/
void vDisplaySensorInfo(sensor_info * sensor);

/****************************************************************************
 * Function name:        vTaskSensorReading
 * Function description: Task responsavel pela leitura e display do valor do
 *			 sensor (via I2C-ADS1115&display128x64)
 * Input parameters:     void ponter (ponteiro para struct sensor_info 
 *                       (sensor sensor_info*))	
 * Output parameters:    void
 ****************************************************************************/
void vTaskSensorReading(void * param);

/****************************************************************************
 * Function name:        xSensorsStateInit
 * Function description: Inicializacao dos estados dos sensores
 * Input parameters:     none	
 * Output parameters:    lista de estados (sensor_state*)
 ****************************************************************************/
sensor_state * xSensorsStateInit();

/****************************************************************************
 * Function name:        vDisplayEstados
 * Function description: Faz o print dos estados da lista de estados
 * Input parameters:     lista de estados (sensor_state*)	
 * Output parameters:    void
 ****************************************************************************/
void vDisplayEstados(sensor_state * lista_estados);

/****************************************************************************
 * Function name:        vTaskReiniciaEstados
 * Function description: Task que atribui estado ESPERA a todos sensores quando 
 * 			 todos estao no estado RETORNO
 * Input parameters:     (void pointer) (lista de estados (sensor_state*))	
 * Output parameters:    void
 ****************************************************************************/
void vTaskReiniciaEstados(void * param);

/****************************************************************************
 * Function name:        vTaskReiniciaEstados
 * Function description: Task reponsavel pelo calculo e display do valor de
 * 			 qualidade
 * Input parameters:     void pointer (ponteiro para display_param_struct)	
 * Output parameters:    void
 ****************************************************************************/
void vTaskDisplayI2C(void * param);

uint16_t uAnalisaAnalog(uint16_t valor, tipo_sensor tipo);
/* Display variables */
	static SSD1306_t dev;
void app_main(void)
{	
 	ESP_LOGD(TAG,"Starting ADS1115 example..");
	/*
  	// Setup I2C
  	i2c_param_config(I2C_NUM, &i2c_cfg);
 	i2c_driver_install(I2C_NUM, I2C_MODE, I2C_RX_BUF_STATE, I2C_TX_BUF_STATE, I2C_INTR_ALOC_FLAG);
	*/
  	// Setup ADS1115
	ADS1115_initiate(&ads1115_cfg);

#if CONFIG_I2C_INTERFACE
	ESP_LOGI(tag, "INTERFACE is i2c");
	ESP_LOGI(tag, "CONFIG_SDA_GPIO=%d",CONFIG_SDA_GPIO);
	ESP_LOGI(tag, "CONFIG_SCL_GPIO=%d",CONFIG_SCL_GPIO);
	ESP_LOGI(tag, "CONFIG_RESET_GPIO=%d",CONFIG_RESET_GPIO);
	i2c_master_init(&dev, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
#endif // CONFIG_I2C_INTERFACE

#if CONFIG_SSD1306_128x64
	ESP_LOGI(tag, "Panel is 128x64");

	ssd1306_init(&dev, 128, 64);
#endif // CONFIG_SSD1306_128x64

	ssd1306_clear_screen(&dev, false);
	ssd1306_contrast(&dev, 0xff);
  	ssd1306_display_text_x3(&dev, 0, "CTI ", 5, false);
  	vTaskDelay(3000 / portTICK_PERIOD_MS);
	ssd1306_clear_screen(&dev, false);
	ssd1306_display_text(&dev, 0, "Projeto Ambient.", 18, false);
	ssd1306_display_text(&dev, 1, "Rafael Ifanger", 16, false);
	ssd1306_display_text(&dev, 2, "Vicente Real  ",17, false);
	ssd1306_display_text(&dev, 3, "              ",18, false);
	ssd1306_display_text(&dev, 4, "              ",18, false);
	

	xBinarySemaphore_I2C = xSemaphoreCreateBinary();
	xBinarySemaphore_estados = xSemaphoreCreateBinary();
	xBinarySemaphore_new = xSemaphoreCreateBinary();
	xBinarySemaphore_leituras = xSemaphoreCreateBinary();	
	
	xSemaphoreGive(xBinarySemaphore_I2C);
	xSemaphoreGive(xBinarySemaphore_estados);
	xSemaphoreGive(xBinarySemaphore_new);
	xSemaphoreGive(xBinarySemaphore_leituras);
	
	event_group_sensor_state = xEventGroupCreate();
	event_group_sensor_display = xEventGroupCreate();
	sensor_state * estados = xSensorsStateInit();
	vDisplayEstados(estados);
	uint8_t * newState = malloc(sizeof(uint8_t)*I2C_NODES_NUMBER);
	uint32_t * valueList = malloc(sizeof(uint32_t)*I2C_NODES_NUMBER);

	display_param_struct * display_param = malloc(sizeof(display_param_struct));
	display_param->newState = newState;
	display_param->valueList = valueList;

	char * Sensor1 = malloc(sizeof(char)*8);
	Sensor1 = "Sensor1";
	sensor_info * newSensor1 = xSensorInit(Sensor1, 0, &valueList[0], 0x35, 5000, &estados[0], MOV_BIT1, &newState[0], TERMOPAR_K);
	vDisplaySensorInfo(newSensor1);

	char * Sensor2 = malloc(sizeof(char)*8);
	Sensor2 = "Sensor2";
	sensor_info * newSensor2 = xSensorInit(Sensor2, 1, &valueList[1], 0x37, 7000, &estados[1], MOV_BIT2, &newState[1], PH);
	vDisplaySensorInfo(newSensor2);

	char * Sensor3 = malloc(sizeof(char)*8);
	Sensor3 = "Sensor3";
	sensor_info * newSensor3 = xSensorInit(Sensor3, 2, &valueList[2], 0x42, 8000, &estados[2], MOV_BIT3, &newState[2], GAS);
	vDisplaySensorInfo(newSensor3);

	char * Sensor4 = malloc(sizeof(char)*8);
	Sensor4 = "Sensor4";
	sensor_info * newSensor4 = xSensorInit(Sensor4, 3, &valueList[3], 0x53, 10000, &estados[3], MOV_BIT4, &newState[3], TURBIDEZ);
	vDisplaySensorInfo(newSensor4);

	xTaskCreate(vTaskSensorReading, "Task de Leitura1", 1024 * 5, newSensor1, 2, NULL);
	xTaskCreate(vTaskSensorReading, "Task de Leitura2", 1024 * 5, newSensor2, 2, NULL);
	xTaskCreate(vTaskSensorReading, "Task de Leitura3", 1024 * 5, newSensor3, 2, NULL);
	xTaskCreate(vTaskSensorReading, "Task de Leitura4", 1024 * 5, newSensor4, 2, NULL);
	xTaskCreate(vTaskReiniciaEstados, "Task de Estados", 1024 * 2, estados, 3, NULL);
	xTaskCreate(vTaskDisplayI2C, "Task de Display", 1024 * 2, display_param, 2, NULL);
	for(int i=0; i<10; i++) printf("%d\n",i);
}

sensor_info* xSensorInit(char * code, uint8_t id, uint32_t * value, uint8_t addr, uint32_t period, sensor_state * estado, int BITx, uint8_t * new, tipo_sensor tipo){
	sensor_info * sensor = malloc(sizeof(sensor_info));
	sensor->code = code;
	sensor->id = id;
	sensor->value = value;
	(*sensor->value) = -1;
	sensor->addr = addr;
	sensor->measurement_period = period;
	sensor->state = estado;
	sensor->BITx = BITx;
	sensor->new = new;
	(*sensor->new) = 0;
	sensor->tipo = tipo;
	return sensor;
}

void vDisplaySensorInfo(sensor_info * sensor){
	printf("Sensor code: %s\n",sensor->code);
	printf("Sensor id: %d\n",sensor->id);
	//printf("Sensor value: %d\n",(*sensor->value));
	printf("Sensor addr: %x\n",sensor->addr);
	printf("Sensor period: %d\n",sensor->measurement_period);
}

void vTaskSensorReading(void * param){
	sensor_info * sensor = (sensor_info *) param;
	vDisplaySensorInfo(sensor);
	char valor_str[12];
	char id_str[12];
	char texto_init_aprestacao[] = "Sensor [";
	char texto_final_aprestacao[] = "]:";
  	char texto[18];
	char texto_display[18];
	sprintf(id_str, "%d", (int)sensor->id);
	strcpy(texto,texto_init_aprestacao);
	strcat(texto,id_str);
	strcat(texto,texto_final_aprestacao);
	// Buffer for result
  	uint16_t result = 0;
	while(1){
		
///		
		if((sensor->measurement_period-((xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period))<=STEP_WINDOW){
			printf("Dentro da janela de 1 segundo [%d]\n",sensor->id);
			if((sensor->measurement_period-((xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period))<=READING_WINDOW){
				printf("Leitura [%d]\n",sensor->id);
				// onde entra sincronizacao do barramento

		xSemaphoreTake( xBinarySemaphore_estados, portMAX_DELAY );
		uint8_t verificaESPERA = 0;
		/* Verifica se tem alguma task de leitura em ESPERA */
		if((*sensor->state)==RETORNO){
			for(int id = 0; id < I2C_NODES_NUMBER; id++){
				if((*(sensor->state-((int) sensor->id)+id))==ESPERA){
					verificaESPERA =1;
				}
			}
		}
		if(((*sensor->state)==ESPERA) || (((*sensor->state)==RETORNO)&&(!verificaESPERA))){
			xSemaphoreGive( xBinarySemaphore_estados);
			strcpy(texto_display,texto);
			xSemaphoreTake( xBinarySemaphore_I2C, portMAX_DELAY );
			xSemaphoreTake( xBinarySemaphore_leituras, portMAX_DELAY );
			
			switch(sensor->tipo){
				case TERMOPAR_K:{ADS1115_request_single_ended_AIN0();}break;
				case PH:{ADS1115_request_single_ended_AIN1();}break;
				case GAS:{ADS1115_request_single_ended_AIN2();}break;
				case TURBIDEZ:{ADS1115_request_single_ended_AIN3();}break;
				default:break;
			}
			// Request single ended on pin AIN0  
   			// ADS1115_request_single_ended_AIN1();
			
    			// Check conversion state - returns true if conversion is complete 
    			while(!ADS1115_get_conversion_state()) 
     			vTaskDelay(pdMS_TO_TICKS(5));          // wait 5ms before check again
    			
    			// Return latest conversion value
    			result = ADS1115_get_conversion();  			
			//(*sensor->value) += 1;
			(*sensor->value) = (int)(result*3.3/65535.0*1000); 
			//(*sensor->value) = uAnalisaAnalog(result, sensor->tipo);
			sprintf(valor_str, "%d", (int)(*sensor->value));
			strcat(texto_display,valor_str);
			strcat(texto_display,"mV");
			ssd1306_display_text(&dev, 3+sensor->id, texto_display, 18, true);
			xSemaphoreGive( xBinarySemaphore_leituras);
			xSemaphoreGive( xBinarySemaphore_I2C);

			printf("Tempo Passado[%d]: %d\nT_janela: %d\nTempo Restante: %d\n",sensor->id,xTaskGetTickCount()*portTICK_RATE_MS,(xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period,(sensor->measurement_period-((xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period)));

			xSemaphoreTake( xBinarySemaphore_estados, portMAX_DELAY );
			(*sensor->state) = RETORNO;
			xSemaphoreGive( xBinarySemaphore_estados);

			xSemaphoreTake( xBinarySemaphore_new, portMAX_DELAY );
			(*sensor->new) = 1;
			xSemaphoreGive( xBinarySemaphore_new);

			xEventGroupSetBits(event_group_sensor_state, sensor->BITx);
			xEventGroupSetBits(event_group_sensor_display, MOV_BIT1);
			
			vTaskDelay((READING_WINDOW*2)/portTICK_RATE_MS);
			//vTaskDelay((sensor->measurement_period)/portTICK_RATE_MS);	
		}else{
			xSemaphoreGive( xBinarySemaphore_estados);
		}

				//
			}else{
				vTaskDelay(STEP_DELAY/portTICK_RATE_MS);
			}
		}else if(((xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period)<=READING_WINDOW){
			vTaskDelay((READING_WINDOW*2)/portTICK_RATE_MS);
		}else{
			printf("Fora da janela [%d]\n",sensor->id);
			vTaskDelay(((sensor->measurement_period-((xTaskGetTickCount()*portTICK_RATE_MS)%sensor->measurement_period)) - STEP_WINDOW)/portTICK_RATE_MS);	
		}
///					
	}
	free(sensor);
	vTaskDelete(NULL);
}

sensor_state * xSensorsStateInit(){
	sensor_state * estados = malloc(sizeof(sensor_state)*I2C_NODES_NUMBER);
	for(int id = 0; id<I2C_NODES_NUMBER; id++) estados[id] = ESPERA;
	return estados;
}

void vDisplayEstados(sensor_state * lista_estados){
	for(int id = 0; id < I2C_NODES_NUMBER; id++){
		printf("Valor de estados[%d]: %d\n",id,lista_estados[id]);	
	}
}

void vTaskReiniciaEstados(void * param){
	sensor_state * estados = (sensor_state *) param;
	while(1){
		xEventGroupWaitBits(event_group_sensor_state, MOV_BIT2+MOV_BIT1+MOV_BIT3, pdTRUE, true, portMAX_DELAY);
		xSemaphoreTake( xBinarySemaphore_estados, portMAX_DELAY );
		vDisplayEstados(estados);
		for(int id = 0; id < I2C_NODES_NUMBER; id++){
			if(estados[id] == RETORNO) estados[id] = ESPERA;
		}		
		printf("-------\n");
		vDisplayEstados(estados);
		xSemaphoreGive( xBinarySemaphore_estados);
	}
}

void vTaskDisplayI2C(void * param){
	display_param_struct * display_param = (display_param_struct *) param;
	uint8_t * newState = display_param->newState;
	uint32_t * valueList = display_param->valueList;
	while(1){
		xEventGroupWaitBits(event_group_sensor_display, MOV_BIT1, pdTRUE, true, portMAX_DELAY);

		for(int id = 0; id < I2C_NODES_NUMBER; id++){
			xSemaphoreTake( xBinarySemaphore_new, portMAX_DELAY );
			xSemaphoreTake( xBinarySemaphore_leituras, portMAX_DELAY );
			if(newState[id]){
				xSemaphoreTake( xBinarySemaphore_I2C, portMAX_DELAY );
				printf("Novo dado para id: %d\n",id);
				printf("Valor: %d\n",valueList[id]);
				xSemaphoreGive( xBinarySemaphore_I2C);
				newState[id] = 0;
			}
			xSemaphoreGive( xBinarySemaphore_new);
			xSemaphoreGive( xBinarySemaphore_leituras);
		}
		vTaskDelay(1000/portTICK_RATE_MS);
	}
	vTaskDelete(NULL);
}
//, -86096392e2, 4.83506e10, -1.18452e12,
/*double a[] = {0.226584602, 24152.10900, 67233.4248, 22110340.682};
                for (int i = 0; i < 4; i++) {
                    analise += (uint64_t)(a[i] * pow(valor, i));
                }*/
/*
uint16_t uAnalisaAnalog(uint16_t valor, tipo_sensor tipo) {
    uint16_t analise = 0;
    double a = 3000, b = 0.23;
    uint16_t amplificacao = 10000;
    uint16_t ddp = (3.3 * valor / (1 << 16) - 1);
    switch (tipo) {
        case TERMOPAR_K:
            {
                
		analise = ddp*25;
                // linear
            }
            break;
        
        case PH:
            {
                uint16_t fator_calibracao = 21.34;
                analise = (uint16_t)(-5.7 * ddp + fator_calibracao);
            }
            break;
        
        case GAS:
	    {
		analise = a*pow((double)ddp,b);
            }
            // exp
            break;
        
        case TURBIDEZ:
	    {
		if(ddp<2.5){
			analise = 3000;
		}else if(ddp>4.0){
			analise = 0;
		}else{
			analise = -1120.4 * pow((double)ddp,2) + 5742.3 * ddp - 4353.8;
		}
	    }
            // n-linear
            break;
        
        default:
            break;
    }
    
    return analise;
}
*/
