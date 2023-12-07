
#include "proyecto.h"
/*
void uart2_tx_init(void);
void uart2_write(int ch);

void uart2_tx_init(void) {
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Configurar el UART del GPIO
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		
// 1. Enable clock to GPIO
	RCC->AHBENR |= ( 1U<<17 );	// Activates IOPA
	
// 2. Set Port mode to AF
	
	//	PA2 = Tx			PA3 = Rx
	// Activa el PIN 2 (PA2) en Alternate Function
	GPIOA->MODER &= ~( 1U << 4);	
	GPIOA->MODER |=  ( 1U << 5); 	
	
// 3. Set Port Alternate Function type to ?
	GPIOA->AFR[0] &= ~(1U << 11);
	GPIOA->AFR[0] |= (0x7U << 8);
	
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Configurar UART module (Character transmission procedure)
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// 1. Enable clock to USART module
	RCC->APB1ENR |=  ( 1U<<17 );	// Activates USART2
	
// 2. Set BaudRate = 115200 bits/s
			// HSI 8 MHZ RC oscillator clock --- frec_APB / BaudRate
			// 8MHz / 115200 = 69.44 ahora 69 en Hexadecimal es 45
			
			USART2->BRR &= ~(0x45U << 0);
			USART2->BRR |=	(0x45U << 0);

// 3. Set transfer Direction
	USART2->CR1 |= ( 1U << 3 );		// TE bit 3 de USART_CR1 y RE bit 2

// 4. Enable USART2
	USART2->CR1 |= ( 1U << 0 );
}

void uart2_write(int ch) {
	
// 1. Wait for tansmit data register to be empty
	while(((USART2->ISR & ( 1U << 7 ))) == 0x00 ){
	//	USART interrupt and status register (USART_ISR)
	//	TXE: Transmit data register empty
	}
	
// 2. Transmit the data
	USART2->TDR = (ch & 0xFF);
}

int main(void) {
	uart2_tx_init();
	while(1){
		uart2_write('b');
	}
}
*/
