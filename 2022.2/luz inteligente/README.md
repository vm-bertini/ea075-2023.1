# `Luz Inteligente`
# `<Smart Light>` 

## Apresentação

Projeto originado das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
Disciplina oferecida pela Profa. Dra. Paula Dornhofer Paro Costa, no segundo semestre de 2022.

|Nome | RA | Curso |
|--|--|--|
| Bruno Vinicius Barros da Silva | 214083 | Eng. Elétrica |
| M Kamel Zinou  | 161534 | Eng. Elétrica |

## Arquivos Importantes

- O src do projeto se encontra zipado (src.zip).
- As imagens relevantes e a visão 3D do projeto se encontra na pasta Images.
- Os arquivos contendo as furações se encontram na pasta gerber.

## Descrição do Projeto

O aparelho Luz Inteligente consiste em um sistema embarcado cujo objetivo é ligar ou desligar as luzes de um ou mais ambientes de maneira mais prática, sem a necessidade de um interruptor, sendo apenas necessário estar no ambiente e bater palmas para ligar ou desligar as luzes, visando o menor esforço do consumidor. 
O aparelho Luz Inteligente possui um sistema de economia de energia, visto que o mesmo também conta com uma desligada de luz programada caso não haja ninguém no ambiente por um certo período de tempo.
O melhor é que o mesmo é pequeno e pode ser instalado em qualquer lugar do ambiente. E tudo isso por um ótimo preço!

## Descrição Funcional

Será um sistema que ligará ou desligará a luz de um cômodo da casa, a partir de palmas ou presença, contando quanto tempo a luz ficou ligada durante o mês atual.
Retiramos a parte de cálculo sobre o preço pois optamos por um microcontrolador mais em conta para o projeto, pois, apenas para o controle do LCD estavamos precisando de metade das entradas utilizadas. O mesmo continua com o plano de calcular a energia, apenas não exibirá em um LCD, podendo ser implementado algum componente capaz de enviar os dados para um computador ou celular.
O cronômetro será feito via código, de modo que haverá um contador via software que será disparado a cada vez que o mesmo deixar de observar a presença de alguém, e será reiniciado via interrupção caso recebe algum sinal.

### Funcionalidades

- **liga/desliga a luz**: o sistema sera capaz de alterar o estado da luz ao perceber que alguém está no ambiente e ouvir palmas.
- **Desliga por inatividade**: o sistema irá desligar altomaticamente após 5 minutos sem ninguém no ambiente.
- **Cálculo de tempo ativo**: o sistema calculará o tempo que a luz ficou ativa durante o mês.
- **Cálculo de conta de energia**:O sistema calculará a conta de energia através do tempo ativo.

### Configurabilidade

O ideal do projeto é ser plug-and-play, ou seja, não há necessidade de configurabilidade, logo após a instalação, o mesmo está pronto para o uso (necessita de alimentação).

### Eventos e Tratamentos

- O sistema deve detectar a presença de uma pessoa para funcionar.
- Receber o sinal sonoro para alterar o estado atual da luz.
- Ao acender a luz, continuar o cronômetro.
- Ao desligar a luz, parar o cronômetro e gravar o tempo na memória, calcular o gasto de energia e gravar na memória.
- Ao iniciar um novo mês, zerar o cronômetro.
- Caso o sistema não detecte nenhuma presença após 5 minutos, desligará a luz.

## Descrição Estrutural do Sistema

- Inicialmente o sistema começa relé desligado esperando pela ativação simultânea do sensor de presença e o sensor sonoro.
- Após ativação simultânea dos sensores caso a luz esteja desligada, o timer do cronômetro e a luz serão ligados.
- Caso a luz esteja ligada durante a ativação simultânea dos sensores, o timer do cronômetro e a luz serão desligados. 
- Caso a luz esteja ligada e o sensor não observou nenhuma presença durante cinco minutos, o timer do cronômetro e a luz serão desligados.
- Sempre que o cronômetro for desligado, o sistema calcalará o valor da conta de energia e exibirá juntamente com o tempo de atividade da luz (mensal).

## Especificações

O sistema consiste em 3 componentes principais que trabalham em conjunto para atender os requisitos do projeto, sendo eles:

- Sensor Sonoro (KY-037) que possui quatro entradas/saídas, sendo as duas do meio para alimentação VDD e GND, e as duas exteriores para saída, sendo uma digital e outra analógica. Para o projeto utilizaremos apenas a saída analógica.
- Sensor de Presença (HC-SR501) que possui três entradas/saídas, sendo as duas exteriores para alimentação, e a do meio para saída, sendo a mesma analógica.
- Microcontrolador (ESP8285) foi escolhido pois atende o requisito de ser mais em conta e simples, entregando a alimentação correta para os sensores (3.3V) e possuindo pinos de E/S GPIO. O mesmo poderá ser integrado à rede Wi-Fi posteriormente.

Para a instalação, certifique-se que o sensor de presença esteja visualizando todo o ambiente, e que o sensor sonoro não esteja sendo abafado.
Mantenha-os de preferência nos cantos dos ambientes, para uma melhor visualização dos sensores.
A alimentação do circuito deverá ser de 5V.

## Estrutura do Sistema

- **Estrutura Inicial Proposta:**
![DIAGRAMA-EA075](https://user-images.githubusercontent.com/112783871/199125714-ed989c85-57b7-41f3-ab7e-61b6ba271a6a.png)

- **Visão 3D:**
![luz_inteligente_3D](https://user-images.githubusercontent.com/73912017/204940767-647e4c15-a11e-4e04-b0d9-0c7c618618fe.png)

## Referências

- **Sensor Sonoro**: https://datasheetspdf.com/pdf-file/1402047/Joy-IT/KY-037/1
- **Sensor Presença**: https://www.epitran.it/ebayDrive/datasheet/44.pdf
- **Microcontrolador**: https://www.espressif.com/sites/default/files/documentation/0a-esp8285_datasheet_en.pdf
 

