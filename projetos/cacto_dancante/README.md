# `Cacto dançante`
# `Dancing cactus`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Vinicius Ventura Andreossi  | 195125  | Eng. Elétrica|
> | Nome2  | 123456  | Eng. Elétrica|


## Descrição do Projeto
> Com o intuito de tornar os lares dos estudantes de engenharia elétrica ambientes mais descontraídos, utilizaremos os conhecimentos adquiridos 
> na disciplina de Sistemas Embarcados para criar um brinquedo interativo que fará todos os alunos da FEEC dançarem: o cacto dançante. 
> O sistema será composto por um detector de áudio que captará os sons produzidos pelo ambiente e os reproduzirá de maneira distorcida e engraçada
> enquanto dança.

## Descrição Funcional
> O cacto dançante deverá ficar em modo de economia de energia enquanto não há nenhum barulho no ambiente externo. Quando um barulho consideravelmente
> alto for detectado, ele deverá armazenar o som do ambiente enquanto este não ficar abaixo do limiar de detecção. Em seguida, ele deverá distorcer o
> som gravado e dançar com o uso de motores.

### Funcionalidades
> **Modo economia de energia:** enquanto estiver ligado, o sistema deve ficar em modo de baixo consumo de energia até que um som acima de um valor limiar
> seja detectado. 
> **Detecção de áudio:** ao detectar um som acima do valor de limiar, o sistema deve recordar todo som do ambiente até que este som fique abaixo do valor
> limiar. O som detectado deve ser armazenado na memória do dispositivo. 
> **Cantar e dançar:** Após recordar o som, o sistema deverá distorcê-lo e reproduzi-lo através de um alto falante enquanto dança utilizando um conjunto
> de motores.

### Configurabilidade
> O sistema funcionará continuamente enquanto estiver ligado.

### Eventos
> * **Eventos periódicos:**
> * Checagem de som ambiente

> * **Eventos não-periódicos:**
> * Iniciar gravação
> * Finalizar gravação
> * Dançar

### Tratamento de Eventos
> * Início da gravação: quando o microfone detectar um som acima de um valor limiar, ele começa a gravar o áudio do ambiente.
> * Fim de gravação: enquanto o sistema estiver gravando, se o microfone detectar que o volume do som ambiente ficou abaixo do valor limiar, a
> gravação deve ser encerrada e o arquivo de áudio armazenado na memória do microcontrolador.
> * Dançar: após a finalização da gravação, o dispositivo deve reproduzir o áudio distorcido enquanto ativa os motores de maneira sincronizada, 
> semelhante a uma coreografia.

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
