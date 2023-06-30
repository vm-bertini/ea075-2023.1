# `<Monitoramento_Estufa>`
# `<Greenhouse_monitoring>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no primeiro semestre de 2023, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Felipe Souza Sisnando de Araujo  | 239617  | Eng. Elétrica|
> | Levi Santos Volotão  | 239783  | Eng. Elétrica|


## Descrição do Projeto
> 
> Hoje em dia, observa-se o surgimento de cada vez mais estufas controladas, pois são um ambiente controlado em que plantações podem ser monitoradas e os aspectos físicos do ambiente podem ser configurados e otimizados para o crescimento e desenvolvimento adequado de uma certa espécie. Embora o custo inicial de uma estufa seja elevado, ela possibilita uma melhora na qualidade dos produtos, aumentando seu valor agregado, e uma dependência menor de características que não podemos controlar quando cultivadas a céu aberto.
> 
> Com uma plantação em estufa, os parâmetros externos não terão tanta influência, e as épocas do ano influenciarão menos as colheitas, garantindo a produção durante o ano todo, reduzindo fenômenos como falta de abastecimento em determinados períodos do ano e prejuízos econômicos dos cultivadores devido ao clima. Como exemplo, observa-se que "no verão, as chuvas demasiadas danificam as plantas e criam condições favoráveis para o aparecimento de doenças, atrapalhando a produção, sendo a época de maiores preços dos produtos hortícolas pela falta de oferta para abastecimento. Por outro lado, o frio e os ventos, do inverno prolongam o ciclo dessas culturas, que consequentemente desprogramam a produção e causam grandes prejuízos econômicos" [Miura, 2011]. Porém, mesmo com influências externas reduzidas, ainda é necessário o controle interno, devido a problemas como a alta irradiação externa resultando em um efeito de aquecimento dentro da estufa,podendo ser prejudicial à plantação caso não ocorra o controle da temperatura necessário. "Além disso, a alta umidade relativa do ar favorece o aparecimento de doenças e provoca menor desenvolvimento das plantas devido ao fato da planta transpirar menos e ter uma menor absorção de nutrientes nessas condições, enquanto, a baixa umidade relativa do ar juntamente com altas temperaturas provoca o aumento da transpiração, fechamento dos estômatos, redução da taxa de transpiração e abortamento das flores devido a uma polinização deficiente" [Lopes e Stripari, 1997]. 
>
> Desse modo, nós propomos o desenvolvimento de um sistema embarcado responsável pelo monitoramento da estufa, que será capaz de identificar quando os valores de temperatura, umidade e luminosidade estiverem fora da faixa desejada, e será capaz de corrigir esses valores, utilizando sistemas de aquecimento e refrigeração (coolers), sistema de ventilação, aspersores de água e um sistema que controla as lâmpadas responsáveis pela luminosidade da estufa, bem como a luminosidade que entra do ambiente externo, a partir de um "shade" (funciona como uma "cortina") cuja abertura é controlada. Esse monitoramento será de grande utilidade para cultivadores de diversos produtos, visto que as faixas de temperautra, luminosidade e umidade desejadas podem ser configuradas conforme os parâmetros adequados para cada espécie. A instalação desse sistema irá aumentar o valor agregado dos seus produtos, viabilizar o cultivo em todas as épocas do ano e permitir um controle automatizado, sem necessidade de mão de obra.
>  


## Descrição Funcional

### Funcionalidades
>O nosso sistema embarcado será capaz de obter a temperatura do ambiente, a luminosidade e a umidade do ar a partir de sensores. Ele mostrará esses valores em um LCD (Liquid Crystal Display). Inicialmente ele amostrará os valores de temperatura e umidade a cada 10 minutos e a luminosidade a cada 5 minutos, porém esses parâmetros serão configuráveis, e a frequência de amostragem de cada fator pode ser alterada conforme a necessidade do cliente. O sistema também será capaz de detectar quando um valor estiver fora da faixa adequada configurada, e para esse caso, irá iniciar rotinas de tratamento adequadas, controlando o funcionamento dos aspersores de água, sistema de aquecimento, coolers, lâmpadas e "shade".
>
> O sistema poderá : 
> - Ligar e desligar os aspersores de água
>
> - Ligar, desligar e controlar a temperatura do sistema de aquecimento
>
> - Ligar, desligar e controlar a temperatura dos coolers
> 
> - Movimentar o "shade" : Abrir o shade caso a luminosidade esteja abaixo da desejada e fechar o shade caso esteja acima da desejada
>
> - Ligar, desligar e controlar a intensidade da luz das lâmpadas de LED (as lâmpadas serão utilizadas caso a luminosidade não seja o bastante mesmo com o shade totalmente aberto (por exemplo à noite)).

