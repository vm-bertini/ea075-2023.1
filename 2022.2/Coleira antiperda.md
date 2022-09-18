# `Coleira antiperda avançada para animais domésticos`
# `Advanced anti-loss collar for pets`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Alef Henrique da Paz Silva  | 212269  | Eng. Elétrica|
> | Matheus Ferreira Silva  | 203442  | Eng. Elétrica|


## Descrição do Projeto
> O objetico deste projeto é ajudar na procura de pets quando ocorre a perda dos mesmos. 
> Há mais de 139 milhões de pets pelo Brasil, e a perda desses animais ocorre com determinada frequência, 
> e com o desenvolvimento desse projeto podemos amenizar este problema.
> 
> É um produto com alta chance de escala, o que pode implicar a venda de grandes lotes, produto com custo fixo rasoável, 
> com venda do produto a um preço acessível a maioria do público.
> 
> Com essa coleira com uma tecnologia embarcada, o dono pode encontrar seu pet que se perdeu em um momento importúno.
> 
> O público-alvo são amantes de pets, ao qual ao adquirir nosso produto, pode dar mais segurança aos mesmos.
> 
> Além disso, pode agregar um valor econômico, pela grande escala de venda, ao qual pode ser vendido em qualquer petshop, 
> o que contribui para fluxo de caixa desse negócios.


## Descrição Funcional
> 
### Funcionalidades

> Comunicação sem fio: O dono pode solicitar a localização pela comunicação via rádio frequência entre a central e a coleira com o auxílio de uma antena portátil,
> caso o pet esteja na condição de perdido.
> 
> Acionar LED: Nesse mesma condição, a coleira aciona uma iluminação, para identificar que o pet está perdido.
> 
> Transmissão de áudio/voz: Opção do dono enviar uma informação de voz ou áudio, caso queira.
> 
> Histórico de trajeto: Opção de registrar trajeto que o pet percorreu.
> 
> Resistência ao grau de IP contra poeira e sólidos IP66: Caso o pet esteja em ambientes externos com muita poeira ou chuva.
> 
> Bateria de duração longa com mini-placa fotovoltáica: Para evitar que o dono sempre fique carregando. 
> 
> QR Code: Caso alguém encontre o pet, pode ler um QR Code para identificação e contato com o dono.

### Configurabilidade
> Antena: Sistema de entrada de dados via rádio frequência, com faixa de banda eespecífica.
> 
> Led's para sinalização: Led's de cor vermelha ao qual podem piscar quando o pet estiver perdido.
> 
> Auto-falante: Para envio do sinal sonoro quando o animal estiver perdido.
> 
> Mini-placa fotovoltaíca: Com capacidade de carregar a bateria, quando o animal estiver perdido.
> 
> Bateria: Com capacidade suficiente de durar 24h, mesmo com todos periféricos estejam consumindo.
> Microcontrolador: Utilizado para processar as informações recebidas, e possa transmitir sua localização e acione os atuadores, caso necessário.
> 
> Circuito fonte de alimentação com entrada para carregador.
> 
> Circuito para codificar e decodificar as informações recebidas e transmitidas.
> 

### Eventos
> Quais eventos o sistema deve tratar?
> 
> 1º Transmissão de localização e duração da bateria:
> 
> Periodicidade: Pode ser periódica, enviando a informação da localização a cada 30s. 
> 
> Prioridade: Alta.
>
> 2º Atuadores quando animal perdido:
> 
> Periodicidade: Fica ligado apenas se o dono quiser, caso queira, é acionado constantemente, leds e sinalizações sonoras.
> 
> Prioridade: Média.

> 3º Coleira carregando:
> 
> Periodicidade: Baixa, apenas quando descarregar a coleira.
> 
> Prioridade: Média.
>
> 

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
> Para leitura real do pet, é preciso enviar a informação da localização e ir registrando de forma que fique um trajeto armazenado.

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
