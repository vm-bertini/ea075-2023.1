# `Estufa Inteligente`
# `Eco Greenhouse`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| Pedro Henrique Carosso Christensen  | 243048  | Eng. Elétrica|
| Juliana Nicolette  | 171244  | Eng. Elétrica|


## Descrição do Projeto
Com o desenvolvimento tecnológico crescendo exponencialmente, ferramentas de controle à distância acabam sendo cada vez mais comuns, trazendo segurança e autonomia a processos industriais e domésticos.

Foi pensando nisso que o projeto Estufa Inteligente surgiu. A intenção é possibilitar controles de temperatura, umidade e irrigação utilizando um controle via APP através de uma interface simples contendo dois modos: o automático e o manual.

Além disso, as possibilidades de rotatividade do plantio são infinitas, já que o proprietário consegue configurar faixas de temperatura, umidade e ciclos de irrigação manualmente, permitindo assim a economia energia conforme o clima local. E no quesito sustentabilidade, a eficácia é garantida: além da economia energética, há também a economia de água.

Com o sistema Estufa Inteligente, além de garantir a qualidade do produto na colheira, você evita a proliferação de pragas, automatiza todos os processos de plantio e controla todas as funções à distância.

A idealização do projeto possui como público alvo qualquer pessoa que deseje automatizar suas estufas e manter um controle manual quando necessário, somente tendo um celular e conexão com a internet.

Um valor seria melhor definido quando o projeto estiver em uma etapa de desenvolvimento mais avançada, por conta de não conseguirmos estipular os custos inicialmente. 

## Descrição Funcional

### Funcionalidades
Como funcionalidades do projeto, podemos listar:
- Controle de temperatura através de ares condicionados;
- Controle de irrigação através de aspersores¹;  
- Controle de umidade através de aspersores (os mesmos utilizados no controle da irrigação);
- Interação manual com os controles por meio de aplicativo, porém o foco é a automação deste trabalho por meio de uma fácil programação feita pelo cliente.

### Configurabilidade
Em nosso projeto, vamos definir dois modos de configuração: automático e manual. Dessa forma, permitimos a autonomia de tomadas de decisões e o proprietário poderá alternar os modos via APP, sendo necessário apenas possuir acesso à rede de internet para se comunicar com o sistema da estufa.

### Eventos

### Tratamento de Eventos

## Descrição Estrutural do Sistema
Estruturalmente o projeto foi divido em três partes, sendo elas: a entrada, o módulo de controle, e a saída. Em cada uma das partes, foram inseridos os dispositivos principais para o funcionamento da estufa, conforme ilustrado na imagem abaixo.

![diagramaprincipal](https://user-images.githubusercontent.com/113607245/191366997-67bf3240-c23d-4b10-90c9-e71ffb440ee0.png)

![diagramacontroletemperatura](https://user-images.githubusercontent.com/113607245/191367051-de9a27ac-5c74-43c3-bffc-4759951f76da.png)
![diagramacontroleumidade](https://user-images.githubusercontent.com/113607245/191367053-6f095790-2c18-4e20-9bbc-e61497113d34.png)



## Referências
[1] https://pt.wikipedia.org/wiki/Irriga%C3%A7%C3%A3o
