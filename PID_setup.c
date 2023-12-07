
#include "proyecto.h"
#include "math.h"

float Vo;
float R1=10000;
float logR2, R2, T, x;
float A=1.009249522e-03, B=2.378405444e-04, C=2.019202697e-07;

// Variables globales
double lastError = 0;
double integral = 0;
double iTerm;
double derivative;
double dTerm;

// PARAMETROS DEL CONTROLADOR
// PARAMETROS DE LA PLANTA
// SETUP
// Initialize Control Variables
// LOOP
// Leer Temperatura
  
	
	

float	NTC_read(){
	Vo = ADC_read()*(5./5600.);
	R2 = R1 * ((5./(float)Vo) - 1.0);
	logR2 = log(R2);
	T = (1.0 / (A + B*logR2 + C*logR2*logR2*logR2));
  T = T - 273.15;
	return T;
}


double pid(double input, double setpoint, double Kp, double Ki, double Kd, double ts) {
  // Cálculo del error
  double error = setpoint - input;

  // Cálculo del término proporcional
  double pTerm = Kp * error;

  // Cálculo del término integral
  integral += error * ts;
  // Limitar la integral para evitar overflow/underflow
  integral = fmin(fmax(integral, -1000), 1000);
  iTerm = Ki * integral;

  // Cálculo del término derivativo
  derivative = (error - lastError) / ts;
  lastError = error;
  dTerm = Kd * derivative;

  // Salida del PID
  return pTerm + iTerm + dTerm;
}

	


