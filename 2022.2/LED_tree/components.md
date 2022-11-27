## Componentes 🔌

A seguir serão listados todos os componentes utilizados para o desenvolvimento do projeto.

- 1 Microcrontrolador PIC 16F689 ➡️ [Datasheet](https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/datasheets/PIC16F689_datasheet.pdf)
- 1 Botão ➡️ [Datasheet](https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/datasheets/botao_datasheet.pdf)
- 1 Piezo Buzzer ➡️ [Datasheet](https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/datasheets/buzzer_datasheet.pdf)
- LEDS    
  - 3 vermelhos
  - 3 verdes
  - 3 amarelos
  - 3 brancos
- 1 Transistor bipolar BC548 ➡️ [Datasheet](https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/datasheets/transistor_datasheet.pdf)
- Resistores
  - 4 resistores de 300 ohms
  - 1 resistor de 1 kohm
  - 1 resistor de 100 ohms
  - 1 resistor de 47 kohms
- Capacitor
  - 1 capacitor de 100 nF
- 3 Pilhas AAA
- 1 Suporte para pilha
---
### Justificativa 🤔

Inicialmente definimos como unidade controladora o PIC16F689 não só pelo seu custo benefício mas também por possuir pinos de interrupção e de PWM, bem como quantidade de memória suficiente para o projeto. Como a tensão de alimentação do PIC varia entre 2V e 5,5V escolhemos como forma de alimentação 3 pilhas de 1,5V cada o que resulta em uma tensão final de 4,5V.

O projeto conta com uma pequena produção sonora de músicas natalinas que serão produzidas através do buzzer. Assim, como desejamos gerar notas musicais distintas foi necessário escolher um buzzer do tipo piezoelétrico ou passivo que permite controlar os sons por meio da frequência. Dessa forma, é esperado que o microcontrolador tenha entradas PWM para a conexão do buzzer. Além disso, de acordo com o [datasheet](https://github.com/juliaplazari/ea075/blob/main/2022.2/LED_tree/datasheets/buzzer_datasheet.pdf) é recomendado que o buzzer seja conectado ao microcontrolador por meio de um transistor. A escolha de tal componente foi feita considerando a disponibilidade no almoxarifado da FEEC e o uso na disciplina EE531. Outro ponto de dastaque foi que o valor da resistência de base do transistor foi feita com base nesse [vídeo](https://www.youtube.com/watch?v=0NUCJKtmzYQ&ab_channel=WRKits).

Ademais, as músicas só serão tocadas quando o usuário apertar um botão. E para garantir o correto funcionamento do botão um pequeno circuito de debounce será montado por meio de resistores (100 ohms e 47 kohms) e um capacitor (1 nF). Tais valores foram obtidos consultando o seguinte [site](https://www.newtoncbraga.com.br/index.php/microcontrolador/143-tecnologia/16303-problemas-de-repique-como-resolver-mic202). Note que o botão será conectado a um pino de interrupção do microcontrolador.

Por fim, a iluminação da árvore de natal se dará pelos LEDS. Para isso, foi necessário o calculo de resistências para limitar a corrente que circula pelos LEDS e evitar a queima do componente. A tabela abaixo mostra a tensão e corrente para cada cor de LED.

Cor  | Valor da Tensão (V) | Valor da Corrente (mA)|
|--|--|--|
| 🔴Vermelho | 1,8 - 2 | 20 |
| 🟢Verde    | 2 - 2,5 | 20 |
| 🟡Amarelo  | 1,8 - 2 | 20 |
| ⚪Branco   | 2,5 - 3 | 20 |

O valor da resistência pode ser encontrado de acordo com a lei de ohm, isto é, subtraindo a tensão de alimentação pela máxima tensão suportada pelo LED e o resultado dividir pela corrente do LED. Como há várias cores, escolhe-se o maior valor de resistência. No entanto, foi definido o valor de 300 ohms (um pouco acima dos valores calculados), pois isso reduzirá o consumo das pilhas e ainda será suficiente para que os LEDS acendem com um bom brilho. Para mais detalhes de como calcular o valor das resistências o seguinte [site](https://www.mundodaeletrica.com.br/aprenda-como-calcular-resistor-para-led/) pode ser consultado.


