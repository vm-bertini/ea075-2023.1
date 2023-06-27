# `<Mapeador de Labirinto>`
# `<Maze Mapper>`

## Components


### Sensor de distância

Modelo: Sensor Ultrassônico HC-SR04
Datasheet: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf
Justificativa: Esses sensores de distância são adequados para o projeto em questão pois: Tem precisão suficiente para realizar as operações necessárias; Tem preço compatível ao orçamento do projeto; A física por trás de seu funcionamento se adequa às situações necessárias.
Preço aproximado: R$ 14,00 
Padrão de comunicação: UART


### Módulo Bluetooth

Modelo: Módulo Bluetooth HC-05
Datasheet: https://components101.com/sites/default/files/component_datasheet/HC-05%20Datasheet.pdf
Justificativa: Esse componente apresenta algumas especificações mais robustas que o necessário para o projeto, porém, a sua simplicidade de uso e configuração, e seu preço em linha com o projeto, fazem com que isso não seja um problema.
Preço aproximado: R$ 47,00
Padrão de comunicação: UART

### Ponte H

Modelo: Ponte H L293D
Datasheet: https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1684653824491&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D
Justificativa: Esse dispositivo será utilizado para realizar o controle dos dois motores do carrinho, foi escolhida a opção mais adequada para o projeto pelo preço mais acessível.
Preço aproximado: R$ 7,00
Padrão de comunicação: UART

### Switch

Modelo: Switch de Alavanca SPDT On/Off
Datasheet: https://cdn-shop.adafruit.com/product-files/3221/singe_blue_switch_diagram.jpg
Justificativa: Por conta do preço baixo desse equipamento, optamos por escolher uma versão com construção com certa robustez, uma vez que o projeto irá operar em ambientes em que pode haver poeira e outros tipos de sujeira.
Preço aproximado: R$ 2,00

### Button

Modelo: KSA0M211
Datasheet: https://www.ckswitches.com/media/1457/ksa_ksl.pdf
Justificativa: Por conta do preço baixo desse equipamento, optamos por escolher uma versão com construção com certa robustez, uma vez que o projeto irá operar em ambientes em que pode haver poeira e outros tipos de sujeira.
Preço aproximado: R$ 2,50

### Motores

Modelo: Motor de Passo NEMA 17
Datasheet: https://storage.googleapis.com/baudaeletronicadatasheet/SM1.8-A1740SCHBK-CS.pdf
Justificativa: Esses motores são ideais para o projeto uma vez que apresentam uma necessidade de alimentação compatível, um gasto energético viavel, uma velocidade máxima de rotação satisfatória, e uma precisão que possibilita o controle de movimentação.
Preço aproximado: R$ 60,00

### Micro SD Reader

Modelo: Módulo Leitor Cartão Micro Sd Card (leitura/escrita)
Datasheet: https://cdn.awsli.com.br/945/945993/arquivos/Datasheet-MicroSD-Module.pdf
Justificativa: Um módulo necessário para realizar a leitura e escrita na memória, sendo ele compatível com o microcontrolador escolhido.
Preço aproximado: R$ 15,00
Padrão de comunicação: SPI

### Micro SD

Modelo: SanDisk Cartão micro SDHC Ultra SDSQUNS-032G-GN3MN 32GB 80MB/s UHS-I Classe 10
Datasheet: https://documents.westerndigital.com/content/dam/doc-library/en_us/assets/public/sandisk/product/memory-cards/ultra-uhs-i-microsd/data-sheet-ultra-uhs-i-microsd.pdf
Justificativa: Esse componente é muito mais robusto que o necessário para sua tarefa, porém, uma vez que seu preço é compatível com o projeto ele foi escolhido, garantindo certa folga para o funcionamento e o salvamento de vários mapas.
Preço aproximado: R$ 20,00

### Bateria

Modelo: 18650 - Bateria Cilíndrica Li-Ion - 3,6V - 2000mAh
Datasheet: https://www.sta-eletronica.com.br/resources/especificacoes/1920.pdf
Justificativa: A bateria tem uma voltagem adequada para que ao colocá-las em série tenhamos todas as tensões elétricas necessárias, e sua carga é capaz de abastecer o sistema todo por algumas horas.
Preço aproximado: R$ 13,00

### Regulador de tensão

Modelo: Regulador de Tensão 5V 7805 SMD DPACK
Datasheet: https://www.onsemi.com/pdf/datasheet/mc7800-d.pdf
Justificativa: Para garantir uma alimentação adequada para os diversos componentes mais sensíveis, a tensão de 10.8V gerada pelas baterias será acoplada a um regulador de 5V, possibilitando uma alimentação adequada de todos os componentes.
Preço aproximado: R$ 4,00

### Microcontrolador

Modelo: ATmega328P
Datasheet: https://pdf1.alldatasheet.com/datasheet-pdf/view/241077/ATMEL/ATMEGA328P.html
Justificativa: Este microcontrolador foi escolhido por cumprir todas as exigências do sistema com um desempenho satisfatório, preço e tamanhos compatíveis, e praticidade de trabalho, devido a sua popularidade.
Preço aproximado: R$ 20,00
