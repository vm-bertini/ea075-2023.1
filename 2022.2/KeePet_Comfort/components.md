## ESP8285H16 - Microcontrolador

A utilização de um microcontrolador é fundamental para coordenar a leitura de periféricos de entrada e a subsequente tomada de decisões, visando o tratamento de eventos. Assim, foi escolhido o *ESP8285H16* graças à sua capacidade de se comunicar com os periféricos escohidos (apresentados a seguir) através de protocólos I2C e 1-Wire, possui comunicação Wi-Fi integrada ao chip para comunicação com ar-condicionado, aquecedor, luzes e configurações de parâmetros de operação, economizando portas que seriam utilizadas para um possível módulo Wi-Fi externo. Sua memória flash interna de 2 MB, além de sua memória SRAM utilizável de cerca de 75 kB, permitem o armazenamento de programas e dados. O número de portas disponíveis no chip satisfazem a quantidade exigida pelos periféricos.

[Link do datasheet](https://www.espressif.com/sites/default/files/documentation/0a-esp8285_datasheet_en.pdf)

## DS18B20 - Sensor de Temperatura

Conforme a exigência do projeto para realização do controle de temperatura, identificou-se a necessidade de um sensor de temperatura. O *DS18B20* foi escolhido por conta de seu protocólo de comunicação 1-Wire, utilizando uma única linha, que é empregada para alimentação e para realizar a transmissão de dados entre dispositivos, economizando número de portas disponíveis. Além disso, para a faixa de -10°C a +85°C a precisão do periférico é de ±0.5°C, atendendo o propósito do projeto que não requer controle fino da temperatura. Se tratando de um termômetro digital, sua resolução pode ser configurada como 9, 10, 11, ou 12 bits, que corresponde a incrementos de 0.5°C, 0.25°C, 0.125°C e 0.0625°C, respectivamente, suficiente para nossa finalidade.

[Link do datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)

## DS3231 - Real-Time-Clock (RTC)

O controle das luzes necessita que a hora seja conhecida e, assim, identificou-se a necessidade de um módulo RTC que permite o controle do tempo. O *DS3231* foi escolhido pois permite contar horas, minutos, segundos, atendendo a aplicação desejada, e por comunicar-se com o microcontrolador por meio da interface serial I2C, aceita pelo ESP8285H16.

[Link do datasheet](https://datasheets.maximintegrated.com/en/ds/DS3231.pdf)
