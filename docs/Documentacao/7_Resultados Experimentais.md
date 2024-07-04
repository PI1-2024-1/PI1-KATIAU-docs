# 7. Resultados Experimentais
___________________________________________________________________________________

## 7.1 Características Gerais

 Introduzir os principais pontos deste capítulo. Cada experimento deve conter explicações completas que garantam sua repetibilidade:

##### 7.1.1 Hipoteses Levantadas

##### 7.1.2 Condições de Contorno

##### 7.1.3 Resultados Esperados

##### 7.1.4 Materiais e Métodos

##### 7.1.5 Precisão e Acurácia das Medidas 


### 7.2 Experimentos da Estrutura

##### 7.2.1 Hipoteses Levantadas

##### 7.2.2 Condições de Contorno

##### 7.2.3 Resultados Esperados

##### 7.2.4 Materiais e Métodos

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
- Calibração dos Sensores:

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