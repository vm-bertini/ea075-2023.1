# `<Monitoramento_Estufa>`
# `<Greenhouse_monitoring>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Felipe Souza Sisnando de Araujo  | 239617  | Eng. Elétrica|
> | Levi Santos Volotão  | 239783  | Eng. Elétrica|


## Descrição do Projeto
> 
> Hoje em dia, observa-se o surgimento de cada vez mais estufas controladas, pois são um ambiente controlado em que plantações podem ser monitoradas e os aspectos físicos do ambiente podem ser configurados e otimizados para o crescimento e desenvolvimento adequado de uma certa espécie. Embora o custo inicial de uma estufa seja elevado, ela possibilita uma melhora na qualidade dos produtos, aumentando seu valor agregado, e uma dependência menor de características que não podemos controlar quando cultivadas a céu aberto.
> 
> Com uma plantação em estufa, os parâmetros externos não terão tanta influência, e as épocas do ano influenciarão menos as colheitas, garantindo a produção durante o ano todo, reduzindo fenômenos como falta de abastecimento em determinados períodos do ano e prejuízos econômicos dos cultivadores devido ao clima. Como exemplo, observa-se que "no verão, as chuvas demasiadas danificam as plantas e criam condições favoráveis para o aparecimento de doenças, atrapalhando a produção, sendo a época de maiores preços dos produtos hortícolas pela falta de oferta para abastecimento. Por outro lado, o frio e os ventos, do inverno prolongam o ciclo dessas culturas, que consequentemente desprogramam a produção e causam grandes prejuízos econômicos" [Miura, 2011]. Porém, mesmo que com influências externas reduzidas ainda é necessário o controle interno devido a problemas como a alta irradiação externa que resulta em um efeito de aquecimento dentro da estufa,podendo ser prejudicial à plantação caso não ocorra o controle da temperatura necessário. 
>
> Desse modo, nós propomos o desenvolvimento de um sistema embarcado responsável pelo monitoramento da estufa, que será capaz de identificar quando os valores de temperatura, umidade e luminosidade estiverem fora da faixa desejada, e será capaz de corrigir esses valores, utilizando sistemas de aquecimento e refrigeração (coolers), sistema de ventilação, aspersores de água e um sistema que controla as lâmpadas responsáveis pela luminosidade da estufa, bem como a luminosidade que entra do ambiente externo, a partir de uma claraboia cuja abertura é controlada. Esse monitoramento será de grande utilidade para cultivadores de diversos produtos, visto que as faixas de temperautra, luminosidade e umidade desejadas podem ser configuradas conforme os parâmetros adequados para cada espécie. A instalação desse sistema irá aumentar o valor agregado dos seus produtos, viabilizar o cultivo em todas as épocas do ano e permitir um controle automatizado, sem necessidade de mão de obra.
>  


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
> 

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
> http://sistemaolimpo.org/midias/uploads/fa4a7bc53246a8a9bf8642442a68fe3c.pdf
>
> https://www.horticeres.com.br/noticias/dicas-para-cultivo-protegido/#:~:text=Para%20efeito%20estufa%20(regi%C3%B5es%20muito,aproximadamente%20400%20a%201000%20m%C2%B2.
>
>https://www.rijkzwaan.com.br/blog/estufa-ou-guarda-chuva
>
>Miura, M. (2011). Análise Econômica do Cultivo em Ambiente Protegido.
>
>https://www.zanatta.com.br/cultivo-protegido/
