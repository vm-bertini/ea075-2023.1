# `Cacto dançante`
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
| Módulo microfone KY-038 | 1 | Entrada de áudio  | Content Cell  | [R$10,90](https://www.makerhero.com/produto/sensor-de-som-ky-038-microfone/)  |
| Módulo amplificador de áudio LM386 | 1 | Amplificação da saída de áudio  | Content Cell  | [R$10,36](https://www.eletrogate.com/modulo-amplificador-de-audio-com-lm386) |
| Auto-falante | 1 | Saída de áudio  | Content Cell  | [R$8,46](https://www.eletrogate.com/mini-alto-falante-0.5w-8ohms) |
| Módulo cartão Micro-SD | 1  | Armazenamento dos áudios gravados pelo usuário | Content Cell  | [R$8,90](https://www.makerhero.com/produto/modulo-cartao-micro-sd/)  |
| Motor DC 1.5-3V | 1 | Atuador | Content Cell  | [R$6,90](https://www.eletrogate.com/mini-motor-dc-15-3v) |
| LEDs | 1 | Indicadores de estado | Content Cell  | []() |
| Botões | 1 | Interface com o usuário | Content Cell  | []() |
| Suporte + 3 pilhas AAA | 1  | Alimentação | Content Cell  | [R$7,00](https://www.multcomercial.com.br/suporte-para-3-pilhas-aaa-com-tampa-e-rabicho-de-15cm-jd15-6039a-jinda.html) (pilhas não inclusas) |

### Especificação estrutural

### Especificação de algoritmos
> <img title="a title" alt="Alt text" src="https://github.com/viniandrs/ea075-2023.1/blob/main/projetos/cacto_dancante/images/especificacao_software.png">


> * Iniciar gravação
> * Parar a gravação
> * Iniciar a dança
> * Parar a dança


## Referências
> [1] https://github.com/thisissihab/arduino-based-digital-voice-recorder/tree/main
