# 4. Projeto Conceitual

___________________________________________________________________________________


## 4.1 Características Gerais

O projeto visa o desenvolvimento de um carrinho seguidor de linha que percorra
três trilhas marcadas no chão, transportando um ovo de galinha ao longo desses trajetos
sem danificá-lo.<br> 
Com o objetivo de minimizar o tempo de percurso, é necessário criar
um carrinho totalmente autônomo, equipado com todos os componentes necessários embarcados.<br>
O carrinho incluirá um design mecânico robusto, priorizando materiais leves e
duráveis para suportar os desafios da corrida sem comprometer a segurança do ovo.<br>
Além disso, o carrinho será projetado com um conjunto de sensores, capaz de interpretar os dados
dos sensores de linha e ajustar sua direção e velocidade de maneira eficiente.<br> 
Com isso, será possível processar essas informações e mostrando os dados em tempo real em uma
aplicação web, de cada corrida.<br> 
Um sistema de propulsão adequado será essencial para otimizar o desempenho do carrinho, 
enquanto uma fonte de energia confiável garantirá sua autonomia ao longo das trilhas.<br>
Combinando as áreas da engenharia e testes rigorosos, o objetivo é criar um carrinho seguidor
de linha que não apenas complete as trilhas no menor tempo possível, mas
também transporte o ovo com segurança, demonstrando a eficácia da autonomia robótica
em ambientes desafiadores.

## 4.2 Estrutura

## 4.3 Descrição de hardware

## 4.4 Análise de consumo energético

Para a análise do consumo energético do projeto foram identificados os itens eletrônicos  escolhidos para o carrinho, consultando as especificações técnicas dos componentes (corrente de operação e a tensão de funcionamento) que estão disponíveis nos datasheets de seus fabricantes, foi determinado o consumo de energia de cada peça durante sua operação. Os elementos e suas características elétricas foram listados na tabela abaixo:

<h6 align = "center"> Características elétricas dos componentes eletrônicos.</h6>

|**Componentes**|**Tensão (V)**|**Corrente (mA)**|**Potência (W)**|**Quantidade**|
|:-------------:|:------------:|:---------------:|:--------------:|:------------:|
|Placa arduino uno R3|7,4|50 |0,35|1|
|Sensores Ópticos Reflexivos TCRT-5000|5|60|0,3|4|
|Módulo Bluetooth Serial Rs232 Escravo Hc-06|5|35|0,175|1|
|Sensor de velocidade módulo encoder|5|15|0,075|2|
|Medidor de Corrente ACS 712|5|8|0,04|1|
|Regulador de Tensão XL 4015|5|5000|25|1|
|Motores de 6V com redutor e rodas|6|200|1,2|2|

Multiplicou-se a corrente de operação pela tensão da fonte de alimentação, obtendo a potência de cada componente em watts (W), utilizando a fórmula:  $P = V \times i$, onde  $P$  é a potência em watts,  $V$  é a tensão em volts e  $i$  é a corrente em amperes. 

Tendo os valores das potências de cada peça, podemos saber o consumo de energia total do carrinho fazendo a soma das potências de todas as peças, com a soma obteve-se o valor de 
 $29,315$  watts. Este valor serve como uma referência importante para dimensionar a fonte de alimentação necessária e garantir um funcionamento eficiente do carrinho.

Para o cálculo da corrente requerida pelo carrinho, utilizamos a tensão de  $7,4 V$, que atende todos os componentes, e a soma das potências obtida no cálculo anterior na seguinte relação matemática:

$$P = v \times i \to i = \frac {29,315} {7,4} \simeq 3,96 A$$

Com os dados de consumo de energia total do carrinho e a capacidade da bateria, podemos calcular o tempo estimado de duração da bateria escolhida para o projeto. Estamos usando duas baterias recarregáveis  18650 ​​de 3,7 V, totalizando 7,4 V, com capacidade de 6800 mAh ( 6,8 Ah).
O tempo de duração da bateria pode ser calculado dividindo a energia total da bateria pelo consumo de energia total do carrinho: 

$$Tempo = \frac{C_{bateria}}{i} \to Tempo = \frac{6,8}{3,96} \simeq 1,7h$$

Portanto, o tempo estimado de duração da bateria para este projeto do carrinho seguidor de linha é de aproximadamente 1,7 horas. Essa é uma estimativa do tempo de operação contínua do carrinho antes que a bateria precise ser recarregada. 


## 4.5 Descrição de Software

### 4.5.1 Diagrama do Processo de Negócio (BPNM)
![Diagrama BPMN](img/BPMN%20PI1.png)
<h6 align = "center"> Imagem 1: Diagrama de classes.
<br> Autor: Samuel Nogueira e Thales Duarte
<br>Fonte: Autor(es)</h6>

### 4.5.2 Lista de Casos de uso 

### 4.5.3 Lista de Requisitos Não-Funcionais

Disponível em [TAP](/docs/Documentacao/2_Tap.md)

### 4.5.5 Diagrama de Classes

A imagem 2 abaixo exibe o diagrama de classes proposto para o desenvolvimento da aplicação de análise de dados.<br>

![Diagrama de Classes](img/diagrama_classes.png)
<h6 align = "center"> Imagem 2: Diagrama de classes.
<br> Autor: Brunna Louise
<br>Fonte: Autor(es)</h6>


