# Árvore Natalina de LEDs

# LED tree

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).


|Nome  | RA | Curso|
|--|--|--|
| Wesna Simone Bulla de Araujo  | 225843  | Eng. Elétrica|
| Júlia Perassolli De Lázari  | 200298  | Eng. Elétrica|


## Descrição do Projeto
<!--- > Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado? -->

O principal objetivo desse projeto é construir uma decoração de Natal com LEDs para a FEEC. A motivação se originou com a provocação da professora em uma das aulas, sobre a falta de uma árvore de Natal de LEDs em uma faculdade de Engenharia Elétrica. Com isso, queremos construir uma árvore de LEDs, visando aplicar os conceitos aprendidos em aula e trazer um pouco de alegria para os alunos, docentes e funcionários no fim do semestre :)

A princípio o projeto não tem um valor econômico associado, mas o mesmo design poderia ser aprimorado e produzido em série como decoração para outros estabelecimentos ou residências.

Outros projetos semelhantes serão usados como inspiração para o desenvolvimento [1],[2],[3].


## Descrição Funcional
<!--- > A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório. -->


### Funcionalidades
<!--- > Detalhe todas as tarefas que o sistema será capaz de executar -->

Como é esperado de todo enfeite natalino, em especial de uma árvore de natal, o projeto terá como funcionalidade explorar diferentes padrões para acender os LEDs dispostos na árvore e ainda tocar musicas típicas de tal época festiva. Assim, o sistema contará com um botão que, ao ser pressionado, irá dar início a uma música natalina e a um padrão para os LEDs piscarem. 

### Configurabilidade
<!--- > Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração. -->

O projeto contará com uma interrupção, pelo botão. Ela será responsável por trocar a música natalina e o padrão dos LEDs. Teremos no mínimo três padrões para os LEDs, cada um associado a uma música natalina.

### Eventos
<!--- > Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)? -->

O sistema deverá tratar as interrupções provenientes do botão. Essa interrupção é não-periódica, visto que irá depender do usuário para acionar o botão. 
Haverá um tempo mínimo de cerca de 30 segundos para que uma nova interrupção seja tratada.

### Tratamento de Eventos
<!--- > Qual comportamento o sistema deve ter para tratar corretamente cada evento? -->

O sistema deverá identificar o pressionamento de um botão. Assim, será necessário tratar o problema de debounce associado aos botões e estipular um tempo razoável para que uma nova interrupção possa ser tratada.

## Descrição Estrutural do Sistema
<!--- > Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github. -->

O projeto é composto por 3 blocos: interface com usuário, processamento e execução. O primeiro deles permite o usuário interagir com a decoração, ao pressionando um botão. Essa interação será então processada pelo microcontrolador, e então a árvore irá executar uma rotina de piscar os LEDs, alterando os padrões, enquanto toca uma música.

O diagrama mostra mais sobre as interações entre esses blocos funcionais:

<img src="https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/Projeto-diagrama_estrutural.drawio.png" width="450" />

## Especificações

### Especificação Estrutural

> (Se preferir, adicione um link para o documento de especificação estrutural)
> 
> Entende-se por estrutural a descrição tanto das características elétricas e temporais como das restrições físicas de cada bloco funcional.
> Nessa etapa do projeto, ainda não será solicitado o diagrama elétrico mas espera-se que já estejam identificados os componentes e circuitos integrados propostos
> para implementação do sistema embarcado proposto.

|Componente | Funcionalidade para o Circuito | Datasheet |
|--|--|--|
| Microcrontrolador PIC 16F8X| Unidade micro-controladora | [link](https://pdf1.alldatasheet.com/datasheet-pdf/view/75016/MICROCHIP/PIC16F877.html) |
| Botão | Mudar padrão de LEDs e música | [link](https://www.hdk.co.jp/pdf/eng/e291702.pdf) |
| Buzzer | Músicas natalinas | [link](https://www.mouser.com/datasheet/2/400/ef532_ps-13444.pdf) |
| Bateria | Alimentação do circuito | entre 2 e 6V|

> Como o projeto de um sistema embarcado é centralizado nas tarefas, recomenda-se iniciar com a definição dos periféricos de entrada e saída (atuadores e/ou sensores) apropriados para o
> sistema. Pode ser necessário definir um endereço distinto para cada um deles. 
> Este endereço será utilizado pela unidade micro-controladora para acessá-los tanto para leitura como para escrita.

#### Charlieplexing

Os LEDs serão ligados com a configuração Charlieplexing, que permite um controle de um grupo de LEDs com poucas portas I/O. Essa técnica permite que n portas controlem n<sup>2</sup> - n LEDs [4],[5]. 
  
O diagrama abaixo mostra uma versão simplificada (sem os resistores) da configuração proposta. Nesse caso, para que o LED 1 seja aceso, precisamos que IO 3 esteja em nível alto, IO 0 em nível baixo e IO 1 e IO 2 como _input_.
  
 <img src="https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/Projeto-charlieplexing.drawio.png" width="450" />
  
> Nesta etapa do projeto espera-se que a unidade micro-controladora seja definida.
> Tendo definidos os periféricos e a memória, é possível projetar um decodificador de endereços
> que converte o endereço referenciado no programa em sinal *Chip Select – CS* do dispositivo
> correspondente, habilitando-o para realizar um ciclo de leitura ou de escrita.
> 
> Nesta etapa do projeto espera-se que sejam identificada também a eventual necessidade do projeto de circuitos de interface para os periféricos do projeto.
> Assim, devem ser incluídos na especificação, se necessário:
> - conversores AD e DA;
> - padrões de comunicação a serem adotados;
> - circuitos de sincronização de sinais temporais.

#### Especificações físicas
> Finalmente, deve-se especificar as restrições físicas e ambientais de funcionamento do circuito, tais como limites mecânicos
> (altura, largura, profundidade) e limites de dissipação térmica.

A árvore de Natal será feita em forma de bordado, em um quadro circular de cerca de ~18cm de diâmetro. Teremos 12 LEDs ligados na configuração Charlieplexing como explicado acima e a placa com o microcontrolador PIC será fixada no quadro do bordado, de forma a deixar o botão e o buzzer à vista. O desenho a seguir ilustra o que foi pensado para a estrutura física do projeto.

<img src="https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/Projeto-estrutura_física.drawio.png" width="450" />


### Especificação de Algoritmos 

> (Se preferir, adicione um link para o documento de especificação de algoritmos).
> 
> Deve ser elaborado para CADA evento o algoritmo de tratamento deste evento. Com base no
> tamanho de cada algoritmo, estima-se o tamanho de memória necessária para armazenar todos
> os programas e os dados associados. Isso permitirá especificar a memória a ser utilizada e o
> espaço onde serão armazenados os programas. O algoritmo de tratamento de evento pode
> ser representado graficamente por um fluxograma. Recomenda-se usar símbolos gráficos consistentes 
> com a norma internacional ISO 1028-1973 e IS0 2972-1979.

## Referências
<!--- > Seção obrigatória. Inclua aqui referências utilizadas no projeto. -->

[1] https://embedded-lab.com/blog/making-a-mini-led-christmas-tree/

[2] https://github.com/Ozonised/LED-Tree-V3

[3] https://www.instructables.com/Mini-8x8-LED-matrix-Christmas-display-with-built-i/
  
[4] https://en.wikipedia.org/wiki/Charlieplexing
  
[5] https://www.arrow.com/en/research-and-events/articles/charlieplexing-an-led-matrix
