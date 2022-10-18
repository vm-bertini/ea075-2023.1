# `<Sistema de Ventilação Forçada Automatizado para Workstations>`
# `<Automated Forced Ventilation System for Workstations>`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Sistemas Embarcados*, 
oferecida no segundo semestre de 2022, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

|Nome  | RA | Curso|
|--|--|--|
| David Daminelli  | 169774  | Eng. Elétrica|
| Giovanna Presta  | 173275  | Eng. Elétrica|


## Descrição do Projeto 

Com o avanço da tecnologia, computadores com maiores capacidades de processamento foram desenvolvidos para resolver os problemas mais complexos. No entanto, essa capacidade de processamento faz com que os componentes eletrônicos dissepem altas quantidades de calor. Para que os computadores operem da maneira desejada e, principalmente, que no sejam danificados, é necessário um sistema de resfriamento que mantenha sua temperatura em um limiar especificado pelo fabricante. 

Uma das formas mais simples de realizar essa função é utilizando ventilação forçada por meio de coolers. Porém, essa solução é custosa e inconveniente por conta da energia gasta e pelo ruído emitido. Nosso sistema resolve essas limitações ao acionar os ventiladores instalados em racks apenas quando a temperatura dos computadores é elevada, desligando caso contrário, mantendo a simplicidade e diminuindo os custos associados à ela.    

## Descrição Funcional

### Funcionalidades

- Medir a temperatura;
- Comparar temperatura medida com valor ajustado;
- Ajustar setpoints de temperatura;
- Acionar/desacionar ventiladores;
- Exibir valor da temperatura medida.

### Configurabilidade

- Ajustar setpoints de liga/desliga dos ventiladores

### Eventos

- Ligar/Desligar coolers com base na temperatura medida.

### Tratamento de Eventos

- Se cooler estiver desligado e temperatura for menor que temperatura ajustada, manter desligado;
- Se cooler estiver desligado e temperatura for maior que temperatura ajustada, ligar cooler;
- Se cooler estiver ligado e temperatura for maior que temperatura ajustada, manter ligado;
- Se cooler estiver ligado e temperatura for menor que temperatura ajustada, desligar.

## Descrição Estrutural do Sistema

Disponível no arquivo `ventsys.drawio` 

## Referências

Nesta primeira etapa não utilizamos nenhuma referência.
