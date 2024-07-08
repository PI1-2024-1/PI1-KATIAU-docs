# 7. Resultados Experimentais
___________________________________________________________________________________

## 7.1 Características Gerais

No carrinho existem dois sistemas, um de controle e outro de telemetria, cada um desses dois sistemas  é dividido em outros subsistemas como mostra a seguir:

#### Sistema de Controle:

Aquisição dos sensores de linha:

- O circuito é composto por sensores de linha que entregam diferentes sinais de tensão de acordo com a distância do objeto ou no nosso caso, a cor da linha. Então basta calibrar cada sensor individualmente para que se obtenha o valor de tensão entregue por cada sensor em contato com a linha preta (o valor mínimo), o valor em contato com outra cor (máximo) e um valor médio (de fronteira);

- Então após a calibração, podemos comparar o valor atual de tensão entregue por cada sensor com o valor de tensão de fronteira calibrado, se a tensão atual for menos, significa que o sensor está em contato com a linha preta, se for maior, não está em contato;

- Guardamos a informação em forma booleana, True (1) quando vê a linha e False (0) quando não vê a linha.

- Os valores são gravados em forma de Array:

$$Sensores[4]={Sensor1,Sensor2,Sensor3,Sensor4}$$

- Em que os sensores estão numerados da seguinte forma, o observador está olhando para a traseira do carrinho, o sensor 1 é o sensor mais à esquerda, e sensor 4 é o mais à direita.

Cálculo do Erro:

- Como são 4 sensores, os possíveis 16 casos de acionamento dos sensores que são:

![sistControle1](img/sistControle1.png)
<h6 align = "center"> Imagem 1: Tabela Verdade dos Sensores.
<br> Autor: Pedro Zago
<br>Fonte: Autor(es)</h6>

Analisamos os casos marcados em laranja: 

- O único caso possível onde um único sensor está em True, é quando estes sensores estão nas extremidades e somente observam a linha porque ela já está saindo do alcance dos sensores;
- Fora estes dois casos, sempre quando um sensor estiver em True, algum dos sensores vizinhos estará em True também, eliminando mais outros casos.

Os casos em amarelo representam: 

- O primeiro representa que o robô perdeu a linha, então ele deve fazer uma curva de acordo com o último dado medido pelos sensores;
- O último representa a condição de parada do robô.

Eliminando os casos e reorganizando as informações obtemos a seguinte tabela e assumimos um erro para cada condição possível, com base em um Incremento de erro base a ser calibrado:

![sistControle2](img/sistControle2.png)
<h6 align = "center"> Imagem 2: Tabela Verdade dos Sensores Reorganizada.
<br> Autor: Pedro Zago
<br>Fonte: Autor(es)</h6>

- X representa que o sensor pode estar em qualquer estado que não interferirá na saída;
- Quando o Erro é positivo, quer dizer que a linha está à direita e o robô deve virar à direita; 
- Quando o Erro é negativo, quer dizer que a linha está à esquerda e o robô deve virar à esquerda.

Cálculo controle:

- O controlador será do tipo bate-bate, ou seja:
- Se o Erro é 1, paramos o motor direito e colocamos a velocidade máxima no motor esquerdo;
- Se o Erro é -1, o motor esquerdo para e o direito recebe tensão máxima;
- Se o Erro é 0, os dois motores recebem tensão máxima.

#### Sistema de Telemetria:

Aquisição dos dados do sensor de corrente elétrica:

- O sensor de 5A tem um ponto médio de 2.5 V na saída que significa 0A;
- O sensor ACD712 5A tem uma sensibilidade de 185 [mv/A], então podemos elaborar uma equação para obter a corrente que passa pelo sensor em função da saída de tensão do sensor;

Primeiramente calculamos a sensibilidade do conversor AD de 10bits do Arduino através de:

$$ADC_Sens=\frac{Vcc}{2^nBits } =\frac{5}{1024}=4.88 [\frac{mV}{bit}]$$

Então calculamos a sensibilidade da corrente em função dos bits do ADC:

$$I_Sens=\frac{1k*ADC_Sens}{ACS_Sens} =\frac{1k*4.88}{185}=26.38 [\frac{mA}{bit}]$$

Calculamos a corrente como:

$$I=(ADC-511.5)*I_Sens=(ADC-511.5)*26.38 [mA]$$

- Aquisição dos valores dos sensores encoder:
- Os sensores encoder são optoacopladores que enviam pulsos quando há interrupção da luz entre seus terminais, nesse caso para adquirir valores do resistor basta criar um contador que irá contar quantas interrupções aconteceram em cada uma das rodas.

