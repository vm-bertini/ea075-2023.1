## Lista de componentes utilizados no projeto:

- [Arduíno ATmega328]();
- [Protoboard MP-830A]();
- [Cabos de ligação/jumpers]();
- [Sensor DHT11](https://github.com/juuhnicolette/ea075/blob/65f5fa74a7536e2b79bdfab2bf62828c2832df3b/2022.2/Estufa%20Inteligente/datasheets/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf);
- [Resistor 10KΩ](https://github.com/juuhnicolette/ea075/blob/65f5fa74a7536e2b79bdfab2bf62828c2832df3b/2022.2/Estufa%20Inteligente/datasheets/resistor10K.pdf);
- [Sensor IRM-3638](https://github.com/juuhnicolette/ea075/blob/65f5fa74a7536e2b79bdfab2bf62828c2832df3b/2022.2/Estufa%20Inteligente/datasheets/IRM-3638.pdf);
- [LED 5MM emissor infravermelho](https://github.com/juuhnicolette/ea075/blob/65f5fa74a7536e2b79bdfab2bf62828c2832df3b/2022.2/Estufa%20Inteligente/datasheets/LedIR.pdf);
- [Válvula solenóide 12 VDC normalmente fechada ZE-4F180](https://github.com/juuhnicolette/ea075/blob/65f5fa74a7536e2b79bdfab2bf62828c2832df3b/2022.2/Estufa%20Inteligente/datasheets/ZE4F18012Vwatersolenoidvalve.pdf);
- [Fonte de alimentação de 12V]();
- [Módulo relê de 5V](https://github.com/juuhnicolette/ea075/blob/cee8a106ab730e02bb94920bd47b5e1a28c42e04/2022.2/Estufa%20Inteligente/datasheets/Relay-Module-Datasheet.pdf);

### Observações:
(I) Escolhemos o sensor de temperatura e umidade DHT11, porém, em um projeto real o ideal seria o sensor DHT22 pois a faixa de temperatura que ele abrange é maior (de -40 a 80 ºC). O sensor DHT11 possui uma faixa menor (de 0 a 50 ºC), e não é indicado para temperaturas acima de 50ºC. Em um projeto real precisamos nos preocupar com possíveis danos dos equipamentos que controlam a temperatura, que seriam os ares-condicionados. Uma falha neles poderia resultar uma temperatura acima de 50º e consequentemente um dano irreversível ao componente que não suporta temperaturas acima do esperado. Com relação ao custo, o sensor DHT11 tem valor R$16,40, enquanto o sensor DHT22 custa R$39,90.

(II)


