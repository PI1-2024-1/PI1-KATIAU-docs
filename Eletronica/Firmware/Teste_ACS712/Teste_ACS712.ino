
#define V_Bat 7.4
#define ACS712 A0


float A_ACS712 =0;
float P_ACS712 =0;
float E_ACS712 =0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  A_ACS712 = analogRead(ACS712)-511.5;                                    // Pego o valor do ADC e Volto ao ponto zero
  A_ACS712 = 5000 * A_ACS712/511.5;                                         // Valor da corrente em [mV]
  P_ACS712 = A_ACS712 * V_Bat;                                            // valor da potência em [mW]
  E_ACS712 = P_ACS712 * 0.2;
  Serial.println(A_ACS712);
  Serial.println(P_ACS712);
  Serial.println(E_ACS712);
}
