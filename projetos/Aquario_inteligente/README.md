# `Aquário Inteligente`
# `Smart Aquarium`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Mateus Almeida Resende de Miranda  | 239852  | Eng. Elétrica|
| Otávio Briske Lima  | 220716  | Eng. Elétrica|


## Descrição do Projeto
O principal objetivo deste projeto é de realizar o controle de algumas grandezas físicas necessárias para a manutenção um ecossistema aquático marinho. Como existem condições específicas e bem controladas para garantir a sobrevivência de peixes, corais e outros animais, é de suma importância repassar a tarefa de controle das condições para uma máquina que fará isso frequentemente. 
O aquário inteligente é um sistema capaz de controlar a temperatura, por meio da habilitação regulada de sistemas de aquecimento e resfriamento externos (não projetados). As informações obtidas serão armazenadas para gerar um relatório, que possuirá as informações de: tempo que o resfriador ficou ligado por período, tempo que o aquecedor ficou ligado por período, temperatura atual do aquário e desempenho energético no período analisado. O relatório analisará os dados obtidos diariamente e semanalmente, podendo ser acessado quando o usuário quiser e sendo atualizado com um período configurável com padrão de a cada 10 minutos. 
Dessa forma, usuários que desejam possuir aquários marinhos, ou que já o possuem, não precisarão se preocupar com as tarefas de tratamento rotineiras requeridas e podem verificar o estado em que o ecossistema se encontra através do relatório gerado, o sistema ainda armazenará parâmetros representativos do aquário em que está operando, que são obtidos durante a sua operação, de forma a permitir uma otimização da potência consumida pelos sistemas de aquecimento e resfriamento, assim como um controle preventivo para o caso em que o sensor de temperatura do aquário apresente medidas incertas.  
A ideia para o projeto foi desenvolvida por meio de uma reflexão sobre como seria possível de se automatizar um processo de manutenção das condições necessárias para a vida aquática visto que qualquer perturbação das condições os corais e os peixes podem ficar doentes e até morrer. Ademais, o projeto também foi desenvolvido a partir da necessidade real de um dos membros da dupla que possuía aquário marinho e que tinha a dificuldade de manter o ecossistema adequado a todo momento. 
No momento atual de escrita dado a fase de desenvolvimento em que o projeto se encontra, se estabelece um valor econômico de R$54,00, correspondente aos valores do SOC (System On Chip) e dos sensores utilizados. 


## Descrição Funcional

### Funcionalidades
O sistema em questão será capaz de executar 4 tipos de tarefas (Configuração, medição, regulação e geração de relatório). O primeiro tipo consiste na configuração do sistema no qual o usuário é capaz de configurar através de um aplicativo o nível ou a faixa de temperatura desejado, a resolução a ser utilizada pelos sensores e o período de amostragem. Após isso, o sistema medirá as condições do aquário através de um sensor de temperatura dentro do aquário e um do lado de fora. As informações obtidas serão atualizadas a cada período no relatório que será armazenado na nuvem podendo ser acessado pelo aplicativo. 

Tarefas: 
- Configuração da operação em valor fixo ou faixa de temperaturas; 
- Configuração das temperaturas desejados; 
- Medir as temperaturas; 
- Gerenciar o aquecedor; 
- Gerenciar o resfriador; 
- Gerar relatórios diários e semanais que são atualizados a cada período. 


### Configurabilidade
É previsto que se possa configurar o sistema para operar em valores fixos de temperatura ou em uma faixa de valores ajustáveis (através do aplicativo), com o objetivo de se adaptar as demandas de diferentes tipos de ecossistemas. Além disso, também é possível se ajustar a taxa de amostragem das grandezas do aquário e a resolução a ser utilizada pelos sensores, de acordo com o desejado. 


### Eventos
O primeiro evento corresponde à uma interrupção gerada por uma alteração das configurações originais (da frequência de amostragem, do modo de operação em valor fixo ou faixa de temperaturas, da resolução dos sensores ou dos valores limites de temperatura) via aplicativo. 
Um segundo evento é a passagem de tempo correspondente a um período para a realização da amostragem e operação dos atuadores (verificada pela comunicação do SoC com a internet via Wi-fi).
Outro evento corresponde a passagem de um segundo período para a transmissão dos valores armazenados na memória interna do SoC para a nuvem via Wi-fi, assim como para o cálculo de novos parâmetros representativos do aquário.
O quarto evento corresponde à uma medição discrepante por parte dos sensores (de temperatura externa e/ou interna ao aquário). 
O último evento considerado é o de queda de energia, em que tanto os sistemas de aquecimento e resfriamento provavelmente irão parar de operar, de forma com que seja sensato que o sistema de controle também cesse a sua operação, considerando que todos os dados e valores configurados já estejam salvos na nuvem. 
Como última parte temos que ao a energia retornar o microcontrolador irá esperar que tanto a energia quanto o Wi-fi sejam reestabelecidos, recuperando então os valores necessários da nuvem e retornando para a sua operação normal. 


### Tratamento de Eventos
Para o primeiro evento a unidade micro controladora deve iniciar uma sub-rotina de atendimento a interrupção na qual se atualiza todos os parâmetros de operação configuráveis e então se retorna ao programa principal. 
No segundo evento, temos que o SoC capta as medições dos sensores realizando então um processamento interno dependente destes valores e dos configurados, de forma com que os dados desejados sejam gerados e armazenados na memória interna do SoC.
Então no terceiro evento (cujo período é superior ao do segundo evento), os dados armazenados na memória até então são finalmente transmitidos para um relatório na nuvem, permitindo que a memória seja limpa, e novos parâmetros para o aquário são calculados. 
No quarto evento temos que caso seja identificado uma leitura improvável em algum dos sensores o sistema deverá realizar um alerta via aplicativo quanto ao valor provavelmente incorreto da leitura. 
Nos últimos dois eventos temos que não são necessárias ações adicionais por parte do microcontrolador, além da recuperação dos dados salvos na nuvem, assim que tanto a energia quanto o Wi-fi fossem reestabelecidos, antes de seu retorno à operação normal. 
Abaixo são ilustrados os fluxogramas de tratamento para cada evento:


## Descrição Estrutural do Sistema
Será necessário a utilização de sensores para temperatura dentro do ambiente aquático e no ambiente externo, para a captação analógica dessas grandezas, e então se converter esses em valores digitais que poderão ser compreendidos pelo sistema embarcado de forma com que ele possa tomar decisões quanto a habilitação dos atuadores (sistemas de refrigeração e de aquecimento). 

![image](https://github.com/Nothingtopus/Imagens/assets/127249262/6bf2077f-7120-4f35-8862-b491f0e0c5ed)


## Especificações

### Especificação Estrutural


### Especificação de Algoritmos

Inicialmente temos que para a passagem de um tempo correspondente ao periodo regulado T teremos o seguinte algoritmo de tratamento:



## Referências
Material postado na página (do google classroom) da disciplina de EA075A, de oferecimento para o primeiro semestre de 2023.
Ferramentas StackEdit e draw.io.
Referência: Mastering Markdown.
