/*
 * uart.c
 *
 *  Created on: May 20, 2025
 *      Author: billcipher
 */


#include "uart.h"



///TODO
// Initialize UART1 (PA9=TX, PA10=RX)
void UART1_Init(void) {

}

// Send a single byte
void UART1_Send(uint8_t data) {

}

// Receive a byte (blocking, with timeout)
uint8_t UART1_Receive(void) {
}

// Send a string (for debugging)
void UART1_SendString(char *str) {
    while(*str) {
        UART1_Send(*str++);
    }
}



//UART 2



void UART2_Init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    GPIOA->MODER |= (2 << GPIO_MODER_MODER2_Pos) | (2 << GPIO_MODER_MODER3_Pos);
    GPIOA->AFR[0] |= (7 << (4*2)) | (7 << (4*3)); // AF7
    USART2->BRR = 69; // 115200 baud @ 8MHz
    USART2->CR1 = USART_CR1_UE | USART_CR1_TE;
}

void UART2_Send(uint8_t data) {
    while(!(USART2->ISR & USART_ISR_TXE));
    USART2->TDR = data;
}

void UART2_SendString(char *str){
    while(*str) {
        UART2_Send(*str++);
    }
}
