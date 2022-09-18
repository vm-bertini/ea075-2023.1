# `<Sistema de Segurança para Vazamento de Gases>`
# `<Gas Leak Safety System>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Matheus Pionório Calcanha  | 203556  | Eng. Elétrica|
> | Vitor Semenzato do Amaral  | 207054  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?




## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

- monitoramento dos níveis de concentração de determinado gás de interesse em um ambiente desejado;
- registro do número de pessoas presentes em determinado local;
- acionar indicador sonoro para alerta de perigo;
- envio de mensagem SMS para números predeterminados;
   
### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

Sendo o objetivo primário do sistema o monitoramento da concentração de gases potencialmente nocivos em um ambiente, o circuito terá margem para alteração do tipo de sensor de gás utilizado, permitindo, assim, a utilização de sensores específicos para cada aplicação. Bastando apenas a troca do sensor atual pelo desejado nos terminais de leitura do microcontraldor. 
 
### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

O sistema deve fazer o tratamento de dois eventos principais: a leitura dos níveis de concentração de determinado gás e a contagem de pessoas em uma sala. A leitura dos níveis de gás é periódica, ocorrendo a cada minuto, enquanto a contagem de pessoas é um evento não-periódico. 

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

Tanto a leitura dos níveis de concentração de gás quanto a contagem de pessoas serão tratadas em rotinas de serviço de interrupção. O sensor de gás envia sinais  ininterruptamente, com isso, sua leitura será feita a cada minuto e o resultado armazenado. Sendo a contagem de pessoas um evento assíncrono, a cada novo registro, o resultado será armazenado. Frente aos dados coletados, um sinal sonoro será emitido, ou não, e um SMS será enviado, ou não.  

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
> 

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
