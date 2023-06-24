# `Sismógrafo com comunicação Bluetooth`
# `Seismograph with Bluetooth communication`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Rodrigo Dutra de Freitas Cardoso  | 205513  | Eng. Elétrica|
 | Vinicius de Lima Quadrado  | 225357  | Eng. Elétrica|

## Arquivos Importantes (:warning: NOVO :warning:)

>[Esquemático em PDF](link para imagens/pdf esquemático)
>
>[Lista de Componentes](components.md)
>
>[PCB](link para imagens/pdf PCB)

## Descrição do Projeto

Com o objetivo de prever catástrofes naturais e salvar vidas, os alunos de Engenharia elétrica
da Unicamp, em conjunto com os conhecimentos desenvolvidos na disciplina de Sistemas
Embarcados, criaram um sismógrafo com interface Bluetooth.

O projeto consiste na implementação de um sensor acelerômetro e um chip BLE
(Bluetooth Low Energy) para a coleta de dados de vibração do solo. Esses dados são enviados
para análise na nuvem e geram relatórios em tempo real das ondas causadas por possíveis
terremotos.

O sistema completo que este projeto trata corresponde a beacon sensor responsável por
detectar ondas sísmicas, processar os dados recolhidos e emiti-los via advertisings BLE.
Um beacon receptor coleta esses advertisings dos beacons sensores e envia-os para a nuvem.
No entanto, estamos limitando o escopo do projeto apenas ao beacon sensor.

### **Apoie este projeto**

O diferencial do nosso projeto está na combinação dessas tecnologias avançadas.
Ao utilizar o sensor acelerômetro, podemos capturar com precisão as vibrações do solo,
fornecendo informações valiosas sobre possíveis terremotos iminentes. A interface Bluetooth
permitirá que esses dados sejam transmitidos em tempo real para a nuvem. Lá serão
processados ​​e utilizados para gerar relatórios detalhados das ondas sísmicas.

Ao investir neste projeto, você estará contribuindo para proteção vida humana
e reduzindo danos causados ​​por catástrofes naturais. O foco inicial é no beacon sensor, mas há potencial para expandir o sistema completo incluindo o beacon receptor e integração com a nuvem.

### **Potenciais usuários**

Os públicos-alvo deste projeto são órgãos públicos, como prefeituras e defesa civil, além de empresas que prestam serviços aos governos locais ou regionais.

### **Valor econômico associado**

O valor econômico deste projeto baseia-se nos benefícios da sua aplicação, como proteção ao capital humano e material. Como exemplos, podemos citar:
- Salvaguarda de vidas
- Redução de custos em desastres naturais
- Impacto na indústria seguradora
- Aplicação em pesquisas e estudos científicos


### **Funcionalidades**
 - Beacon sensor
   - Tratar dados crus provenientes dos sensoresß
   - Emitir em advertisings BLE com os dados processados
 - Beacon receptor
   - Receber dados processados de diversos beacons sensores
   - Enviar dados para a nuvem.

### **Configurabilidade**
 O usuário poderá configurar os seguintes itens:
	- frequência com a qual será captadas as oscilações do solo
	- potência de comunicação via Bluetooth
 	- taxa de amostragem das oscilações


### **Eventos**

Os eventos tratados para o sistema serão:

1. Captura das ondas sísmicas
2. Filtragem e processamento dos sinais
3. Emissão dos advertisings contendo os dados tratados

Todos os eventos são periódicos, de frequência **F** a determinar em ensaios. Essa frequência deve ser tal que as frequências de onda mais comuns de eventos sísmicos possam ser detectadas precisamente.

### **Tratamento de Eventos**
 Para tratar os eventos vamos separar em três etapas:
	1 - propagação das ondas Sísmicas são captadas pelo sensor Acelerômetro
	2 - há um pré-tratamento dos dados, de forma que somente os dados considerados válidos serão guardados
	3 - envio dos dados para o beacon receptor 
  
## Descrição Estrutural do Sistema  (:warning: ATUALIZAR :warning:)
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
Esq> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.

![Kiku](Diagrama_projeto_ea075.jpg)

## Especificação estrutural
Este tópico descreve as especificações estruturais do projeto

### **Saídas e entradas do dispositivo**

Este tópico mostra quais são saídas e entradas, e seus respectivos tipos, empregadas neste dispositivo, tão bem 
quanto as entradas e saídas de intercomunicão entre os circuitos integrados.

### **Saídas e entradas para o ambiente**

Teremos três modos de I/O’s, duas cabeadas e uma sem fio.

Cabeadas: 
- SWD (Serial Wired Debug)
  - Através desta será feito a gravação em fábrica do firmware, pois possui acesso direto a memória do microcontrolador.
- SCI (Serial Comunnication Interface)
  - Através desta será usado o protocolo UART para comunicação serial assíncrona.
  - Os dados e funcionalidades disponibilizadas através desta interface serão definidos no firmware do microcontrolador.

Sem fio:
- BLE (Bluetooth Low Energy) 2.4 GHz
  - Através desta interface serão publicados os advertisings BLE contendo os dados processados dos tremores sísmicos medidos.

