#define EncE 2              // Porta onde estão conectados os encoders
#define EncD 3
#define M1 5               // Porta do motor Esquerdo M1
#define M2 6               // Porta do motor direito M2
#define ACS712 A0           // Porta analógica do sensor de corrente
#define Sensor1 A1         // Portas analógicas do sensores de linha
#define Sensor2 A2
#define Sensor3 A3
#define Sensor4 A4
#define V_Bat 8

float A_ACS712 =0;
uint8_t cont = 1;
uint16_t analog = 0;
float v = 0;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  analogWrite(M1,255);
  analogWrite(M2,255);

}

void loop() {

  analog = analogRead(ACS712);
  v = analog * 0.0049;
  A_ACS712 = fabs(((analog-2.5)*1000)/185);                                    // Pego o valor do ADC e Volto ao ponto zero
  Serial.print("ADC: ");
  Serial.println(analog);  
  Serial.print("Tensão: ");
  Serial.println(v);  
  Serial.print("Corrente: ");
  Serial.println(A_ACS712);  
  if(cont == 0){
    analogWrite(M1,cont);
    analogWrite(M2,cont);
  }
  if(cont== 255){
    analogWrite(M1,cont);
    analogWrite(M2,cont);
  }
  delay(200);


}