### Configurabilidade
> A estufa está sendo projetada para uma diversidade de espécies de plantas, e cada planta tem suas especificidades em relação ao ambiente para ter uma produtividade melhor. Portanto, será possível configurar a faixa de valores desejada e a frequência com que os dados serão amostrados. Essa configuração será feita por botões. O LCD no modo exibição mostrará o último estado amostrado, e atualizará a cada amostragem. Ao apertar o botão de configuração, o sistema irá funcionar no modo de configuração, e o LCD mostrará os valores definidos para o período de amostragem e os valores máximo e mínimo para cada parâmetro. Para mudar esses valores, haverá 3 botões (além do botão que muda entre o modo de exibição e configuração, totalizando 4 botões), um botão que muda a característica cujo valor deseja-se alterar, um botão para incrementar esse valor e um botão para decrementar esse valor. Ao pressionar o botão de configuração novamente, retorna-se para o modo de exibição. Os valores possíveis para as características obedecerão a limites de acordo com as especificações dos sensores, e o período de amostragem poderá variar de 1 a 59 minutos.
### Eventos
>  O sistema deve tratar os seguintes eventos periódicos:
>
> - Amostragem de temperatura: De X em X minutos deve-se obter o valor da temperatura lido no sensor (em que X é um valor configurável, inicialmete colocado como 10 minutos) 
>
> - Amostragem de umidade: De Y em Y minutos deve-se obter o valor da umidade lido no sensor (em que Y é um valor configurável, inicialmete colocado como 10 minutos) 
>
> - Amostragem de luminosidade: De Z em Z minutos deve-se obter o valor da umidade lido no sensor (em que Z é um valor configurável, inicialmete colocado como 10 minutos)
>
> O sistema deve tratar os seguintes eventos não periódicos:
> 
> - Temperatura dentro da faixa desejada
> 
> - Temperatura abaixo da temperatura mínima configurada
>
> - Temperatura acima da temperatura máxima configurada
>
> - Umidade dentro da faixa desejada
> 
> - Umidade abaixo da umidade mínima configurada
>
> - Umidade acima da umidade máxima configurada
>
> - Luminosidade dentro da faixa desejada
> 
> - Luminosidade abaixo da luminosidade mínima configurada
>
> - Luminosidade acima da luminosidade máxima configurada
>
> - Botão para mudar para o modo configuração apertado
>
> - Botão para incrementar em 1 o valor do parâmetro selecionado apertado
>
> - Botão para decrementar em 1 o valor do parâmetro selecionado apertado
>
> - Botão para mudar parâmetro selecionado (cujo valor deseja-se mudar) apertado
>
>

