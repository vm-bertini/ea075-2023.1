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
> O objetiVo deste projeto é ajudar na procura de pets quando ocorre a perda dos mesmos. 
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

> Dentre todas funcionalidades, o nosso projeto inicial terá como uma ideia simples, ao qual, caso ocorra perda de comunicação via bluetooth aciona um alarme para o > > dono.
> Acionar LED: Nesse mesma condição, a coleira aciona uma iluminação, para identificar que o pet está perdido.
> 
> Ademais, tendo-se a condição que o projeto incial está funcionando, será implementado, novas funcionalidades, como:
> 
> Comunicação sem fio: O dono pode solicitar a localização pela comunicação via rádio frequência entre a central e a coleira com o auxílio de uma antena portátil,
> caso o pet esteja na condição de perdido.
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

> Módulos de comunicação Bluetooth.
> 
> Microcontrolador principal ATMEGA328P
> 
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
>
> 1º Transmissão e recepção com comunicação em conformidade (Animal dentro da distância permitida)
>
> Periodicidade: Periódica, enviando enviando um ping a cada 30s. 
> 
> Prioridade: Alta.
> 
> 2º Transmissão e recepção sem comunicação (Animal fora da distância permitida)
>
> Periodicidade: Único, para apenas com reset pelo dono.
>
> Prioridade: Alta.
> 
> 3º Transmissão de localização e duração da bateria:
> 
> Periodicidade: Pode ser periódica, enviando a informação da localização a cada 30s. 
> 
> Prioridade: Alta.
>
> 4º Atuadores quando animal perdido:
> 
> Periodicidade: Fica ligado apenas se o dono quiser, caso queira, é acionado constantemente, leds e sinalizações sonoras.
> 
> Prioridade: Média.

> 5º Coleira carregando:
> 
> Periodicidade: Baixa, apenas quando descarregar a coleira.
> 
> Prioridade: Alta.
> 

### Tratamento de Eventos
>
> Ping na transmissão e recepção da comunicação Bluetooth, caso ocorra a perda da comunicação ( Animal fora da distância permitada) o alarme toca até o dono resetar.
>
> Stand by: Nesse modo, o consumo é infimo, apenas alimentando o circuito sem fio de radio frequência, ao qual fica aguardando o comando, caso o pet se perda.
> 
> Comunicação caso animal se perca: O dono envia um sinal externo, a coleira decodifica o sinal recebido e atua de acordo o solicitado.
> 
> LED's: Pisca, caso o dono queira, para ajuda na encontra do pet.
> 
> Auto-falante: Emite sinal sonoro, caso o dono queira, para ajuda na encontra do pet. 
> 
> Transmissão de localização e duração da bateria: É enviado o sinal toda vez que o dono solicita, ou envia a cada 30s, conforme o que for melhor para o dono do pet.
>
> Estado de carregamento: Quando alimentado ao carregador, é gerado uma interrupção e a coleira fica no estado de carregando.

## Descrição Estrutural do Sistema

O seguinte projeto tem como objetivo monitorar com recorrência  a localização de um pet. A primeira parte iterativa com usuario, sera feita através de um app para celulares. O processamento sera feito com modulo lora e modulo arudino sendo o microcontrolador, recebendo a comunicação continuamente, caso a comunicação pare será emitido sinais de led e vibra. 

## Especificações

### Especificação Estrutural

![Diagrama sem nome drawio](https://user-images.githubusercontent.com/91965153/198913517-3fd4e910-e93b-464a-a269-afabd49308bb.png)

### Especificação de Algoritmos 


>
## Referências
> https://www.electronica-pt.com/radio-frequencia

> https://appinventor.mit.edu/

> https://blog.novaeletronica.com.br/circuito-receptor-e-transmissor-de-dados-de-baixo-custo/

> https://www.youtube.com/watch?v=6l2XSbG7_Gg&ab_channel=YourWildLifeProject

> https://makezine.com/projects/gps-cat-tracker-2/

