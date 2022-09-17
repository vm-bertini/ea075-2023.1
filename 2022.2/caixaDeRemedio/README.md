# `<Caixa de Remédio>` 	
# `<Medicine Box>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Gabriel Dante Ferreira Roque  | 197242  | Eng. Elétrica|
> | Fernando Teodoro de Cillo | 197029  | Eng. Elétrica|


## Descrição do Projeto

> A motivação do projeto é criar uma caixa de remédios automática para ajudar as pessoas a não se perderem nos horários de tomar os seus remédios, principalmente pessoas idosas e com perda de memória. Além disso, alguns remédios, como antibióticos, precisam ser tomados nos horários corretos, e todo o tratamento pode não dar certo caso sejam esquecidos. Vale ressaltar, que qualquer pessoa pode utilizar a caixa de remédios automatizada, não somente usuários com perda de memória, pois fornece praticidade para uma tarefa chata do dia a dia.

> Nesse projeto é possível estabelecer um valor econômico visto que muitas pessoas possuem alguém do público alvo do produto na família e se preocupam com seus cuidados. Além disso, acreditamos que o valor de produção seja baixo, o que permite altas margens de lucro para os investidores.

Diagrama.drawio.png

## Descrição Funcional
 
> O conceito envolve um dispositvo que contém dois repositórios para cada dia da semana (total de 14 repositórios), que podem ser programados para abrir nos horários corretos. A programação dos horários dos repositórios é feita através de um interface em que se seleciona qual o dia da semana, se é o repositório número 1 ou 2 daquele dia e o horário.

> Quando chega algum horário programado soa um alarme sonoro e um alarme visual na interface avisando que é horário de tomar algum remédio. Além disso, um atuador abre o repositório correspondente.


### Funcionalidades

> Setar os horários dos alarmes para cada repositório;

> Abrir automaticamente o repositório quando chegar o horário para qual está setado, através de um atuador;

> Soar o alarme sonoro e o visual na interface nos horários programados;

> Possibilidade de abrir o repositório para colocar os remédios e setar o alarme em qualquer horário;

> Possibilidade de escolher qual o alarme sonoro que vai soar;

> Relógio para determinar o horário atual e comparar com os alarmes setados.


### Configurabilidade

> O circuito precisará de: 
> uma memória para salvar os horários dos alarmes, os repositórios e os alarmes sonoros; 

> um microcontrolador para gerir as relações entre cada parte do circuito; 

> 14 atuadores para poder abrir e fechar os repositórios;

> uma interface para o usuário programar os alarmes;

> um alto-falante para emitir os alarmes sonoros;

> um relógio; 

> e uma fonte conectada à rede elétrica para energizar o sistema.

### Eventos

> Um evento aperiódico é a programação dos horários de cada alarme.

> Definir o alarme sonoro também é um evento não-periódico.

> Abrir repositório para colocar remédio.

> Quando der o horário do alarme o repositório deve abrir e soar alarme sonoro.

> Entender que o repositório ja foi fechado depois do usuário pegar os remédios e assim para de tocar o alarme sonoro.

> Programar o Horário do Relógio (Evento não-periódico).

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

> Como o evento de programar horários de alarme e repositório é aperiódico, podemos tratar o evento como uma interrupção para salvar na memória o horário em que foi configurado e o repositório selecionado.

> O evento de seleção de um alarme sonoro vai ser tratado via interrupação, pois é aperiódico. Dessa forma, quando a pessoa fazer a seleção do alarme sonoro pela interface o som deve ser tocado e quando selecionado a interrupção irá salvar na memória qual alarme sonoro irá tocar quando o evento de alarme para tomar remédio chegar.

> Como o evento de abrir o repositório para colocar o remédio é aperiódico, a interface irá mandar uma interrução para abrir o repositório indicado pelo usuário. Após o fechamento o usuário irá selecionar na interface que o repositório ja foi fechado.

> Para tratar o evento de alarme para tomar o remédio o sistema irá ficar em pooling comparando o horário e o dia do relógio atual com os horários e dias configurados na memória, dessa forma, quando o horario e dia forem iguais ao da memória, o atuador irá abrir o repositório selecionado para o alarme e irá tocar o alarme sonoro escolhido.

> Depois que a pessoa pegar o remédio ela irá fechar o respositório. Dessa forma, a pessoa clicará na interface que ja tomou o remédio, assim os sistema irá parar de tocar o alarme sonoro e voltará para estado de pooling.

> Como o evento de programar o horário do relógio é não-periódico a sistema irá fazer uma interupção para configurar o horário do relógio.
 

## Descrição Estrutural do Sistema
https://github.com/danteroque/ea075/blob/e8cf4e6888c433116a8870814cff056a95bfb77b/2022.2/caixaDeRemedio/Diagrama.drawio.png
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.

> Precisa-se de uma memória para salvar os horários e o respectivo repositório dos alarmes. Na memória também ficarão salvos os possíveis toques dos alarmes, que podem ser selecionados na interface.
> O microcontrolador será responsável por toda a lógica realizada, como comparar o horário atual com os horários setados para os alarmes. O microcontrolador também será utilizado para escrever na memória os horários e os respectivos repositórios setados na interface.

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
