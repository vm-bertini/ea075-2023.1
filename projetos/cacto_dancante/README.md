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
> O sistema terá um microfone que será usado para gravar áudios que serão reproduzidos de maneira distorcida e engraçada enquanto o boneco dança.

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

## Referências
> Por enquanto não foram utilizadas referências
