# `<Monitoramento_Estufa>`
# `<Greenhouse_monitoring>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Felipe Souza Sisnando de Araujo  | 239617  | Eng. Elétrica|
> | Levi Santos Volotão  | 239783  | Eng. Elétrica|


## Arquivos Importantes (:warning: NOVO :warning:)

>[Esquemático em PDF](link para imagens/pdf esquemático)
>
> PDF:
>https://github.com/Felipe-Sisnando/ea075-2023.1/blob/main/projetos/Monitoramento_estufa/pdf/Esquematico.pdf
>
>
>
>[Lista de Componentes]
>https://github.com/Felipe-Sisnando/ea075-2023.1/blob/main/projetos/Monitoramento_estufa/components.md
>
>[PCB](link para imagens/pdf PCB)
>
> Imagens:
>
>
>PDF:
>
>

## Descrição do Projeto
> 
> Hoje em dia, observa-se o surgimento de cada vez mais estufas controladas, pois são um ambiente controlado em que plantações podem ser monitoradas e os aspectos físicos do ambiente podem ser configurados e otimizados para o crescimento e desenvolvimento adequado de uma certa espécie. Embora o custo inicial de uma estufa seja elevado, ela possibilita uma melhora na qualidade dos produtos, aumentando seu valor agregado, e uma dependência menor de características que não podemos controlar quando cultivadas a céu aberto.
> 
> Com uma plantação em estufa, os parâmetros externos não terão tanta influência, e as épocas do ano influenciarão menos as colheitas, garantindo a produção durante o ano todo, reduzindo fenômenos como falta de abastecimento em determinados períodos do ano e prejuízos econômicos dos cultivadores devido ao clima. Como exemplo, observa-se que "no verão, as chuvas demasiadas danificam as plantas e criam condições favoráveis para o aparecimento de doenças, atrapalhando a produção, sendo a época de maiores preços dos produtos hortícolas pela falta de oferta para abastecimento. Por outro lado, o frio e os ventos, do inverno prolongam o ciclo dessas culturas, que consequentemente desprogramam a produção e causam grandes prejuízos econômicos" [Miura, 2011]. Porém, mesmo com influências externas reduzidas, ainda é necessário o controle interno, devido a problemas como a alta irradiação externa resultando em um efeito de aquecimento dentro da estufa,podendo ser prejudicial à plantação caso não ocorra o controle da temperatura necessário. "Além disso, a alta umidade relativa do ar favorece o aparecimento de doenças e provoca menor desenvolvimento das plantas devido ao fato da planta transpirar menos e ter uma menor absorção de nutrientes nessas condições, enquanto, a baixa umidade relativa do ar juntamente com altas temperaturas provoca o aumento da transpiração, fechamento dos estômatos, redução da taxa de transpiração e abortamento das flores devido a uma polinização deficiente" [Lopes e Stripari, 1997].  Além disso, "A manutenção adequada da umidade do solo é crítica para a produção de plantas em sistemas de cultivo fechados, onde as plantas dependem inteiramente da água fornecida pelo sistema de irrigação" (Raimondi et al., 2021).
>
> Desse modo, nós propomos o desenvolvimento de um sistema embarcado responsável pelo monitoramento da estufa, que será capaz de identificar quando os valores de temperatura, umidade do solo e luminosidade estiverem fora da faixa desejada, e será capaz de corrigir esses valores, utilizando sistemas de aquecimento e refrigeração (coolers),aspersores de água e um sistema que controla as lâmpadas responsáveis pela luminosidade da estufa, bem como a luminosidade que entra do ambiente externo, a partir de um "shade" (funciona como uma "cortina") cuja abertura é controlada. Esse monitoramento será de grande utilidade para cultivadores de diversos produtos, visto que as faixas de temperautra, luminosidade e umidade desejadas podem ser configuradas conforme os parâmetros adequados para cada espécie. A instalação desse sistema irá aumentar o valor agregado dos seus produtos, viabilizar o cultivo em todas as épocas do ano e permitir um controle automatizado, sem necessidade de mão de obra.
>  


## Descrição Funcional

