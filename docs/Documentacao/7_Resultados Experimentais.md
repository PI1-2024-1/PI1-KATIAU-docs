# 7. Resultados Experimentais
___________________________________________________________________________________

## Características Gerais

 Introduzir os principais pontos deste capítulo. Cada experimento deve conter explicações completas que garantam sua repetibilidade:

### Hipóteses levantadas

### Condições de contorno

### Resultados esperados

### Materiais e métodos

### Precisão e acurácia das medidas obtidas

### Experimentos da Extrutura

### Experimentos de Hardware

Sensores de linha:

- A tensão dos sensores de linha em contato com material de cor preta, não ultrapassa 200mv, em unidades de ADC dá 41uc (unidades de conversor)
- Feito através do calculo: ADC = V/(5/1023)
- Tensão  em preto de cada sensor 1 representa esquerda e 4 direita: V1=18,1mV; V2=21,1mV; V3=18,3mV; V4= 129mV.
- Por motivos construtivos do sensor e a diferença de proximidade à superfície em relação aos outros sensores, pela estratégia de montagem, o Sensor 4 demonstra uma tensão em preto maior, mas não é algo muito expressivo.
- Tensão em contato com superfície marrom:   V1=226mV; V2=580mV; V3=633mV; V4= 1347mV;
- Mostra-se necessário diferentes constantes de calibração para cada sensor.

Correções a serem feitas após os testes:

- Fazer a devida solda nos terminais dos sensores e da parte de alimentacao;

Observações sobre o processo de programação do microcontrolador:

- Módulo bluetooth deve estar desligado quando se está fazendo a programação do arduino, pois a programação é feita pela porta serial, a mesma utilizada pelo módulo bluetooth. 
- Basta pressionar o botão push button com trava para desligar o módulo.

### Experimentos de Consumo Energético

### Experimentos de Software

### Experimentos de Integração

