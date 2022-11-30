# `<Sistema de Ventilação Forçada Automatizado para Workstations>`
# `<Automated Forced Ventilation System for Workstations>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| David Daminelli  | 169774  | Eng. Elétrica|
| Giovanna Presta  | 173275  | Eng. Elétrica|

## Arquivos Importantes

[Esquemático em PDF](pdf/Ventsys%20V1I1.PDF)

[Lista de Componentes](./BOM%20Ventsys%20V1I1.xlsx)

[PCB](pdf/Ventsys%20V1I1%203D.PDF)

## Descrição do Projeto 

Com o avanço da tecnologia, computadores com maiores capacidades de processamento foram desenvolvidos para resolver os problemas mais complexos. No entanto, essa capacidade de processamento faz com que os componentes eletrônicos dissepem altas quantidades de calor. Para que os computadores operem da maneira desejada e, principalmente, que no sejam danificados, é necessário um sistema de resfriamento que mantenha sua temperatura em um limiar especificado pelo fabricante. 

Uma das formas mais simples de realizar essa função é utilizando ventilação forçada por meio de coolers. Porém, essa solução é custosa e inconveniente por conta da energia gasta e pelo ruído emitido. Nosso sistema resolve essas limitações ao acionar os ventiladores instalados em racks apenas quando a temperatura dos computadores é elevada, desligando caso contrário, mantendo a simplicidade e diminuindo os custos associados à ela.    

Nosso sistema busca ser o mais genérico possível, possibilitando medir até 4 sensores de temperatura, os quais podem ser escolhidos e adaptados para comunicar-se com nosso sistema, além de ser possivel acionar até 4 pares de ventiladores. 

## Descrição Funcional

### Funcionalidades

- Medir a temperatura;
- Comparar temperatura medida com valor ajustado;
- Ajustar setpoints de temperatura;
- Acionar/desacionar ventiladores;
- Exibir valor da temperatura medida.

### Configurabilidade

- Ajustar setpoints de liga/desliga dos ventiladores

### Eventos

- Ligar/Desligar coolers com base na temperatura medida.

### Tratamento de Eventos

- Se cooler estiver desligado e temperatura for menor que temperatura ajustada, manter desligado;
- Se cooler estiver desligado e temperatura for maior que temperatura ajustada, ligar cooler;
- Se cooler estiver ligado e temperatura for maior que temperatura ajustada, manter ligado;
- Se cooler estiver ligado e temperatura for menor que temperatura ajustada, desligar;
- Se botão B1 for pressionado, inicia processo de modificar setpoints.

## Descrição Estrutural do Sistema

Disponível no arquivo `ventsys.drawio` 

## Especificações


### Especificação Estrutural

* **Microcontrolador**

    A unidade microcontroladora escolhida é o PIC16F877. Como será descrito nos itens subsequêntes, o microcontrolador deverá comunicar-se com o conversor AD via SPI, comparar as tensões com um valor de referência, mostrar valores em um display LCD e acionar um motor DC. 

* **Sensor de temperatura**

    A temperatura que deverá ser lida pelo sensor vai depender da Workstation que será conrtrolada pelo sistema, uma vez que unidades mais potentes podem chegar a temperaturas mais altas. Uma especificação que abrange uma alta gama de computadores é o intervalo de 0-150°C. 

    Além disso, para simplicidade do projeto, o sensor deve fornecer uma tensão de saída proporcional a temperatura medida, tensão essa que deve estar no intervalo de leitura do ADC (0-5V).

    Para que diferentes sensores possam ser escolhidos à depender da aplicação, o projeto permitira que diferentes sensores possam ser conectados no conector de entrada/saída. 

Apesar da versalidade, uma escolha que atende às especificações listadas é o LM35.

* **Conversor AD**

    Os sensores forneceram uma tensão proporcional à temperatura medida. Ao invés de usar as poucas portas de ADC disponíveis no PIC, uma melhor escolha é utilizar um ADC externo, possibilitando uma melhor resolução e um maior número de leituras.

    O ADC escolhido deve ser capaz de comunicar-se via protocolo SPI com o microcontrolador e ler até 4 tensões de 0-5V.

* **Atuador**

    O projeto não contempla, inicialmente, o controle de velocidade do ventilador. Sendo assim, o acionamento pode ser realizado por um MOSFET atuando como chave. A corrente máxima do MOSFET escolhido deve ser pelomenos 2A para que este suporte o acionamento de uma alta gama de coolers disponíveis.

* **Display**

    Um Display irá mostrar a temperatura das workstations medidas, além de auxliar no ajuste da temperatura máxima e mínima. Um Display LCD 16x2 é suficiente para essa aplicação. 

### Especificação de Algoritmos 

Disponível no arquivo `algoritmos` 

## Referências

https://circuitdigest.com/microcontroller-projects/pic16f877a-spi-communication-tutorial

https://circuitdigest.com/microcontroller-projects/16x2-lcd-interfacing-with-pic-microcontroller

Notas de aula Prof. José Raimundo de Oliveira e Wu Shin-Ting
