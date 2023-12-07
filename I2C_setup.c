
#include "proyecto.h"
/*
void I2C_setup() {
    // enable clock access to port (Port A)
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // SDA and SCL lines in alternate function mapping table (Pin14 & Pin15)
    // Pin 15 (SCL)
    // set port pin to alternate function
    GPIOA->MODER &= ~(1U << 30);
    GPIOA->MODER |= (1U << 31);

    // Pin 14 (SDA)
    GPIOA->MODER &= ~(1U << 28);
    GPIOA->MODER |=  (1U << 29);

    // output type to open drain
    GPIOA->OTYPER |= (GPIOAPIN15);
    GPIOA->OTYPER |= (GPIOAPIN14);

    // enable pullup
    GPIOA->PUPDR |= (GPIOAPIN30);
    GPIOA->PUPDR &= ~(GPIOAPIN31);

    GPIOA->PUPDR |= (GPIOAPIN28);
    GPIOA->PUPDR &= ~(GPIOAPIN29);

    // enable clock access to i2c
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;

    // configure i2c
    // Buena practica
    // Reset mode in Control register
    // prender i2c

    // Configurar el clock del periferico
    I2C1->TIMINGR |= FREQ_100KHz;

    // Modo el periferico Standard Mode etc
    I2C1->TIMINGR |= Mode;


    // Enable peripheral
    I2C1->CR1 |= PEBIT;


}

void i2cReadByte(char slaveAdd, char memAdd, char* data) {
    // status register
    // Esperar hasta el bus I2C no este ocupado
    while(I2C->ISR & (BUSY)) {}

    // Start generate Control Register

    // Transmit address slave + Write (Read) I2C

    // Esperar a que el address sea enviado
    while() {}

    // Limpiar el bit de address

    // Mandar la infromacion y esperar a que esta sea enviaa

    // Otra vez generar el start

    // Mandar inrofmacion

    // Esperar a qtermine revisar el bit de stop


    // Esperar a a recibir la infromacion
    // Leer la informacion que se recibio del register 


}
*/
