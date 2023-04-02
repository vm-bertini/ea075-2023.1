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
Este projeto de propões a ser, antes de tudo, um controlador para plantas de diferentes espécies no interior de ambientes. Após completar essa tarefa, nos propomos a expandir o desenvolvimento do projeto para o controle remoto do sistem, controle de fatores avançados da planta, até um completo simulador de ambiente biológico multi-expansível.

Plantas em casa são a sensação de paz e vida no ambiente, mas, para sempre reluzirem verde, precisam do cuidado constante e especifico. Aguamento constante e na proporção, iluminação adequada e suficiente, umidade do local, e mesmo o monitoramente de nutrientes, são fatores que possuem maior ou menor peso para cada diferente espécies, aumentando a dificuldade dos cuidados.
Tantos fatores são determinantes para uma planta constantemente viva, verde e vigorosa, e um ambiente harmonizado.

- Para algumas espécies, alguns dias ou um fim de semana sem aguamento é suficiente para que a planta resseque ou morra.
- Muitas plantas adoecem e morrem pela falta de iluminação suficiente e não podem preencher o interior dos ambientes.
- Quando expostas a um ambiente com constante incidência solar, algumas plantas adoencem pelo estresse e podem ressecar e morrer.
- Nem sempre se dispõe de um ambiente externo ou solo para o cultivo. Às vezes ornar o ambiente interno é mais desejável.
- Após algum tempo, algumas plantas adoecem pelo esgotamento dos nutrientes do substrato.
  Cuidar de plantas ou com elas ornar a casa é um hábito desejável que nem sempre a ausência de tantos fatores permite possuir.
  Todos esses fatores podem ser resolvidos com uma solução automatizada.

Em média para se possuir algumas plantas no interior de uma casa, já considerando que se possua um local adequado. Os valores com as ferramentas, o substrato, os vazos e os aparatos de rega de uma única planta estão em torno de R$200 - 300.
Algumas plantas, como orquídeas, custam de R$50~100 nos melhores preços e comumente adoecem e são substituídas por outras novas. Outras, como cactus adoecem pelo excesso de água. A substituição da planta devido à ausência do cuidado é a solução encontrada.
No interior de empresas, para harmonização de ambientes, os gastos para manutenção e reposição de plantas são constantes. A presença de uma ambientação adequada é a diferença entre uma recepção que cause boa impressão ou sensação de abandono, uma ambiente de trabalho que forneça tranquilidade ou descuido.

De forma geral, bons cuidados com plantas no interior de ambientes significam cuidado com zelo constante e hábilidade, às vezes altos gastos com reposição ou presença constante de profissionais especializados.

Tantos fatores benéficos, para casas e empresas, poderiam ser alcançados por uma solução automatizada, que cobrissem os cuidados constantes necessários e mantivessem o experiência vitalizadora da presença das plantas no ambiente.

## Descrição Funcional

### Funcionalidades
- Umidade do substrato:
   - Medir a umidade do substrato e indicar a falta ou o excesso.
         - Medir a umidade do solo para, plantas em geral.
         - Medir a umidade do ar no interior de raízes ou em superfície, para orquídeas
         - Medir nível de água para espécies com alto aguamento.
   - Fornecer aguação adequada e programável:
         - Quantidade de água configurada por planta
         - Modos de aguamento múltiplos:
            - irrigação por gotejamento direto na solo (plantas em geral).
            - borrifamento leve (orquídeas e similares).
            - aspersão e simulação de chuva (displays fechados)
- Iluminação:
   - Medir a iluminação incidente e indicar falta ou excesso de luz.
   - Fornecer iluminação artificial que substitua ou suplemente a iluminação presente.
- Temperatura:
   - Medir temperatura local e indicar necessidade de intervenção
<!--    - Fornecer aquecimento possível. -->
- Tempo:
   - Medir o tempo e fornecer iluminação ou aguamento de acordo com cronograma diário ou semanal.
- Nutrientes:
   - Medir nutrientes principais e ph do solo, indicando ação necessária.
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
- Configuração customizada de aguamento e iluminação.
- Opções de configurações pré-fornecidas de aguamento e iluminação por espécies mais comuns.

### Eventos
- Aguamento: baixo nível de umidade.
  - Intervalos entre atuações de 10 ~ 30min, a variar por espécie.
  - Identificar nível de umidade crítico e aguar o substrato.
- Iluminação: baixo nível de iluminação.
  - Atuação imediata 100 ~ 1000ms.
  - Atuação durante período do dia (janela de iluminação).
- Identificação de nutrientes: baixo nível de nutrientes.
  - Evento com menor intervalo, de 1 ~ 7 dias entre cada aferimento e indicação.
- Temperatura: temperatura excessivamente alta ou baixa.
  - Sinalizar protamente, podendo ser desabilitado.

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
- Para o aguamento da planta o intervalo necessário de monitoramento estivo estimado está entre 10 min até mesmo 1 hora. Considera-se que, com a sinalização de necessidade de água, o atuador de irrigação deverá agir prontamente, mas acredita-se que será necessário um tempo em torno de 10 min para que a água se infiltre no substrato e uma nova aferição correta de umidade possa ser feita. Portanto esse será o tempo mínimo estimado para uma nova intervenção.
- Para a detecção iluminação insuficiente a ação dos atuadores deve ser imediata e em tempo real. No entanto, considera-se que nenhuma mudança drástica deve ocorrer em um período maior que 1 segundo, e portanto esse será o intervalo entre cada monitoramento.
- Outro modo de ação da iluminação poderá ser, em conjuto com o anterior ou exclusivamente, de acordo com a janela diária de horário de iluminação programada.
- Para a possibilade de monitoramento de nutrientes, estima-se que, em caso de adição dos compostos necessários, manual ou automaticamente, seja necessário um tempo maior para que uma nova aferição correta pode ser feita, assim que os compostos tenha se dissolvido no substrato. Estimasse entre horas ou dias. Assim, se o equipamento sinalizar a falta de algum nutriente, assim que ouver alguma adição de composto, o microcontrolador deverá demorar essa quantidade maior de tempo, com o usuário do aparelho indicando a adição no dispositivo ou tal ação sendo tomada automaticamente.

## Descrição Estrutural do Sistema
O Sistem foi pensado e dividido nas seguintes partes: sensores gerais, que medem um parâmetro para a planta; atuadores de iluminação e irrigação; módulo de relógio, para controle de tempo; elementos de comunicação, como módulo wifi e, como possibilidade, display e botões (o projeto tem como objetivo ser totalmente controlado apenas remotamente, sem configurações diretas no dispositivo); e o módulo de câmera e produção de imagens, que foi pensado separadamente, devido à complexidade específica.

![image](https://drive.google.com/file/d/1snFjC7HWc4AtHhKjwESGPSURNZZuK8Be/view?usp=share_link)

## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.

https://www.bybrittanygoldwyn.com/grow-lights-houseplants/

https://www.youtube.com/watch?v=QTH9m6MDIfc&ab_channel=Dr.Plants
