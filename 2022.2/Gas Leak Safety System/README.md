# `Sistema de Segurança para Vazamento de Gases`
# `Gas Leak Safety System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.

 |Nome  | RA | Curso|
 |--|--|--|
 | Matheus Pionório Calcanha  | 203556  | Eng. Elétrica|
 | Vitor Semenzato do Amaral  | 207054  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?

O objetivo deste projeto é desenvolver um detector de gases versátil que consiga realizar a detecção de diferentes tipos de gases nocivos utilizando um mesmo dispositivo. O usuário poderá escolher o tipo de gás que o sistema irá ser responsável de reconhecer, poderá configurar a máxima concentração permitida do gás no local e informar os números de telefone cujo o sistema ficará responsável de enviar SMSs ao indentificar uma concentração de gás acima da especificada e ainda acionar um buzzer no local. A nossa maior motivação para desenvolver esse dispositivo é trazer para um mercado um dispositivo versátil que além de permitir o usuário escolher o gás que irá ser analisado, ele ainda sozinho, consegue enviar mensagens SMS, sem precisar que seja integrado a um sistema de segurança do local. Com isso, queremos solucionar o problema de se ter diferentes tipos de sensores numa instalação de diferentes fabricantes que acabam dificultando a integração aos sistemas de segurança.
O nosso produto visa atender principalmente indústrias e laboratórios químicos. Não temos um valor para nosso produto, porém, a ideia é que o custo do nosso produto seja competitivo com os sensores de leituras específicas do mercado de forma que, como o nosso produto consegue ler diferentes tipos de gases, ele seja mais atrativo do que os demais sensores.

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.



### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

- Configuração do sensor que será integrado ao sistema, permitindo o usuário configurar a máxima concentração permitida do gás no local;
- Configuração dos números de telefone cujo o sistema ficará responsável de enviar SMSs ao indentificar uma concentração de gás acima da especificada; 
- Monitoramento dos níveis de concentração de determinado gás de interesse em um ambiente desejado;
- Registro do número de pessoas presentes em determinado local;
- Acionar indicador sonoro para alerta de perigo;
- Envio de mensagem SMS para números predeterminados;
   
### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

Sendo o objetivo primário do sistema o monitoramento da concentração de gases potencialmente nocivos em um ambiente, o circuito terá margem para as seguintes configurações:

- Modelo do sensor de gás integrado ao sistema;
- Determinação do nível de concentração máxima do gás permitida no local;
- Determinação dos números de telefone para envio de SMS.
 
### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

O sistema deve fazer o tratamento de dois eventos principais: a leitura dos níveis de concentração de determinado gás e a contagem de pessoas em uma sala. A leitura do nível de gás é periódica, ocorrendo a cada segundo, enquanto a contagem de pessoas é um evento não-periódico. 

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

Tanto a leitura dos níveis de concentração de gás quanto a contagem de pessoas serão tratadas em rotinas de serviço de interrupção. O sensor de gás envia sinais  ininterruptamente, com isso, sua leitura será feita a cada segundo e o resultado armazenado. Sendo a contagem de pessoas um evento assíncrono, a cada novo registro, o resultado será armazenado. Frente aos dados coletados, um sinal sonoro será emitido, ou não, e um SMS será enviado em caso de detecção de concentração de gás acima do especificado pelo usuário. O usuário ao realizar a aquisição do sistema deve configurar o tipo de gás, a concentração máxima permitida e informar os números de telefone da equipe de segurança e resgaste para qual o sistema ficará responsável de enviar uma mensagem em caso de detecção de uma concentração acima da permitida do gás que foi especificado pelo usuário.

## Descrição Estrutural do Sistema
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.

O nosso projeto tem a detecção de diferentes tipo de gases como a sua função principal, para isso, iremos utilizar um microcontrolador (ainda não definido) com memória embutida que será responsável por armazenar as informações enviadas por 2 sensores infravermelhos que irão indicar quantas pessoas estão no local em que o sensor de gás está instalado, conseguindo nos dizer quando uma pessoa entra/sai da instalação. Além dessa informação, o microcontrolador deverá receber um sinal digital informando que a concentração de gas excedeu o limite permitido ou um sinal analógico que deverá ser tratado internamente verificando se o valor enviado pelo sensor excedeu o limite de concentração configurado pelo usuário por meio de um display LCD e um teclado embutido no mesmo. Por meio do display LCD, o usuário ainda poderá escolher o tipo de gás que o sistema irá detectar baseado numa lista de opções que será mostrada no display LCD e estará armazenada na memória interna do microcontrolador e em seguida, caso o sensor associado ao gás escolhido seja analógico, o usuário terá que informar qual o valor que o sistema deverá tratar como limite de concentração.

Ainda por meio do display LCD o usuário poderá configurar quais os números que deverão receber SMSs em caso de detecção de concentração acima do limite permitido, essa configuração terá dois níveis de prioridade, o primeiro nível é o referente a equipe de segurança que será informada quando for indicado que a concentração de gás excedeu o limite independente se existem pessoas no local ou não. O segundo nível é o referente a equipe de resgate que será informada quando ocorre a condição citada anteriormente tendo pessoas na instalação. Vale ressaltar que quando ocorrer a ocorrência, além do microcontrolador enviar um sinal para o módulo SMS indicando quais os números que devem receber a mensagem, ele também irá acionar um buzzer acoplado ao próprio sensor por meio de uma saída digital por volta 1 minuto, indicando que a região não deve ser acessada.

O diagrama a seguir ilustra o comportamento do sistema.

![Alt](Gas_Safety_Sys.drawio.png)

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.

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
