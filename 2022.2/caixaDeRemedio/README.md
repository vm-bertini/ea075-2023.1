# `Caixa de Remédio` 	
# `Medicine Box`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Gabriel Dante Ferreira Roque  | 197242  | Eng. Elétrica|
> | Fernando Teodoro de Cillo | 197029  | Eng. Elétrica|


## Arquivos Importantes 

>[Esquemático em PDF](https://github.com/danteroque/ea075/blob/main/2022.2/caixaDeRemedio/pdf/esquematico.pdf)
>
>[Lista de Componentes](https://github.com/danteroque/ea075/blob/main/2022.2/caixaDeRemedio/components.md)
>
>[PCB](link para imagens/pdf PCB)

## Descrição do Projeto

> A motivação do projeto é criar uma caixa de remédios automática para ajudar as pessoas a não se perderem nos horários de tomar os seus remédios, principalmente pessoas idosas e com perda de memória. Além disso, alguns remédios, como antibióticos, precisam ser tomados nos horários corretos, e todo o tratamento pode não dar certo caso sejam esquecidos. Vale ressaltar, que qualquer pessoa pode utilizar a caixa de remédios automatizada, não somente usuários com perda de memória, pois fornece praticidade para uma tarefa chata do dia a dia.

> Nesse projeto é possível estabelecer um valor econômico visto que muitas pessoas possuem alguém do público alvo do produto na família e se preocupam com seus cuidados. Além disso, acreditamos que o valor de produção seja baixo, o que permite altas margens de lucro para os investidores.


## Descrição Funcional
 
> O conceito envolve um dispositvo que contém dois repositórios para cada dia da semana (total de 14 repositórios), que podem ser programados para abrir nos horários corretos. A programação dos horários dos repositórios é feita através de um interface em que se seleciona qual o dia da semana, se é o repositório número 1 ou 2 daquele dia e o horário.

> Quando chega algum horário programado soa um alarme sonoro e um alarme visual na interface avisando que é horário de tomar algum remédio. Além disso, um atuador abre o repositório correspondente.


### Funcionalidades

> Setar os horários dos alarmes para cada repositório;

> Abrir automaticamente o repositório quando chegar o horário para qual está setado, através de um atuador;

> Soar o alarme sonoro e o visual na interface nos horários programados;

> Possibilidade de abrir o repositório para colocar os remédios e setar o alarme em qualquer horário;

> Possibilidade de escolher qual o alarme sonoro que vai soar;

> Relógio para determinar o horário atual e comparar com os alarmes setados.


### Configurabilidade
> O circuito precisará de: 

> uma memória para salvar os horários dos alarmes, os repositórios e os alarmes sonoros; 

> um microcontrolador para gerir as relações entre cada parte do circuito; 

> 14 atuadores para poder abrir e fechar os repositórios;

> uma interface para o usuário programar os alarmes;

> um alto-falante para emitir os alarmes sonoros;

> um relógio; 

> uma fonte conectada à rede elétrica para energizar o sistema.


### Eventos

> Um evento aperiódico é a programação dos horários de cada alarme.

> Definir o alarme sonoro também é um evento não-periódico.

> Abrir repositório para colocar remédio.

> Quando der o horário do alarme o repositório deve abrir e soar o alarme sonoro.

> Entender que o repositório ja foi fechado depois do usuário pegar os remédios e assim para de tocar o alarme sonoro.

> Programar o Horário do Relógio (Evento não-periódico).

### Tratamento de Eventos

> Como o evento de programar horários de alarme e data é aperiódico, podemos tratar o evento como uma interrupção para salvar na memória o horário em que foi configurado e o repositório selecionado.

> O evento de seleção de um alarme sonoro vai ser tratado via interrupação, pois é aperiódico. Dessa forma, quando a pessoa fizer a seleção do alarme sonoro pela interface a interrupção irá salvar na memória qual alarme sonoro irá tocar no evento de alarme.

> Como o evento de abrir o repositório para colocar o remédio é aperiódico, a interface irá mandar uma interrupção para abrir o repositório indicado pelo usuário. Após o fechamento o usuário irá selecionar na interface que o repositório já foi fechado.

> Para tratar o evento de alarme para tomar o remédio o sistema irá ficar em pooling comparando o horário e o dia do relógio atual com os horários e dias configurados na memória. Dessa forma, quando o horário e dia forem iguais ao da memória, o atuador irá abrir o repositório selecionado para o alarme e irá tocar o alarme sonoro escolhido.

> Depois que a pessoa pegar o remédio ela irá fechar o repositório. Dessa forma, a pessoa clicará na interface que já tomou o remédio, assim os sistema irá parar de tocar o alarme sonoro e voltará para estado de pooling.

> Como o evento de programar o horário do relógio é não-periódico, o sistema irá fazer uma interrupção para configurar o horário do relógio.
 

## Descrição Estrutural do Sistema
![Diagrama Caixa de Remédio](https://github.com/danteroque/ea075/blob/e8cf4e6888c433116a8870814cff056a95bfb77b/2022.2/caixaDeRemedio/Diagrama.drawio.png)

> Precisa-se de uma memória para salvar os horários e os respectivos repositórios dos alarmes. Na memória também ficarão salvos os possíveis toques dos alarmes, que podem ser selecionados na interface, e qual deles deve ser soado.

> O microcontrolador será responsável por toda a lógica realizada, como comparar o horário atual do relógio com os horários setados para os alarmes. O microcontrolador também será utilizado para escrever na memória os horários e os respectivos repositórios setados na interface e por informar ao relógio qual o horário atual na inicialização do sistema. Quando a interrupção do alarme tocar, o microcontrolador ativa o alto-falante e dispara uma mensagem na interface, além de ativar o atuador do repositório respectivo àquele alarme.

> O relógio marca a hora atual.

> Os atuadores abrem o seu respectivo repositório durante o tratamento da interrupção de alarme ou podem ser abertos pela interface para colocar os remédios na caixa.

> O alto-falante (Buzzer) soa durante a interrupção de alarme e para de tocar quando o usuário informar na interface que já tomou os remédios. O toque do alto-falante (Buzzer) é informado pelo microcontrolador e guardado na memória.

> A interface permite ao usuário configurar os horários de alarme de cada repositório, selecionar o toque do alarme sonoro e desativá-lo quando o repositório for fechado. A programação do relógio após a inicialização do sistema também é feita pela interface.

## Especificações

### Especificação Estrutural

### Atuadores

> Será utilizado um multiplexador 16x4 para que o processador possa controlar os atuadores utilizando menos pinos. Vale ressaltar que o multiplexador tem 16 saidas e temos 14 atuadores. Dessa forma, um estado do multiplexador vai ser utilizado como modo espera até que realmente o processador comande a abertura de algum atuador. 
> Os atuadores serão eletroímãs cilíndricos de sucção de 8mm, operando em tensão de 3 V, ativo (fechado) em nível lógico alto.

### Interface

> A interface será  composta por um display LCD e um teclado. O display LCD 16x2 é compatível com o padrão Hitachi HD44780U e será conectado a um adaptador I2C para se comunicar com o microcontrolador. O teclado utilizado será um teclado matricial de 3 colunas e 4 linhas, com um pino controlando cada linha e um para cada coluna, totalizando 7.

### Auto-falante/Buzzer

> O alarme sonoro será um buzzer DA03 de 3.3 V ativo alto da marca CDR01, que suporta correntes menores que 25 mA.

### Microcontrolador e Relógio

> O microcontrolador utilizado será um ATmega328P. O relógio será implementado por código, dessa forma, vamos utilizar o próprio software para a realização dessa estrutura no sistema.

### Memória

>
> O tamanho da memória necessária pode ser estimado por comparação com um projeto similar, um alarme programável projetado para o microcontrolador Kinetis KL25Z128, da Freescale, disponível em https://github.com/fernandocillo/EA871/blob/main/alarme-final.zip. Este projeto de alarme consome 17 Kbytes de memória flash e 2Kbytes de memória RAM. 
>
> Como a Caixa de Remédios tem algumas intruções adicionais relativas à abertura dos compartimentos e as músicas selecionáveis para o alarme serão armazenadas na memória (em forma de sequências de notas associadas à frequência, que pode ser controlada através da tensão enviada por PWM ao buzzer), serão necessários em torno de 20 Kbytes de memória flash. Um módulo de memória flash de 32 Kbytes concede uma larga margem para a aplicação. Vamos usar a própria memória flash do microcontrolador que possui 32 kbytes.
> 
> Além disso, há a necessidade de, durante a execução do programa, registrar o dia e horário atual, o dia e horário de cada um dos 14 compartimentos e a música selecionada para o alarme. Isso significa que o consumo de memória RAM será bem maior que do projeto de alarme, que deve ser suprida com tranquilidade por um módulo de memória RAM de 2 Kbytes.

### Especificação das restrições físicas e ambientais de funcionamento do circuito

> Imaginamos que para esse projeto devemos ter uma caixa com quatorze divisões possuindo um tamanho de 10cmx35cmx10cm, sendo suficientes para colocar os remédios e os atuadores em cima de cada repositório. Cada repositório terá um tamanho de 5cmx5xm.
>
> Sobre restrições ambientais, recomendamos que a caixa de remédio fique em locais frescos e arejados, com baixa incidência solar e, de preferência, com baixa umidade, para preservar os remédios.
>
> Vale ressaltar que não precisamos nos preocupar muito com dissipação de calor, visto que os componenentes utilizados não possuem grandes potências, além disso, os atuadores são metálicos, ajudando assim na dissipação do calor.


### Especificação de Algoritmos 

### Diagrama Main
![Diagrama Main](https://github.com/danteroque/ea075/blob/main/2022.2/caixaDeRemedio/Diagrama_main.drawio.png)

## Interrupções
![Diagrama Interrupções](https://github.com/danteroque/ea075/blob/main/2022.2/caixaDeRemedio/dia_int.drawio.png)

## Referências
[1] https://www.tecmundo.com.br/produto/142311-porta-remedios-inteligente-avisa-usuarios-tomar-medicamento.htm

[2] https://tecnosenior.com/dispensador-de-medicamentos-automatico/

[3] https://www.eletrogate.com/display-lcd-16x2-com-backlight-verde?utm_source=Site&utm_medium=GoogleMerchant&utm_campaign=GoogleMerchant

[4] https://www.casadarobotica.com/robotica/atuadores/outros/3x-buzzer-5v-ativo

[5] https://pt.aliexpress.com/item/32652790510.html?UTABTest=aliabtest343279_484914&_randl_currency=BRL&_randl_shipto=BR&src=google&src=google&albch=shopping&acnt=768-202-3196&slnk=&plac=&mtctp=&albbt=Google_7_shopping&isSmbAutoCall=false&needSmbHouyi=false&albcp=18265403963&albag=&trgt=&crea=pt32652790510&netw=x&device=c&albpg=&albpd=pt32652790510&gclid=Cj0KCQjwnvOaBhDTARIsAJf8eVOsHYZP6gvAff69Z34DvzMRyWPaaTfNbtYgujTt67OWACp4CXFOQ2waAqfDEALw_wcB&gclsrc=aw.ds&aff_fcid=8dc6da2d43ff40e4bf5b44c3ff39803e-1667051125100-04959-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=8dc6da2d43ff40e4bf5b44c3ff39803e-1667051125100-04959-UneMJZVf&terminal_id=d1aaf1f986c7418bbeef73196755d327&OLP=1084400108_f_group0&o_s_id=1084400108&afSmartRedirect=y

