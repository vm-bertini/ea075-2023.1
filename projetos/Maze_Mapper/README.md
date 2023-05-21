# `<Mapeador de Labirinto>`
# `<Maze Mapper>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> |Nome  | RA | Curso|
> |--|--|--|
> | Caio Mendes Rehder  | 232607  | Eng. Elétrica|
> | Daniel Yamamoto Damico  | 220770  | Eng. Elétrica|


## Descrição do Projeto
> O projeto “Maze mapper” visa facilitar o mapeamento de estruturas de caminhos ramificados, como labirintos, encanamentos e túneis, que são de difícil acesso humano. Embora esse projeto tenha o objetivo de ser um protótipo que funcione apenas em ambientes mais controlados, a solução proposta, se aplicada com as devidas modificações circunstanciais, teria utilidade em uma ampla variedade de setores, incluindo manutenção de infraestrutura e inspeção de segurança.
> Em um caso de tubulações, por exemplo, seria possível tornar o trabalho humano mais simples e eficiente, evitando danos desnecessários, como abrir encanamentos em vários pontos para encontrar obstruções, e acelerando o processo de mapeamento.
> A solução baseia-se em um sistema embarcado de mapeamento quase inteiramente autônomo que usa tecnologias de sensores e mapeamento bidimensional para navegar e mapear essas estruturas complexas. O sistema visa ser capaz de detectar pontos de obstrução, saídas e ramificações, bem como registrá-los em um mapa que preserve as características espaciais do ambiente avaliado.
> Uma característica distinta do sistema seria sua capacidade de salvar o progresso em uma memória externa por meio de conexão USB, de modo a diminuir a necessidade de memória não-volátil no sistema, o que possibilitaria uma redução de custos.
> Assim, com seu potencial para simplificar o mapeamento de estruturas complexas e reduzir o tempo e os custos associados a essas tarefas, espera-se que o sistema desenvolvido para esse projeto possa ser adotado em muitas aplicações subsequentes de cunho similar.



## Descrição Funcional
https://lh3.googleusercontent.com/fC0IpyfMusjBiv2cPaGizkHsz6THlQ7D1Wrn_8VQFXbeXM-SBUuwmMSCG1fEY0D2XlPK9xC2zFK4G4ikAx4hqPGKDdTxSjYu4amp8GY641PDLVqZuEAmB1MZTrWi-_QC_l9ZbEE7PjevJs6IXxQD2z2g9BEwbMv3r9O7B305E1y2lR8pC6B3BN7FTuD7OVgm8VwuqZ3IvhjsRHtPvI98S-G3C6cj_DYEZym01dceuEB7zdEHhr9PXJlbcuUuNSuVB5HMpStYzW9VFUgTCT-DMpK4gGs5bqlVMoCke8wRBYtYInnPWtl4NlM6Ddzg7cc2a8x3ZJqQwv2515hthywd8bLYEbdhcpp2ffgMz7VwOImNPqd-zZSCmOuWeRm4AITtqbrObtg7pt77O625w4HCB_FC2IcyaULZVO9VHXmaSLf8zeksF_-63DCLF0FL1HIV4E2WPkcxaXi6kl1_hNekKNlsbQDZUgyIyN1RG80WwgO7NuiHc8vZBbEgboGoLLtQaW2FdTMPR2mAeMxaLbAeS-mfKjHknB4OOLWSxKyzScwd6tg4-xRxuxh4v9FClXJtYtz9uTvFKEYlz5pX6ZXImImzs3S3tlLmnANfm1ngwUVLyA-q_0kMaR_XQlE-LIHXdr_v8XEQOk-pQrNtDqsbqSdwHtPg80LnMycO1QQ022XGx40iv9pIm4vUXeFySe20PNJnfTd4Ht_jmVV1ywpwpxqsHXDJMOomQ5tZVnmCWNWWzsBnvFKg2mZdCx44LjBHwPYqCnslqbM7p8Zj6MHfwDr_lJEDjGR5t2Co5hR0O_y8wR_ngWbKS3mt9iLYWpehw2fpst2fYdsqri-_RCTLrX2kGP0QA6ONSRTRurN1lZwo83xSSufu_HarCEza5e6qrlFlx6zf5jAam_YNlTgv0Wv5eL0zZWOt-98u2HNiSNK0T8SrKwqd84uZkBfrgu2xcB_3Nw9keFkaEdPlTgio=w1350-h929-s-no?authuser=0

### Funcionalidades
> O projeto possui uma série de funcionalidades para realizar a tarefa proposta, conforme as descrições a seguir.

> Seu sistema emprega sensores para identificar os possíveis caminhos a serem seguidos e, com base nessas informações, toma a decisão de qual caminho seguir quando diante de uma ramificação, a fim de evitar repetições desnecessárias e otimizar o tempo de mapeamento.

> Para a locomoção, o dispositivo conta com a funcionalidade de ir para frente, para trás e rotacionar até 180º para ambos os lados de acordo com instruções automatizadas.

