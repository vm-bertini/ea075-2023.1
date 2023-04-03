# Sensor de Qualidade de Água
# Water Quality Sensor

## Apresentação
O presente projeto foi originado no contexto das atividades da disciplina de graduação EA075 – Sistemas Embarcados, oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).
O desenvolvimento será realizado pelos seguintes alunos:
Nome	RA	Curso
Rafael Ifanger Ribeiro       250499 Eng. Automação
Vicente José Campitelli Real 239834 Eng. Computação

## Descrição do Projeto
O presente projeto destina-se a desenvolver um sensor que analise a qualidade da água em fluxo por um conduto, permitindo sua classificação em relação às possíveis aplicações desejadas, sejam elas provenientes de quaisquer fontes, como:
•	Captação de águas pluviais;
•	Efluentes (industriais, domésticos etc.);
•	Corpos hídricos;
•	Etc.

## Utilizações possíveis
A partir do conjunto adequado de sensores e do desenvolvimento do firmware correspondente, o sistema proposto poderá ser utilizado em diversas aplicações, como, por exemplo: análise de água de aquário, destinação adequada de águas pluviais, análise de qualidade de corpos hídricos e definição do tratamento e destinação corretas de efluentes industriais em tempo real.
O projeto será desenvolvido visando o aproveitamento de águas pluviais em uma residências, devido a perspectiva de implementação prática imediata, sem envolver outros agentes externos ao desenvolvimento e a possiblidade de multiplicação da aplicação beneficiando a comunidade no entorno da Unicamp.

## Motivação
A destinação adequada dos recursos de água doce é de tamanha importância na busca de uma economia sustável que foi escolhido para compor o capítulo 18 da Agenda 21. De modo coerente às recomendações da Agenda, em 21 de fevereiro de 1993, a Assembleia Geral da Organização das Nações Unidas, declarou o dia 22 de março como o “Dia Mundial da Água”. De acordo com a Wikipédia:
A cada ano, uma agência diferente das Nações Unidas produz um kit para imprensa sobre o DMA que é distribuído nas redes de agências contatadas. Este kit tem como objetivos, além de focar a atenção nas necessidades, entre outras, de:
Tocar assuntos relacionados a problemas de abastecimento de água potável;
Aumentar a consciência pública sobre a importância de conservação, preservação e proteção da água, fontes e suprimentos de água potável;
Aumentar a consciência dos governos, de agências internacionais, organizações não governamentais e setor privado;
Promover campanhas sobre a importância da água.
Portanto as sociedades já tomaram consciência que a água é um recurso a ser preservado e corretamente utilizado, justificando o projeto em tela.