### Tratamento de Eventos
>
> - Tratamento da amostragem de temperatura: 
> 
> Obter o valor da temperatura e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
> 
> - Tratamento da amostragem de umidade:
> 
> Obter o valor da umidade e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
> 
> - Tratamento da amostragem de luminosidade: 
> 
>  Obter o valor da luminosidade e analisar se está acima, abaixo ou dentro da faixa desejada, acionando o tratamento do evento correspondente. 
>  
> - Tratamendo quando a temperatura está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a temperatura está abaixo da temperatura mínima configurada:
> 
> Caso o cooler esteja ligado, desliga o cooler.
> 
>  Caso contrário, se o sistema de aquecimento estiver desligado, liga-se o sistema de aquecimento. Se estiver ligado, aumenta em 5°C a temperatura do aquecedor.
> 
> - Tratamento quando a temperatura está acima da temperatura máxima configurada:
> 
> Caso o aquecedor esteja ligado, desliga o aquecedor. 
> 
> Caso contrário, se o cooler estiver desligado, liga-se o cooler. Se estiver ligado, diminui em 5°C a temperatura do cooler.
> 
> - Tratamento quando a umidade está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a umidade está abaixo da umidade mínima configurada:
> 
> Caso a ventilação esteja ligada, desliga a ventilação. 
> 
> Caso contrário, liga-se o aspersor de água e, após 30 segundos, ele é desligado.
>
> - Tratamento quando a umidade está acima da umidade máxima configurada:
> 
> Liga-se o sistema de ventilação. 
> 
> Caso já esteja ligado, aumenta sua potência.
>
> - Tratamento quando a luminosidade está dentro da faixa desejada:
> 
> O sistema retorna ao fluxo normal do programa
> 
> - Tratamento quando a luminosidade está abaixo da luminosidade mínima configurada:
> 
> Caso o shade esteja fechado, abrir o shade.
> 
>  Caso contrário, acender as lâmpadas de LED. Se estiverem acesas, aumentar intensidade da luz.
>
> - Tratamento quando a luminosidade está acima da luminosidade máxima configurada:
> 
> Caso as lâmpadas estejam ligadas, desligar as lâmpadas.
> 
>  Caso contrário, fechar o shade
>
> - Tratamento quando o botão de configuração está apertado:
> 
> Caso esteja no modo exibição, muda para o modo de configuração (o LCD passa a mostrar os limites dos parâmetros e o período de amostragem)
> 
> Caso esteja no modo de configuração, muda para o modo exibição(o LCD mostra os valores de temperatura, luminosidade e umidade lidos pelos sensores), estabelece os novos valores limites das faixas de temperatura, umidade e luminosidade e estabelece o novo período de amostragem.
>
> - Tratamento quando o botão de incremento está apertado:
> 
> Caso esteja no modo configuração, aumenta o valor da característica selecionada em 1
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
> 
> - Tratamento quando o botão de decremento está apertado:
> 
> Caso esteja no modo configuração, decrementa o valor da característica selecionada em 1
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
>
> - Tratamento quando o botão para mudar parâmetro selecionado está apertado:
> 
> Caso esteja no modo configuração, muda a característica selecionada
> 
> Caso esteja no modo exibição, esse evento é ignorado e o programa continua seu fluxo normal
>

## Descrição Estrutural do Sistema

>![image](https://user-images.githubusercontent.com/129390336/228986991-64179348-208a-4698-8d23-44ea0e69f3e3.png)
>
> Observa-se que podem-se destacar três grandes blocos funcionais: o microcontrolador, os sensores e os atuadores. No bloco dos sensores tem-se os sensores de luminosidade, umidade e temperatura, bem como os botões (que podem ser considerados como sensores de pressão); já como atuadores, observa-se o cooler, shade,  sistema de ventilação, aquecedor, lâmpadas e os aspersores, bem como o LCD (que pode ser considerado um atuador, permitindo a visualização de dados na tela). Os sensores são capazes de transformar parâmetros físicos em sinais elétricos, que podem ser processados pelo microcoontrolador. A partir desses sinais, o microcoontrolador processa o programa de tratamento de enventos (conforme explicado em seções anteriores),  e envia sinais de controle para os atuadores, que atuam com base nesses sinais e transformam esses sinais elétricos em alguns parâmetros físicos, permitindo o correto funcionamento do circuito.

## Referências
> http://sistemaolimpo.org/midias/uploads/fa4a7bc53246a8a9bf8642442a68fe3c.pdf
>
> https://www.horticeres.com.br/noticias/dicas-para-cultivo-protegido/#:~:text=Para%20efeito%20estufa%20(regi%C3%B5es%20muito,aproximadamente%20400%20a%201000%20m%C2%B2.
>
>https://www.rijkzwaan.com.br/blog/estufa-ou-guarda-chuva
>
>Miura, M. (2011). Análise Econômica do Cultivo em Ambiente Protegido.
>
>https://www.zanatta.com.br/cultivo-protegido/
>
>https://embarcados.com.br/sensores-e-atuadores-iot/