### **Saídas e entradas para intercomunicação entre circuitos integrados**

Harwired (cabeado na PCB):
- SPI (3 Fios)
  - Através desta será transmitido do acelerômetro para o microcontrolador os dados crús dos tremores sísmicos.ß

### **Componentes principais**
Este tópico descreve os principais componentes utilizados no projeto

### **Microcontrolador**
 Modelo: EFR32BG13P632F512GM32-D

 Datasheet: [EFR32BG13](./datasheet/efr32bg13-datasheet.pdf)

 Este SoC faz parte da família de microcontroladores EFR32BG13, que possui  conectividade Bluetooth Low Energy (BLE) e são baseados na plataforma EFR32 da Silicon Labs. Ele foi projetado para fornecer recursos de comunicação sem fio de baixa energia para aplicações IoT (Internet of Things). 

 Características Elétricas:
  - Tensão de Alimentação: de  1,8 V a 3,8 V de uma fonte única. A ideia inicial é utilizar duas pilhas alcalinas tamanho AA em série, com tensão inicial de 3,2 volts. 
  - Correntes de Operação: A corrente de operação depende dos fatores abaixo:
    - Potência do rádio (Potência usada para emitir advertisings e realizar scans ativos). e frequência de emissão de advertisings.
      - 8.5 mA em TX a 0 dBm de potência em 2,4 GHz
      - 35.3 mA em Tx a 14 dBm de potência em 869 MHz. (Este MCU chega apenas até 10 dBM de potência de saída em rádio).
    - Uso da CPU para rodar o programa
      - 69 μA/MHz em Modo Ativo (EM0 - Energy Mode 0)
    - Modo Sleep:
      - 1.3 μA em EM2 (Energy Mode 2) DeepSleep (Retém 16 kB de RAM e roda RTCC a partir do LFRCO)
        - RTCC ->  Real Time Counter and Calendar
        - LFRCO -> Low-Frequency RC Oscillator
  - Possíveis Interfaces de Comunicação, a decisão é feita no firmware. 
    - Comuns:
      - UART - Universal Asynchronous Receiver/Transmitter
      - SPI - Serial Peripheral Interface
      - I2C - Inter-Integrated Circuit
    - Outras:
      - SmartCard (ISO 7816) - é um padrão internacional relacionado a cartões de identificação eletrônica com contatos,
      - IrDA - (Infrared Data Association)
      - I2S - Equivalente a I2C para sinais digitais de áudio.

 Características Temporais:
  - Taxa de Dados BLE: O módulo suporta uma taxa de dados especificada para comunicação Bluetooth Low Energy, geralmente na faixa de vários kilobits por segundo.
  - Taxa de amostragem do conversor AD: até 1 Msps (1M de amostras por segundo).
  - Taxa de entrada e saída de dados:
    - Bluetooth Low Energy: até 1 Mbps  
    - Interfaces seriais:
      - UART: depende do baudrate, normalmente 115200 bps (padrão) ou 115 Kbps
      - SPI: depende do uso atual das CPU’s e do tamanho da palavra
  - Latência: Cada ciclo de envio por rádio BLE, considerando transmissão nos 3 canais padrões do BLE: 37, 38 e 39; levam em torno de 4 ms para se completar.

 Restrições Físicas:
  - Tamanho e Layout de Pinos:
    - Empacotamento QFN32:
      - Dimensões: 5 x 5 x 0.75 mm
      - Pinos: 32 pinos
  - Configuração de Antenas: Antena tipo F invertida, construída na própria PCB (Printed Circuit Board). Detalhes serão exemplificados em uma sessão dedicada.

### **Sensor Acelerômetro**
Modelo: ADXL345

Datasheet: [ADXL345](./datasheet/adxl345.pdf)

O acelerômetro ADXL345 é um sensor de alta resolução e baixo consumo de energia projetado para medir acelerações em três eixos (x, y e z). Ele utiliza a tecnologia de microeletromecânica (MEMS) para detectar mudanças nas forças de aceleração e converter essas mudanças em um sinal elétrico proporcional.

Características Elétricas:
- Tensão de Alimentação: O acelerômetro ADXL345 opera com uma faixa de tensão especificada, geralmente entre 2.0V e 3.6V, garantindo uma alimentação adequada para seu funcionamento.
- Corrente de Operação: É importante considerar a corrente típica de operação do acelerômetro para dimensionar corretamente a fonte de alimentação e garantir uma eficiência energética adequada.
  - consumo típico de corrente é de cerca de 40 microamperes (µA) a 2,5 volts de alimentação
- Interface de Comunicação: O ADXL345 pode ser configurado para se comunicar por meio de uma interface digital, como I2C ou SPI, permitindo a integração com microcontroladores ou outros dispositivos em seu projeto.

Características Temporais:
- Faixa de Medição: O acelerômetro ADXL345 possui uma faixa de medição especificada para cada um dos três eixos (x, y e z), permitindo a detecção de acelerações em uma determinada escala, como ±2g, ±4g ou ±16g.
- Resolução: É importante considerar a resolução do acelerômetro, que indica a menor mudança de aceleração que pode ser detectada. O ADXL345 possui uma resolução de 10 bits, o que proporciona uma precisão adequada para muitas aplicações.

