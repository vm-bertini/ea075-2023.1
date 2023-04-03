# `E1: Horta automatizada`
# `Automated vegetable garden`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Gabriel Benê Teixeira Pereira | 234674  | Eng. Elétrica|
> | Mariana Figueiredo Menezes | 248101 | Eng. Elétrica|


## Descrição do Projeto

O objetivo principal do projeto é criar um produto que faça a manutenção de uma pequena horta doméstica de forma automatizada, sem que o(a) usuário(a) necessite ter um cuidado diário com a horta. A motivação se originou no fato de existirem pessoas com interesse em cultivar uma horta doméstica, mas que passam a maior parte do dia ou até mesmo vários dias fora de casa e por isso não podem realizar as tarefas necessárias para o cultivo de forma ideal, principalmente em relação a irrigação. Assim, os potenciais usuários são estas pessoas que querem cultivar uma horta doméstica, mas não podem ou não querem realizar os cuidados rotineiros manualmente.

De início, não foi possível estabelecer um valor econômico associado ao projeto, mas o mesmo design pode ser adaptado para uma produção em maior escala e, junto de uma análise de mercado para prever um número potencial de vendas, pode-se chegar a um valor viável que cubra os custos de produção individual do produto e seus custos de projeto e gere um retorno financeiro.


## Descrição Funcional

### Funcionalidades

O projeto tem como as principais funcionalidades:
- Molhar a planta;
- Fertilizar o solo;
- Iluminar a planta.


### Configurabilidade

Quanto as configurabilidades, é possivel que o(a) usuário(a) decida manualmente, através de um botão, se quiser molhar ou fertilizar. Além disso, o(a) usuário(a) poderá configurar se a planta está em um espaço com iluminação natural ou não, por meio de um interruptor, e se ela será ou não fertilizada automaticamente a cada 30 dias.


### Eventos

O sistema deverá verificar a umidade do solo a cada 12h, decidir molhar ou não. Além de verificar interrupções provenientes dos botões, que não são periódicos, quanto à: a) molhar naquele momento; b) fertilizar naquele momento; c) ativar/desativar a fertilização automática e; d) ativar/desativar modo iluminação artificial.

Caso a função de fertilização esteja ativada, o sistema deverá periodicamente realizar a fertilização da planta. O mesmo se aplica para a função de iluminação artificial.


### Tratamento de Eventos

O sistema deverá tratar o pressionamento dos botões e do interruptor. Outro ponto a ser tratado são as rotinas de molhar, fertilizar e iluminar as plantas periodicamente.

Ao tratar o evento de "a) molhar naquele momento", o sistema deve realizar a irrigação e colocar a rotina de molhar automaticamente no estado de espera após uma irrigação.

Já ao tratar o evento de "b) fertilizar naquele momento", o sistema deve realizar a fertilização e colocar a rotina de fetilização automática no início da espera para a nova fertilização, caso esta função esteja ativada.

## Descrição Estrutural do Sistema

Para tratar corretamente os eventos, temos que, para a irrigação das plantas, é necessário:
1) Medir a umidade do solo e de acordo com os padrões pré-estabelecidos categorizar entre: criticamente seco, seco ou úmido. 
2) Caso esteja:
    1) criticamente seco: molhar e esperar 12 horas para reiniciar o sistema;
    2) seco: verificar a luminosidade, se estiver:
        1) escuro: esperar 3 horas para reiniciar o sistema;
        2) luminosidade ideal: molhar e esperar 12 horas para reiniciar o sistema;
        3) muita luminosidade: esperar 3 horas para reiniciar o sistema;
    3) umido: esperar 3h para reiniciar o sistema;

A verificação da luminosidade deve ser robusta a variações momentâneas da luminosidade que façam um período de muita luminosidade parecer um período de luminosidade ideal, como uma sombra feita sobre sistema no momento da medição de luminosidade. Esta robustez pode ser obtida medindo a luminosidade mais de uma vez em instantes próximos e usando o conjunto de medições para determinar a luminosidade atual.

Assim, o comportamento descrito do sistema de irrigação pode ser visualizado pelo seguinte fluxograma:

![Fluxograma de funcionamento do sistema de irrigação](https://github.com/marifmenezes/ea075-2023.1/blob/7f2e1aa3a34f9040a63b6bae250f3a26109d58bd/projetos/horta/ea075-molhar.drawio(1).png "Fluxograma de funcionamento do sistema de irrigação")

Quanto a adubação da horta, é realizada uma fertilização automaticamente a cada 30 dias, caso o(a) usuário(a) ative esta funcionalidade. Esta fertilização é feita adicionando o fertilizante a água da próxima irrigação.

Este processo pode ser acompanhado pelo fluxograma abaixo:

![Fluxograma de funcionamento do sistema de fertilização](https://github.com/marifmenezes/ea075-2023.1/blob/00f817132645def5ac477aeb62ce1dbcd82fcc9a/projetos/horta/diagrama_fertilizacao.png "Fluxograma de funcionamento do sistema de fertilização")

Para a iluminação, caso o(a) usuário(a) tenha definido que o sistema está em uma área sem iluminação natural, é necessário executar uma rotina que aumente gradualmente a intensidade luminosa das lâmpadas ao longo de 6 horas até um valor máximo e depois diminua esta intensidade ao longo de outras 6 horas. Em seguida, deve-se esperar 12 horas até que a mesma rotina seja executada novamente, simulando o ciclo de luminosidade do sol ao longo de um dia. 

Este processo pode ser acompanhado pelo fluxograma abaixo:

![Fluxograma de funcionamento do sistema de iluminação](https://github.com/marifmenezes/ea075-2023.1/blob/00f817132645def5ac477aeb62ce1dbcd82fcc9a/projetos/horta/diagrama_iuminacao.png "Fluxograma de funcionamento do sistema de iluminação")


## Referências

[1] [Horta automatizada](https://github.com/renanserrano/horta-automatizada)

[2] [Monitore sua planta usando arduino](https://www.makerhero.com/blog/monitore-sua-planta-usando-arduino/)

[3] [Projeto arduino de irrigação automática - Sua planta bem cuidada](https://www.usinainfo.com.br/blog/projeto-arduino-de-irrigacao-automatica-sua-planta-sempre-bem-cuidada/)