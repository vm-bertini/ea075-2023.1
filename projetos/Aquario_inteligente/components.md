Componentes | Datasheet ou Ficha Técnica | Justificativa da escolha |
-- | -- | -- |
Sensores: |   |   | 
DS18B20 (para o ar) | https://www.alldatasheet.com/datasheet-pdf/pdf/58557/DALLAS/DS18B20.html | Realiza a medição da temperatura ambiente, permitindo uma otimização da potência consumida para a manutenção dos valores de temperatura desejados no interior do aquário, correspondendo a um sensor de baixa relação custo/benefício, que apresenta uma precisão programável, um protocolo de comunicação que é facilmente estabelecido através de sua conexão a um pino digital do microcontrolador (por ja possuir um conversor analógico-digital interno, caracterizando um protocolo de comunicação denominado de One Wire). |
DS18B20 (para a água) | https://www.alldatasheet.com/datasheet-pdf/pdf/58557/DALLAS/DS18B20.html | Indispensável para a realiização do controle da temperatura interna do ambiente marinho e para a transmissão de seus valores através do relatório gerado, sua única diferença ao sensor utilizado para o ar (a princípio) corresponde ao seu involucro que permite que seja utilizado dentro da água, possuindo um cabo que também apresenta maior extensão. | 
System on a chip: |   |   |
ESP8266 | https://pdf1.alldatasheet.com/datasheet-pdf/view/1132995/ESPRESSIF/ESP8266.html | O System on Chip ESP8266 foi escolhido para ser utilizado neste projeto por corresponder a um controlador relativamente simples que possui integrado um módulo que permite o estabelecimento de comunicação via Wi-fi, o que é crucial para a transmissão dos relatórios gerados para a nuvem (de acordo com a ideia central do projeto do aquário inteligente). Outro motivo corresponde à sua capacidade de estabelecer comunicação pelo protocolo I2C, utilizada para a operação de um sistema refrigerador (não projetado). |
Cabo USB - Micro USB | - | A princípio seria utilizado para se programar o SoC empregado no projeto através de um computador com uma IDE (Ambiente de Desenvolvimento Integrado). |
Sistema aquecedor: |   |   | 
Escolhido pelo próprio consumidor, dado restrições do aparelho de controle | - | Dependendo do aquário no qual o sistema será aplicado diferentes tipos de sistemas aquecedores podem ser requeridos, de forma com que a escolha deva ser tomada pelo próprio consumidor (considerando a operação do sistema de controle). | 
Sistema resfriador: |   |   |
Projetado à parte | - | Atualmente tem-se que os sistemas refrigeradores que apresentam maior eficiência correspondem à resfriadores termodinâmicos denominados de "Chillers", que por normalmente apresentarem um controle já embutido de temperatura acabariam por dificultar sua integração com o sistema projetado, desta forma tem-se que seu projeto seria realizado à parte e então integrado ao do sistema de controle. |
Sistema de interfaceamento entre o SoC e o aquecedor: |   |   |  
Resistor filme metálico 1/4W 1% - 33 Ω | 1 | 0,15 |
Resistor filme metálico 1/4W 1% - 56 Ω | 1 | 0,1 |
Resistor filme metálico 1/4W 1% - 100 Ω | 1 | 0,21 | 
Resistor 1/4W 5% - 240 Ω | 1 | 0,05 |
Resistor 1/4W 5% - 4,7 kΩ | 2 | 0,05 |
Capacitor Cerâmico 33nF / 50V | 1 | 0,14 |
TRIAC BTA41-600 | https://www.baudaeletronica.com.br/triac-bta41-600.html?gclid=Cj0KCQjwmZejBhC_ARIsAGhCqndPYXh0QL_n650W_XxhjM_BYkFvXZbdkZvSSor0seZzj2QmbDE0zwgaAmOREALw_wcB | Utilizado para realizar o controle da potência do sistema aquecedor, através de sua operação em conjunto de um sistema específico que permite esse controle pelo método de modulação por lagura de pulso (PWM), utilizando para tanto também o controlador ESP8266. |
MOC3020M | https://pdf1.alldatasheet.com/datasheet-pdf/view/5039/MOTOROLA/MOC3021.html | Optoacoplador utilizado como parte do sistema para o controle da potênca entregue ao aquecedor, que possui como propósito majoritário isolar eletricamente o sistema de controle (de baixa potência) do composto pelos atuadores (de maior potência), evitando principalmente o sistema de controle passe a apresentar falhas devido a algum imprevisto relacionado a uma conexão elétrica existente com um sistema de maior potência. |
Circuito retificador de onda completa para a alimentação do SoC: |   |   | 
LM7805 | 1 | 3 |
Capacitor de 100nF | 2 | 0,2 |
Diodo1N4007 | 5 | 0,2 |
Capacitor eletrolítico 220uF 25v | 1 | 0,35 | 
Transformador de 220V para 12V | https://produto.mercadolivre.com.br/MLB-3276527293-conversor-de-tenso-220v-para-12v-transformador-eletrnico-i-_JM?matt_tool=54307261&matt_word=&matt_source=google&matt_campaign_id=14302215582&matt_ad_group_id=134553712308&matt_match_type=&matt_network=g&matt_device=c&matt_creative=539425529689&matt_keyword=&matt_ad_position=&matt_ad_type=pla&matt_merchant_id=623194816&matt_product_id=MLB3276527293&matt_product_partition_id=1802672036537&matt_target_id=pla-1802672036537&gclid=CjwKCAjwgqejBhBAEiwAuWHioJUjP2nSSHbEiWERYT_BIw9dajKQbRiMtEKUTwAVvxpAHGNx5dkc4hoCR28QAvD_BwE | Aplicado para se reduzir a tensão da rede para uma que pode ser retificada facilmente para se estabelecer uma tensão adequada para a alimentação do sistema de controle (de forma com que sua alimentação possa ser realizada em conjunto com a dos sistemas atuadores, não requerendo um cabo adicional). | 
Para a alimentação do aquecedor: |   |   |   
Tomada com plugue fêmea 2P 250V 10A 57420952 Tramontina | https://www.dimensional.com.br/plugue-femea-2p-250v-10a-57420952-tramontina/p?idsku=192830&gclid=CjwKCAjwgqejBhBAEiwAuWHioKcka9j1v_gFVKNrZYaaJW1ZBMC7G3IKxYh_wfv3idYQUSwBucLkwxoCQvcQAvD_BwE | Utilizada para permitir uma fácil alimentação tanto do sistema de controle quanto dos sistemas atuadores (de aquecimento e resfriamento). |

