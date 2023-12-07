/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Proyecto Final de Sistemas Embedidos I (IMT-222)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "proyecto.h"
double input = 0;      // Tu valor de entrada
double setpoint = 100; // Tu valor de consigna
double Kp = 0.0185;       // Ganancia proporcional
double Ki = 6.61e-5;       // Ganancia integral
double Kd = 0.00231;      // Ganancia derivativa
double ts = 0.25;      // Tiempo de muestreo
double pid_calc;

int main(){
	// 1. PWM_setup
				// Empieza el DC en 0%
	PWM_setup();
		
	// 2. ADC_setup
				// Un pin de entrada que lea el sensor
	ADC_setup();
	
	//PID_setup();
	//I2C_setup();
	
	//LOOP
	while(1){
		
		input = NTC_read();
		pid_calc = pid(input, setpoint, Kp, Ki, Kd, ts);
		TIM2->CCR1 = pid_calc*(65535/255);
		systick_delay_ms(250);
	}
	
}
