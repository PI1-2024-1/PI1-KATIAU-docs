#include <TimerOne.h>
#include <math.h>
#include "Robo_Seguidor_Linha.h"
#include <ArduinoJson.h>
#include "string.h"

// Defines importantes
// Portas
#define EncE 2              // Porta onde estão conectados os encoders
#define EncD 3
#define M1 5               // Porta do motor Esquerdo M1
#define M2 6               // Porta do motor direito M2
#define ACS712 A0           // Porta analógica do sensor de corrente
#define Sensor1 A1         // Portas analógicas do sensores de linha
#define Sensor2 A2
#define Sensor3 A3
#define Sensor4 A4

// Constantes a serem alteradas posteriormente
#define velb_Dir 120           // Velocidade Básica de PWM motor direito
#define velb_Esq  110       // Velocidade Básica de PWM motor esquerdo
#define Valor_Sensor 20      // Valor a ser comparado com os sensores
#define Inc_Erro 5         // Incremento do erro para os casos do PID
#define Num_Furos 20           // Número de furos do disco encoder
#define Raio_Enc   1.3         // Valor do raio do disco encoder [mm]
#define Met_L 8.75              // Metade da largura do robô em [cm]
#define V_Bat 8.00             // Tensão da bateria


// Vars para pid
bool sensor[4];           // Vars que representam os sensores de linha
uint8_t Cont_Par = 0;
int8_t Erro = 0;

uint16_t sensor_value[4] = {24, 73, 84, 150};

// Vars das leituras dos Encoders
uint16_t Enc_Dir = 0;
uint16_t Enc_Esq = 0;

//Vars para cálculos
const float Dist_Furos = 2 *3.14*Raio_Enc/Num_Furos;      // CircunferÊncia do disco encoder caso r= 13 Circun=88.4 [cm]
uint16_t Dist = 0;                       // Distância percorrida [cm]
uint16_t Dist_Anterior =0;                // DistÂncia anterior
float Vel =   0.0;                    // Velocidade tangencial [cm/s]
float Vel_Anterior = 0.0;             // Velocidade vel anterior
float Vel_X = 0.0;                  // Velocidade em X [cm/s]
float Vel_Y = 0.0;                  // Velocidae em Y [cm/s]
float Teta =  0.0;                   // Ângulo do robô
float Pos_X = 0.0;                   // Pos em X
float Pos_Y = 0.0;                  // Pos em Y
float Acel = 0.0;                   // Aceleração [cm/s2]
int Dist_Dif_Enc = 0;               // DistÂncia diferencial dos encoders [cm]

float A_ACS712 =0;
float P_ACS712 =0;
float E_ACS712 =0;

bool Count_INCE = false;          // Booleanos para cálculo de deboucing das interrupções
bool Count_INCD = false;  

//Inicializando objeto JSON
StaticJsonDocument<200>jsonDoc;


void setup() {
  //Configurando Serial
  Serial.begin(9600);   // Inicialização da comunicação serial

  // Configurando Motores
  pinMode(M1, OUTPUT);   // Colocando as saídas do PWM
  pinMode(M2, OUTPUT);

  // Calibrando sensores de linha
  Calibrate();

  // Configurando Interrupções dos Encoders
  pinMode(EncE, INPUT_PULLUP);    
  attachInterrupt(digitalPinToInterrupt(EncE), Inc_EncE, HIGH);     //O Sistema irá identificar uma interrupção quando o sinal vai de LOW para HIGH
  pinMode(EncD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EncD), Inc_EncE, HIGH);


  // O robô só começará a andar quando recebero char R por Serial
  while(!Serial.available()){};

  //Configurando interrupção do Timer 
  Timer1.initialize(2000000);
  Timer1.attachInterrupt(Int_500, 2000000);

  // O robô só começará a andar quando recebero char R por Serial
  uint8_t n =0;
  //Serial.println('Envie R');
  /*while(n < 1){
    if(Serial.read()== 'R'){n=1;}
  }*/
    analogWrite(M1,velb_Esq);
    analogWrite(M2,velb_Dir);


}
void loop(){
  Get_Sensor();
  Erro_C();
}

//Funções de Controle Movimento

void Get_Sensor(void){
  for(uint8_t i=0; i<4; i++){                     // Para cada porta analógica testo a presença do sensor na linha
    if(analogRead(A1+i) <= Valor_Sensor){
      sensor[i] = HIGH;
    }
    else{
      sensor[i] = LOW;
    }
  }
}

void Erro_C(void){
  // Atricuindo Erro
  if((sensor[0]==LOW) && (sensor[3]==LOW)){ Erro = 0;}                        // Atribuo um valor de erro para cada ocasião dos sensores
  else if((sensor[0]==LOW) && (sensor[3]==HIGH)){ Erro = 1;}
  else if((sensor[0]==HIGH) && (sensor[3]==LOW)) {Erro = -1;}
  else if((sensor[0]==HIGH) && (sensor[1]==HIGH) && (sensor[2]==HIGH) && (sensor[3]==HIGH)) {Parada();}
  //Serial.println(Erro);
  Controle();

}

