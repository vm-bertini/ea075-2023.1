# `Sistema de Irrigação Automático`
# `Automated Irrigation System`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Membros da equipe:
> |Nome  | RA | Curso|
> |--|--|--|
> | Lucas Lobato Ciciliato  | 220817  | Desenvolvimento de hardware |
> | Deivit Lopes Bonach  | 166508  | Desenvolvimento de software |


## Descrição do Projeto
> Com o crescimento da procura por uma alimentação saudável com vegetais orgânicos e livres de pesticidas, este projeto tem o seu público alvo para pessoas que
> gostariam de desenvolver sua própria horta caseira como um hobby, mas não possuem tanto tempo para poder tomar conta. Além de ser automático, a irrigação por
> gotejamento é uma boa forma de gastar menos água por evaporação, o que diminui o custo da conta de água. 
> Esse sistema irriga e deposita adubo em plantas de uma horta caseira por gotejamento. Ele é baseado em uma central onde fica armazenado o adubo líquido
> ou fertilizante e a água para irrigação. Nesta central, o usuário pode setar as configurações da irrigação.
> Dessa central saem canos para a horta, e ele possui um injetor pra colocar fertilizante ou adubo na água. 
> Além disso, o sistema possuí dois sensores de pressão para monitorar a capacidade de água e
> adubo líquido restante (caso não seja possível deixar uma torneira conectada no sistema). Nos canos existem furos intermediários que podem ser acionados de maneira independentes para irrigar partes específicas da horta.
>

## Descrição Funcional

### Funcionalidades
> Irrigar a horta em determinados intervalos com certo volume de água, definidos pelo usuário
> Manter o solo com um certo nível de umidade para a raiz do vegetal
> Adubação ou fertilização líquida do solo automático
> Medidor de água e adubo líquido/fertilizante restante
> Medidor do nível de bateria

### Configurabilidade
> Volume de água
> Intervalo entre irrigações
> Nível de umidade do solo
> Volume de adubo ou fertilizante
> Local onde será irrigado naquele momento

### Eventos
> Nível baixo de água ou de adubo líquido (não-periódico, vai depender do quanto a planta exige)
> Umidade do solo menor do que o configurado (não-periódico, ele irá variar muito pois depende do quanto a planta puxa de água e depende
> da temperatura e umidade ambiente)
> Irrigação da horta (periódico, setado pelo usuário)
> Aplicação de adubo líquido (periódico, setado pelo usuário)
> Bateria baixa (não-periódico)

### Tratamento de Eventos
> Nível baixo de água ou de adubo/fertilizante: Enviar uma mensagem via Wi-Fi para o usuário e acender um led (led azul para água e led amarelo para adubo)
> Umidade do solo menor do que o configurado: Gotejar água no solo até atingir o valor setado pelo usuário
> Irrigação da horta: Irrigar a horta com o volume de água no horário determinado pelo usuário
> Aplicação de adubo/fertilizante: Aplicar na água que será gotejada na horta
> Bateria baixa: Enviar uma mensagem via Wi-Fi para o usuário e acender um led (led vermelho)

## Descrição Estrutural do Sistema
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/Lobato-B3313/ea075/1669fc1ca83abd8f34cf037b9d73f4315930ea1e/2022.2/irrigador-horta/images/diagram.svg">

## Especificações

### Especificação Estrutural

