# `Micro-mixer SD`
# `SD Micromixer`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Vinicius Ventura Andreossi  | 195125  | Eng. Elétrica|
> | Nome2  | 123456  | Eng. Elétrica|


## Descrição do Projeto
> Hoje em dia o mundo da música vem andando lado a lado com a tecnologia com o uso de equipamentos avançados que permitem a
> DJs e produtores de música formas cada vez mais inovadoras de manipulação de áudio, inclusive em tempo real. No entanto, muitas vezes esses 
> equipamentos são caros e complexos, tendo uma baixa acessibilidade para amadores. 
> Este projeto pretende fornecer um sistema simples de mixagem de som para que pessoas que não sejam da área possam ter 
> uma primeira experiência por um preço acessível.

## Descrição Funcional
> Esse sistema pretende fornecer as funcionalidades básicas de um player utilizado por DJs. Sendo assim, o sistema reproduzirá músicas armazenadas em um 
> cartão SD e permitirá pequenas edições em tempo real: transicionar de uma música para outra, aplicar efeitos de *fade* e equalizar frequências graves, > médias e agudas. Os dados relativo a cada um dos efeitos serão mostrados em um display LCD/OLED. Para otimizar o uso dos recursos computacionais, 
> alguns efeitos serão aplicados diretamente por hardware.

### Funcionalidades
> **Armazenamento de músicas em SD:** as músicas devem estar em formato .wav e armazenadas em um cartão SD.
> **Dois canais de áudio:** o mixer terá dois players, sendo que a saída de áudio principal será a combinação dos sinais dos dois canais. 
> **Controle de fade:** o sistema fará o controle da intensidade de cada um dos canais separadamente, permitindo que o DJ realize transições naturais
> entre as músicas.
> **Equalização de frequências**: a saída de aúdio principal será ligada a um equalizador que permitirá o controle da intensidade de baixas, médias e 
> altas frequências. Isso permitirá que o DJ controle a a qualidade das músicas em qualquer tipo de alto-falante.

### Configurabilidade
> O usuário deve colocar as músicas que serão utilizadas no diretório raíz do cartão SD em formato .wav.

### Eventos
> Quais eventos o sistema deve tratar?
> O sistema terá ações passivas que estarão acontecendo continuamente mesmo sem ação do usuário:
> * Duas músicas serão lidas do cartão SD e tocadas em cada um dos players.
> * Os sinais da saída dos players devem ser combinadas em um único sinal, que estará sendo reproduzido no alto falante principal.
> 
> O usuário terá acesso aos seguintes controles:
> * dois potenciômetros que regulam a amplitude dos sinais na saída de cada um dos players.
> * três potenciômetros que regulam a amplitude das frequências baixas, médias e altas.
> * cada player terá um botão que avança para a próxima música do cartão SD.

### Tratamento de Eventos
> * Quando a amplitude de um dos canais for alterada no player, o sinal do alto falante principal deve refletir essa mudança.
> * Quando a amplitude de uma faixa de frequência for alterada, o filtro aplicado ao sinal do alto falante princial deve ser alterado.
> * Quando o botão 'alterar música' do player for pressionado, o player deve ler o arquivo seguinte no cartão SD. Inicialmente não será possível 
> alterar a ordem da lista de reprodução. 

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
