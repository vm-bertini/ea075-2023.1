### Componentes

  

**Módulo PWM:** O modelo escolhido foi o LED1642GWPTR, pois estava presente no software KiCAD. Facilitando, desta forma, o seu uso no projeto e atende às demandas por se tratar de um dispositivo com 16 canais de 12 bits sendo suficiente para realizar o controle dos LEDs e ampliação futura.
*Datasheet:* https://br.mouser.com/datasheet/2/389/dm00080246-1797962.pdf

**Comunicação Sem Fio:** O modelo escolhido foi o módulo Wi-Fi ESP8266 do fabricante Parallax Inc. A comunicação é feita através de uma porta serial através dos pinos 7 e P sendo TX e RX. Sua alimentação é de 5 V.
Datasheet: https://www.mouser.com/datasheet/2/321/32420-Parallax-WX-WiFi-Module-Guide-v1.0-1111706.pdf

**Sensor de luz:** O modelo escolhido foi o AS7261 por conta da comunicação ser tanto I2C quanto UART facilitando a integração com outros dispositivos do projeto. Além de cumprir com o objetivo de identificar as cores das luzes. Ele identifica na faixa de 350nm a 1000nm. 
*Datasheet:* https://www.mouser.com/catalog/specsheets/AMS_03152019_AS7341_DS000504_1-00.pdf

**Bomba de água:** O modelo escolhido foi o modelo 350 GPH do Fabricante Sparkfun Electronics. Sua capacidade é de 350 galões por hora, que representa 1324 litros por hora ou 22 litros por minuto. Essa bomba poderá ser utilizada também caso queira ampliar o jardim.
*Datasheet:* [https://www.digikey.lu/htmldatasheets/production/2459747/0/0/1/rob-10455.html](https://www.digikey.lu/htmldatasheets/production/2459747/0/0/1/rob-10455.html)

**Microcontrolador:** O microcontrolador escolhido é o PIC32, de 32 bits, pois possui várias entradas com diferentes interfaces de comunicação (6 UART, 5 I2C, 4 SPI, CTMU e I²S). Desta forma, é possível conectar todos os sensores e atuadores utilizados no projeto. Tem cerca de 512KB de memória Flash e 128KB de memória SRAM (volátil).
*Datasheet:* https://br.mouser.com/new/microchip/microchip_pic32/

**Sensor de umidade:** O sensor de umidade é específico para solo. Seu modelo é “Soil Moisture V1.0” do fabricante STEMinds. Seu contato elétrico é colocado diretamente na terra. É alimentado com 5 Vcc e o sinal gerado é analógico, sendo necessário um conversor AD para leitura no microcontrolador.
*Datasheet:* https://www.mouser.com/catalog/specsheets/Crowd%20Supply_06082021_EDUPON-SENLG.pdf

**Sensor de temperatura:** O sensor de temperatura modelo DS18B20, do fabricante Maxim Integrated, disponibiliza o valor da temperatura ambiente em até 12 bits. O sensor disponibiliza leituras de -30 ºC a 100 ºC com erro de ± 1 ºC.
*Datasheet:* https://br.mouser.com/datasheet/2/256/maxim%20integrated%20products_ds18b20-1178755.pdf

**LEDS:** Os LEDs utilizados no projeto são de modelos diferentes descritos abaixo:  

**LED faixa do visível:** Para maior facilidade de montagem serão adotados LEDs RGB de 5mm modelo T-1 ¾ (WP154A4SEJ3VBDZGC/CA), do fabricante Kingbright. A tensão nominal de trabalho é de 3 V, a corrente consumida pelas três cores é de 85 mA.
*Datasheet:* https://www.kingbrightusa.com/images/catalog/SPEC/WP154A4SEJ3VBDZGC-CA.pdf

**LED de infravermelho:** É do modelo TSHF6210 do fabricante Vishay. A tensão nominal de trabalho é de 5 V, a corrente consumida é de 100 mA.
*Datasheet:* https://www.vishay.com/docs/81734/tshf6210.pdf

**LED ultravioleta:** É o modelo UV3TZ-385-15 do fabricante Bivar. Sua emissão é centrada em 385 nm.
*Datasheet:* https://br.mouser.com/datasheet/2/50/UV3TZ_XXX_XX-3002137.pdf

**Fontes de alimentação:** Foram escolhidas a partir das necessidades dos dispositivos. Optou-se por fontes do fabricante Mean Well pois seus modelos já estão inclusos no software KiCAD. 

**Modelo IRM-02-5:** Para componentes com alimentação de 5V (Sensor de umidade).
*Datasheet:* [https://www.meanwell-web.com/content/files/pdfs/productPdfs/MW/IRM-02/IRM-02-spec.pdf](https://www.meanwell-web.com/content/files/pdfs/productPdfs/MW/IRM-02/IRM-02-spec.pdf)

**Modelo IRM-03-3.3**: Para componentes com alimentação de 3.3V (Demais componentes).
Datasheet: https://www.meanwell.com/productPdf.aspx?i=677#1

**IRM-60-12:** Para componentes com alimentação de 12V (Bomba d’água).
*Datasheet:* https://www.meanwellusa.com/productPdf.aspx?i=687

**Transistor para acionamento da bomba d’água:** Um transistor modelo 2SC1945. Pois através da tensão aplicada é fácil configurar o acionamento.
**Datasheet:** https://www.meanwellusa.com/productPdf.aspx?i=687
