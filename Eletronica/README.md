# Aqui se encontram as informações referentes à área de Eletrônica
--------------------------------------------------------------------------
### Reuniões no discord às terças e quintas 18:00 de acordo com demanda
-----------------------------------------------------------------------------
## Informações sobre os sistemas eletrônicos do robô
------------------------------------------------------------------------------
### 1 - Sistema de Controle

* **1 Placa arduino uno R3** - comumente utilizada em projetos simplificados em robótica;

### 2 -  Sistema de Aquisição para movimentação

* **4 Sensores Ópticos Reflexivos TCRT-5000** -  são utilizados quando as distâncias de medição são pequenas; [Datasheet TCRT5000](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Datasheets/TCRT5000.PDF)


### 3 -Sistema de Comunicação

* **1 Módulo Bluetooth Serial Rs232 Escravo Hc-06** -  converte os dados de medições do arduino e envia por Bluetooth, sendo possível a criação do banco de dados pedido; [Datasheet Hc-06](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Datasheets/HC-06.PDF)

### 4 - Sistema de medição para dados

* **2 Sensor de velocidade módulo encoder** - desacoplador óptico, com ele é possível calcular a distância, velocidade e aceleração;  [Datasheet encoder](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Datasheets/Encoder.pdf)
* **2 Discos encoder para medição com módulo encoder**;
* **1 Medidor de Corrente ACS 712** - é um medidor de corrente invasivo, porém não é necessário nenhum dimensionamento de circuito adicional; [Datasheet ACS 712](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Datasheets/ACS712.PDF)

### 5 - Sistema de movimento

* **1 Regulador de Tensão LM317** - para regular a tensão em até 6V dada a entrada de 7.4;[Datasheet XL 4015](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Datasheets/XL4015.PDF)
* **2 Motores de 6V com redutor e rodas**;[Site compra](link.com) **Colocar link**

### 6 - Bateria	
#### Dado como exemplo, deve ser revisado pela área de energia
* **2 Baterias Recarregáveis de 3.7 V 18650** - totalizando 7.4 V;
	
### 6 - Componentes Complementares

| Quantidade | Nome | Aplicação |
| ---------- | ---- | --------- |
| **6** | **Resistor 100 ohm** | **Sensores** |
| **4** | **Resistor 1k ohm** | **Sensores** |
| **1** | **Resistor 3k3 ohm**  | **Comunicação** |
| **1** | **Resistor 5k  ohm** | **Comunicação** |
| **2** | **Transistor BC547**  | **Movimento** |
| **2** | **Diodo 1N4007** | **Movimento** |
| **1** | **Suporte para 2 Baterias 18650** | **Bateria** |
| **1** | **Placa Perfurada** |**Montagem** |
| **2** | **Chaves/Interruptores** | **Segurança do circuito** |  

----------------------------------------------------------------------------------------------		
## Informações por área
**Vide [Esquemático](https://github.com/PI1-2024-1/PI1-2024-1/blob/main/Repo%20-%20Eletronica/Esquemáticos/Segundo%20esquemático/Esquemático%202.pdf)**
### Estruturas

* **Placa Arduino uno R3**: Dimensões 10.0 x 6.0 x 3.0 [cm], peso 0.058 kg;
* **Sensores TCRT-5000**: Dimensões 10 x 5.6 x 7 [mm], esses sensores serão soldados na placa perfurada, juntamente com os resistores, são ligados diretamente à placa arduino;
* **Módulo Bluetooth Hc-06**: Dimensões 5 x 3 x 1 [cm], ligada ao arduino e alimentada por ele;
* **Sensores de Velocidade módulo encoder**: Dimensões 32 x 14 x 7 [mm], cada um deve estar próximo de um eixo de rotação, pois o disco encoder passa pelo optoacoplador do sensor;
* **Discos encoder 20 furos**: espessura 2.6 [mm], Diâmetro 25 [mm], perímetro 78.74 [mm], cada furo corresponde a 3.92 [mm]. Os discos deves estar acoplados a um eixo de rotação, para que cada furo passante pelo sensor encoder gere um pulso elétrico, podendo assim calcular a tragetória, velocidade e aceleração;  
* **Medidor de corrente  ACS712**: Dimensões 30 x 12 x 12 [mm] conectado às baterias e ao arduíno;
* **Regulador de tensão XL 4015**: Dimensões 54 x 23 x 15 [mm];
* **Motor 6V com redutor**: Dimensões: 70 x 37 x 23 [mm];
* **Suporte para baterias**: Dimensões 75 x 41 x 20 [mm];

**...**

### Firmware
* **Sensores TCRT-5000**: os sensores entregam tensões de 0 a 5V, deve-se calibrar uma variável que indica se está na linha ou não;
* **Módulo Bluetooth Hc-06**: Só é necessário o envio pela porta serial;
* **Sensores de Velocidade módulo encoder**: Envia um pulso quando passa por um buraco no disco encoder;
* **Discos encoder 20 furos**: cada furo corresponde a 3.92 [mm]. 
* **Motor 6V com redutor**: Para movimento do motor deve-se enviar o sinal PWM pelas saídas definidas no esquemático;
* **Medidor de corrente  ACS712**: Entrega uma tensão, que para o cálculo da corrente, deve ter uma variável calibrada. Correntes negativas também geram tensões positivas;

### Software
* **Os dados serão recebidos por software em forma de vetor dados = [Enc direito; Enc esquerdo; velocidade; aceleração] o cálculo da posição relativa do robô é mais fácilmente calculado em software do que em firmware, assim a cada período de comunicação serão enviados os valores do encoder daquele período, por exemplo:**   
  	* Enc direito = 2; Enc esquerdo = 4; sabe-se que o carrinho andou uma distância em linha reta e outra  para a  direita;

### Eletrônica / Energia 
* **Placa arduino**: alimentação 7.4V;
* **Módulo Bluetooth Hc-06**: alimentação 5V, **Obs** Deve ser desligado quando estiver programando o arduino;
* **Sensores Encoder**: alimentação 5V;
* **Medidor de corrente ACS 712**: alimentação 5V;
* **Regulador de Tensão LM317**: Tensão de entrada 7.4V, saída de 5V, deve ser regulada para atender à corrente dos Motores

#### Dado como exemplo, deve ser revisado pela área de energia
* **Baterias 18650**: Duas baterias em série totalizando 7.4V, pode ser alterada para outro arranjo de outras baterias com tensões entre 7 e 12V porque é o limite de entrada do arduino. 

## Item emprestados do Felipe
* 2 Motores 6V
* 2 Discos encoder
* 1 Hc06
* 2 Rodas
* 2 Baterias 18650
* 1 Carregador das Baterias
* 1 Suporte das Baterias
