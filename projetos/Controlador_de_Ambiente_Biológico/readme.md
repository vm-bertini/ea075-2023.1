# `InteliPlanta`

# `SmartPlant`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação _EA075 - Sistemas Embarcados_,
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
|Nome | RA | Curso|
| --- | --- | --- |
| Rafael Domingos Nascimento Molina Ogallas | 176121 | Eng. Elétrica |
| Rodrigo Toshio Ogasawara Tahara | 205578 | Eng. Elétrica |

## Descrição do Projeto
A natureza e sua preservação, tal como os impactos ambientais, têm tido cada vez mais destaque no mundo contemporâneo. A cada etapa de projeto, critérios como a sustentabilidade, otimização de processos e utilização de meios alternativos detém uma presença mais que necessária, uma vez que a sociedade passou a ser mais exigente com os comprometimentos sócio-ambientais. 

O projeto de simulador ambiental para desenvolvimento de plantas agrega muito valor econômico e ambiental, pois os processos passam a se tornar automatizados, possibilitando um cenário mais adequado para a planta. Grandezas como temperatura, umidade e luminosidade passam a ser monitoradas através de sensores e câmeras, possibilitando uma maior eficácia em seu desenvolvimento, graças a atuadores conectados à microcontroladores que possibilitam em alguns casos, até mesmo vigilância via remota por meio de aplicativos. A importância desses parâmetros é evidenciada quando destaca-se que, em condições não propícias de maturação das plantas, pode ocorrer o fechamento dos estômatos que provocam uma diminuição de trocas gasosas e, consequentemente, uma alteração no processo de difusão de vapor de água que pode vir a interferir no processo de fotossíntese; inclusive reduzindo a quantidade de nutrientes absorvidos. Outra possível consequência é quando ela se encontra em um ambiente com constante incidência solar, pois algumas plantas adoecem devido ao estresse, o que pode arrecatar no fato de ressecar e morrer. 

De forma geral, cuidar de plantas no interior de ambientes requer muito zelo, responsabilidade e habilidade, que por muitas vezes; devido à fatores como pressão externa, falta de tempo ou mesmo esquecimento, acaba com comprometer sua integridade. Dependendo da situação, pode requerer reposição de mudas ou até mesmo presença constante de profissionais especializados, sendo que se contabilizar gastos com ferramentas, substratos e vasos, o gasto pode chegar a se tornar inviável, chegando em torno de R$200 - 300 por planta. Por esse motivo, a presença de uma ambientação adequada e otimizada é a diferença entre uma estabilidade e durabilibilidade maximizada do tempo de vida desses seres. Como o projeto propõe, a criação dentro de um ambiente interno é mais desejável, pois além de proporcionar condições desejadas para as plantas, servir de decoração (podendo ser utilizado até dentro do âmbito empresarial) e melhorar a qualidade do ar; uma vantagem extremamente importante é que no caso de plantas voltadas ao cultivo para consumo, há uma proteção quase que integral contra possíveis predadores e pragas.

Embora o problema mundial em relação à fome não seja diretamente relacionada à falta de comida, mas sim pela falta de gestão e o desperdício descontrolado de alimentos; tal projeto visa um público que deseja ter sua própria fonte de alimento caseira, com boa flexibilidade de manejo e um isolamento sobre a dependência parcial do mercado. 
Visa, inclusive, o desenvolvimento de plantas de diferentes espécies no interior de ambientes, tais como leguminosas e oleagenosas. Propomos-nos a expandir o desenvolvimento do projeto para o controle remoto do sistema, de forma a alterar as condições da planta, sintezindo um modelo próximo ao de um simulador de ambiente biológico multi-expansível como meta final.

## Descrição Funcional

### Funcionalidades
- Umidade do substrato:
   - Medir a umidade do substrato e indicar a falta ou o excesso.
      - Medir a umidade do solo para plantas no geral.
      - Medir a umidade do ar no interior de raízes ou em superfície, para orquídeas
      - Medir nível de água para espécies com alta demanda de água.
   - Fornecer regagem adequada e programável:
      - Quantidade de água configurada por planta
      - Modos de deposição de água múltiplos:
         1. irrigação por gotejamento direto na solo (plantas em geral).
         2. borrifamento leve (orquídeas e similares).
         3. aspersão e simulação de chuva (displays fechados)
- Iluminação:
   - Medir a iluminação incidente e indicar falta ou excesso de luz.
   - Fornecer iluminação artificial que substitua ou suplemente a iluminação presente através de fitas de LED.