### Funcionalidades (:warning: Atualizado :warning:)
>O nosso sistema embarcado será capaz de obter a temperatura do ambiente, a luminosidade e a umidade do solo a partir de sensores. Ele mostrará esses valores em um LCD (Liquid Crystal Display). Inicialmente ele amostrará os valores de temperatura, umidade do solo e luminosidade a cada 10 minutos, porém esses parâmetros serão configuráveis, e a frequência de amostragem de cada fator pode ser alterada conforme a necessidade do cliente. O sistema também será capaz de detectar quando um valor estiver fora da faixa adequada configurada, e para esse caso, irá iniciar rotinas de tratamento adequadas, controlando o funcionamento dos aspersores de água, sistema de aquecimento, coolers, lâmpadas.
>
> O sistema poderá : 
> - Ligar e desligar os aspersores de água.
>
> - Ligar, desligar e controlar o sistema de aquecimento (por meio de PWM).
>
> - Ligar, desligar e controlar o cooler (por meio de PWM).
>
> - Ligar, desligar e controlar a intensidade da luz das lâmpadas de LED (por meio de um dimmer).

### Configurabilidade (:warning: Atualizado :warning:)
> A estufa está sendo projetada para uma diversidade de espécies de plantas, e cada planta tem suas especificidades em relação ao ambiente para ter uma produtividade melhor. Portanto, será possível configurar a faixa de valores desejada e a frequência com que os dados serão amostrados. Essa configuração será feita por botões. O LCD no modo exibição mostrará o último estado amostrado, e atualizará a cada amostragem. Ao apertar o botão de configuração, o sistema irá funcionar no modo de configuração, e o LCD mostrará os valores definidos para o período de amostragem e os valores máximo e mínimo para cada parâmetro. Para mudar esses valores, haverá 3 botões (além do botão que muda entre o modo de exibição e configuração, totalizando 4 botões), um botão que muda a característica cujo valor deseja-se alterar, um botão para incrementar esse valor e um botão para decrementar esse valor. Ao pressionar o botão de configuração novamente, retorna-se para o modo de exibição. Os valores possíveis para as características obedecerão a limites de acordo com as especificações dos sensores, e o período de amostragem poderá variar de 1 a 59 minutos. Por simplicidade, os sensores terão o mesmo perído de amostragem.
### Eventos
>  O sistema deve tratar os seguintes eventos periódicos:
>
> - Amostragem de temperatura: De X em X minutos deve-se obter o valor da temperatura lido no sensor (em que X é um valor configurável, inicialmete colocado como 10 minutos) 
>
> - Amostragem de umidade do solo: De X em X minutos deve-se obter o valor da umidade lido no sensor 
>
> - Amostragem de luminosidade: De X em X minutos deve-se obter o valor da umidade lido no sensor 
>
> O sistema deve tratar os seguintes eventos não periódicos:
> 
> - Temperatura dentro da faixa desejada
> 
> - Temperatura abaixo da temperatura mínima configurada
>
> - Temperatura acima da temperatura máxima configurada
>
> - Umidade do solo dentro da faixa desejada
> 
> - Umidade abaixo da umidade mínima configurada
>
> - Luminosidade dentro da faixa desejada
> 
> - Luminosidade abaixo da luminosidade mínima configurada
>
> - Luminosidade acima da luminosidade máxima configurada
>
> - Botão para mudar para o modo configuração apertado
>
> - Botão para incrementar em 1 o valor do parâmetro selecionado apertado
>
> - Botão para decrementar em 1 o valor do parâmetro selecionado apertado
>
> - Botão para mudar parâmetro selecionado (cujo valor deseja-se mudar) apertado
>
>

