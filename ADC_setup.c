
#include "proyecto.h"

uint32_t val;
uint16_t i;

void ADC_setup(){
	ADC_port_init();
  start_adc();
	systick_delay_ms(500); 		// Small delay to finish setup
  ADC_start_convertion();
}

void ADC_port_init(void){
	RCC->AHBENR |= IOPB;			// Enable GPIOB
	GPIOB->MODER |= PB1;			// Set PB1 in Analog Mode
	RCC->AHBENR |= ADC12_EN;	// Enable ADC
	
	// Set ADC common params (clock source and prescaler if necessary)
  // Clear the CKMODE bits
  ADC12_COMMON->CCR &= ~(0x3U<<16);
  // Set the source clock to Synchronous
  ADC12_COMMON->CCR |= (1U<<17);
	
	// Enable the watchdog 1 
	ADC1->CFGR |= EN_AWD1;
	// Analog watchdog 1
	ADC1->CFGR |= (1U<<23);		// Regular xAWD1EN
	ADC1->CFGR &=~ (1U<<24);	//Injected(JAWD1EN)
	
	// Analog watchdog 1 channel selection
	ADC1->CFGR &=~ CH12_CFGR;
	ADC1->CFGR |=  CH12_CFGR;
	
	// PB1 se encuentra en el ADC1_IN12
	ADC1->SQR1 &=~ CH12_SQR1;
	ADC1->SQR1 |=  CH12_SQR1;
	
	// Continuous conversion mode
	ADC1->CFGR |= (1U<<13);	// (CONT)
}


void start_adc(void) {
  // Enable ADC module and voltage regulator
  // Voltage regulator (intermediate mode first)
  ADC1->CR &=~ (1U<<29);
  ADC1->CR &=~ (1U<<28);

  // Voltage regulator enabled
  ADC1->CR |= (1 << 28);	

  // Enable ADC module
  ADC1->CR |= (1 << 0);	// (ADEN)
}


void ADC_start_convertion(void){
	// Comenzando la conversion 
	ADC1->CR |= START_CONV;

}  

void systick_delay_ms(uint16_t delay) {
	// Reload with number of clocks per millisenconds (8MHz)
	SysTick->LOAD = 8000;
	// Clear Systick current value register
	SysTick->VAL = 0;
	// Enable Systick and select internal clock source
	SysTick->CTRL = (1U<<0) | (1U<<2);

	for(i=0; i<delay; i++) {
		// wait till the COUNTFLAG is set
		while((SysTick->CTRL & (1U<<16)) == 0) {}
	}
	SysTick->CTRL=0;
}

uint32_t ADC_read(void){
    // read converter results (DR)
    //return (ADC1->DR);
	return ADC1->DR;
}
