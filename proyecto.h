
#ifndef PROYECTO_H_
#define PROYECTO_H_


#include "stm32f3xx.h"																 // Platform specific header (HW definition)
#include "stm32f3xx_hal.h" 														 // HAL Drivers

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~ Prototipos de funciones ~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Para el MAIN
void PWM_setup(void);
void ADC_setup(void);
void PID_setup(void);
void I2C_setup(void);

extern uint32_t lectura_temp;

// Para PWM_setup
void GPIO_Init(void);
void TIM2_Init(void);
void TIM3_ms_Delay(uint32_t delay);
void Pulse_width(uint32_t PWM);
void PWM_Incremental(void);
void pwmWrite(void);

// Para ADC_setup
void systick_delay_ms(uint16_t delay);
void start_adc(void);
void ADC_port_init(void);
void ADC_start_convertion(void);
uint32_t ADC_read(void);
void led_init(void);
// Variables ADC
extern uint32_t val;
extern uint16_t i;

// Para PID
float	NTC_read(void);
double pid(double input, double setpoint, double Kp, double Ki, double Kd, double ts);
// Variables PID
extern float Vo;
extern float R1;
extern float logR2, R2, T, x;
extern float A, B, C;




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//							Macros
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define PB1 (0x3U << 2)
#define IOPA (1U << 18)
#define IOPB (1U << 18)
#define ADC12_EN (1U<<28)
#define CH12_SQR1 (0xCU<<6)					// C=12 - CH12 on Regular Sequence Register
#define CH12_CFGR (0xCU << 26)			// CH12 on ADC Configuration Register
#define EN_AWD1 (1U<<22)						// Analog WatchDog 1 Single Channel or Multiple

#define CONT (1U<<13)
#define START_CONV (1U<<2)
#define ISR_EOC (1U<<2)


#endif /* LAB4_H_ */