### Tratamento de Eventos ((:warning: Atualizado :warning:)
>
> - Tratamento da amostragem de temperatura: 
> 
> Obter o valor da temperatura e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
> 
> - Tratamento da amostragem de umidade:
> 
> Obter o valor da umidade e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
> 
> - Tratamento da amostragem de luminosidade: 
> 
>  Obter o valor da luminosidade e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
>  
> - Tratamendo quando a temperatura está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a temperatura está abaixo da temperatura mínima configurada:
> 
> Caso o cooler esteja ligado, desliga o cooler.
> 
>  Caso contrário, se o sistema de aquecimento estiver desligado, liga-se o sistema de aquecimento. Se estiver ligado, aumenta aproximadamente em 5°C a temperatura do aquecedor (aumenta o duty-cicle).
> 
> - Tratamento quando a temperatura está acima da temperatura máxima configurada:
> 
> Caso o aquecedor esteja ligado, desliga o aquecedor. 
> 
> Caso contrário, se o cooler estiver desligado, liga-se o cooler. Se estiver ligado, diminui aproximadamente em 5°C a temperatura do cooler (aumenta o duty-cicle).
> 
> - Tratamento quando a umidade está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a umidade está abaixo da umidade mínima configurada:
>  
> Liga-se o aspersor de água e, após 30 segundos, ele é desligado.
>
> - Tratamento quando a luminosidade está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a luminosidade está abaixo da luminosidade mínima configurada:
> 
> Acender as lâmpadas de LED. Se estiverem acesas, aumentar intensidade da luz (dimmer).
>
> - Tratamento quando a luminosidade está acima da luminosidade máxima configurada:
> 
> Caso as lâmpadas estejam ligadas, desligar as lâmpadas.
>
> - Tratamento quando o botão de configuração está apertado:
> 
> Caso esteja no modo exibição, muda para o modo de configuração (o LCD passa a mostrar os limites dos parâmetros e o período de amostragem)
> 
> Caso esteja no modo de configuração, muda para o modo exibição(o LCD mostra os valores de temperatura, luminosidade e umidade lidos pelos sensores), estabelece os novos valores limites das faixas de temperatura, umidade e luminosidade e estabelece o novo período de amostragem.
>
> - Tratamento quando o botão de incremento está apertado:
> 
> Caso esteja no modo configuração, aumenta o valor da característica selecionada em 1
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
> 
> - Tratamento quando o botão de decremento está apertado:
> 
> Caso esteja no modo configuração, decrementa o valor da característica selecionada em 1
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
>
> - Tratamento quando o botão para mudar parâmetro selecionado está apertado:
> 
> Caso esteja no modo configuração, muda a característica selecionada
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
>

## Descrição Estrutural do Sistema (:warning: Atualizado :warning:)

>![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/129390336/fd3b15b8-b798-4ff8-a2c2-e191e8297fbb)
>
> Observa-se que podem-se destacar três grandes blocos funcionais: o microcontrolador, os sensores e os atuadores. No bloco dos sensores tem-se os sensores de luminosidade, umidade e temperatura, bem como os botões (que podem ser considerados como sensores de pressão); já como atuadores, observa-se o cooler, aquecedor, lâmpadas e o aspersor, bem como o LCD (que pode ser considerado um atuador, permitindo a visualização de dados na tela). Os sensores são capazes de transformar parâmetros físicos em sinais elétricos, que podem ser processados pelo microcoontrolador. A partir desses sinais, o microcoontrolador processa o programa de tratamento de enventos (conforme explicado em seções anteriores),  e envia sinais de controle para os atuadores, que atuam com base nesses sinais e transformam esses sinais elétricos em alguns parâmetros físicos, permitindo o correto funcionamento do circuito.

## Especificações 

### Especificação Estrutural


