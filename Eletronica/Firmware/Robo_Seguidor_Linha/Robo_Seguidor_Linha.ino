#include <TimerOne.h>
#include <math.h>
#include "Robo_Seguidor_Linha.h"

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
#define velb_Dir 255           // Velocidade Básica de PWM motor direito
#define velb_Esq  255       // Velocidade Básica de PWM motor esquerdo
#define Valor_Sensor 5      // Valor a ser comparado com os sensores
#define Inc_Erro 1         // Incremento do erro para os casos do PID
#define Num_Furos 20           // Número de furos do disco encoder
#define Raio_Enc   13         // Valor do raio do disco encoder [mm]
#define Met_L 10              // Metade da largura do robô em [cm]
#define V_Bat 7.4             // Tensão da bateria

enum{
  Distancia,
  PosX,
  PosY,
  Velocidade,
  Aceleracao,
  Corrente,
  Potencia,
  Energia,
  Max,
};  

// Vars para pid
int kp = 35;              // Cte de PID proporção
int ki = 0;               // Cte de PID integral
int kd = 35;              // Cte de PID derivativo
int Erro = 0;
int Erro_Anterior;
int I;                    // Incrementos do PID
int P;
int D;
int PID;
float Vel_Esq;          //Velocidade dos motores
float Vel_Dir;          //  == 
bool sensor[4];           // Vars que representam os sensores de linha

// Vars das leituras dos Encoders
uint8_t Enc_Dir = 0;
uint8_t Enc_Esq = 0;

//Vars para cálculos
float Circun = 2*3.14*Raio_Enc;     // CircunferÊncia do disco encoder caso r= 13 Circun=88.4 [mm]
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

// Vars para transmissão de dados
float Transmit[8];

void setup() {
  //Configurando Serial
  Serial.begin(9600);   // Inicialização da comunicação serial

  // Configurando Motores
  pinMode(M1, OUTPUT);   // Colocando as saídas do PWM
  pinMode(M2, OUTPUT);

  // Configurando Interrupções dos Encoders
  pinMode(EncE, INPUT_PULLUP);    
  attachInterrupt(digitalPinToInterrupt(EncE), Inc_EncE, RISING);     //O Sistema irá identificar uma interrupção quando o sinal vai de LOW para HIGH
  pinMode(EncD, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(EncD), Inc_EncE, RISING);

  //Configurando interrupção do Timer 
  Timer1.initialize(2000);
  Timer1.attachInterrupt(Int_200);

  // O robô só começará a andar quando recebero char R por Serial
  uint8_t n =0;
  Serial.println('Envie R');
  while(n < 1){
    if(Serial.read()== 'R'){n=1;}
  }
    analogWrite(M1,velb_Esq);
    analogWrite(M2,velb_Dir);
}
void loop(){
  Get_Sensor();
  Controle_PID();
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

void Controle_PID(void){
  // Atricuindo Erro
  if((sensor[0]==LOW) && (sensor[1]==LOW) && (sensor[2]==LOW) && (sensor[3]==HIGH)){ Erro = 3 * Inc_Erro;}                        // Atribuo um valor de erro para cada ocasião dos sensores
  else if((sensor[0]==LOW) && (sensor[1]==LOW) && (sensor[2]==HIGH) && (sensor[3]==HIGH)){ Erro = 2 * Inc_Erro;}
  else if((sensor[0]==LOW) && (sensor[1]==HIGH) && (sensor[2]==HIGH) && (sensor[3]==HIGH)) {Erro = Inc_Erro;}
  else if((sensor[0]==LOW) && (sensor[1]==HIGH) && (sensor[2]==HIGH) && (sensor[3]==LOW)) {Erro = 0;}
  else if((sensor[0]==HIGH) && (sensor[1]==HIGH) && (sensor[2]==HIGH) && (sensor[3]==LOW)) {Erro = -1 * Inc_Erro;}
  else if((sensor[0]==HIGH) && (sensor[1]==HIGH) && (sensor[2]==LOW) && (sensor[3]==LOW)) {Erro = -2 * Inc_Erro;}
  else if((sensor[0]==HIGH) && (sensor[1]==LOW) && (sensor[2]==LOW) && (sensor[3]==LOW)) {Erro = -3 * Inc_Erro;}

  // Calculando PID
  if(Erro == 0){I = 0;}        
  P = Erro;
  I = I + Erro;
  if(I>255){I= 255;}
  else if(I<-255){I=-255;}
  D = Erro - Erro_Anterior;
  PID = kp*P+ki*I+kd*D;

  //Mandando PID para motores
  if(PID>=0){
    Vel_Esq = velb_Esq;
    Vel_Dir = Vel_Dir - PID;
    analogWrite(M1,Vel_Esq);
    analogWrite(M2,Vel_Dir);
  }
  else{
    Vel_Esq = Vel_Esq+PID;
    Vel_Dir = velb_Dir;
    analogWrite(M1,Vel_Esq);
    analogWrite(M2,Vel_Dir);
  }

}

// Funções de interrupção dos Encoders]
void Inc_EncE(void){
  Enc_Esq = Enc_Esq+1;    // Para cada pulso somo os encoders
}

void Inc_EncD(void){
  Enc_Dir = Enc_Dir +1;
}

// Função de Interrupção dos Timers

void Int_200(void){
  // Valores absolutos
  Dist =  ((Enc_Dir+Enc_Esq)/2)*Circun/(10*Num_Furos);               // Calculando a distância percorrida em cm
  Vel =   Dist/0.2;                                                      // Calculando a velocidade tangencial a 200 ms
  Dist_Anterior = Dist + Dist_Anterior;                                        // DistÂncia total
  Acel = (Vel-Vel_Anterior)/0.2;            
  Vel_Anterior = Vel;  

  Transmit[Distancia] = Dist_Anterior;
  Transmit[Velocidade] = Vel;
  Transmit[Aceleracao] = Acel;


  //Valores da cinemática
  Dist_Dif_Enc= (Enc_Dir-Enc_Esq)*Circun/(10*Num_Furos);                // Agora se obtem a distÂncia percorrida na difÊncia das rodas, pode ser positivo ou negativo
  Teta = atan(Dist_Dif_Enc/Met_L);
  Vel_X = cos(Teta) * Vel;                                              // Calcula-se a componente da velocidade no eixo X              
  Vel_Y = sin(Teta) * Vel;                                              // Calcula-se a componente da velocidade no eixo Y

  Pos_X = Pos_X + (Vel_X*0.2);                                          // Calcula-se a posição total no eixo X  
  Pos_Y = Pos_Y + (Vel_Y*0.2);                                          // Calcula-se a posição total no eixo Y
  Transmit[PosX] = Pos_X;
  Transmit[PosY] = Pos_Y;   

  Enc_Dir =0;                                                           //Zero o s encoders para próximos calculos
  Enc_Esq =0;

  // Valor do sensor de corrente
  A_ACS712 = analogRead(ACS712)-511.5;                                    // Pego o valor do ADC e Volto ao ponto zero
  A_ACS712 = 5000 * A_ACS712/511.5;                                         // Valor da corrente em [mV]
  P_ACS712 = A_ACS712 * V_Bat;                                            // valor da potência em [mW]
  E_ACS712 = P_ACS712 * 0.2;

  Transmit[Corrente] = A_ACS712;
  Transmit[Potencia] = P_ACS712;
  Transmit[Energia] = E_ACS712;

  // Enviando os dados pelo serial
  for(uint8_t i =0; 1<8; i++){
    Serial.println(Transmit[i]);
  }
  










}
