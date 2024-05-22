
#define V_Bat 7.4
#define ACS712 A0


float A_ACS712 =0;
float P_ACS712 =0;
float E_ACS712 =0;
uint8_t count = 0;

float corrente = 0;
float mediaADC = 0;
void setup() {
  Serial.begin(9600);
  /*pinMode(EncE, INPUT_PULLUP);    
  attachInterrupt(digitalPinToInterrupt(EncE), Inc_EncE, RISING);     //O Sistema irá identificar uma interrupção quando o sinal vai de LOW para HIGH
  pinMode(EncD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EncD), Inc_EncE, RISING);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);*/
  pinMode(2, INPUT_PULLUP);    
  attachInterrupt(digitalPinToInterrupt(2), Inc_EncE, RISING);     //O Sistema irá identificar uma interrupção quando o sinal vai de LOW para HIGH
  
}

void loop() {

 /* Serial.println("Sensor A");
  Serial.println(analogRead(A1));
  Serial.println("Sensor B");
  Serial.println(analogRead(A2));
  Serial.println("Sensor C");
  Serial.println(analogRead(A3));
  Serial.println("Sensor D");
  Serial.println(analogRead(A4));
  delay(1000);*/

  /*analogWrite(5, count);
  analogWrite(6, count);
  Serial.println(count);
  count++;
  delay(100);*/

  /*mediaADC = 0;
  for(size_t i = 0; i< 1000 ; i++){
    mediaADC = mediaADC + analogRead(A0);
  }
  mediaADC = mediaADC/1000;
  Serial.println(mediaADC);
  
  Serial.println("Valor geral ADC");
  Serial.println(mediaADC);
  Serial.println("Tensão no ADC");
  Serial.println(mediaADC*(0.005));
  //MediaCorrente();
  Serial.println("valor da Corrente em mA");
  Serial.println(mediaADC = 5000*(mediaADC-511.5)/511.5); 
  delay(200);*/
}
void Inc_EncE(void){
  Serial.println("Interrupção");




}
void MediaCorrente(void){
  corrente = 0;
  for(uint8_t i = 0; i<100; i++ ){
    corrente = corrente + analogRead(A0);
  }
  corrente = corrente/100;
  corrente = 5000*(corrente-511)/511;
}