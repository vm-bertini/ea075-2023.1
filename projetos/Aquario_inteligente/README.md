# `Aquário Inteligente`
# `Smart Aquarium`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Mateus Almeida Resende de Miranda  | 239852  | Eng. Elétrica|
| Otávio Briske Lima  | 220716  | Eng. Elétrica|


## Descrição do Projeto
O principal objetivo deste projeto é de realizar o controle da temperatura necessárias para a manutenção de um ecossistema aquático marinho, reduzindo o gasto de energia da rede. Como existem condições bem específicas para garantir a sobrevivência de peixes, corais e outros seres vivos, é de suma importância repassar a tarefa de controle dessas condições para uma máquina que fará isso frequentemente. Neste caso, a condição abordada pelo aquário inteligente será a temperatura da água.
O aquário inteligente é um sistema capaz de controlar a temperatura, por meio da habilitação regulada de sistemas de aquecimento e resfriamento externos (não projetados). As informações obtidas serão armazenadas para gerar um relatório em um aplicativo e que possuirá os seguintes gráficos: temperatura X tempo, gasto energético (do aquecedor mais do resfriador) X tempo; e as segiuntes informações: temperatura atual do aquário, desempenho energético no período analisado, alertas de erro como temperatura fora da faixa ideal. O relatório analisará os dados obtidos diariamente e semanalmente, podendo ser acessado quando o usuário quiser e sendo atualizado com um período configurável com padrão de a cada 10 minutos. 
Dessa forma, usuários que desejam possuir aquários marinhos, ou que já o possuem, não precisarão se preocupar com as tarefas de tratamento rotineiras requeridas e podem verificar o estado em que o ecossistema se encontra através do relatório gerado, o sistema ainda armazenará parâmetros representativos do aquário em que está operando, que são obtidos durante a sua operação, de forma a permitir uma otimização da potência consumida pelos sistemas de aquecimento e resfriamento, assim como um controle preventivo para o caso em que o sensor de temperatura do aquário apresente medidas incertas ou em que os sensores falhem.  
A ideia para o projeto foi desenvolvida por meio de uma reflexão sobre como seria possível de se automatizar um processo de manutenção das condições necessárias para a vida aquática visto que qualquer perturbação das condições os corais e os peixes podem ficar doentes e até morrer. Ademais, o projeto também foi desenvolvido a partir da necessidade real de um dos membros da dupla que possuía aquário marinho e que tinha a dificuldade de manter o ecossistema adequado a todo momento. 
No momento atual de escrita dado a fase de desenvolvimento em que o projeto se encontra, se estabelece um valor de custo de aproximadamente R$96,15, correspondente aos materiais utilizados. 


## Descrição Funcional

### Funcionalidades
O sistema em questão será capaz de executar 4 tipos de tarefas (Configuração, medição, regulação e geração de relatório). O primeiro tipo consiste na configuração do sistema no qual o usuário é capaz de configurar através de um aplicativo o nível ou a faixa de temperatura desejado e o período de amostragem. Após isso, o sistema medirá as condições do aquário através de um sensor de temperatura dentro do aquário e um do lado de fora em contato com o ar. As informações obtidas serão atualizadas a cada período no relatório que será armazenado na nuvem podendo ser acessado pelo aplicativo. 

Tarefas: 
- Configuração da operação em valor fixo ou faixa de temperaturas; 
- Configuração das temperaturas desejados; 
- Medir as temperaturas; 
- Gerenciar o aquecedor; 
- Gerenciar o resfriador; 
- Gerar relatórios diários e semanais que são atualizados a cada 12h ou cada vez que for solicitado pelo aplicativo. 


### Configurabilidade
É previsto que se possa configurar o sistema para operar em valores fixos de temperatura ou em uma faixa de valores ajustáveis (através do aplicativo), com o objetivo de se adaptar as demandas de diferentes tipos de ecossistemas. Além disso, também é possível se ajustar a taxa de amostragem das grandezas do aquário de acordo com o desejado. 


### Eventos
O primeiro evento corresponde à uma interrupção gerada por uma alteração das configurações originais (da frequência de amostragem, do modo de operação em valor fixo ou faixa de temperaturas ou dos valores limites de temperatura) via aplicativo. 
Um segundo evento é a passagem de tempo correspondente a um período para a realização da amostragem e operação dos atuadores (verificada pela comunicação do SoC com a internet via Wi-fi).

Outro evento corresponde a passagem de um segundo período para a transmissão dos valores armazenados na memória interna do SoC para a nuvem via Wi-fi, assim como para o cálculo de novos parâmetros representativos do aquário. Os valores enviados para a nuvem, também pode ocorrer fora do período se for solicitado no aplicativo, através de um botão, a atualização dos dados.