- Temperatura:
   - Medir temperatura local e indicar necessidade de intervenção da fita de LED ou do sistema de irrigação com o intuito de alterar a temperatura.
<!--    - Fornecer aquecimento possível. -->
- Tempo:
   - Medir o tempo e fornecer iluminação ou irrigação de acordo com cronograma diário ou semanal.
- Nutrientes:
   - Medir nutrientes principais e PH do solo, indicando o momento que seja necessário intervenção para seu enrequecimento.
- Monitoramento e conectividade:
   - Monitorar medições e armazenar dados da planta com relatório e possível indicação de intervenção.
   - Enviar dados da planta por wifi e monitoramento remoto por API ou aplicativo.
- Captura, envio e tratamento de imagens:
   - Capturar imagens da planta e torná-las acessíveis remotamente (por API ou aplicativo).
   - Fornecer imagens e informaçãoes do momento atual.
   - Produzir animação timelapse de certos períodos.
     <!-- - Possível avaliação da saúde da planta por tratamento de imagem. -->
     <!-- - Possível identificação automática de espécie. -->

### Configurabilidade
Configurações editáveis no aparelho ou remotamente (o objetivo inicial do projeto é ser totalmente controlado de forma remota):
- Configuração customizada de irrigação e iluminação.
- Opções de configurações pré-determinadas de irrigação e iluminação por espécies mais comuns.

### Eventos
- Irrigação: apenas em casos de baixo nível de umidade.
  - Intervalos entre atuações de 10 ~ 30min, a variar por espécie.
  - Identificar nível de umidade crítico e jogar água sobre o substrato.
- Iluminação: baixo nível de iluminação.
  - Atuação imediata 100 ~ 1000ms.
  - Atuação durante período do dia (janela de iluminação).
- Identificação de nutrientes: baixo nível de nutrientes.
  - Evento com menor intervalo, de 1 ~ 7 dias entre cada aferimento e indicação.
- Temperatura: temperatura excessivamente alta ou baixa.
  - Sinalizar prontamente, podendo ser desabilitado.

### Tratamento de Eventos
- Para a irrigação da planta, o intervalo necessário de monitoramento estivo estimado está entre 10 min até mesmo 1 hora. Considera-se que, com a sinalização de necessidade de água, o atuador de irrigação deverá agir prontamente, mas acredita-se que será necessário um tempo em torno de 10 min para que a água se infiltre no substrato e uma nova medição correta de umidade possa ser feita. Portanto esse será o tempo mínimo estimado para uma nova intervenção.
- Para a detecção iluminação insuficiente a ação dos atuadores deve ser imediata e em tempo real. No entanto, considera-se que nenhuma mudança drástica deve ocorrer em um período maior que 1 segundo, e portanto esse será o intervalo entre cada monitoramento.
- Outro modo de ação da iluminação poderá ser, em conjuto com o anterior ou exclusivamente, de acordo com a janela diária de horário de iluminação programada.
- Para a possibilade de monitoramento de nutrientes, estima-se que, em caso de adição dos compostos necessários, manual ou automaticamente, seja necessário um tempo maior para que uma nova aferição correta pode ser feita, assim que os compostos tenham se dissolvido no substrato. Estima-se entre horas ou dias para que o processo finalize. Assim, se o equipamento sinalizar a falta de algum nutriente, deve haver a adição de composto, sendo que o microcontrolador deverá tomar esse tipo de decisão ou ainda, com o usuário do aparelho indicando se tal ação deve ser efetuada.

## Descrição Estrutural do Sistema
O Sistema foi pensado e dividido nas seguintes partes: sensores gerais, que medem um parâmetro para a planta; atuadores de iluminação e irrigação; módulo de relógio, para controle de tempo; elementos de comunicação, como módulo wifi e, como possibilidade, display e botões (o projeto tem como objetivo ser totalmente controlado apenas remotamente, sem configurações diretas no dispositivo); e o módulo de câmera e produção de imagens, que foi pensado separadamente, devido à complexidade específica.

![image](https://drive.google.com/uc?export=view&id=1fs4Ybog8M8WIbZz2sgrIXaeM3cn_ePwT)

## Referências
https://www.bybrittanygoldwyn.com/grow-lights-houseplants/

https://www.youtube.com/watch?v=QTH9m6MDIfc&ab_channel=Dr.Plants

https://repositorio.unesp.br/bitstream/handle/11449/103444/souza_tr_dr_botfca.pdf?sequence=1&isAllowed=y

https://repositorio.ufu.br/bitstream/123456789/34084/1/SistemaAutomatizadoIrriga%c3%a7%c3%a3o.pdf
