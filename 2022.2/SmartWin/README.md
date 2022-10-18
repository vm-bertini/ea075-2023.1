# `Janela Inteligente`
# `SmartWin`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Davi Pereira da Silva  | 233429  | Eng. Elétrica|



## Descrição do Projeto
Dado o aumento da integração dos dispositivos eletrodomésticos e eletroportáteis para serem utilizados de forma remota, através de comandos de voz ou qualquer outro evento que os acione de forma autônoma, um outro questionamento vem surgindo: o quanto é possível automatizar também itens relacionados a alvenaria de uma residência, como por exemplo, uma porta ou uma janela dado alguns eventos? E como fazer isso de forma elegante e também com um bom custo?  
Com esses questionamentos em mente, propõe-se o projeto de controle de abertura e fechamento de uma janela chamado de SmartWin.   
SmartWin foi pensado para auxiliar em uma tarefa simples do cotidiano, que é o abrir e fechar uma janela, mas que se esquecida pode ocasionar o alagamento de um cmodo, ou até mesmo de todo o apartamento.  
Entretanto, não é apenas um controlador para janelas qualquer. Com o SmartWin é possível ficar despreocupado com a previsão do tempo, pois ele mesmo consulta para você e realiza o fechamento da sua janela se houver previsão de chuva para 1:00PM, por exemplo. Mas sabe-se que a previsão do tempo pode mudar sem qualquer aviso. Mesmo nesse caso, o SmartWin não te deixará na mão, pois ele conta com um sistema de umidade que conseguirá detectar a chuva em instantes e protegerá sua casa.  
Com o SmartWin você também tem o controle das sua janela, podendo abri-la, fechá-la em tempos pré-determinados ou com apenas um clique na tela do seu celular, ou um comando da sua Alexa ou Google Home. 

<center> SmartWin, mais que controle, inteligência. </center>

## Descrição Funcional
  
O SmartWin é um controlador inteligente para abrir e fechar janelas através de comandos enviados por um smartfone, previsão do tempo e sensor de umidade.
Ele foi pensado não só para controlar janelas em momentos de chuva, mas também em situações onde o morador não está presente fisicamente em sua residencia e gostaria de controlá-la de forma remota, para climatizar sua residencia abrindo a janela, caso seja um dia esteja muito quente, ou até fechá-la para ligar o seu ar-condicionado remotamente e climatizar a sua residencia.  


### Funcionalidades
As funcionalidades do SmartWin estão listadas abaixo:

* Abertura ou fechamento de uma janela quando estiver chovendo via sensor de umidade;
* Abertura ou fechamento de uma janela via consulta da previsão do tempo;
* Abertura ou fechamento de uma janela via aplicativo de celular (instantânea ou programada);
* Abertura ou fechamento de uma janela via comando de Alexa ou Google Home.

### Configurabilidade
  
Dado que as configurações de abertura e fechamento da janela são feitas através de sensor de umidade, consulta da previsão do tempo ou aplicativo de celular, prevê-se 2 configurações que podem ser feitas pelo usuário: configuração inicial para conectar o dispositivo a rede de wi-fi e a sensibilidade do sensor de umidade.  
  
#### Configuração Inicial:  

A configuração inicial do dispositivo é feita conforme o diagrama mostrado abaixo:

![](config_1.png)

#### Sensor de Umidade:

Para configurar a sensibilidade do sensor de umidade, gire o potenciômetro P1 presente ao lado de B1, conforme mostra a imagem abaixo:

![](config_2.png)

* Aumentar a sensibilidade: Ao aumentar a sensibilidade, chuvas mais brandas serão identificadas.

* Diminuir a sensibilidade: Ao diminuir essa sensibilidade, apenas chuvas mais fortes serão identificadas.



### Eventos

Os eventos que serão recebidos são:

* Dados do sensor de umidade indicando chuva;
* Dados recebidos da API de previsão do tempo;
* Dados recebidos do aplicativo de celular para controlar a janela ou programar um horário para que ela seja controlada;
* Sinal de controle enviado pela API da Alexa ou Google Home;

### Tratamento de Eventos

Para cada um dos eventos listados acima é dado os seguintes tratamentos especificados em cada seção.  
  
#### Sensor de Umidade:  

Ao detectar a presença de umidade no ambiente, o sensor enviará um sinal ao controlador que verificará se a janela está fechada ou aberta. Caso esteja aberta, a mesma será fechada, acionando um motor. Se a janela estiver fechada, deverá permanecer assim.


#### API de previsão do Tempo:  

Uma vez por dia, uma API de previsão do tempo será consultada para obter dados sobre a previsão do tempo. Ao analisar esses e houver previsão de chuva para um horário especifico, esse horário será definido como o momento onde a janela deve ser fechada, se estiver aberta.
Quando o relógio chegar no horário definido, o motor será acionado e a janela será fechada, se já não estiver nesse estado. Caso esteja, o motor não será acionado, e ela permanecerá fechada até o horário definido pelos dados da previsão do tempo para que seja aberta novamente caso não chova mais.

#### Controle via Aplicativo de Celular:  
##### 1 Abertura/Fechamento da Janela:  

Ao receber um comando celular via internet, a janela deverá ser aberta ou fechada, considerando o estado atual. Entretanto, se o sensor de umidade detectar que está chovendo, ou há previsão de chuva para um horário próximo, uma mensagem deve ser enviada para o usuário informando que é provável que esteja chovendo(ou irá chover) e que não deve abrir a janela naquele momento. 

##### 2 Abertura/Fechamento programado da Janela:  

Ao receber um comando do celular via internet com horários definidos para a abertura e fechamento da janela, o controlador deverá salvar esses dados e aplicá-los a rotina que verifica se existe um horário setado para que a janela possa ser aberta ou fechada. 

Quando o relógio chegar no horário definido, o motor será acionado e a janela será fechada, se já não estiver nesse estado. Caso esteja, o motor não será acionado, e ela permanecerá fechada até o horário definido pelo usuário através do aplicativo, onde será aberta novamente.

#### Controle via Alexa ou Google Home:  
##### 1 Abertura/Fechamento da Janela:  
Ao receber um sinal enviado pela Alexa ou Google Home, a janela deverá ser aberta ou fechada, considerando o estado atual. Entretanto, se o sensor de umidade detectar que está chovendo, ou há previsão de chuva para um horário próximo, uma mensagem deve ser enviada para o assistente inteligente informando que é provável que esteja chovendo(ou irá chover) e que não deve abrir a janela naquele momento. 

##### 2 Abertura/Fechamento programado da Janela:  
Ao receber um sinal enviado pela Alexa ou Google Home com horários definidos para a abertura e fechamento da janela, o controlador deverá salvar esses dados e aplicá-los a rotina que verifica se existe um horário setado para que a janela possa ser aberta ou fechada. 

Quando o relógio chegar no horário definido, o motor será acionado e a janela será fechada, se já não estiver nesse estado. Caso esteja, o motor não será acionado, e ela permanecerá fechada até o horário definido pelo usuário através do aplicativo, onde será aberta novamente.

## Descrição Estrutural do Sistema
A estrutura básica do SmartWin pode ser conferida abaixo:

![](estrutura_1.png)

## Referências
 
Micropython - https://micropython.org/ 
Alexa API - https://developer.amazon.com/pt-BR/alexa/alexa-skills-kit
Google Home - https://developers.home.google.com/
