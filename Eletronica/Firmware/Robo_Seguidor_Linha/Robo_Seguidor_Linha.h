/*
 * File:    Robo_Seguidor_Linha.h
 * Author:  Pedro Zago
 *
 */

 /**
 * Definição de funções do código
 */

/**
* Função que pega as leituras do ADC e compara com um valor de base para verificar a posição dos sensores na linha
*/
void Get_Sensor(void);

/**
* Função que faz cálculo do PID e já atualiza PWM dos motores
*/
void Controle_PID(void);

/**
* Função de interrupção com deboucing e incrementa o número de pulsos do motor esquerdo
*/
void Inc_EncE(void);

/**
* Função de interrupção com deboucing e incrementa o número de pulsos do motor direito
*/
void Inc_EncD(void);

/**
* Função que faz cálculos de cinemática e estados dos sensores  e transmite pelo Serial
*/
void Int_200(void);