![sistControle3](img/sistControle3Encoder.png)
<h6 align = "center"> Imagem 3: Encoder.
<br> Autor: Pedro Zago
<br>Fonte: Autor(es)</h6>

Cálculo da Distância percorrida:

- Denominando EncE e EncD como sensor os contadores de pulsos encoder esquerdo e direito respectivamente.

Sabendo o raio R do disco, seu número de furos Pr, pode-se calcular o perímetro do disco por:

$$P_r=2*π*R [cm]$$

Com o perímetro calculado pode-se calcular a distância entre os furos Df:

$$D_f=\frac{P_r}{N_f} [cm]$$

Pode-se calcular a distância percorrida pela multiplicação da distância entre furos pela média dos contadores encoder:

$$D_t=D_f*(\frac{Enc_E+Enc_D}{2})[cm]$$

Cálculo da Velocidade escalar:

Tendo como base um intervalo de tempo fixo T, pode-se calcular a velocidade escalar como:


$$V=  \frac{D_t}{T}[\frac{cm}{s}]$$

Cálculo do ângulo do robô:

![sistControle4](img/sistControle4.png)
<h6 align = "center"> Imagem 4: Angulação Carrinho.
<br> Autor: Artur Forner Cordeiro
<br>Fonte: Modelos Cinemáticos de Robôs com Rodas PMR3502</h6>

Observando a imagem percebe-se que o carrinho muda sua angulação de acordo com a rotação dos motores, ou seja, tornando possível o cálculo com os contadores encoder:

$$θ=atan(\frac{H}{L})[graus]$$

H seria a distância entre o eixo x da posição final da roda direita e o da posição inicial da roda direita, considerando que o ângulo aumenta no sentido anti-horário:

$$H= Enc_E-Enc_D  [cm]$$

Por conseguinte:

$$θ=atan(\frac{Enc_E-Enc_D}{L})[graus]$$

Cálculo da velocidade vetorial e suas componentes X e Y:
Sabendo o valor da velocidade escalar e o ângulo do carrinho obtemos o vetor Velocidade V ⃗;
É possível desmembrar o vetor velocidade em suas componentes em X e em Y:

$$V_x= V*cos(θ)  [cm/s]$$

$$V_y= V*sen(θ)[cm/s]$$

Cálculo da posição X e Y:

Sabendo as velocidades em X e em Y pode-se calcular a posição em x e em y:

$$P_x=V_x*T [cm]$$

$$P_y=V_y*T [cm]$$

Cálculo da Aceleração:

Denominando Vi como a velocidade escalar atual e Vi-1 a velocidade escalar previamente calculada calcula-se a aceleração como:

$$Ac=  \frac{( V_i-V_(i-1) )}{T}   [cm/s^2 ]$$

### 7.2 Experimentos da Estrutura

##### 7.2.1 Hipoteses Levantadas
- A utilização do menor CAD possível foi considerada ideal para conceder mobilidade ao projeto do carrinho seguidor de linha.
- Optar por uma estrutura com duas bases: uma base principal e uma base superior.
- Posicionar o ovo e a bateria na base superior para permitir uma melhor distribuição de peso e acessibilidade.
- Colocar os componentes eletrônicos na base principal, abaixo da superior, para facilitar a organização e a manutenção dos circuitos necessários para o funcionamento do carrinho, além de proteger o hardware da luz solar.
- Posicionar os sensores na parte frontal do carrinho, o mais próximo possível do chão, para otimizar a função de seguir a linha.

##### 7.2.2 Condições de Contorno

##### 7.2.3 Resultados Esperados

##### 7.2.4 Materiais e Métodos
- Os materiais para a construção das bases e outras partes do carrinho serão impressos em 3D, utilizando o filamento PLA (ácido polilático). O PLA foi escolhido pelo baixo custo e por suas propriedades mecânicas adequadas para este tipo de aplicação, sendo elas:

Densidade: 1250 kg/m³. A densidade do PLA torna-o suficientemente leve para aplicações em pequenos robôs móveis, sem comprometer a resistência estrutural.
Módulo de Young: 3,45x10⁹ Pa. Este módulo de elasticidade indica a rigidez do material, garantindo que o PLA possa suportar a carga sem deformações significativas.
Coeficiente de Poisson: 0,39. Este valor descreve a relação entre a deformação transversal e longitudinal e é relevante para a análise de tensões no material.
Módulo de Bulk: 5,2273x10⁹ Pa. O módulo de bulk, ou módulo de incompressibilidade, mostra a resistência do material à compressão uniforme, importante para a durabilidade do carrinho.
Módulo de Shear: 1,241x10⁹ Pa. Este módulo de cisalhamento mede a resistência do material à deformação por forças de corte, essencial para a integridade das partes impressas em 3D.
Tensão de escoamento: 5,41x10⁷ Pa. A tensão de escoamento indica o ponto em que o material começa a deformar plasticamente, permitindo prever o comportamento do carrinho sob cargas elevadas.
Resistência à Tração: 5,92x10⁷ Pa. Esta resistência à tração máxima mostra a capacidade do material de suportar forças de tração sem falhar, crucial para a durabilidade das peças impressas.

