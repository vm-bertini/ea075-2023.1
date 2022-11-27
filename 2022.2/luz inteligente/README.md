# `Luz Inteligente`
# `<Smart Light>` 

## Apresentação

Projeto originado das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
Disciplina oferecida pela Profa. Dra. Paula Dornhofer Paro Costa, no segundo semestre de 2022.

|Nome | RA | Curso |
|--|--|--|
| Bruno Vinicius Barros da Silva | 214083 | Eng. Elétrica |
| M Kamel Zinou  | 161534 | Eng. Elétrica |

## Descrição do Projeto

O projeto consiste em um sistema embarcado cujo objetivo é ligar ou desligar as luzes de um ou mais ambientes de maneira mais prática, sem a necessidade de um interruptor, sendo apenas necessário estar no ambiente e bater palmas para ligar ou desligar as luzes.

## Descrição Funcional

Será um sistema que ligará ou desligará a luz de um cômodo da casa, a partir de palmas ou presença, contando quanto tempo a luz ficou ligada durante o mês atual. Podendo exibir a quantia de energia a ser paga.

### Funcionalidades
- **liga/desliga a luz**: o sistema sera capaz de alterar o estado da luz ao perceber que alguém está no ambiente e ouvir palmas.
- **Desliga por inatividade**: o sistema irá desligar altomaticamente após 5 minutos sem ninguém no ambiente.
- **Cálculo de tempo ativo**: o sistema calculará o tempo que a luz ficou ativa durante o mês, possibilitando.
- **Cálculo de conta de energia**:O sistema calculará a conta de energia através do tempo ativo.

### Configurabilidade
O usuário poderá configurar:
- Horário de alimentação
- Periodicidade do envio do relatório


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


## Estrutura do Sistema

![DIAGRAMA-EA075](https://user-images.githubusercontent.com/112783871/199125714-ed989c85-57b7-41f3-ab7e-61b6ba271a6a.png)


## Referências

- **Sensor Sonoro**: https://datasheetspdf.com/pdf-file/1402047/Joy-IT/KY-037/1
- **Sensor Presença**: https://www.epitran.it/ebayDrive/datasheet/44.pdf
 

