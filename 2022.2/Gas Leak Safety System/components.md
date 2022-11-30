## Microcontrolador ATMEGA328P
Devido a sua ampla utilização e disponibilidade no mercado foi adotado o microcontrolador ATMEGA328P para ser o responsável por tratar e gerenciar as rotinas do nosso dispositivo. O ATMEGA328P possui como características principais o fato de possuir 3 memórias internas, sendo elas uma memória Flash (32 KB), uma SRAM (2 KB) e uma EEPROM (1 KB), possui também 23 I/Os, opera com uma tensão de 5V e as suas saídas fornecem uma corrente de 40 mA, além disso, consegue operar com um clock entre 0 à 20 MHz.

## Sensores para detecção de gás

Estes sensores, de modo geral, apresentam um material sensível ao gás que precisa ser detectado. Em contato com o ar puro sua condutividade elétrica é baixa enquanto na presença do gás desejado sua condutividade aumenta com a concentração. Desta forma, essa diferença de condutividade é explorada para obtenção de um sinal indicador da presença da substância desejada. 

Os sensores utilizados nesta aplicação serão o MQ-7, MQ-6 e MQ-4, responsáveis pela detecção de monóxido de carbono, gás inflamável (GLP) e gás metano, respectivamente. 

O sinal de saída de cada um destes componentes é analógico, entretanto, a conexão dos sensores MQ-7 e MQ-4 com o microcontrolador será feita via porta digital visto que estes componentes possuem módulos comerciais com conversão AD integrada. O sensor MQ-6 será conectado diretamente à porta analógica do microcontrolador. 

### MQ-7 (Monóxido de Carbono)

Para realizar a detecção do monóxido de carbono o módulo do sensor MQ-7 com conversão analógico-digital já integrada será utilizado, sua conexão com o microcontrolador será feita via porta digital 24.

[Datasheet](https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ7.pdf)

### MQ-4 (Metano)

Para realizar a detecção do gás metano o sensor MQ-4 com conversão analógico-digital já integrada será utilizado, sua conexão com o microcontrolador será feita via porta digital 25.

[Datasheet](https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ4.pdf)

### MQ-6 (GLP)

Para realizar a detecção de GLP o sensor MQ-6 será utilizado, sua conexão com o microcontrolador será feita via porta analógica 23 24.

[Datasheet](https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ7.pdf)