> O sistema também realiza a função de identificar obstruções, ramificações e saídas e registrá-las como pontos chave do mapeamento. Paralelamente, há o monitoramento da distância atual em relação ao ponto inicial para que o dispositivo não vá além de um raio de atuação máximo estabelecido para o sistema.
Para garantir que todas as informações sejam armazenadas e que o progresso do mapeamento não seja perdido, o sistema periodicamente salva o mapeamento realizado em uma memória externa. 

> Além disso, o sistema inclui um alerta que é acionado para um controlador externo caso o dispositivo fique preso, o que, por agilizar a comunicação, colabora para contornar situações de interrupção inesperada. Ademais, após o disparo desse alerta, o sistema automaticamente interrompe todas as suas funcionalidades exceto o acendimento de lâmpadas externas de sinalização, aumentando a chance de recuperação do equipamento. 

> O dispositivo também será capaz de receber um sinal de retorno imediato do controlador externo, situação na qual todas as funcionalidades de mapeamento são interrompidas e o dispositivo automaticamente navega de volta ao ponto inicial.


### Configurabilidade
> O sistema disporá de 4 modos configuráveis por meio de dois switches. Um dos switches regulará se o objeto de busca do sistema são obstruções (caminhos sem saída) ou saídas (pontos onde é possível sair do labirinto). Já o segundo, configura se serão buscados apenas uma obstrução ou saída ou se serão mapeados múltiplos objetos de busca, de forma que, no primeiro caso, o sistema automaticamente retorna para o ponto inicial ao encontrar o primeiro objeto de busca e no segundo, apenas interrompe sua operação se for comandado externamente ou se ficar preso.
Com isso, os 4 modos configuráveis são:
- Uma obstrução
- Múltiplas obstruções
- Uma saída
- Múltiplas saídas


### Eventos
> Periódicos

1. Utilização dos sensores para varredura (500ms).
2. Verificar a distância do ponto inicial (5000ms).
3. Verificar status da locomoção (5000ms).
4. Verificação de bateria (60000 ms).
5. Mapeamento (5000ms).

> Não Periódicos (não ocorrem simultaneamente, portanto não preocupações com tempo mínimo)

1. Encontrou ramificação.
2. Encontrou obstrução.
3. Encontrou saída.
4. Liga/desliga.
5. Requisição de retorno (prioritário).
6. Transferência do mapa para a memória externa.


### Tratamento de Eventos
> Periódicos:

1. Verificação de ramificação, obstrução, saída (trigger para os eventos não periódicos 1, 2 e 3).
2. Se a distância for maior que o raio de atuação, ou houver perda de sinal, voltar.
3. Caso a locomoção seja comprometida, enviar sinal de ajuda e entrar em modo de segurança (economia de bateria, e LEDs ligados para facilitar localização).
4. Caso a bateria esteja abaixo de um certo limite, voltar.
5. Atualizar o mapa na memória RAM com uma reta entre a posição anterior e a atual. 

> Não Periódicos

1. Sempre escolher o caminho mais a esquerda que ainda não tenha sido percorrido. Salvar ponto de ramificação no mapa.
2. Salvar como obstrução e retornar até a última ramificação. Caso em modo de busca por obstrução única, salvar o mapa e retornar (tarefa concluída).
3. Salvar como saída e retornar até a última ramificação. Caso em modo de busca por saída única, salvar o mapa e retornar (tarefa concluída).
4. Ligar e desligar o sistema.
5. Interromper o processamento normal e retornar ao ponto inicial pelo caminho mais curto.
6. Atualizar o mapeamento salvo na memória externa a cada 10 pontos.


## Descrição Estrutural do Sistema
A estrutura necessária ao desenvolvimento do projeto pode ser sintetizada por meio do diagrama de blocos abaixo:

https://lh3.googleusercontent.com/dEtVDtnTXxLJs2YYxXNb0YExX45h7YhmmGbJCrGO4sbP2ZZwJrNeD3CY3kNnnNn1MOc_i2NYhD7OoQTKKm-OF_cWPBtkUW8biwlghvfG6UCvnFZPj2UeGYljBR-BsjQR0KA4t5QSpiZ1Jix3We95ZKLccMm8YyE3aOPf8G4DnTZotGIEM2rgNRHAiD76IM5BgzH0TtamWFA5DCAXd4-pcw4trpwiD-JUC33PNrmV1CWi9pT8C5I92LdoWfY1Ec3f6cZehMzdCzcqZf-5uIqZoQoZjLwkxHvmVgWe8-j4WIKPq7la2c3aOd5zIQWVE2AXV_EAUcg-z0WvHdTZJMw9N8tFOSOWJRKPhNHEFswCotGq_2gUgKjMR_n0wGdeixbLrn4nDEE07uq8pmKNOlksIx2X9_0paFxJMaYFt6npttZCa77iwNZRlALwv5dJbdZcSegy8CWIgomoQt4AF9Fa2MkYIMzbUhBROzZSqjilxc7-dHtrxTUGEOntlQkvR-ELTWRPeqz0nPbGutO7dZlrbudsggeqF1Rku95srSUsARWYBDHM6RPCwYlpBHLm5fve8Pxziw7pz1yMRHUMhR0xsQvAigK59uL--UEVNycbC4heRKmV4OdUifqym0w6EwuqS9nhm3d5hlTe8VTZAow9OVri6-WX2R50HzPvcExxrbtEpq2tUnpoY2wj4LuRpEPsQrf77MfZ1FskSxJk2BW4G6oe34vHrq1PgSrP9Qw8iKS7OcndvZkM5rkG3azaZevEZENrn9EPafDHcCPKIXD_9icAC9tufazBlWFSVTjDs5aLe2dWyNjiDEMXMykMnTB0zYDss4y2Sk3G8Ry9ohlHrENwtcikjsefNcAV0n1R9WFKxq1fEF4C3zWya820p0CL_6dbBmrJqltqvHi29xbmXpwQjUTYey81mp7qNv5JV0BfEfGq_w7mZNI6FKuMbwMfnvMomsnphSEHfYOlv3Qq=w1057-h541-s-no?authuser=0

### Descrição dos blocos:
#### SENSORES: 
> Descrição: Contempla o conjunto de sensores necessários para que o sistema obtenha informações do mundo externo, como a posição atual, direção de movimento e se há algo nas proximidades do dispositivo que exige a chamada de um evento

> Relações com outros blocos:
> > Tem como fonte de alimentação o bloco BATERIA
> 
> > Envia informações e sinalizadores de evento ao MICROCONTROLADOR 

#### MICROCONTROLADOR:
> Descrição: Centro de processamento do sistema embarcado, o qual realiza todas as tarefas relacionados ao tratamento de dados e eventos, além do envio de dados e sinais de controle aos demais blocos

> Relações com outros blocos:
> > Alimentado pela BATERIA
> 
> > Envia sinais de controle para os blocos BATERIA, SISTEMA MEC NICO e SISTEMA Rx/Tx
> 
> > Envia dados para MEMÓRIA EXTERNA  
> 
> > Recebe sinais e dados dos blocos SENSOR e SISTEMA Rx/Tx durante a execução do programa e recebe configurações do bloco SWITCH antes da execução

#### MEMÓRIA EXTERNA:
> Descrição: Bloco responsável por armazenar permanentemente os dados de mapeamento obtidos ao longo da navegação, conectado ao microcontrolador por uma entrada USB

> Relações com outros blocos:
> > Alimentado pela BATERIA
> 
> > Apenas recebe dados do bloco MICROCONTROLADOR 

#### SISTEMA Rx/Tx (RECEPÇÃO E TRANSMISSÃO):
> Descrição: Sistema responsável pela comunicação entre o usuário e o dispositivo principal, utilizado apenas para encerrar a operação, seja por requisição do usuário (recepção do sinal de retorno) ou pelo dispositivo quando este se encontrar impossibilitado de retornar (transmissão de sinal de “socorro”)

> Relações com outros blocos: 
> > Alimentado pela BATERIA
> 
> > Comunica-se com o CONTROLE EXTERNO e com o MICROCONTROLADOR  por meio da transmissão e recepção de sinais 

#### SISTEMA MECANICO:
> Descrição: Toda a estrutura mecânica de motor, rodas e outros componentes necessários para que o dispositivo se mova segundo os comandos do microcontrolador

> Relações com outros blocos:
> > Alimentado pela BATERIA
> 
> > Recebe sinais de controle apenas do MICROCONTROLADOR 

#### BATERIA:
> Descrição: Fonte de energia elétrica de todo o sistema embarcado

> Relações com outros blocos:
> > Relaciona-se com todos os demais blocos, exceto MEMÓRIA EXTERNA e CONTROLE EXTERNO, alimentando-os com energia elétrica

#### SWITCH (Botões e Switches):
> Descrição: Componentes responsáveis por ligar e desligar o aparelho (um botão simples) e por selecionar o modo de atuação a ser configurado (dois switches)

> Relações com outros blocos:
> > Envia sinais de controle à BATERIA e ao MICROCONTROLADOR 

#### CONTROLE EXTERNO:
> Descrição: Dispositivo não integrado fisicamente ao sistema principal e que permanecerá com o usuário a todo momento, tendo como únicas funções enviar um sinal para que o aparelho retorne e receber o sinal de “socorro” indicando que o aparelho não consegue voltar

> Relações com outros blocos:
> > Apenas se comunica com o bloco SISTEMA Rx/Tx


## Referências
- https://www.youtube.com/playlist?list=PLifLftIJFUm-1iIAEPWvuSJTA50YKYD7J
- megaAVR® Data Sheet, ATmega48A/PA/88A/PA/168A/PA/328/P
- Módulo Sensor de Distancia Ultrassónico, Chipsce, Hc-Sr04
