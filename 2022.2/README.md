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
Para demonstrar e funcionalidade no sistema podemos apresentar isoladamente cada sensor e com qual parte do sistema o seu atuador vai reagir dependendo do sinal de entrada, então segue a descrição de cada comportamento:

Controle da temperatura: Ao definir uma faixa de temperatura o sensor de temperatura vai mandar sinais para os ar-condicionados quando: Atingir temperatura limite inferior -> Ligar aquecedor. Atingir temperatura limite superior -> Ligar resfriamento. Esse sinal de ligar será único e outro sinal de desligamento será enviado quando o sensor de temperatura detectar a temperatura ideal atingida (geralmente leva-se a faixa de temperatura com a temperatura ideal posicionada exatamente no meio dessa faixa).
Para a parte manual, o cliente terá a informação da temperatura atual da sala e poderá acionar o resfriamento ou o aquecimento do ambiente manualmente, tendo em vista que os limites da faixa devem ser respeitados, mesmo que no modo manual.

Controle de umidade: Ao definir a faixa de umidade desejada o sensor de umidade vai mandar sinais para os irrigadores quando: Atingir umidade limite inferior -> Ligar os irrigadores. Porém o controle para diminuir a umidade do ambiente não será necessária, pois a umidade dentro da estufa terá que ser maior que a umidade externa. Para desligar os irrigadores, um sinal será enviado do sensor de umidade quando a umidade ideal for atingida, com o tempo a umidade tende a cair e o ciclo se repete.
Para o controle manual, o cliente terá a informação coletada pelo sensor de umidade do momento presente da umidade, e poderá acionar o irrigador, tendo em vista que os limites da faixa devem ser respeitados, mesmo que no modo manual.

Controle de irrigação: Com uma periodicidade programada os irrigadores irão acionar, porém isso será programado pelo cliente, pois os sensores de umidade também irão acionar os irrigadores, então temos que pensar em um intervalo padronizado para não irrigar em excesso as plantas, isso vai ser variável para cada tipo de planta, conforme o desejo do cliente.

### Funcionalidades
Como funcionalidades do projeto, podemos listar:
- Controle de temperatura através de ares condicionados;
- Controle de irrigação através de aspersores¹;  
- Controle de umidade através de aspersores (os mesmos utilizados no controle da irrigação);
- Interação manual com os controles por meio de aplicativo, porém o foco é a automação deste trabalho por meio de uma fácil programação feita pelo cliente.

### Configurabilidade
Em nosso projeto, vamos definir dois modos de configuração: automático e manual. Dessa forma, permitimos a autonomia de tomadas de decisões e o proprietário poderá alternar os modos via APP, sendo necessário apenas possuir acesso à rede de internet para se comunicar com o sistema da estufa.

### Eventos
Ditamos como evento periódico o controle de irrigação, que ocorre uma vez ao dia em situações normais. Dependendo do plantio e da configuração do cliente, é possível ajustar tornando-o mais/menos frequente. É possível configurar também o tempo de duração da irrigação para cada vez que ela for ativada, buscando um melhor aproveitamento e economia de água.

Como eventos não-periódicos listamos o controle de temperatura e umidade, que vão ocorrer com base nos dados recebidos pelos sensores. Portanto, os ajustes de temperatura e umidade terão definidos pontos limites mínimos e pontos limites máximos para cada um, para que esses parâmetros fiquem dentro de uma faixa ideal definida pelo cliente e que consiga ser eficiente para não ocorrer gasto desnecessário de energia.

### Tratamento de Eventos
Modo automático ligado:
Se temperatura for superior à Xº - acionamento dos ares condicionados por 1 hora
Se temperatura for inferior à Xº - desligamento dos ares condicionados por 30 minutos
Se umidade for superior à Y% - acionamento dos aspersores por 30 minutos
Se umidade for inferior à Y% - desligamento dos aspersores por 2 horas

Observação: A temperatura X e a umidade Y serão definidos pelo usuário do app mobile.

Modo automático desligado: Sistema ficará em espera aguardando um novo comando do usuário via app mobile.

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