O quarto evento corresponde à uma medição discrepante por parte dos sensores (de temperatura externa e/ou interna ao aquário) ou falha nos atuadores. Se os eventos ocorrerem, será interrompida qualquer atuação do aquecedor e resfriador, além de gerar um alerta no aplicativo e um pop-up de notificação no celular informando o erro. 

O último evento considerado é o de queda de energia, em que tanto os sistemas de aquecimento e resfriamento provavelmente irão parar de operar, de forma com que seja sensato que o sistema de controle também cesse a sua operação, considerando que todos os dados e valores configurados já estejam salvos na nuvem. 
Como última parte temos que ao a energia retornar o microcontrolador irá esperar que tanto a energia quanto o Wi-fi sejam reestabelecidos, recuperando então os valores necessários da nuvem e retornando para a sua operação normal. 


### Tratamento de Eventos
Para o primeiro evento deve-se inicialmente enviar os dados das novas configurações para a unidade microcontroladora, pelo acesso a internet, e depois a unidade deve iniciar uma sub-rotina de atendimento a interrupção na qual se atualiza todos os parâmetros de operação configuráveis e então se retorna ao programa principal. 

No segundo evento, temos que o SoC capta as medições dos sensores realizando então um processamento interno, dependente desses valores e dos configurados, de forma com que os dados dos sensores sejam armazenados na memória flash do SoC e informe ao aquecedor ou resfriador, quem deve ser ligado e qual potência deve fornecer ao aquário.

Então no terceiro evento (cujo período é superior ao do segundo evento), os dados armazenados na memória até então são finalmente transmitidos para um relatório na nuvem, permitindo que a memória seja limpa, após fazer o cálculo de novos parâmetros do aquário (parâmetros que permitem entender como o aquário reage ao aquecimento e resfriamento, permitindo a otimização do sistema e economia de energia da rede).

No quarto evento temos que caso seja identificado uma leitura improvável em algum dos sensores o sistema deverá realizar um alerta via aplicativo quanto ao valor provavelmente incorreto da leitura. 

Nos últimos dois eventos temos que não são necessárias ações adicionais por parte do microcontrolador, além da recuperação dos dados salvos na nuvem, assim que tanto a energia quanto o Wi-fi fossem reestabelecidos, antes de seu retorno à operação normal. 


## Descrição Estrutural do Sistema
Será necessário a utilização de sensores para temperatura dentro do ambiente aquático e no ambiente externo, para a captação analógica dessas grandezas, e então se converter esses em valores digitais (A conversão analógica-digital é feita pelo próprio sensor) que poderão ser compreendidos pelo sistema embarcado de forma com que ele possa tomar decisões quanto a habilitação dos atuadores (sistemas de resfriamento e de aquecimento). 

