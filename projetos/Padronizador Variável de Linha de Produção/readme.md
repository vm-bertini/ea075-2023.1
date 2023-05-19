# `Padronizador Variável de Linha de Produção`
# `Variable Line Production Standardizer`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Marcelo Montandon Magalhães  | 259118  | Eng. Elétrica|
> | Victor Mario Bertini  | 194761  | Eng. Elétrica|


## Descrição do Projeto
>Este projeto surge como um otimizador de linhas de produção. Nesse contexto, 
>os produtos que serão manufaturados são transportados por uma esteira transportadora, distribuídos de forma a estarem equidistantes uns dos outros,
>dando assim um tempo padronizado para as máquinas e trabalhadores do chão de fábrica para trabalharem no produto. 
>Entretanto isto nem sempre acontece, existem casos onde os produtos são transportados amontoados 
>ou muito espaçados uns entre os outros, em ambos os casos isso pode gerar problemas; se os produtos estiverem amontoados, 
>há maior chance de perda de produtos, onde os trabalhadores/ máquinas não conseguirão trabalhar em todos, 
>necessitando descarte, ou, no caso deles estarem muito espaçados, há o problema de aumento no tempo de manufatura, 
>que irá gerar uma perda para a fábrica.

>O objetivo do padronizador é resolver esse problema. Padronizando as distâncias entre os produtos nas esteiras, 
>assim evitando ambos os casos e podendo aumentar/diminuir o fluxo de produtos dependendo da necessidade para a manufatura, os defeitos rítimicos
>descritos acima podem ser atenuados, ou completamente anulados.

>Esse produto forneceria uma nova alavanca de eficiência, que facilitaria o controle de produção ou a administração de crescimento,
>que será feita por um gestor. A má administração de demando, ou o fluxo aumentado de entrada de produtos pode mais facilmente ser controlada
>com a presença desse padronizador.

>O problema que será resolvido é pontual, e, igualmente, o projeto irá resolver ele pontualmente, com baixo número de componentes, 
>necessitando apenas de um sensor simples, um microcontrolador (MCU), um temporizador, e um motor (de preferência DC). 


## Descrição Funcional

* Valores a serem considerados e pré configurados:
 * ´Frequência de produtos: produtos/segundo que devem chegar ao fim da esteira´
 * ´Tamanho da esteira´: para um controle básico e padrão
 * ´Tempo de inatividade´: tempo sem registro de novo produto em que a esteira continuaria funcionando

>(O processo como todo pode ser visto em forma de diagrama mais abaixo)


>O padronizador funciona utilizando um sensor infravermelho que detecta a presença de produto passando, 
>junto de um temporizador de entrada para registrar o tempo no qual os item passam.  

>O padronizador lidaria com um produto principal, ajustando a velocidade para que esse produto principal 
>chegue na frequência desejada, no caso o produto mais a frente sempre seria o produto principal.

>Um temporizador de saída estaria contando regressivamente o tempo que esse produto demoraria para passar a esteira
>assim que este zerar o próximo produto se tornaria o produto principal

>Utilizando da velocidade que a esteira esteve rodando e da defasagem temporal registrada pelo primeiro temporizador (de entrada), 
>seria possível estabelcer a distância que o novo produto principal está do fim da esteira, 
>permitindo que seja calculada uma velocidade apropriada para a chegada desse produto, 
>visando mante a ´frequência de produtos´ configurada para essa esteira

>Por exemplo, caso a necessidade de entrega de produto for de 1 produto/10 segundos, 
>e ele detecta um produto no momento t = 1 e outro no t = 9, com Δt = 8s, após a entrega do primeiro produto, 
>ele irá desacelerar a  esteira para entregar o segundo produto com o atraso pedido de 10s.

>O produto também é altamente customizavel, já que os valores usados para calcular a velocidade do motor leva em consideração variáveis
>estabelecidas pelo próprio usuário, como a própria taxa de produto/sengundo (usada no parágrafo anterior)

>Para casos como o primeiro produto após uma inicialização (ou reset) a velocidade da esteira estaria configurada para um valor
>padrão visando suprir a necessidade de ´frequência de produto´ estabelecida. Esse valor só pode ser calculado através do valor
>de ´tamanho de esteira´ que junto da ´frequência de produto´ forneceria a velocidade de inicialização

>Por último para o caso de ausência de produtos detectados pelo sensor e visando economizar energia, 
>após um determinado período de tempo (´Tempo de inatividade´) o padronizador entraria em iddle ou reset, 
>esperando o próximo produto ser captado pelo sensor, onde o motor funcionaria em seu nível mais baixo efetivamente parando uma esteira sem produtos

### Funcionalidades
* Detecção de Produtos por meio do sensor infravermelho:
  * Item chega na esteira conectada com o padronizador, passando pelo sensor
  * Sensor registra o momento de passagem 
* Cálculo de distância entre dois produtos em sequência:
  * Momento da passagem é usado em comparação com o segundo item e com a velocidade da esteira para calcular a distância entre os items
  
* Aceleração ou diminuição da velocidade da esteira de acordo com a quantidade e distância entre o próximo item na esteira e o final da esteira:
  * Aciona um valor de tensão para o motor DC regulando a velocidade desejada para a chegada do produto

### Configurabilidade
> Configurado para funcionar em apenas um modo

### Eventos
* Passagem de item pelo sensor (não periódico)
* Item saindo da esteira (não periódico)

> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

### Tratamento de Eventos
* Passagem de item pelo sensor (não periódico):
  * Para esse evento o padronizador deve registrar o momento de passagem referente a esse produto
  * Ele deve comparar esse valor registrado com o valor do item anterior a ele, para calcular sua distância
  * Caso o item em questão seja o primeiro ele deve ser tratado de maneira diferente
* Item saindo da esteira (não periódico)
  * O motor deve ser ajustado para um novo valor de velocidade, referente ao próximo item, sempre que o mais a frente sai da esteira
  * Esse saída do item pela esteira deve ser estimado pelo microcontrolador, baseada na velocidade da esteira em em seu tamanha (ou sua distância para o fim da esteira)

## Descrição Estrutural do Sistema
![Draw.io padronizador](Diagrama sem nome.drawio)

## Especificações

### Especificação Estrutural
### Especificação de Algoritiomos
* Sob o documento "código modelo" um modelo de algorítimo em linguagem de IDE de Arduíno como modelo para o funcionamento do sistema, é notável que o arduíno NÃO será o MCU utilizado por este projeto


## Referências
* Motor referência para o projeto:
 * https://terravida.com.br/uploads/produto_arquivos/2020091511353535_2808.pdf
* Problemas de produção podem ser facilitados com o padronizador:
 * https://ausland.com.br/blog/indicadores-da-ineficiencia-produtiva-na-industria/
 * https://blog.dimensional.com.br/erros-no-controle-da-linha-de-producao/
