# `<Título em Português do Projeto>`
# `<Project Title in in English>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Nome1  | 123456  | Eng. Elétrica|
> | Nome2  | 123456  | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?

Com o avanaço da tecnologia, computadores com maiores capacidades de processamento foram desenvolvidos para resolver os problemas mais complexos. No entanto, essa capacidade de processamento faz com que os componentes eletrônicos dissepem altas quantidades de calor. Para que os computadores operem da maneira desejada e, principalmente, que no sejam danificados, é necessário um sistema de resfriamento que mantenha sua temperatura em um limiar especificado pelo fabricante. 

Uma das formas mais simples de realizar essa função é utilizando ventilação forçada por meio de coolers. Porém, essa soluço é custosa e inconveniente por conta da energia gasta e pelo ruído emitido. Nosso sistema resolve essas limitaçes ao acionar os ventiladores apenas quando a temperatura dos computadores é elevada, mantendo a simplicidade e diminuindo os custos associados à ela.    

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

- Medir a temperatura;
- Comparar temperatura medida com valor ajustado;
- Ajustar setpoints de temperatura;
- Acionar/desacionar ventiladores;
- Exibir valor da temperatura medida.

### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

- Ajustar setpoints de liga/desliga dos ventiladores

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

- Ligar/Desligar coolers com base na temperatura medida.

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

- Se cooler estiver desligado e temperatura for menor que temperatura ajustada, manter desligado;
- Se cooler estiver desligado e temperatura for maior que temperatura ajustada, ligar cooler;
- Se cooler estiver ligado e temperatura for maior que temperatura ajustada, manter ligado;
- Se cooler estiver ligado e temperatura for menor que temperatura ajustada, desligar.

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