## Regulamentação aplicável
No Brasil, a Agência Nacional de Águas (ANA), publicou os Indicadores de Qualidade das Águas (IQA) para avaliar a qualidade da água bruta (água não tratada), adotando a sistemática que vinha sendo utilizada pela CETESB (Companhia Ambiental do Estado de São Paulo) desde 1975 (criado pela National Sanitation Foundation dos Estados em 1970). A composição do IQA está listada na tabela 1:
![image](https://user-images.githubusercontent.com/86883576/229387705-6212b3b1-538a-4138-b65f-1a2d739d79bf.png)

Tabela 1: Indicadores de Qualidade das Águas (IQA) – fonte ANA

Conforme observado, na tabela 1, os IQA são nove parâmetros com respectivos pesos.
A publicação traz, ainda, o valor de qualidade em função da concentração de cada parâmetro, conforme figura 1:
![image](https://user-images.githubusercontent.com/86883576/229387739-ec50dd09-3e0c-447a-9ee0-07b0c7c74ea6.png)

Figura 1: Qualidade da Água em Cada Parâmetro do IQA – fonte ANA

A Agência reconhece as limitações de tal sistemática, posto que não são observados outros parâmetros importantes para o abastecimento, como o teor de substâncias tóxicas (pesticidas, metais pesados etc.) e agentes patogênicos entre outros.
Considerando as várias possiblidades de utilização das águas, o Conselho Nacional do Meio Ambiente-CONAMA, publicou a Resolução CONAMA nº 357, de 17 de março de 2005, que “dispõe sobre a classificação e diretrizes ambientais para o enquadramento dos corpos de água superficiais, bem como estabelece as condições e padrões de lançamento de efluentes”. Tal regulamentação classifica as águas doces, salinas e salobras em classes adequadas à diversas finalidades e amplia os parâmetros utilizados para tal classificação indicando, por exemplo, teores limites de contaminantes (orgânicos e inorgânicos) para os diversos usos.

## Descrição Funcional
Os componentes principais de hardware serão um processador, os sensores, o atuador e os leds indicativos de qualidade da água (satisfatória ou não).
O firmware será desenvolvido em linguagem C. Ele possibilitará a parametrização para as diversas aplicações, entretanto o desenvolvimento pleno será realizado para água pluvial, conforme item anterior.
O protótipo será montado para análise dos parâmetros de turbidez, pH. Serão, ainda, registradas as leituras de temperatura e vazão.
Após a determinação da qualidade da água o fluxo será direcionado adequadamente por uma válvula de duas vias.
 ![image](https://user-images.githubusercontent.com/86883576/229387759-a90bdc5c-de45-4e76-be83-720aca4c6e24.png)
 
Figura 2: Fluxograma funcional do sistema – elaboração própria

## Funcionalidades
A funcionalidade básica do sistema é detectar a qualidade da água a partir de sensores e processamento dos dados por um microcontrolador.
Desse modo, utilizando o sistema operacional de tempo real FreeRTOS, o sistema recolherá periodicamente os valores de sensores como de pH, turbidez e temperatura (estes serão implementados no protótipo). Tais sensores têm o propósito de fornecer a leitura dos parâmetros que determinam a qualidade da água. No protótipo serão escolhidos aqueles que apresentam baixo custo e fácil implementação, porém, em aplicações industriais, outros sensores poderão ser mais adequados.
Armazenando as entradas, o sistema (microcontrolador), a partir de limiares de qualidade estabelecidos, definirá se a água do fluxo analisado está dentro ou fora do aceitável.
Se a qualidade for aceita, com uma válvula de duas vias, o fluxo é direcionado para a aplicação estabelecida. Em caso contrário o fluxo é desviado para descarte, ou armazenado, para uma análise mais detalhada, laboratorial, e sua destinação adequada.

##Configurabilidade
Como citado, o sistema deverá ser configurado para a aplicação a que se destinar, que no caso em desenvolvimento, será o aproveitamento de águas pluviais. Portanto os parâmetros de determinam a qualidade da água devem ser configurados para a aplicação.
Outras configurações do sistema são o período de leitura dos sensores, podendo diminuir ou aumentar a periodicidade entre as leituras de cada sensor, para formar o log de eventos de acordo com a demanda da aplicação.
Tais configurações serão realizadas por software.

## Eventos
Os eventos serão gerados pelo confronto entre os dados aquisitados, pelos sensores, com os parâmetros de qualidade de água. Tais comparações irão determinar o destino do fluxo de água e serão acumulados em log de eventos. Não haverá eventos externos além dos gerados pelos sensores.
Poderá ser adicionada a configuração dos limiares com um teclado em versão futura, possibilitando maior flexibilidade ao sistema. Neste caso, o evento de configuração por teclado matricial, este evento será não periódico.

## Tratamento de Eventos
Para o evento de recepção dos dados dos sensores, o tratamento será feito por uma tarefa periódica, que, ao longo de um tempo t, deve colher n amostras de modo que, periodicamente de T em T segundos, execute a leitura para armazenamento e tratamento dos dados. O tratamento dos dados será feito por uma outra tarefa não periódica.
A qualidade da água definida pelo sistema será apresentada por um display.
Caso seja implementada a configuração por teclado matricial, o tratamento será interrompido.
O microcontrolador que se deseja utilizar (ESP32 possui dois núcleos).

## Descrição Estrutural do Sistema
O sistema é composto pelas seguintes partes:
- Microcontrolador;
- Sensores (todos intrusivos): pH, turbidez, temperatura, vazão, presença de gases;
- Atuador: válvula de duas vias;
- Leds indicadores de qualidade da água.
Os sensores, a exceção do sensor de gás, serão montados em um caráter que será colocado na tubulação por onde passa o fluxo de água. O sensor de gás será colocado em uma derivação adequada que impeça a perda de água.
A válvula de duas vias será colocada após o carretel dos sensores de modo a desviar o fluxo que foi analisado.

## Glossário
Agenda 21: foi um dos principais resultados da conferência Eco-92 ou Rio-92, ocorrida no Rio de Janeiro, Brasil, em 1992. É um documento que estabeleceu a importância de cada país a se comprometer a refletir, global e localmente, sobre a forma pela qual governos, empresas, organizações não-governamentais e todos os setores da sociedade poderiam cooperar no estudo de soluções para os problemas socioambientais (fonte Wikipédia).

## Referências
Agência Nacional das águas (ANA): Indicadores de Qualidade das Águas (IQA), disponível em http://pnqa.ana.gov.br/indicadores-indice-aguas.aspx, consulta em 15.mar.2023
Conselho Nacional do Meio Ambiente-CONAMA: Resolução CONAMA nº 357, de 17 de março de 2005, disponível em https://www.mpf.mp.br/atuacao-tematica/ccr4/dados-da-atuacao/projetos/qualidade-da-agua/legislacao/resolucoes/resolucao-conama-no-357-de-17-de-marco-de-2005/view#:~:text=Disp%C3%B5e%20sobre%20a%20classifica%C3%A7%C3%A3o%20dos,efluentes%2C%20e%20d%C3%A1%20outras%20provid%C3%AAncias, consulta em 15.mar.2023
Wikipédia: Dia Mundial da Água, disponível em https://pt.wikipedia.org/wiki/Dia_Mundial_da_%C3%81gua#:~:text=O%20Dia%20Mundial%20da%20%C3%81gua,com%20as%20recomenda%C3%A7%C3%B5es%20da%20Confer%C3%AAncia, consulta em 15.mar.2023
_______ Agenda 21, disponível em https://pt.wikipedia.org/wiki/Agenda_21, consulta em 15.mar.2023