// Funções de interrupção dos Encoders
void Inc_EncE(void){
  detachInterrupt(digitalPinToInterrupt(EncE));
  if(Count_INCE){
    Enc_Esq = Enc_Esq+1;    // Para cada pulso somo os encoders
    Count_INCE = false;
  }
  else{
    Count_INCE = true;
  }
  attachInterrupt(digitalPinToInterrupt(EncE), Inc_EncE, HIGH);
}

void Inc_EncD(void){
  detachInterrupt(digitalPinToInterrupt(EncD));
  if(Count_INCD){
    Enc_Dir = Enc_Dir +1;    // Para cada pulso somo os encoders
    Count_INCD = false;
  }
  else{
    Count_INCD = true;
  }
  attachInterrupt(digitalPinToInterrupt(EncD), Inc_EncD, HIGH);
}

// Função de Interrupção dos Timers

void Int_500(void){
  // Valores absolutos
  Dist =  ((Enc_Dir+Enc_Esq)/2)*Dist_Furos/10;               // Calculando a distância percorrida em cm
  Vel =   Dist/2;                                                      // Calculando a velocidade tangencial a 2000 ms em cm/s
  Dist_Anterior = Dist + Dist_Anterior;                                        // DistÂncia total
  Acel = (Vel-Vel_Anterior)/2;            
  Vel_Anterior = Vel;  
  jsonDoc["distTotal"] = Dist_Anterior;
  jsonDoc["velocidade"] =  Vel;
  jsonDoc["aceleracao"] = Acel;


  //Valores da cinemática
  Dist_Dif_Enc= (Enc_Dir-Enc_Esq)*Dist_Furos/10;                // Agora se obtem a distÂncia percorrida na diferençaa das rodas, pode ser positivo ou negativo
  Teta = atan2(Dist_Dif_Enc,Met_L);
  Vel_X = cos(Teta) * Vel;                                              // Calcula-se a componente da velocidade no eixo X              
  Vel_Y = sin(Teta) * Vel;                                              // Calcula-se a componente da velocidade no eixo Y

  Pos_X = Pos_X + (Vel_X*2);                                          // Calcula-se a posição total no eixo X  
  Pos_Y = Pos_Y + (Vel_Y*2);                                          // Calcula-se a posição total no eixo Y
  jsonDoc["posX"] = Pos_X;
  jsonDoc["posY"] = Pos_Y;   

  Enc_Dir =0;                                                           //Zero o s encoders para próximos calculos
  Enc_Esq =0;

  // Valor do sensor de corrente
  A_ACS712 = fabs((analogRead(ACS712)-511.5)*2.638);                                    // Pego o valor do ADC e Volto ao ponto zero
  P_ACS712 = fabs(A_ACS712 * V_Bat/1000);                                            // valor da potência em [W]
  E_ACS712 = fabs(P_ACS712 * 2);                                                        // Energia em Joules
  jsonDoc["corrente"]= A_ACS712;
  jsonDoc["potencia"]= P_ACS712;
  jsonDoc["energia"] = E_ACS712;

  char jsonStr[200];
  serializeJson(jsonDoc, jsonStr);
  Serial.println(jsonStr);
}

void Calibrate(void){
  uint16_t min[4] , max[4];
  uint16_t val = 0;
  for(size_t i = 0; i<4; i++){
    min[i] = analogRead(A1+i);
    max[i] = analogRead(A1+i);
  }
  analogWrite(M1, 255);
  for(size_t i = 0; i<30000; i++){
    for(size_t n = 0; n<4; n++){
      val = analogRead(A1 + n);
      if(val>max[n]){
        max[n] = val;
      }
      if(val<min[n]){
        min[n] = val;
      }
    }
  }
  for(size_t i = 0; i<4; i++){
    sensor_value[i] = (min[i] + max[i])/2;
  }
  analogWrite(M1, 0);
  analogWrite(M2, 0); 
}

void Parada(void){
  if(Cont_Par == 150){
    analogWrite(M1, 0);
    analogWrite(M2, 0);
    Serial.println("{\"evento\":\"Fim\"}");
    while(1){}
  }
  Cont_Par +=1;
}

void Controle(void){
  if(Erro==0){
    analogWrite(M1, velb_Esq);
    analogWrite(M2, velb_Dir);
  }
  else if(Erro>0 ){
    analogWrite(M1, 175);
    analogWrite(M2,0);
  }
  else if(Erro < 0){
    analogWrite(M1, 0);
    analogWrite(M2, 175);
  }
}
