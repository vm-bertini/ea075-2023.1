# `<Título em Português do Projeto>`
# `<Project Title in in English>`

# LED tree

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Nome1  | 123456  | Eng. Elétrica|
> | Júlia Perassolli De Lázari  | 123456  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?

O principal objetivo desse projeto é construir uma decoração de Natal com LEDs para a FEEC. A motivação se originou com a provocação da professora em uma das aulas, sobre a falta de uma árvore de Natal de LEDs em uma faculdade de Engenharia Elétrica. Com isso, queremos construir uma árvore de LEDs, visando aplicar os conceitos aprendidos em aula e trazer um pouco de alegria para os alunos, docentes e funcionários no fim do semestre :)

A princípio o projeto não tem um valor econômico associado, mas o mesmo design poderia ser aprimorado e produzido em série como decoração para outros estabelecimentos ou residências.

Outros projetos semlhantes serão usados como inspiração para o desenvolvimento [1],[2],[3].


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

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

O projeto é composto por 3 blocos: interface com usuário, processamento e execução. O primeiro deles permite o usuário interagir com a decoração, seja apenas com movimento ou pressionando um botão. Essa interação será então processada pelo microcontrolador: caso o sinal venha do botão, a árvore irá executar uma rotina de piscar os LEDs e alterar os padrões enquanto toca uma música; caso o sinal venha do sensor de movimento, apenas a rotina dos LEDs será executada. 

O diagrama mostra mais sobre as interações entre esses blocos funcionais:

<img src="https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/diagrama_estrutural.png" width="450" />

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
[1] https://embedded-lab.com/blog/making-a-mini-led-christmas-tree/
[2] https://github.com/Ozonised/LED-Tree-V3
[3] https://www.instructables.com/Mini-8x8-LED-matrix-Christmas-display-with-built-i/
