# `Aquário Inteligente`
# `Smart Aquarium`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).



|Nome  | RA | Curso|
|--|--|--|
| Mateus Almeida Resende de Miranda  | 239852  | Eng. Elétrica|
| Otávio Briske Lima  | 220716  | Eng. Elétrica|


## Descrição do Projeto
  O principal objetivo deste projeto é de realizar o controle de algumas grandezas físicas e químicas necessárias para a manutenção um ecossistema aquático marinho. Como existem condições específicas e bem controladas para garantir a sobrevivência de peixes, corais e outros animais, é de suma importância repassar a tarefa de controle das condições para uma máquina que fará isso a todo momento.
  O aquário inteligente é um sistema capaz de controlar o pH, a temperatura e medir o nível de ${CO}_2$ de um tanque responsável pelo controle de pH. As informações obtidas serão exibidas em tempo real no display e serão armazenadas para gerar os seguintes relatórios: nível de ${CO}_2$ por período, tempo que o resfriador ficou ligado por período e tempo que o aquecedor ficou ligado por período. O período pode ser escolhido pelo usuário entre diário ou semanal.
  Dessa forma, usuários que desejam possuir aquários marinhos, ou que já o possuem, não precisarão se preocupar com as tarefas de tratamento requeridas e podem verificar o estado em que o ecossistema se encontra através do relatório gerado que também serve para otimizar o aquário caso esteja descontrolado. 
  A ideia para o projeto foi desenvolvida por meio de uma reflexão sobre como seria possível de se automatizar um processo de manutenção das condições necessárias para a vida aquática visto que qualquer perturbação das condições os corais e os peixes podem ficar doentes e até morrer. Ademais, o projeto também foi desenvolvido a partir da necessidade real de um dos membros da dupla que possuía aquário marinho e que tinha a dificuldade de manter o ecossistema adequado a todo momento.
  No momento atual de escrita dado a fase de desenvolvimento em que o projeto se encontra, é difícil de se estabelecer um valor econômico a sua implementação prática.


## Descrição Funcional


### Funcionalidades
O sistema em questão será capaz de executar 4 tipos de tarefas (Configuração, medição, regulação e geração de relatório). O primeiro tipo consiste na configuração do sistema no qual o usuário é capaz de configurar através de botões e de um display o nível ou a faixa de temperatura e de pH desejados. Após isso, o sistema medirá as condições do aquário através de um sensor de temperatura e um de pH, além de medir o nível de ${CO}_2$ do tanque que é usado para regular o pH. As informações obtidas serão exibidas em tempo real no display e serão armazenadas para gerar os relatórios.

Tarefas:
- Configuração do pH e temperatura desejados
- Medir pH
- Medir Temperatura
- Medir o nível de ${CO}_2$ no tanque
- Aquecer a água
- Resfriar a água
- Liberar ${CO}_2$ na água
- Geração de relatórios e alertas no display



### Configurabilidade
É previsto que se possa configurar o sistema para operar em valores fixos de temperatura e/ou pH ou em uma faixa de valores ajustáveis (através de botões conectados ao microcontrolador e de uma interface via display), com o objetivo de se adaptar as demandas de diferentes tipos de ecossistemas. Além disso, também é possível na hora de observar os relatórios escolher o período desejado de observação dos resultados entre diário e semanal.


### Eventos
Os eventos descritos a seguir ocorrerão tanto para o caso em que o sistema esteja operando em uma faixa de valores quanto no de operação em valores fixos.
O primeiro dos eventos consiste na percepção por parte dos sensores de leituras não desejadas de temperatura ou de pH, em que: haverá os eventos em que a grandeza é medida com uma intensidade menor ou maior que a esperada, totalizando três eventos totais (apenas o evento de intensidade maior ocorre para o pH, o evento de pH menor é raro e caso seja identificado será gerado um alerta no display). Os sensores farão leituras a cada 10 minutos.
O segundo evento corresponde à geração do relatório por meio das medidas dos sensores. O evento em questão é aperiódico, pois sempre que houver uma medida o dado será armazenado e gerará o relatório no instante que o usuário solicitar.
E, como último evento, temos a solicitação (por meio do pressionamento de um botão) de alterações desejadas nos valores considerados como ideais e que regem a ativação dos atuadores, juntamente das medidas dos sensores.


### Tratamento de Eventos
O tratamento do primeiro tipo de evento consiste em utilizar atuadores de forma a balancear as variáveis físicas para que atinjam os valores configurados, nesse aspecto: caso a temperatura esteja abaixo/acima do valor desejado o microcontrolador deve ativar respectivamente o sistema de aquecimento/resfriamento; enquanto caso o pH esteja acima do esperado o sistema embarcado deve comandar a liberação de ${CO}_2$.
Já para o último evento um elemento deve alertar a passagem de um ciclo, de forma com que os valores medidos pelos sensores, assim como os estados do sistema de refrigeração, do sistema de aquecimento e da válvula de liberação de ${CO}_2$ são captados e transferidos para um relatório, juntamente das configurações atuais, que são exibidos em um display.


## Descrição Estrutural do Sistema
![Estrutura do aquário inteligente](https://user-images.githubusercontent.com/128386956/229377444-eb438f00-ec3f-4680-8948-adeb6f429f39.png)



## Referências
Material postado na página (do google classroom) da disciplina de EA075A, de oferecimento para o primeiro semestre de 2023.
