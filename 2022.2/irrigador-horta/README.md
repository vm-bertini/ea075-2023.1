# `Sistema de Irrigação Automático`
# `Automated Irrigation System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Membros da equipe:
> |Nome  | RA | Curso|
> |--|--|--|
> | Lucas Lobato Ciciliato  | 220817  | Desenvolvimento de hardware |
> | Deivit Lopes Bonach  | 166508  | Desenvolvimento de software |


## Descrição do Projeto
> Com o crescimento da procura por uma alimentação saudável com vegetais orgânicos e livres de pesticidas, este projeto tem o seu público alvo para pessoas que
> gostariam de desenvolver sua própria horta caseira como um hobby, mas não possuem tanto tempo para poder tomar conta. Além de ser automático, a irrigação por
> gotejamento é uma boa forma de gastar menos água por evaporação, o que diminui o custo da conta de água. 
> Esse sistema irriga e deposita adubo em plantas de uma horta caseira por gotejamento. Ele é baseado em uma central onde fica armazenado o adubo líquido
> ou fertilizante e a água para irrigação. Nesta central, o usuário pode setar as configurações da irrigação.
> Dessa central saem canos para a horta, e ele possui um injetor pra colocar fertilizante ou adubo na água. 
> Além disso, o sistema possuí dois sensores de pressão para monitorar a capacidade de água e
> adubo líquido restante (caso não seja possível deixar uma torneira conectada no sistema). Nos canos existem furos intermediários que podem ser acionados de maneira independentes para irrigar partes específicas da horta.
>

## Descrição Funcional

### Funcionalidades
> Irrigar a horta em determinados intervalos com certo volume de água, definidos pelo usuário
> Manter o solo com um certo nível de umidade para a raiz do vegetal
> Adubação ou fertilização líquida do solo automático
> Medidor de água e adubo líquido/fertilizante restante
> Medidor do nível de bateria

### Configurabilidade
> Volume de água
> Intervalo entre irrigações
> Nível de umidade do solo
> Volume de adubo ou fertilizante
> Local onde será irrigado naquele momento

### Eventos
> Nível baixo de água ou de adubo líquido (não-periódico, vai depender do quanto a planta exige)
> Umidade do solo menor do que o configurado (não-periódico, ele irá variar muito pois depende do quanto a planta puxa de água e depende
> da temperatura e umidade ambiente)
> Irrigação da horta (periódico, setado pelo usuário)
> Aplicação de adubo líquido (periódico, setado pelo usuário)
> Bateria baixa (não-periódico)

### Tratamento de Eventos
> Nível baixo de água ou de adubo/fertilizante: Enviar uma mensagem via Wi-Fi para o usuário e acender um led (led azul para água e led amarelo para adubo)
> Umidade do solo menor do que o configurado: Gotejar água no solo até atingir o valor setado pelo usuário
> Irrigação da horta: Irrigar a horta com o volume de água no horário determinado pelo usuário
> Aplicação de adubo/fertilizante: Aplicar na água que será gotejada na horta
> Bateria baixa: Enviar uma mensagem via Wi-Fi para o usuário e acender um led (led vermelho)

## Descrição Estrutural do Sistema
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/Lobato-B3313/ea075/1669fc1ca83abd8f34cf037b9d73f4315930ea1e/2022.2/irrigador-horta/images/diagram.svg">

## Especificações (NOVO)

### Especificação Estrutural

> (Se preferir, adicione um link para o documento de especificação estrutural)
> 
> Entende-se por estrutural a descrição tanto das características elétricas e temporais como das restrições físicas de cada bloco funcional.
> Nessa etapa do projeto, ainda não será solicitado o diagrama elétrico mas espera-se que já estejam identificados os componentes e circuitos integrados propostos
> para implementação do sistema embarcado proposto.
> 
> Como o projeto de um sistema embarcado é centralizado nas tarefas, recomenda-se iniciar com a definição dos periféricos de entrada e saída (atuadores e/ou sensores) apropriados para o
> sistema. Pode ser necessário definir um endereço distinto para cada um deles. 
> Este endereço será utilizado pela unidade micro-controladora para acessá-los tanto para leitura como para escrita.

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
> 
> Finalmente, deve-se especificar as restrições físicas e ambientais de funcionamento do circuito, tais como limites mecânicos
> (altura, largura, profundidade) e limites de dissipação térmica.

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
> Expansão do mercado de produtos organicos [Valor](https://valor.globo.com/empresas/esg/noticia/2022/09/09/de-cosmeticos-a-alimentos-mercado-de-produtos-verdes-esta-em-franca.ghtml)
 
> Como cultivar uma horta caseira [Estadão](https://revistacasaejardim.globo.com/Casa-e-Jardim/Paisagismo/noticia/2022/08/10-dicas-simples-e-certeiras-para-ter-uma-horta-caseira-saudavel.html)

> Irrigation Systems - Automatic Watering Systems [Irrigation Systems](https://www.gardeners.com/how-to/about-snip-n-drip/7886.html)

> DripWorks - How to choose a garden irrigation system [DripWorks](https://www.dripworks.com/blog/how-to-choose-a-garden-irrigation-system)

> DripWorks - Fertilizer Injectors [DripWorks](https://www.dripworks.com/drip-irrigation/fertilizer-injectors)

> Gardena - Automatic Irrigation [Gardena](https://www.gardena.com/int/products/guidance/automatic-irrigation/)