![Descrição estrutural](https://github.com/mateusmiranda01/ea075-2023.1/assets/128386956/08942d95-266c-4345-9533-fb43e9eb0096)



## Especificações

### Especificação Estrutural

Partindo pela especificação dos sensores a serem utilizados temos que o mesmo modelo de sensor será utilizado tanto para a realização da leitura da temperatura do ar quanto da água, com a diferença de que para a água este sensor (DS18B20) possuirá um encapsulamento diferenciado pare permitir sua submersão nela. Considerando que esses sensores utilizam um protocolo de comunicação denominado de one-wire, no qual para a realização da transferência das leituras para o SoC basta conectar o devido terminal de dados do sensor à um pino GPIO do SoC, e que o ESP8266 possui 16 pinos GPIO, logo não será necessário a implementação de interfaces com lógicas de chip select (CS) para ordanar a comunicação dos periféricos de entrada com o microcontrolador.

Então temos o microcontrolador a ser utilizado, que como já denominado corresponde ao System on a Chip (SoC) ESP8266, que será utilizado principalmente por apresentar comunicação Wi-fi embutida, necessária para a transmissão de dados para compor relatórios salvos na nuvem; PWM (Pulse Width Modulation) necessário para o controle da potência fornecida para os atuadores; e por apresentar metódos que reduzem seu consumo de energia.

Este SoC possuirá como saída terminais para comunicação I2C com o resfriador (que não será projetado), e terminais para a realização do controle de potência via PWM de um sistema aquecedor (que corresponde à uma resistência que é aquecida pelo efeito Joule), para isso o seguinte sistema será utilizado para o interfaceamento entre o SoC e o aquecedor:

![articles-opto6](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/d07226a5-fa47-4077-becb-7d797307b300)

Fonte: https://www.electronics-tutorials.ws/blog/optocoupler.html 

Cujos componentes serão devidamente apresentados adiante.

Ademais será necessário um cabo para a realização do carregamento do programa no ESP8266, e um circuito retificador de onda completa (apresentado abaixo) que alimentará o SoC externamente, por seu pino Vin, com uma tensão de 5V; de forma com que não seja necessário a presença do cabo utilizado para o carregamento para a alimentação elétrica, evitando, por exemplo, que se utilize duas saídas de uma régua de tomadas e deixando este cabo disponível para outras aplicações. Para isso adicionalmente ao circuito apresentado abaixo, será necessário um transformador que converta o valor da tensão da rede elétrica para um valor adequado como V1 = 12V.

![image](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/867f7b1f-24fd-4d27-9cfd-39c06d7492dc)

Fonte: https://eletronicaparahobbistas.blogspot.com/2017/02/retificador-de-onda-completa-com_5.html

Finalmente são apresentados abaixo os componetes utilizados nesse projeto, no formato de uma lista de materiais:

<html>
<body>
<!--StartFragment--><google-sheets-html-origin><!--td {border: 1px solid #cccccc;}br {mso-data-placement:same-cell;}-->

Componentes | Quantidade [unidades] | Valor unitário [R$] | Valor total [R$] | Valor estimado para o projeto [R$]
-- | -- | -- | -- | --
Sensores: |   |   |   | 96,15
DS18B20 (para o ar) | 1 | 10 | 10 |  
DS18B20 (para a água) | 1 | 14 | 14 |  
System on a chip: |   |   |   |  
ESP8266 | 1 | 30 | 30 |  
Cabo USB - Micro USB | 1 | 12 | 12 |  
Sistema aquecedor: |   |   |   |  
Escolhido pelo própio consumidor, dado restrições do aparelho de controle |   |   |   |  
Sistema resfriador: |   |   |   |  
Projetado à parte |   |   |   |  
Sistema de interfaceamento entre o SoC e o aquecedor: |   |   |   |  
Resistor filme metálico 1/4W 1% - 56 ohms | 1 | 0,1 | 0,1 |  
Resistor filme metálico 1/4W 1% - 100 ohms | 1 | 0,21 | 0,21 |  
Resistor filme metálico 1/4W 1% - 33 ohms | 1 | 0,15 | 0,15 |  
Capacitor Cerâmico 33nF / 50V | 1 | 0,14 | 0,14 |  
TRIAC BTA41-600 | 1 | 13 | 13 |  
Circuito retificador de onda completa para a alimentação do SoC: |   |   |   |  
LM7805 | 1 | 3 | 3 |  
Capacitor de 100nF | 2 | 0,2 | 0,4 |  
Diodo1N4007 | 4 | 0,2 | 0,8 |  
Capacitor eletrolítico 220uF 25v | 1 | 0,35 | 0,35 |  
Conectores KRE de 2 vias | 2 | 2 | 4 |  
Transformador de 220V para 12V | ? | ? | ? |  
Para a alimentação do aquecedor: |   |   |   |  
Tomada com plugue Fêmea 2P+T 20 A 250 V | 1 | 8 | 8 |  

<!--EndFragment-->
</body>
</html>

Finalmente podemos estabelecer algumas recomendações e restrições para o uso do aquário inteligente, assim recomenda-se que: os sensores de temperatura da água e o aquecedor sejam mantidos em um aquário secundário (e não no de exibição), com o sensor de temparatura da água mergulhado até metade do nível de água presente (considerando que o sensor DS18B20 possui um cabo de 1 metro de comprimento, sem extensores, o aquário secundário (sump) em que ele seria aplicado poderia ter no máximo 2 metros de profundidade); se evite de posicionar o sensor de temperatura do ar próximo de fontes ou sovedouros de calor; o aquecedor utilizado não exceda as especificações elétricas máximas do plug de tomada, possuindo uma potência menor que 5kW.

### Especificação de Algoritmos

Inicialmente para a mudança de alguma das possíveis configurações:

![image](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/c533ee61-b0d7-4e5d-ba3c-395c4b029a7e)

Então temos que para a passagem de um tempo correspondente ao periodo de amostragem regulado T teremos o seguinte algoritmo de tratamento:

![image](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/a3a0430c-7015-4a37-ac56-b5204683dc1d)

Para a transmissão dos dados para nuvem e atualização dos parâmetros a cada 12 horas temos:

![image](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/4a855b0d-782f-43b7-ad43-a25f45c2f32c)

Para a vericação de leituras improváveis de parte dos sensores:

![image](https://github.com/mateusmiranda01/ea075-2023.1/assets/127249262/3d5206d0-fe6e-477e-99c1-dbb603f7540b)

No caso de queda de energia não são necessárias ações adicionais, considerando que os dados estão salvos em uma memória flash não volátil (ou na nuvem) e que o SoC irá esperar o reestabelecimento tanto de sua alimentação elétrica quanto da comunicação via Wi-fi para prosseguir com seu funcionamento.

Com base nos algoritmos apresentados acima podemos estimar o espaço que será ocupado na memória flash do SoC pela realização de um esboço de código em C++ (uma vez que este SoC pode ser programada nessa linguagem via a IDE do arduino), com feito abaixo:

## Referências

-Material postado na página (do google classroom) da disciplina de EA075A, de oferecimento para o primeiro semestre de 2023. 
  
-Referências sobre aquarismo:
  
https://www.aquarismomarinho.com.br/blog/sump-marinho/

-Uso do sensor de temperatura DS18B20: 

https://curtocircuito.com.br/blog/Categoria%20Arduino/como-utilizar-o-ds18b20#teste_ds18b20 

-Datasheet do SoC ESP8266 (SoC utilizado no projeto): 

https://pdf1.alldatasheet.com/datasheet-pdf/view/1132995/ESPRESSIF/ESP8266.html 

-Datasheet do SoC ESP32: 

https://pdf1.alldatasheet.com/datasheet-pdf/view/1148023/ESPRESSIF/ESP32.html 

https://pdf1.alldatasheet.com/datasheet-pdf/view/1424855/ESPRESSIF/ESP32-S2.html 

-Datasheet do sensor de temperatura DS18B20: 

https://www.alldatasheet.com/datasheet-pdf/pdf/58557/DALLAS/DS18B20.html 

https://storage.googleapis.com/baudaeletronicadatasheet/DS18B20.pdf 

-Arquitetura do SoC ESP8266 (SoC utilizado no projeto):  
  
https://blogmasterwalkershop.com.br/embarcados/esp8266/descomplicando-a-pinagem-do-nodemcu
  
-Arquitetura do SoC ESP32: 

https://deinfo.uepg.br/~alunoso/2019/SO/ESP32/HARDWARE/#:~:text=O%20ESP32%20%C3%A9%20um%20microcontrolador,um%20grande%20n%C3%BAmero%20de%20aplica%C3%A7%C3%B5es 

-Referência para a escolha da resistência de aquecimento dependendo da capacidade do aquário utilizado: 

https://www.youtube.com/watch?v=ziXkMCADjBo  

-Referência para o circuito de interfaceamento com o aquecedor: 

https://www.electronics-tutorials.ws/blog/optocoupler.html 

https://www.fvml.com.br/2020/06/controle-de-potencia-de-carga-110220vac.html  

-Datasheet do opto acoplador MOC3021 Datasheet: 

https://pdf1.alldatasheet.com/datasheet-pdf/view/5039/MOTOROLA/MOC3021.html 

-TRIAC BTA41-600: 

https://www.baudaeletronica.com.br/triac-bta41-600.html?gclid=Cj0KCQjwmZejBhC_ARIsAGhCqndPYXh0QL_n650W_XxhjM_BYkFvXZbdkZvSSor0seZzj2QmbDE0zwgaAmOREALw_wcB 

-Referência para a o desenvolvimento de um circuito retificador para a alimentação do SoC utilizado: 

https://eletronicaparahobbistas.blogspot.com/2017/02/retificador-de-onda-completa-com_5.html?m=1 

-Referências para a elaboração dos diagramas de fluxo: 

https://cdn.standards.iteh.ai/samples/5500/6b28378512604ff7bdaace506be7dc0c/ISO-1028-1973.pdf 

https://cdn.standards.iteh.ai/samples/8027/d55d5d8d5033436e945431e3f6e00f34/ISO-2972-1979.pdf 

https://rjbfx.files.wordpress.com/2012/08/aula-01-introduc3a7c3a3o-a-lc3b3gica-e-algoritmos.pdf  
  
-Referência para se programar no ESP8266 pela IDE do Arduino:
  
https://www.blogdarobotica.com/2020/05/28/como-programar-a-placa-nodemcu-esp8266-no-arduino-ide/

-Referências utilizadas para a utilização da plataforma GitHub:
  
  [Ferramentas StackEdit e draw.io.](https://stackedit.io/)
  
  [Referência: Mastering Markdown.](https://docs.github.com/pt/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
