# `Estufa Inteligente`
# `Eco Greenhouse`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Pedro Henrique Carosso Christensen  | 243048  | Eng. Elétrica|
| Juliana Nicolette  | 171244  | Eng. Elétrica|


## Descrição do Projeto
Com o desenvolvimento tecnológico crescendo exponencialmente, ferramentas de controle à distância acabam sendo cada vez mais comuns, trazendo segurança e autonomia a processos industriais e domésticos.

Foi pensando nisso que o projeto Estufa Inteligente surgiu. A intenção é possibilitar controles de temperatura, umidade e irrigação utilizando um controle via APP através de uma interface simples contendo dois modos: o automático e o manual.

Além disso, as possibilidades de rotatividade do plantio são infinitas, já que o proprietário consegue configurar faixas de temperatura, umidade e ciclos de irrigação manualmente, permitindo assim a economia energia conforme o clima local. E no quesito sustentabilidade, a eficácia é garantida: além da economia energética, há também a economia de água.

Com o sistema Estufa Inteligente, além de garantir a qualidade do produto na colheira, você evita a proliferação de pragas, automatiza todos os processos de plantio e controla todas as funções à distância.

A idealização do projeto possui como público alvo qualquer pessoa que deseje automatizar suas estufas e manter um controle manual quando necessário, somente tendo um celular e conexão com a internet.

Um valor seria melhor definido quando o projeto estiver em uma etapa de desenvolvimento mais avançada, por conta de não conseguirmos estipular os custos inicialmente. 

## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
Como funcionalidades do projeto, podemos listar:
- Controle de temperatura através de ares condicionados;
- Controle de irrigação através de aspersores¹;  
- Controle de umidade através de aspersores (os mesmos utilizados no controle da irrigação);
- Interação manual com os controles por meio de aplicativo, porém o foco é a automação deste trabalho por meio de uma fácil programação feita pelo cliente.

### Configurabilidade
Em nosso projeto, vamos definir dois modos de configuração: automático e manual. Dessa forma, permitimos a autonomia de tomadas de decisões e o proprietário poderá alternar os modos via APP, sendo necessário apenas possuir acesso à rede de internet para se comunicar com o sistema da estufa.

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
[1] https://pt.wikipedia.org/wiki/Irriga%C3%A7%C3%A3o
