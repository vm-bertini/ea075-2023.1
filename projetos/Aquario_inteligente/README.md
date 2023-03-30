# `<Aquário Inteligente>`
# `<Smart Aquarium>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Mateus Almeida Resende de Miranda  | 239852  | Eng. Elétrica|
> | Otávio Briske Lima  | 220716  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?


O principal objetivo deste projeto é de realizar o controle necessário para a manutenção das grandezas físicas necessárias de um ecossistema aquático.
A ideia para o projeto foi desenvolvida por meio de uma reflexão sobre como seria possível de se automatizar um processo de manutenção das condições necessárias para vida aquática.
O aquário inteligente é um sistema capaz de controlar condições do biossistema como pH, temperatura e nível de água de um aquário marinho. Como tais existem condições específicas e bem controladas para garantir a sobrevivência de peixes, corais e outros animais, é de suma importância repassar a tarefa de controle das condições para uma máquina que fará isso a todo momento.
Dessa forma usuários que desejam possuir aquários não precisarão se preocupar com as tarefas de tratamento requeridas, podendo verificar o estado em que o ecossistema se encontra através do relatório gerado.


## Descrição Funcional


### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

O sistema será capaz de regular a temperatura, por meio de aquecedores e resfriadores, e o PH do ecossistema, através da liberação de CO2, gerando um relatório periódico sobre suas atividades, através da captação desses valores avaliados por sensores e dos configurados como ideais.

O sistema em questão será capaz de executar 4 tipos de tarefas. O primeiro tipo consiste na configuração do sistema no qual o usuário é capaz de configurar através de um display o nível ou a faixa de temperatura e de pH desejados. Após isso, o sistema medirá as condições do aquário através de um sensor de temperatura e um de pH. Além disso, medirá o nível de CO_2 no tanque que regula o pH. A partir das informações obtidas o dispositivo irá regular qualquer alteração das condições do aquário por meio da injeção de gás CO_2, um aquecedor e um refrigerador. Ademais, a partir das alterações do ecossistema e das ações tomadas pelo dispositivo, o aquário inteligente vai gerar um relatório para uma análise precisa de como o aquário está se comportando.


### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

É previsto que se possa configurar o sistema para operar em valores máximos fixos de temperatura e/ou PH ou em uma faixa de valores ajustáveis.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

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