> #### Microcontrolador (:warning: Atualizado :warning:)
>Foi selecionado o microcontrolador da família PIC, especificamente o modelo PIC16F886, devido à presença das características essenciais para o projeto em questão. O referido microcontrolador apresenta uma configuração de 28 pinos, dos quais 21 serão empregados no projeto. Além disso, destaca-se a compatibilidade do PIC16F886 com os protocolos seriais I2C e SPI, que são fundamentais para a comunicação com os sensores utilizados neste projeto. Adicionalmente, é relevante mencionar que a faixa de tensão de operação do microcontrolador é de 2 a 5.5V, o que se alinha com a tensão de operação de 5V presente em vários sensores utilizados no projeto. Um fator adicional que influenciou a escolha deste microcontrolador foi a sua ampla popularidade e a disponibilidade de informações acessíveis, tanto por meio da fabricante Microchip quanto em fóruns especializados.
>
>Datasheet: https://ww1.microchip.com/downloads/aemDocuments/documents/OTH/ProductDocuments/DataSheets/40001291H.pdf
>
> #### Sensor de Temperatura (:warning: Atualizado :warning:)
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
> #### Sensor Higrômetro (:warning: Atualizado :warning:)
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
> #### Sensor Luminosidade
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
> #### Sensor de Pressão/ Botões
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
> #### Motores (:warning: Atualizado :warning:)
>  Cooler 5V: Um cooler para ambientes é um dispositivo de ventilação projetado para facilitar a circulação de ar e fornecer resfriamento em espaços confinados ou com ventilação insuficiente. No contexto do projeto em questão, o cooler é representado por meio de um motor de 5V. Seu controle será feito por PWM. Nesse contexto, o cooler é acionado como parte de um sistema automatizado, sendo ligado e desligado conforme a necessidade de resfriamento do ambiente. Um dos pinos do microcontrolador que atuará como saída digital é responsável por ativar o motor do cooler. Essa abordagem digital simplifica o controle do cooler, permitindo que ele opere de forma eficiente e precisa dentro dos parâmetros estabelecidos. Dessa forma, o resfriamento adequado do ambiente é alcançado sem a necessidade de um controle contínuo e analógico, simplificando o projeto e otimizando o consumo de energia. Um cooler possível proposto é: OD4028-05MB.
> 
> Datasheet: https://orionfans.com/productFiles/datasheet/OD4028.pdf
>  
>  Aspesor de Água 12V: No projeto em questão, será utilizada um modelo com uma vazão de 2 litros por minuto. Para essa finalidade, será empregado um motor de 12V, especificamente o modelo RS385 (Datasheet: http://descargas.cetronic.es/RS-385SH.pdf ). O motor RS385 será controlado com uma saída digital no sistema, operando como um componente que pode ser ligado e desligado por meio de um sinal digital. Dessa forma, o motor será acionado por um tempo específico conforme as necessidades do projeto, e em seguida desligado. Não haverá a necessidade de um controle analógico contínuo para sua operação. A escolha do motor RS385 se dá devido às suas características técnicas adequadas para a aplicação, como tensão de alimentação de 12V e as especificações de desempenho conforme descritas no respectivo datasheet. Essa configuração simplifica o controle do motor e otimiza o consumo de energia, contribuindo para o bom funcionamento do sistema como um todo.
>  
> #### Aquecedor (:warning: Atualizado :warning:)
>No projeto em questão, é possível utilizar qualquer heating element de 5V para aquecer o ambiente. O heating element é um dispositivo projetado especificamente para converter energia elétrica em calor. Geralmente, é constituído por um fio ou uma fita resistiva feita de um material que apresenta alta resistência elétrica e baixa condutividade térmica. O princípio de funcionamento do heating element baseia-se na resistência do material quando uma corrente elétrica passa por ele. Essa resistência resulta na dissipação de energia na forma de calor. O calor gerado pelo heating element é transferido para o ambiente circundante ou para um objeto próximo, promovendo o aquecimento desejado.
>
>No projeto utilizado, o heating element será operado como um dispositivo digital, com um método de PWM. É importante ressaltar que a escolha adequada do heating element deve considerar a potência elétrica necessária para atingir a temperatura desejada, bem como a compatibilidade com a voltagem de 5V disponível no projeto. Além disso, é fundamental garantir a correta dissipação de calor e adotar medidas de segurança, como dispositivos de proteção térmica, para evitar superaquecimento e riscos associados.

> #### Controle da Luminosidade.
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
> #### Monitor  (:warning: Atualizado :warning:)
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
   

### Especificação de Algoritmos 
>
> A seguir, apresenta-se, para cada evento, um pseudocódigo e um fluxograma representando o algoritmo de tratamento do evento:
> 
> - Inicialmente, devem-se estabelecer as variáveis que serão utilizadas:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/7e5bbacb-94a5-408a-84a1-655590c42cc3)
>
> - Destaca-se que o programa principal sera feito por polling (programado), mas os botoes serão por interrupcao
>
> - Após cada ciclo do programa, deverá ser atualizado o display LCD com os parâmetros lidos:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/7fd63365-c0cd-4e0b-9ed6-37ea33706fa4)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/a63415ca-f883-475c-b92c-f8e1865c83b8)
>
> - Para a amostragem de temperatura, tem-se
> 
>![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/7ff64b59-5883-4a74-a93b-ee71dbe0ad6e)
>
>![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/c687cd53-ee9e-4ef1-8467-c444719c225b)
>
> - Para a amostragem de umidade:
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/df5403e4-7258-4f50-ab6e-b6c69b9a4b11)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/8d4ad63f-a4e7-468a-8a89-96989eb41f35)
> 
> -  Para a amostragem de luminosidade: 
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/e2c17bf5-1b0d-4cb1-95a9-84a65b43f161)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/5f48d73d-08f8-4360-b55b-8117d94ab1e2)
>
> - Tratamento quando a temperatura está abaixo da temperatura mínima configurada:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/abb771fc-3ed0-48dd-b825-9bbbdbcc0b13)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/d8826e5a-1c55-434c-8f12-5c56110c4dca)
>
> - Tratamento quando a temperatura está acima da temperatura máxima configurada:
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/df398531-873c-4687-99f4-44c448207c7b)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/fb9cfcf1-505b-4df3-bfad-bf7597067f98)
>
> - Tratamento quando a umidade está abaixo da umidade mínima configurada:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/b4538e9a-2ddc-4b07-b38c-33740533d5d2)
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/15c6c9af-fb86-4f09-ad2e-22651ca13d8b)
>
> - Tratamento quando a luminosidade está abaixo da luminosidade mínima configurada:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/cad6369d-14aa-49b6-a982-15a33bbe190a)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/53273447-6f45-4978-a3f1-40cdb941e53b)
>
> - Tratamento quando a luminosidade está acima da luminosidade máxima configurada:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/39610879-54bb-48f2-b874-79dfc1ca40f9)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/6745f4cb-10b0-4f65-a0bf-396712aca5cc)
> 
> - Tratamento quando o botão de configuração está apertado:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/98f3dba9-a3cb-4d62-a334-488ff92bc8d6)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/46f8a0be-8ef2-4c89-8266-1ba055902a51)
> 
> - Tratamento quando o botão de incremento está apertado:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/123abd49-a325-4b75-97ac-153d6aebe00c)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/6bbfbd84-39fa-4e6d-8741-38ee8c83736d)
> 
> - Tratamento quando o botão de decremento está apertado:
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/e8cd53dd-6074-4193-861b-092054b47442)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/1242f632-88a1-4bae-9a4b-0bbf9a1e308a)
> 
> - Tratamento quando o botão para mudar parâmetro selecionado está apertado:>
> 
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/9131b6b7-6827-4488-b692-cb954ab87470)
>
> ![image](https://github.com/Felipe-Sisnando/ea075-2023.1/assets/107422206/53d54bce-c40e-4735-8697-98cde562fb30)
>
## Referências
> http://sistemaolimpo.org/midias/uploads/fa4a7bc53246a8a9bf8642442a68fe3c.pdf
>
> https://www.horticeres.com.br/noticias/dicas-para-cultivo-protegido/#:~:text=Para%20efeito%20estufa%20(regi%C3%B5es%20muito,aproximadamente%20400%20a%201000%20m%C2%B2.
>
>https://www.rijkzwaan.com.br/blog/estufa-ou-guarda-chuva
>
>Miura, M. (2011). Análise Econômica do Cultivo em Ambiente Protegido.
>
>https://www.zanatta.com.br/cultivo-protegido/
>
>https://embarcados.com.br/sensores-e-atuadores-iot/
>
>https://dgadelha.github.io/Portugol-Webstudio/
>
>https://lyceumonline.usf.edu.br/salavirtual/documentos/2702.pdf
>
>https://www.mdpi.com/2223-7747/10/4/784
>
> https://app.diagrams.net/#G1VgatLxhPqeB7UaBn3qgqynvQ_LG72IgF