### 4.5.6 Arquitetura do software

A arquitetura do software é o elemento que define a organização e a comunicação
entre as entidades a serem desenvolvidas. Por meio do esquema abaixo, é possível
visualizar os componentes e os relacionamentos entre eles em um sistema de software.

![Diagrama da arquitetura](img/diagrama_arquitetura.png)
<h6 align = "center"> Imagem 3: Diagrama da arquitetura.
<br> Autor: Gabriel Avelino
<br>Fonte: Autor(es)</h6>

Os componentes podem ser divididos em:

- **Front-end**: O ViteJs é um framework utilizado para criação de aplicações WEB de maneira ágil. Vai ser o responsável por mostrar
os dados no dashboard para o usuário.

- **Back-end**: Vai ser construído utilizando o web framework FastAPI para a manipulação dos dados e o banco de dados PostgresSQL para a persistência
dos dados enviados pelo arduíno.

- **Comunicação bluetooth**: Um script python vai ser utilizado para conectar com o módulo bluetooth do arduíno e enviar os dados dos sensores que foram lidos para o backend.


### 4.5.7 Descrição e Roteiro dos testes

### Testes de unidade

| Componente | Caso de teste                 | Descrição                                           |
| ---------- | ----------------------------- | --------------------------------------------------- |
| API        | Cálculo de velocidade         | Deve calcular a velocidade em um momento            |
| API        | Cálculo de aceleração         | Deve calcular a aceleração em um momento            |
| API        | Cálculo de consumo de bateria | Deve calcular o consumo de bateria em um momento    |
| API        | Cálculo de distância          | Deve calcular a distância total percorrida          |
| Front-end  | Visualização dos dados        | Deve ser possível visualizar os dados no dashboard. |


### Testes de integração

| Componente                  | Caso de teste                                     | Descrição                                                                                                                      |
| --------------------------- | ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| Módulo de conexão bluetooth | Certificar se dados estão sendo recebidos         | Deve receber um JSON com informações enviadas pelo carrinho                                                                    |
| Modulo de conexão bluetooth | Certificar se dados estão sendo enviados para API | Deve enviar um JSON recebido via requisição HTTP para a API.                                                                   |
| API                         | Certificar o recebimento e salvamento de dados    | Ao receber uma requisição HTTP de dados enviada pelo Módulo de conexão bluetooth, deve poder salvar os dados no banco de dados |
| API                         | Certificar a disponibilização dos dados           | Testar a disponibilização dos dados                                                                                            |
| Front-end                   | Verificar a visualização dos dados                | Deve ser possível visualizar os dados recebidos da requisição à API                                                            |

___________________________________________________________________________________

## Componentes a serem aprofundados

- Estruturas:
    - O carrinho deve ser construído com materiais leves, mas robustos,
    capazes de suportar os rigores da corrida sem comprometer a integridade do ovo.<br>

- Coleta e Transmissão de Dados: 
    - É fundamental garantir a transmissão de
    dados pelos sensores e exatidão na coleta de informações eficiente para o banco de dados.<br>
- Análise de Consumo Energético: 
    - A principal preocupação energética é o consumo da bateria que alimenta os componentes eletrônicos.<br> 
    Esta análise busca compreender e otimizar o consumo da bateria, assegurando a operação contínua dos sensores e sistemas
    embarcados durante todo o percuso do carrinho.<br>
- Construção de Software: 
    - Abordará as melhores estratégias para o desenvolvi-
    mento, armazenamento e exibição dos dados coletados.

___________________________________________________________________________________

## EAP - Estrutura Analítica de Projeto

Estrutura Análitica do Projeto (EAP) é um diagrama que tem a finalidade de
organizar e decompor o escopo do projeto em pequenas partes, facilitando o entendimento
e a visualização do projeto como um todo.<br>
A EAP é uma ferramenta muito utilizada no gerenciamento de projetos, pois ela permite que
tenha uma visão geral do projeto, podendo assim, identificar os principais entregáveis e
as atividades necessárias para a conclusão do projeto.<br>
Assim, as etapas que foram definidas são:<br>

- Documentação: Fase que envolve a pesquisa teórica e documentação do projeto,
definindo escopo, custo e tempo.<br>
- Estruturas: Fase de desenvolvimento do projeto de estruturas do carrinho. Com
pesquisas teóricas, escolha de materiais e construção da estrutura do projeto.<br>
- Energia: Fase de desenvolvimento do projeto energético, com pesquisas teoricas
sobre consumo energético e escolha dos componentes para o consumo de energia do
carrinho.<br>
- Eletrônica: Fase de desenvolvimento do projeto de eletrônica, com pesquisa de sen-
sores e esquemáticos dos componentes e desenvolvimento dos códigos e calibrações
dos sensores.<br>
- Software: Fase de desenvolvimento do projeto de software, com criação de diagra-
mas e fluxos de usuários, bem como também o desenvolvimento da aplicação que
receberá os dados do carrinho em tempo real.<br>
- Integração: Etapa que corresponde a integração de todos as partes do projeto e
testes de integração para a conclusão do produto.

___________________________________________________________________________________


![EAP](img/EAP_PI1.png)

___________________________________________________________________________________