> Micro-controlador: [STM32F103CB](https://www.st.com/content/st_com/en/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-mainstream-mcus/stm32f1-series/stm32f103/stm32f103cb.html)

> Modulo-wifi: [ESP8266](https://www.robocore.net/wifi/modulo-wifi-esp8266)

> Sensor-umidade solo: [392-EDUPON-SENLG](https://www.mouser.com/ProductDetail/STEMinds/EDUPON-SENLG?qs=QNEnbhJQKvaVLsRNVVZeYw%3D%3D)

> Regulador de Tensão Linear: [KF50BDT-TR](https://www.st.com/en/power-management/kfxx.html)

> Sensor de pressão: [MP-1.25 ULTRA MINIATURE FLAT PRESSURE SENSOR](https://www.althensensors.com/media/29757/mp-1-25-ultra-miniature-flat-pressure-sensor-en.pdf)

> Bomba de água genérica: [link](https://www.baudaeletronica.com.br/mini-bomba-de-agua-submersivel-5v.html?gclid=CjwKCAjw5P2aBhAlEiwAAdY7dKnaw92g9KBMIXnRh0uPQ8sluj-jkq_YxA1S1TjTgT_wLM4kPu1H9hoCqpYQAvD_BwE)

> O bloco “Sistema de Processamento e Comunicação” será responsável por realizar todo o processamento dos dados. Ele é composto pelo microcontrolador, o módulo Wi-Fi e bateria.  Neste bloco, os dados virão dos sensores de umidade e do reservatório, da tensão restante na bateria, do usuário através da comunicação Wi-Fi. O componente responsável por todo este processamento será um microcontrolador da STMicroelectronics chamado de STM32F103CBT6. O microcontrolador irá comunicar-se com o módulo Wi-Fi regularmente para passar ao usuário o status do irrigador, e por último, ele irá controlar as bombas de água e de fertilizante líquido. O protocolo de comunicação que será usado para comunicar com o módulo Wi-Fi é o UART e para atualizar o display e acionar as bombas será usado pinos GPIO.

> O bloco “Sistema de reservatórios” é responsável por armazenar a água e adubo ou fertilizante líquido e em comunicar para a central de controle a quantidade restante destes recursos em seus respectivos tanques. Ele é composto pelos reservatórios de água e de adubo ou fertilizante líquido.

> O bloco “Sistema de irrigação” é responsável por gotejar os recursos sobre as plantas através de canos e comunicar a central o status da umidade do solo. Ele é composto por duas mini bombas de água, canos e sensores de umidade do solo.

> É importante ressaltar que no circuito do bloco “Sistema de Processamento e Comunicação” terá dois cristais osciladores, um deles é para a frequência das operações do microcontrolador (na faixa de 16MHz) e o outro de frequência menor (na faixa de 32,768kHz) será projetado para operações que irão utilizar o tempo em segundo, que serão necessários no caso do usuário querer setar períodos para acionar a irrigação. Além disso, é bem provável que

### Especificação de Algoritmos 

Algoritmo reservatório de água e adubo
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/Lobato-B3313/ea075/a7f233d5c7e6227305e15914f0450e0f48069358/2022.2/irrigador-horta/images/diagrama_agua.svg">

Algoritmo nível de bateria
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/Lobato-B3313/ea075/a7f233d5c7e6227305e15914f0450e0f48069358/2022.2/irrigador-horta/images/diagrama_bateria.svg">

Algoritmo sistema de irrigação
> <img title="a title" alt="Alt text" src="https://raw.githubusercontent.com/Lobato-B3313/ea075/a7f233d5c7e6227305e15914f0450e0f48069358/2022.2/irrigador-horta/images/diagrama_irrigacao.svg">

## Referências
> Expansão do mercado de produtos organicos [Valor](https://valor.globo.com/empresas/esg/noticia/2022/09/09/de-cosmeticos-a-alimentos-mercado-de-produtos-verdes-esta-em-franca.ghtml)
 
> Como cultivar uma horta caseira [Estadão](https://revistacasaejardim.globo.com/Casa-e-Jardim/Paisagismo/noticia/2022/08/10-dicas-simples-e-certeiras-para-ter-uma-horta-caseira-saudavel.html)

> Irrigation Systems - Automatic Watering Systems [Irrigation Systems](https://www.gardeners.com/how-to/about-snip-n-drip/7886.html)

> DripWorks - How to choose a garden irrigation system [DripWorks](https://www.dripworks.com/blog/how-to-choose-a-garden-irrigation-system)

> DripWorks - Fertilizer Injectors [DripWorks](https://www.dripworks.com/drip-irrigation/fertilizer-injectors)

> Gardena - Automatic Irrigation [Gardena](https://www.gardena.com/int/products/guidance/automatic-irrigation/)