Restrições Físicas:
- Tamanho e Layout de Pinos: 
  - Dimensões:
    - 3 x 5 x 1 mm
  - Pinos:
    - 14 pinos
- Sensibilidade à Vibração: O acelerômetro é sensível a vibrações externas, portanto, considere medidas adequadas para minimizar interferências indesejadas, como o uso de isoladores mecânicos ou filtros adequados.

### **Antena F invertida**

Construída na própria PCB do dispositivo, comumente conhecida por sua estrutura simples e eficiência de radiação, sendo frequentemente utilizada em aplicações de transmissão e recepção de sinais de rádio.

Documentação Antena F Invertida:
- [Design of 2.4 GHz-Band Meander Planar Inverted F Antenna for Bionic Hand Using DOE Method](https://ieeexplore.ieee.org/document/9501861)
- [Inverted-F antenna](https://en.wikipedia.org/wiki/Inverted-F_antenna)

Modelo: Antena F invertido

Datasheet: [AN1088: Designing with an Inverted-F 2.4 GHz PCB Antenna](./datasheet/an1088-designing-with-pcb-antenna.pdf)

Características Elétricas:
- Faixa de Frequência: A antena F invertida é projetada para operar em uma determinada faixa de frequência, que pode variar dependendo da aplicação específica. Neste caso, seguindo a normas do Bluetooth Core, a operação se dará em 2,4 Ghz.
- Impedância Característica: A antena F invertida geralmente possui uma impedância característica específica, como 50 ohms, que deve ser compatível com o sistema de transmissão/recepção utilizado.

Características Geométricas:
- Sobre as dimensões da antena, o fabricante do microcontrolador recomenda seguir, vide datasheet, as seguintes especificações para a antena tipo F invertido
  - Para PCB FR4 de espessura 0,8mm e 0,062”, referência na imagem 2.1, página 3, do datasheet AN1088 da antena F invertido.


## Especificação de Algoritmos

O algoritmo STFT-WF (Short-Time Fourier Transform com pré-filtragem de Wavelet) é uma técnica que combina a Transformada de Fourier 
de Curta Duração com a pré-filtragem de wavelets para analisar sinais e obter uma representação tempo-frequência mais precisa. 
Este especialmente útil para sinais não-estacionários ou com características espectrais variáveis.

Ao combinar a pré-filtragem de wavelet com a STFT, o algoritmo STFT-WF permite uma análise mais precisa das variações 
espectrais ao longo do tempo, o que proporciona um entendimento detalhado das propriedades temporais e espectrais do sinal. 
Esta abordagem é particularmente valiosa para aplicações que requerem processamento sensível ao tempo e à frequência, tais como 
processamento de sinais de áudio, análise de vibração e processamento sísmico.

Em resumo, o algoritmo STFT-WF pode ser usado para melhorar a precisão da análise tempo-frequência em sinais complexos e é adequado 
para aplicações onde informações detalhadas sobre as propriedades temporais e espectrais são importantes.

O fluxograma para implementação deste algoritmo:
::: mermaid
graph TD
A[Leitura do sinal de entrada] --> B[Aplicar wavelet pre-filtragem]
    B --> C[Dividir o sinal em segmentos sobrepostos]
    C --> D[Aplicar a janela de segmento]
    D --> E[Calcular a Transformada de Fourier de cada segmento]
    E --> F[Geração do espectrograma]
    F --> G[Análise e processamento do espectrograma]
    G --> H[Determinar picos de energia]
    H --> I[Aplicar critérios de picking de fases]
    I --> J[Marcar as fases identificadas]
    J --> L[Obter resultados desejados]
    L --> M[Finalizar]
    G --> K[Refinamento da localização das fases]
    K --> I
:::

O tamanho do algoritmo em memória é estimado entre 4 e 10 kB, a stack Bluetooth Low Energy deve ocupar em torno de 50 kB.
Como o microcontrolador possui 512 kB de flash e 64 kB de RAM, este terá os recursos necessários para a 
implementação da aplicação.

## Referências
Decifrando a Terra. . São Paulo: Companhia Editora Nacional. . Acesso em: 02 abr. 2023. , 2009

Anthony, Robert & Ringler, Adam & Wilson, David & Wolin, Emily. (2018). Os sismógrafos de baixo custo funcionam bem o suficiente para a sua rede? Uma visão geral dos testes de laboratório e observações de campo do Raspberry Shake 4D da OSOP. Seismological Research Letters. 90. 10.1785/0220180251.

Özcebe, A.G.; Tiganescu, A.; Ozer, E.; Negulescu, C.; Galiana-Merino, J.J.; Tubaldi, E.; Toma-Danila, D.; Molina, S.; Kharazian, A.; Bozzoni, F.; et al. Raspberry Shake-Based Rapid Structural Identification of Existing Buildings Subject to Earthquake Ground Motion: The Case Study of Bucharest. Sensors 2022, 22, 4787. https://doi.org/10.3390/s22134787