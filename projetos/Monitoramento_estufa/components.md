# Componentes

 ## Microcontrolador 
>Foi selecionado o microcontrolador da família PIC, especificamente o modelo PIC16F886, devido à presença das características essenciais para o projeto em questão. O referido microcontrolador apresenta uma configuração de 28 pinos, dos quais 21 serão empregados no projeto. Além disso, destaca-se a compatibilidade do PIC16F886 com os protocolos seriais I2C e SPI, que são fundamentais para a comunicação com os sensores utilizados neste projeto. Adicionalmente, é relevante mencionar que a faixa de tensão de operação do microcontrolador é de 2 a 5.5V, o que se alinha com a tensão de operação de 5V presente em vários sensores utilizados no projeto. Um fator adicional que influenciou a escolha deste microcontrolador foi a sua ampla popularidade e a disponibilidade de informações acessíveis, tanto por meio da fabricante Microchip quanto em fóruns especializados.
>
>Datasheet: https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001291H.pdf
>
> ## Sensor de Temperatura 
> 
>  O sensor de temperatura escolhido foi o LM35D (Precision Centigrade Temperature Sensor), que oferece uma voltagem de saída diretamente proporcional à temperatura em °C. Ele possui as seguintes especificações relevantes ao nosso projeto:
>  
> A faixa de operação do sensor é de 4 a 30V.
> 
> A temperatura de operação recomendada desse sensor é na faixa de 0 a 100°C (região apropriada para o monitoramento de uma estufa).
> 
> O sensor ja da o valor em graus centígrados, logo não precisa de nenhuma conversão.
> 
> A precisão é de 0,75 °C.
> 
> Tem 3 pinos: VCC(5V no caso do projeto, mesmo do controlador), GND e Vout(Analog Output).
> 
> Datasheet:https://storage.googleapis.com/baudaeletronicadatasheet/lm35-texas.pdf
> 
> ## Sensor Higrômetro 
> 
> O sensor escolhido foi o SKU: SEN0193, um sensor de umidade do solo que mede os níveis de umidade do solo por detecção capacitiva em vez de detecção resistiva como outros sensores no mercado. É feito de material resistente à corrosão, o que lhe confere uma excelente vida útil. Ele possui as seguintes especificações relevantes ao nosso projeto:
> 
> Faixa de operação de 3,3 a 5.5 VDC
> 
> A variação da capacitância é proporcional a variação da umidade (no datasheet contém informações para a calibração do sensor).
> 
> Tem 3 pinos: VCC(5V no caso do projeto, mesmo do controlador), GND e Aout(Analog Output).
> 
> Datasheet: https://wiki.dfrobot.com/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193
> 
> ## Sensor Luminosidade
> 
> O sensor escolhido foi o Sensor de Luminosidade LDR é um componente cuja resistência varia de acordo com a intensidade da luz. Quanto mais luz incidir sobre o componente, menor a resistência. Ele possui as seguintes especificações relevantes ao nosso projeto:
> 
> Temperatura de operação: -25 a 75°C.
> 
> Maxíma voltagem de 150 V, no caso do projeto utilizaremos 5V.
> 
> Tem 2 pinos: GND E VCC( 5 V e Analog Output conectada no mesmo pino).
> 
> https://components101.com/sites/default/files/component_datasheet/LDR%20Datasheet.pdf
> 
> ## Sensor de Pressão/ Botões
> Vão ser utilizados 4 push Buttons 6x6x4;3mm como botão que vai operar junto com o Display LCD 20X4.Ele possui as seguintes especificações relevantes ao nosso projeto:
> 
> Temperatura de operação: -20 a 70°C.
> 
> Máximo de 24V, no caso do projeto utilizaremos 5V.
> 
> Bounce de 5ms.
> 
> Datasheet: https://www.hdk.co.jp/pdf/eng/e291702.pdf
> 
> Agora vamos entrar na parte dos Atuadores do projeto. Veja que alguns dos atuadores são 12V, por isso, será necessário uma alimentação externa de uma bateria de 12V.
>
> ## Motores 
>  Cooler 5V: Um cooler para ambientes é um dispositivo de ventilação projetado para facilitar a circulação de ar e fornecer resfriamento em espaços confinados ou com ventilação insuficiente. No contexto do projeto em questão, o cooler é representado por meio de um motor de 5V. Seu controle será feito por PWM. Nesse contexto, o cooler é acionado como parte de um sistema automatizado, sendo ligado e desligado conforme a necessidade de resfriamento do ambiente. Um dos pinos do microcontrolador que atuará como saída digital é responsável por ativar o motor do cooler. Essa abordagem digital simplifica o controle do cooler, permitindo que ele opere de forma eficiente e precisa dentro dos parâmetros estabelecidos. Dessa forma, o resfriamento adequado do ambiente é alcançado sem a necessidade de um controle contínuo e analógico, simplificando o projeto e otimizando o consumo de energia. Um cooler possível proposto é: OD4028-05MB.
> 
> Datasheet: https://orionfans.com/productFiles/datasheet/OD4028.pdf
>  
>  Aspesor de Água 12V: No projeto em questão, será utilizada um modelo com uma vazão de 2 litros por minuto. Para essa finalidade, será empregado um motor de 12V, especificamente o modelo RS385 (Datasheet: http://descargas.cetronic.es/RS-385SH.pdf ). O motor RS385 será controlado com uma saída digital no sistema, operando como um componente que pode ser ligado e desligado por meio de um sinal digital. Dessa forma, o motor será acionado por um tempo específico conforme as necessidades do projeto, e em seguida desligado. Não haverá a necessidade de um controle analógico contínuo para sua operação. A escolha do motor RS385 se dá devido às suas características técnicas adequadas para a aplicação, como tensão de alimentação de 12V e as especificações de desempenho conforme descritas no respectivo datasheet. Essa configuração simplifica o controle do motor e otimiza o consumo de energia, contribuindo para o bom funcionamento do sistema como um todo.
>  
> ## Aquecedor 
>No projeto em questão, é possível utilizar qualquer heating element de 5V para aquecer o ambiente. O heating element é um dispositivo projetado especificamente para converter energia elétrica em calor. Geralmente, é constituído por um fio ou uma fita resistiva feita de um material que apresenta alta resistência elétrica e baixa condutividade térmica. O princípio de funcionamento do heating element baseia-se na resistência do material quando uma corrente elétrica passa por ele. Essa resistência resulta na dissipação de energia na forma de calor. O calor gerado pelo heating element é transferido para o ambiente circundante ou para um objeto próximo, promovendo o aquecimento desejado.
>
>No projeto utilizado, o heating element será operado como um dispositivo digital. É importante ressaltar que a escolha adequada do heating element deve considerar a potência elétrica necessária para atingir a temperatura desejada, bem como a compatibilidade com a voltagem de 5V disponível no projeto. Além disso, é fundamental garantir a correta dissipação de calor e adotar medidas de segurança, como dispositivos de proteção térmica, para evitar superaquecimento e riscos associados.

> ## Controle da Luminosidade.
> No projeto para controlar a intensidade luminosa das lâmpadas utilizaremos um Dimmer MC-8A que pode ser tanto 127/220V,ou seja, feito para ser ligado na tomada. É um equipamento eletrônico que permite realizar o controle da quantidade de energia que é enviada para a lâmpada incandescente, consecutivamente proporcionando maior ou menor luminosidade, de forma a dimerizá-la.Ele possui as seguintes especificações relevantes ao nosso projeto:
> 
> Tem 4 entradas relativas ao controle : VCC(5V), GND, ZC(Digital Output), DIM(Analog output), 2 entradas (alimentação) para conectar na tomada(220 ou 127V) e duas saídas para conectar à lampâda.
> 
> Possui fácil controle e simples instalação.
> 
> Tem compatibilidade com o microcontrolador PIC.
> 
> Datasheet:https://www.usinainfo.com.br/dimmer-arduino/modulo-dimmer-para-arduino-pic-mc-8a-com-sinal-zero-cross-220v-5915.html
> https://www.usinainfo.com.br/index.php?controller=attachment&id_attachment=71
>
> ## Monitor  
> Será utilizado um Display LCD 16x2 com uma interface serial I2C que é compatível com o microcontrolador PIC selecionado. O principal objetivo desse display é atuar como um monitor, exibindo informações como temperatura, umidade do solo e luminosidade. Através do display, será possível controlar, em conjunto com os botões correspondentes, os intervalos de amostragem dos parâmetros da estufa. O Display LCD em questão possui as seguintes especificações relevantes para o nosso projeto:
> 
> Tensão de operação: 5V
> 
> Tamanho: 16 colunas por 2 linhas, permitindo uma exibição adequada das informações.
> 
> Comunicação serial: Utiliza o protocolo I2C, o qual é compatível com o microcontrolador PIC escolhido. Essa interface simplifica a conexão do display com o microcontrolador e permite uma comunicação eficiente entre os dispositivos.
> 
> Possibilidade de controle: O display é capaz de receber comandos do microcontrolador para atualizar as informações exibidas e ajustar o conteúdo de acordo com as necessidades do projeto.
> 
> Vai utilizar 8 portas de saída: VCC, GND e 6 Digital Output.
> 
> Temperatura de operação:-20 a 70°C.
> 
> Essas especificações relevantes ao nosso projeto garantem que o Display LCD 16x2 seja uma escolha adequada para a função de monitorização e controle dos dados sensoriais na estufa, permitindo uma exibição clara e facilitando a interação com o sistema por meio dos botões correspondentes.
> 
> Datasheet: https://www.vishay.com/docs/37299/37299.pdf
> 
   