Para garantir a proteção do ovo, ele será colocado em uma caixa cujas laterais estarão revestidas com isopor e espuma. Esta proteção é considerada suficiente, pois o carrinho seguirá uma linha pré-determinada e não estará sujeito a impactos significativos que possam causar danos ao ovo.

Esta estrutura cuidadosamente planejada visa otimizar a funcionalidade e a proteção dos componentes do carrinho seguidor de linha, garantindo um desempenho eficiente e seguro. As propriedades do PLA tornam-no um material adequado para impressão 3D, oferecendo a combinação certa de rigidez, resistência, preço e leveza para o projeto.

##### 7.2.5 Precisão e Acurácia das Medidas 


### 7.3 Experimentos de Hardware

##### 7.3.1 Hipoteses Levantadas

- A precisão dos sensores de linha será suficiente para detectar a diferença entre superfícies de cores diferentes (preto e marrom).
- Sensores calibrados corretamente proporcionarão um bom desempenho do carrinho na detecção da linha.

##### 7.3.2 Condições de Contorno

As condições ambientais, como iluminação e refletividade da superfície, podem afetar as leituras dos sensores.
A uniformidade da superfície e a estabilidade do carrinho durante o movimento também influenciam as medições.

##### 7.3.3 Resultados Esperados

- Os sensores de linha deverão produzir tensões significativamente diferentes quando em contato com superfícies de cores distintas, permitindo a detecção clara da linha.
- Cada sensor terá uma faixa de calibração própria devido às variações construtivas e de montagem.

##### 7.3.4 Materiais e Métodos

Materiais:

- Chassi do carrinho.
- Sensores de linha (4 unidades).
- Superfícies de teste (preta e marrom).
- Multímetro.
- Baterias de alimentação (7V).

Métodos:

Configuração do Sistema:

- Montagem dos sensores de linha no carrinho, garantindo que estejam posicionados para detectar a linha diretamente abaixo.
- Configuração do sistema de aquisição de dados para registrar as tensões dos sensores.

 Calibração dos Sensores:

- Posicionamento do carrinho sobre a superfície preta e realiada a medida da tensão de cada sensor.
- Repetido o procedimento sobre uma superfície marrom.
- Realizado o calculo das unidades ADC para cada medição utilizando a fórmula:
 
$$ADC = \frac{V}{\frac{5}{1023}}$$

Teste de Detecção:

- Condução do carrinho sobre uma linha preta em diferentes condições de luz e superfícies para avaliar a consistência das leituras dos sensores.

##### 7.3.5 Precisão e Acurácia das Medidas 

Tensão dos Sensores em Superfície Preta:

- Sensor 1 (Esquerda): 18,1 mV
- Sensor 2: 21,1 mV
- Sensor 3: 18,3 mV
- Sensor 4 (Direita): 129 mV

Tensão dos Sensores em Superfície Marrom:

- Sensor 1 (Esquerda): 226 mV
- Sensor 2: 580 mV
- Sensor 3: 633 mV
- Sensor 4 (Direita): 1347 mV

### 7.4 Experimentos de Consumo Energético

##### 7.4.1 Hipoteses Levantadas

##### 7.4.2 Condições de Contorno

##### 7.4.3 Resultados Esperados

##### 7.4.4 Materiais e Métodos

##### 7.4.5 Precisão e Acurácia das Medidas 

### 7.5 Experimentos de Software

##### 7.5.1 Hipoteses Levantadas

##### 7.5.2 Condições de Contorno

##### 7.5.3 Resultados Esperados

##### 7.5.4 Materiais e Métodos

##### 7.5.5 Precisão e Acurácia das Medidas 

### 7.6 Experimentos de Integração

##### 7.6.1 Hipoteses Levantadas

##### 7.6.2 Condições de Contorno

##### 7.6.3 Resultados Esperados

##### 7.6.4 Materiais e Métodos

##### 7.6.5 Precisão e Acurácia das Medidas 
