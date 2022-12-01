## Microcontrolador ATMEGA328P
Devido a sua ampla utilização e disponibilidade no mercado foi adotado o microcontrolador ATMEGA328P para ser o responsável por tratar e gerenciar as rotinas do nosso dispositivo. O ATMEGA328P possui como características principais o fato de possuir 3 memórias internas, sendo elas uma memória Flash (32 KB), uma SRAM (2 KB) e uma EEPROM (1 KB), possui também 23 I/Os, opera com uma tensão de 5V e as suas saídas fornecem uma corrente de 40 mA, além disso, consegue operar com um clock entre 0 à 20 MHz.

[Datasheet](https://br.mouser.com/datasheet/2/268/ATmega48A_PA_88A_PA_168A_PA_328_P_DS_DS40002061B-3050139.pdf)

## Sensores para detecção de gás

Estes sensores, de modo geral, apresentam um material sensível ao gás que precisa ser detectado. Em contato com o ar puro sua condutividade elétrica é baixa enquanto na presença do gás desejado sua condutividade aumenta com a concentração. Desta forma, essa diferença de condutividade é explorada para obtenção de um sinal indicador da presença da substância desejada. 

Os sensores utilizados nesta aplicação serão o MQ-7, MQ-6 e MQ-4, responsáveis pela detecção de monóxido de carbono, gás inflamável (GLP) e gás metano, respectivamente. 

O sinal de saída de cada um destes componentes é analógico, entretanto, a conexão dos sensores MQ-7 e MQ-4 com o microcontrolador será feita via porta digital visto que estes componentes possuem módulos comerciais com conversão AD integrada. O sensor MQ-6 não iremos utilizar um módulo comercial e por isso será conectado diretamente à porta analógica do microcontrolador. 

### MQ-7 (Monóxido de Carbono)

Para realizar a detecção do monóxido de carbono o módulo do sensor MQ-7 com conversão analógico-digital já integrada será utilizado, sua conexão com o microcontrolador será feita via porta digital 24.

[Datasheet](https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ7.pdf)

### MQ-4 (Metano)

Para realizar a detecção do gás metano o sensor MQ-4 com conversão analógico-digital já integrada será utilizado, sua conexão com o microcontrolador será feita via porta digital 25.

[Datasheet](https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ4.pdf)

### MQ-6 (GLP)

Para realizar a detecção de GLP o sensor MQ-6 será utilizado, sua conexão com o microcontrolador será feita via porta analógica 23.

[Datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-6.pdf)


## Sensor infravermelho

O sensor infravermelho implementado é o E18-D80NK-N. Este sensor com saída digital possui um emissor e um detector de sinal infravermelho. Caso haja algum objeto na frente deste dispositivo, o sinal infravermelho é refletido pela superfície do objeto e retorna ao detector, ocasionando um sinal de nível lógico baixo na saída, sendo assim, o sensor apresenta saída em nível baixo quando detecta algo e apresenta saída em nível alto quando não está sendo obstruído.

Este sensor opera com 5V e pode ser ajustado para detectar um objeto entre 6cm e 80cm. De acordo com o datasheet, este dispositivo pode apresentar ligeiras variações no range de detecção frente a cor e composição do objeto, assim, recomenda-se que seja feita a calibração antes do uso final.  

A conexão do sensor com o microcontrolador será feita via porta digital (portas 4 e 5 ) com um resistor de pull-up de 10k.

[Datasheet](https://datasheetspdf.com/pdf-file/1311838/ETT/E18-D80NK-N/1)

## Buzzer

Caso um gás seja detectado acima do nível de concentração especificado um alerta sonoro será emitido por meio de um buzzer ativo de 5V conectado ao microcontrolador por meio de uma porta digital. A corrente necessária para suprir o buzzer será fornecida por meio de um transistor, evitando, assim, danos na porta do microcontrolador.

[Datasheet](https://www.farnell.com/datasheets/2171929.pdf)

## Display LCD

O shield contém um display alfanumérico de 2 linhas de 16 colunas, com backlight azul. Para a sua configuração, é necessário que se tenha 7 saídas do microcontrolador dedicadas ao display, sendo 4 para fazer com que o mesmo opera no modo 4 bits (que oferece uma melhor resolução), 1 saída dedicada para controle do backlight do display, 1 saída para habilitar e desabilitar o shield e 1 saída de RS (Data or Signal Display Selection).Além disso, a leitura dos botões é feita através de parâmetros analógicos. Os cinco botões do shield serão ligados à uma única entrada analógica do microcontrolador, sendo possível identificar qual botão foi pressionado por meio dos níveis de tensão medidos pelo ADC do microcontrolador, pois o módulo envia valores de tensão distintos para a entrada analógica. O display, por ser um módulo comercial de arduino opera com uma tensão de 5V.

As portas do microcontrolador usadas para isso foram as portas 16,17,18 e 19 para o modo 4 bits, a porta 11 para o pino de RS do LCD, a porta 12 para habilitar e desabilitar o display, a porta 13 para controle do backlight e a porta 26 para leitura dos botões. 

[Datasheet](https://datasheetspdf.com/pdf-file/746588/D-Robotics/DFR0009/1)

## Regulador de tensão (L7805CV)

Para a regulação da tensão de alimentação em 5V o L7805CV será utilizado.

[Datasheet](https://br.mouser.com/datasheet/2/389/cd00000444-1795274.pdf)


## Transistor 2N7000

Para fornecimento de corrente ao buzzer minimizando eventuais riscos à porta do microntrolador o transistor 2N7000 será utilizado. 

[Datasheet](https://br.mouser.com/datasheet/2/308/NDS7002A_D-1522662.pdf)


## Botão táctil/ Push Button

O push button escolhido é uma chave normalmente aberta (NA) que quando é pressionado fecha um contato, convertendo assim, um comando mecânico em elétrico. No nosso projeto utilizamos dois desses botões, sendo o primeiro para ligar e desligar o dispositivo e o segundo para realizar resets quando necessário do produto. Para ligar e desligar o sistema foi utilizado a porta 6 do microcontrolador, enquanto que para realizar o reset foi utilizado a porta 1.

[Datasheet](https://www.eletropecas.com/_uploads/ProdutoDownload/produto_316.pdf)

## Resistores de 10 kΩ

Os resistores de  10 kΩ foram usados no nosso projeto como resistores de pull-up no circuito do botão de liga e desliga e no circuito de leitura das saídas digitais dos sensores infravermelho. E um desses resistores foi utilizado como resistor de pull-down no circuito de reset do microcontrolador, visto que o ATMEGA328P reseta em nível lógico baixo (0).

## Resistor de 20 kΩ

Conforme aplicação no datasheet do sensor de gás MQ6, utilizamos um resistor de 20 kΩ entre os pinos 3 e 5 do sensor.

## Cristal oscilador de 16 MHz

Para geração do clock do nosso dispositivo, estamos usando  um oscilador controlado por cristal de quartzo para a frequência de 16 MHz, pois esses cristais mantém a frequência de oscilação do circuito no valor desejado e com muita precisão.

## Capacitores de 22 pF

Capacitores adicinados conforme recomendação no datasheet do microcontrolador para circuito de clock com o cristal oscilador.

## Capacitores de 0.33 uF e 0.1 uF

Como recomendação do datasheet do regulador de tensão, foi adicionado esses 2 capacitores no circuito de regulação de tensão. 

## Conectores jack DC fêmea

Utilizamos um conector jack DC fêmea para alimentação do nosso circuito, possibilitando que o circuito seje alimentado facilmente por fontes externas.

## Barras de pinos fêmea do tipo pin socket 2.54mm

Para facilitar a instalação do LCD, dos sensores MQ4, MQ7 e do sensor de infra-vermelho que são módulos, foram utilizadas barras de conectores do tipo pin socket 2.54mm.
