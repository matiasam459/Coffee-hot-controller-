
#include "proyecto.h"

void PWM_setup(){
   
   GPIO_Init();								// GPIO Config
   TIM2_Init();								// TIM2 PWM Config
   
   //while(1){
		 //PWM_Incremental();
		 //pwmWrite();
		 //}
}


void Pulse_width(uint32_t PWM){
	TIM2->CCR1 = PWM;
}

void GPIO_Init(){
	RCC->AHBENR |= (1 << 17);		// Enable GPIOA
	GPIOA->MODER |= (1 << 11);	// Set PA5 to AF
	GPIOA->AFR[0] |= (1 << 20); // AF1 en el PA5
}

void TIM2_Init(){
	RCC->CFGR &= ~(1U << 10); 	// Set APB1 = 8 MHz
  RCC->APB1ENR |= (1 << 0); 	// Enable TIM2
	TIM2->PSC = 8-1; 						// Setting the clock frequency to 1MHz.
  TIM2->ARR = 20000; 					// Period of the timer 20ms (1/1MHz)
  TIM2->CNT = 0;
  TIM2->CCMR1 |= (0x6 << 4); 	// 0110: PWM mode for the timer						
  TIM2->CCER |= 1; 						// Capture mode enabled channel 1 as output
  TIM2->CCR1 = 0; 					// Pulse width for PWM
	TIM2->CR1 |= (1 << 0);			// Counter Enable
}

void TIM3_ms_Delay(uint32_t delay){
  RCC->APB1ENR |= (1 << 1); 							// Enable TIM3
  TIM3->PSC = 8000-1; 							// Setting the clock frequency to 1kHz.
  TIM3->ARR = (delay); 							// Total period of the timer
  TIM3->CNT = 0;
  TIM3->CR1 |= 1; 									 // Start the Timer
  while(!(TIM3->SR & TIM_SR_UIF)){}  // Polling the update interrupt flag
	TIM3->SR &= ~(1U << 0); 					   // Reset the update interrupt flag
}

void PWM_Incremental(){
	if(TIM2->CCR1 < 65400){						// 16bits = 65536
			TIM2->CCR1 = TIM2->CCR1 + 100;	// Increases Pulse Width by 100
      TIM3_ms_Delay(10);							// Delay
    }
    else{
      TIM2->CCR1 = 0;					 // Pulse Width = 0
      TIM3_ms_Delay(10);       // Delay
}}
/*
void PWM_ctrl_Tont(void){
if ((90<T)&&(T<100)){
    x=0.005;
  }else if(T>100){
    x=0;
  }else if(T>80){
    x=0.02;
  }else if(T>70){
    x=0.05;
  }else if(T>60){
    x=0.10;
  }else if(T>50){
    x=0.15;
  }else{
    x=0.20;
  }}
*/
void pwmWrite(){
	val = ADC_read();
	TIM2->CCR1 = val;
}
