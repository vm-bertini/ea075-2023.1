# `Sistema de Segurança para Vazamento de Gases`
# `Gas Leak Safety System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Matheus Pionório Calcanha  | 203556  | Eng. Elétrica|
 | Vitor Semenzato do Amaral  | 207054  | Eng. Elétrica|


## Descrição do Projeto

O objetivo deste projeto é desenvolver um detector de gases versátil que consiga realizar a detecção de diferentes tipos de gases nocivos utilizando um mesmo dispositivo. O usuário poderá escolher o tipo de gás que o sistema irá ser responsável de reconhecer, poderá configurar a máxima concentração permitida do gás no local e informar os números de telefone pelos quais o sistema ficará responsável de enviar SMS ao indentificar uma concentração de gás acima da especificada e ainda acionar um buzzer no local. A nossa maior motivação para desenvolver este projeto é trazer para o mercado um dispositivo versátil que além de permitir ao usuário escolher o gás que irá ser analisado, ele ainda sozinho, consegue enviar mensagens SMS, sem precisar que seja integrado a um sistema de segurança do local. Com isso, queremos solucionar o problema de se ter diferentes tipos de sensores numa instalação de diferentes fabricantes que acabam dificultando a integração aos sistemas de segurança.
O nosso produto visa atender principalmente indústrias e laboratórios químicos. Não temos um valor para nosso produto, porém, a ideia é que seu custo seja competitivo com o dos sensores de leituras específicas do mercado, de forma que como o nosso produto consegue ler diferentes tipos de gases, ele seja mais atrativo do que os demais sensores.

## Descrição Funcional

O nosso projeto tem a detecção de diferentes tipos de gases como a sua função principal, para isso, iremos utilizar um microcontrolador com memória embutida que será responsável por armazenar as informações enviadas por 2 sensores infravermelhos que irão indicar quantas pessoas estão no local em que o sensor de gás está instalado, conseguindo nos dizer quando uma pessoa entra/sai da instalação. Além dessa informação, o microcontrolador deverá receber um sinal digital informando se a concentração de gás excedeu o limite permitido ou então um sinal analógico que deverá ser tratado internamente verificando se o valor enviado pelo sensor excedeu o limite de concentração configurado pelo usuário por meio de um display LCD e um teclado embutido no mesmo. Por meio do display LCD, o usuário ainda poderá escolher o tipo de gás que o sistema irá detectar baseado numa lista de opções que será mostrada no display e estará armazenada na memória interna do microcontrolador e em seguida, caso o sensor associado ao gás escolhido seja analógico, o usuário terá que informar qual o valor que o sistema deverá tratar como limite de concentração.

Ainda por meio do display LCD o usuário poderá configurar quais os números que deverão receber SMS em caso de detecção de concentração acima do limite permitido, essa configuração terá dois níveis de prioridade, o primeiro nível é o referente a equipe de segurança que será informada quando for indicado que a concentração de gás excedeu o limite independente se existem pessoas no local ou não. O segundo nível é o referente a equipe de resgate que será informada quando ocorre a condição citada anteriormente tendo pessoas na instalação. Vale ressaltar que ao se detectar uma ocorrência de risco, além do microcontrolador enviar um sinal para o módulo SMS indicando quais os números que devem receber a mensagem, ele também irá acionar um buzzer acoplado ao próprio sensor por meio de uma saída digital por volta de 1 minuto, indicando que a região não deve ser acessada.

### Funcionalidades

- Configuração do sensor que será integrado ao sistema, permitindo o usuário configurar a máxima concentração permitida do gás no local;
- Configuração dos números de telefone pelos quais o sistema ficará responsável de enviar SMS ao indentificar uma concentração de gás acima da especificada; 
- Monitoramento dos níveis de concentração de determinado gás de interesse em um ambiente desejado;
- Registro do número de pessoas presentes em determinado local;
- Acionar indicador sonoro para alerta de perigo;
- Envio de mensagem SMS para números predeterminados;
   
### Configurabilidade

Sendo o objetivo primário do sistema o monitoramento da concentração de gases potencialmente nocivos em um ambiente, o circuito terá margem para as seguintes configurações:

- Modelo do sensor de gás integrado ao sistema;
- Determinação do nível de concentração máxima do gás permitida no local;
- Determinação dos números de telefone para envio de SMS.
 
### Eventos

O sistema estará constantemente monitorando os níveis de concentração de determinado gás em um ambiente e a quantidade de pessoas presentes neste mesmo local. Desta forma, deverá realizar o tratamento dos seguintes eventos principais:

- Níveis de concentração abaixo do especificado sem pessoas na sala;

- Níveis de concentração abaixo do especificado com pessoas na sala;

- Níveis de concentração acima do especificado sem pessoas na sala;

- Níveis de concentração acima do especificado com pessoas na sala;

A leitura dos níveis de concentração é periódica, ocorrendo a cada segundo, enquanto a contagem de pessoas é um evento não-periódico, desta forma, os eventos que deverão ser tratados são periódicos, de frequência correspondente à da leitura dos níveis de concentração.

### Tratamento de Eventos

Ao detectar níveis de concentração abaixo do especificado independente de quantas pessoas estejam presentes, o sistema deverá apenas armazenar as informações coletadas pelos sensores, nenhuma ação será necessária;

Ao detectar níveis de concentração acima do especificado sem pessoas na sala, o sistema deverá enviar um SMS para o número da equipe de segurança cadastrado no dispositivo e emitir um alerta sonoro por meio do buzzer, indicando que o local em questão deve ser evitado;

Ao detectar níveis de concentração acima do especificado com pessoas na sala, o sistema deverá enviar um SMS tanto para o número da equipe de segurança quanto para o da equipe de resgate, e emitir um alerta sonoro por meio do buzzer, indicando que o local em questão deve ser evitado;

## Descrição Estrutural do Sistema

O diagrama a seguir ilustra o comportamento do sistema frente aos eventos que deverão ser tratados.

![Alt](Gas_Safety_Sys.drawio.png)

## Referências

https://www.filipeflop.com/img/files/download/Datasheet_Sensor_Gas_MQ2.pdf

https://www.filipeflop.com/img/files/download/DOC_SIM900_Hardware%20Design_V2.00.pdf

https://www.filipeflop.com/img/files/download/SIM808_Hardware+Design_V1.00.pdf

https://www.filipeflop.com/produto/sensor-de-proximidade-infravermelho/

https://lastminuteengineers.com/sim800l-gsm-module-arduino-tutorial/

https://www.ti.com/microcontrollers-mcus-processors/microcontrollers/overview.html

https://www.st.com/en/microcontrollers-microprocessors

https://www.renesas.com/us/en/products/microcontrollers-microprocessors

https://www.microcontrollertips.com/key-factors-consider-choosing-microcontroller/

https://www.filipeflop.com/produto/display-lcd-shield-com-teclado-para-arduino/

https://www.researchgate.net/publication/266869911_Embedded_system_for_Hazardous_Gas_detection_and_Alerting
