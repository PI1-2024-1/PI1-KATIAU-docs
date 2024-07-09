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
- A utilização do menor CAD possível foi considerada ideal para conceder mobilidade ao projeto do carrinho seguidor de linha.
- Optar por uma estrutura com duas bases: uma base principal e uma base superior.
- Posicionar o ovo e a bateria na base superior para permitir uma melhor distribuição de peso e acessibilidade.
- Colocar os componentes eletrônicos na base principal, abaixo da superior, para facilitar a organização e a manutenção dos circuitos necessários para o funcionamento do carrinho, além de proteger o hardware da luz solar.
- Posicionar os sensores na parte frontal do carrinho, o mais próximo possível do chão, para otimizar a função de seguir a linha.

##### 7.2.2 Condições de Contorno
- Por não possuir uma roda dianteira, provavelmente o carrinho perca velocidade devido ao atrito.
- Posicionamos os sensores em locais onde não houvesse influência do sol e afete a leitura.

##### 7.2.3 Resultados Esperados
- Imprimimos o carrinho com o PLA e esta estrutura cuidadosamente planejada visa otimizar a funcionalidade e a proteção dos componentes do carrinho seguidor de linha, garantindo um desempenho eficiente e seguro. As propriedades do PLA tornam-no um material adequado para impressão 3D, oferecendo a combinação certa de rigidez, resistência, preço e leveza para o projeto.
- Esperamos que o carrinho faça o percuso da forma mais rápida devido ao seu tamanho.
- Ao imprimir, a base superior se encaixasse na base inferior. No entanto, antes de colocar os componentes, percebemos que não ocorreria o encaixe. Portanto, lixamos a peça para que se ajustasse perfeitamente à base inferior, facilitando assim as manutenções caso necessário.

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

##### 7.2.5 Precisão e Acurácia das Medidas 
- Tivemos um erro ao imprimir a peça 3D, pois a base superior deveria se encaixar na base inferior, mas erramos na medida e ela não encaixou corretamente. Para solucionar, improvisamos lixando a peça, o que permitiu um encaixe perfeito.

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
