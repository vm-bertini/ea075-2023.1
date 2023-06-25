![image](https://github.com/viniandrs/ea075-2023.1/assets/71352251/3107ba8b-86a3-4b2f-965a-61f0eb7baba0)![image](https://github.com/viniandrs/ea075-2023.1/assets/71352251/fde9b561-6cc5-4d23-be14-bc1c45ae9b92)# `Cacto dançante`
# `Dancing cactus`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Vinicius Ventura Andreossi  | 195125  | Eng. Elétrica|
> | Gabriel Machado Severo Mendes  | 234906  | Eng. Elétrica|


## Descrição do Projeto
> Com o intuito de tornar os lares dos estudantes de engenharia elétrica mais descontraídos, utilizaremos os conhecimentos adquiridos 
> na disciplina de Sistemas Embarcados para desenvolver um brinquedo interativo que fará todos os alunos da FEEC dançarem: o cacto dançante. 
> O sistema será capaz de gravar áudios que serão reproduzidos de maneira distorcida e engraçada enquanto o boneco dança.

> Apesar de se tratar de um brinquedo simples, o cacto dançante pode gerar boas risadas quando utilizado com amigos. Além disso, o brinquedo possui um custo bem baixo e acessível.

## Descrição Funcional
> O cacto dançante possuirá os botões "gravar" e "dançar". Para gravar um áudio, basta manter o botão "gravar" pressionado. Ao pressionar o botão dançar,
> o cacto reproduzirá o áudio armazenado em sua memória de maneira distorcida enquanto dois motores o farão rebolar. Caso não tenha nenhum áudio gravado
> na memória do brinquedo, um áudio padrão será reproduzido.

### Funcionalidades
> **Gravador de áudio:** o brinquedo permitirá que o usuário grave sua própria voz cantando ou sua música favorita para o cacto dançar.  
> **Cantar e dançar:** o sistema reproduzirá o áudio gravado com uma voz engraçada enquanto dança.

### Configurabilidade
> O usuário deve gravar um áudio na memória do brinquedo, caso contrário um áudio padrão com o cacto falando "cante uma música para mim!" será 
> reproduzido sem que o brinquedo dance. 

### Eventos
> * **Eventos periódicos:**
> * Enquanto não houver pedido de ações, o controlador se mantem no modo Economia De Energia.
> * LED ligado para identificar que o brinquedo está ligado.

> * **Eventos não-periódicos:**
> * Iniciar gravação
> * Parar a gravação
> * Iniciar a dança
> * Parar a dança

### Tratamento de Eventos
> * Início da gravação: quando o botão gravar for pressionado, o cacto começa a gravar o áudio através do microfone.
> * Parar gravação: quando o botão for solto, o cacto para a gravação e armazena o áudio na memória do dispositivo.
> * Iniciar a dança: quando o botão dançar for pressionado, o cacto reproduzirá o áudio em sua memória de maneira distorcida enquanto dança. Caso não
> possua áudio nenhum em sua memória, um áudio padrão será reproduzido sem que o brinquedo dance.
> * Parar dança: caso o brinquedo comece a dançar, ele irá parar se o botão dançar for pressionado novamente ou após três reproduções completas do áudio.

## Descrição Estrutural do Sistema
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/viniandrs/ea075-2023.1/main/projetos/cacto_dancante/images/diagrama_estrutural.png">

## Especificações

Lista de componentes utilizados:

| Componente  | Quantidade | Função | Datasheet | Preço |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Microcontrolador PIC16C72A  | 1  | Unidade micro-controladora  | Content Cell  | [R$20,00](https://www.acheicomponentes.com.br/circuitos-integrados/dip-pth/dip-28/ci-microcontrolador-pic16c72a-04sp-dip-28) |
| Módulo de motor L9110S | 1 | Módulo de controle do motor  | Content Cell  | [R$20,00](https://www.acheicomponentes.com.br/circuitos-integrados/dip-pth/dip-28/ci-microcontrolador-pic16c72a-04sp-dip-28) |
| Terminal com conector parafuso  | 3 | Conexão a periféricos  | Content Cell  | [R$20,00](https://www.acheicomponentes.com.br/circuitos-integrados/dip-pth/dip-28/ci-microcontrolador-pic16c72a-04sp-dip-28) |
| Módulo cartão Micro-SD SMT MEM2067 | 1 | Interface micro-SD | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Transistor NPN 2N3904 | 1 | Amplificador do microfone | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Potenciômetro | 1 | Ajuste do volume | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Resistores | 13 | - | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Botão TL2230EEF140 | 2 | On/Off | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| LM386N-3/NOPB | 1 | Amplificador da saída de áudio | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Regulador de voltagem AMS1117 | 1 |  | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |




| Módulo microfone KY-038 | 1 | Entrada de áudio  | Content Cell  | [R$10,90](https://www.makerhero.com/produto/sensor-de-som-ky-038-microfone/)  |
| Módulo amplificador de áudio LM386 | 1 | Amplificação da saída de áudio  | Content Cell  | [R$10,36](https://www.eletrogate.com/modulo-amplificador-de-audio-com-lm386) |
| Auto-falante | 1 | Saída de áudio  | Content Cell  | [R$8,46](https://www.eletrogate.com/mini-alto-falante-0.5w-8ohms) |

| Motor DC 1.5-3V | 1 | Atuador | Content Cell  | [R$6,90](https://www.eletrogate.com/mini-motor-dc-15-3v) |
| LEDs | 1 | Indicadores de estado | Content Cell  | []() |
| Botões | 1 | Interface com o usuário | Content Cell  | []() |
| Suporte + 3 pilhas AAA | 1  | Alimentação | Content Cell  | [R$7,00](https://www.multcomercial.com.br/suporte-para-3-pilhas-aaa-com-tampa-e-rabicho-de-15cm-jd15-6039a-jinda.html) (pilhas não inclusas) |

### Especificação estrutural

Para o controle do projeto definiu-se o PIC16C72A que possui 4.5KB de memória, 28 pinos, entradas analógicas além de pinos para comunicação SPI e saída PWM. A escolha foi feita baseando no baixo custo, por ser DIP,
possuir comunicação SPI necessária para a gravação do cartão de memória e um PWM de resolução 10-bit que atende ao controle do motor. 

A alimentação do microcontrolador serão utilizados 3 pilhas AAA de 1,5V cada totalizando uma tensão de 4,5V.

Na sequência serão tratados os blocos de funcionamento do cricuito do Cacto Dançarino.
Abaixo está todo o esquemático do projeto, para acompanhar o funcionamento de cada bloco (que foram colocados separados para melhor visualização).
> <img title="a title" alt="Alt text" src="https://github.com/viniandrs/ea075-2023.1/blob/main/projetos/cacto_dancante/images/EsquematicoCacto.png">

### Debounce
Para evitar que ocorra o efeito de repique (as oscilações que podem comprometer o correto funcionamento das interrupções) nos botões de gravação e reprodução, foram colocados um resistor de 10K e um capacitor de 
0.1uF com o intuito de suavizar a transiçãode niveis lógicos. Assim evitará o efeito do debounce.

### Entrada e saída de áudio
Na entrada de áudio foi colocado um heade qque será conectado ao microfone. Este Header está ligado em um circuito amplificador de sinal utilizando um transistor do tipo TBJ e filtros capacitivos.
O sinal amplificado está ligado na entrada analógica do controlador, que a partir dela salvará no cartão.
A saída de áudio é um PWM modulado de forma a reproduzir o áudio WMV que foi salvo no cartão pelo PIC. O PWM passa por um amplificador operacional antes de ssair no alto-falante, para passar
por um processo de amplificação de áudio.


### Controle do motor
O motor não precisa de um controle fino no seu movimento, então a saída do PWM foi ligada na entrada de sinal de uma ponte H que i´ra controlar a rotacão do motor
de acordo com o áudio reproduzido. 

### Cartão SD
Para o cartão SD escolheu-se um adaptador que liga as conecxões do cartão até entradas e saídas do PIC. Para ser feita a escrita e leitura opotou-se pela comunicação SPI
ao invés da comunicação em paralelo, visto qque essa já tem bibliotecas implementadas além de apresentar menos conectores. 


### Especificação de algoritmos
> <img title="a title" alt="Alt text" src="https://github.com/viniandrs/ea075-2023.1/blob/main/projetos/cacto_dancante/images/especificacao_software.png">


> * Iniciar gravação
> * Parar a gravação
> * Iniciar a dança
> * Parar a dança


## Referências
> [1] https://github.com/thisissihab/arduino-based-digital-voice-recorder/tree/main
