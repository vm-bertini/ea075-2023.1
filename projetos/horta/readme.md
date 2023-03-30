# `E1: Horta automatizada`
# `Automated vegetable garden`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Nome2 | 123456  | Eng. Elétrica|
> | Mariana Figueiredo Menezes | 248101 | Eng. Elétrica|


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado? 

Não foi possível estabelecer um valor econômico associado a esse projeto, mas o mesmo design poderia ser aprimorado e produzido em maior escala a fim de trazer maior comodidade e conforto para as pessoas.


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar

O projeto tem como as principais funcionalidades:
- Molhar a planta;
- Fertilizar o solo;
- Iluminar a planta.


### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.


Quanto as configurabilidades, é possivel que o(a) usuário(a) decida manualmente, atraves de um botão, se quiser molhar ou fertilizar. Além disso, o(a) usuário(a) poderá configurar se a planta está em um espaço com iluminação natural ou não, por meio de um interruptor.


### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?

O sistema deverá verificar a umidade do solo a cada 12h, decidir molhar ou não. Além de verificar interrupções provenientes dos botões, que não são periódicos, quanto à: a)molhar naquele momento; b) fertilizar naquele momento e; c) ativar modo iluminação artificial.


### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?

O sistema deverá tratar o pressionamento dos botões e do interruptor. Outro ponto a ser tratado é a rotina de molhar as plantas periodicamente.

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


Para tratar corretamente os eventos, temos que para a irrigação das plantas:
1) Medir a umidade do solo e de acordo com os padrões pré-estabelecidos categorizar entre: criticamente seco, seco ou úmido. 
2) Caso esteja:
    1) criticamente seco: molhar e esperar 12 horas para reiniciar o sistema;
    2) seco: verificar a luminosidade, se estiver:
        1) escuro: esperar 3 horas para reiniciar o sistema;
        2) luminosidade ideal: molhar e esperar 12horas para reiniciar o sistema;
        3) muita luminosidade: esperar 3 horas para reiniciar o sistema;
    3) umido: esperar 3h para reiniciar o sistema;
   
Quanto a adubação da horta, é realizada uma fertilização a cada x dias.

Para a iluminação é necessário:

Todo esse processo pode ser acompanhado pelo fluxograma abaixo:

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
> https://github.com/renanserrano/horta-automatizada
> https://www.makerhero.com/blog/monitore-sua-planta-usando-arduino/
> https://www.usinainfo.com.br/blog/projeto-arduino-de-irrigacao-automatica-sua-planta-sempre-bem-cuidada/
