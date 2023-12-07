
#include "proyecto.h"

void GPIO_setup(void){
	RCC->AHBENR |= (1U<<17);				// Enable clock access to GPIOA
	
	GPIOA->MODER |=  (1U<<12);			
	GPIOA->MODER &= ~(1U<<13); 			// Configure the PA6 as output
	
	GPIOA->ODR &= ~(1U<<6);					// Output pin PA6=LOW
}
