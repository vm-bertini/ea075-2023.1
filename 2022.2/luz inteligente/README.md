# `Luz Inteligente`

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

### Eventos e Tratamentos

- O sistema deve detectar a presença de uma pessoa para funcionar.
- Receber o sinal sonoro para alterar o estado atual da luz.
- Ao acender a luz, continuar o cronômetro.
- Ao desligar a luz, parar o cronômetro e gravar o tempo na memória, calcular o gasto de energia e gravar na memória.
- Ao iniciar um novo mês, zerar o cronômetro.
- Caso o sistema não detecte nenhuma presença após 5 minutos, desligará a luz.

## Estrutura do Sistema
