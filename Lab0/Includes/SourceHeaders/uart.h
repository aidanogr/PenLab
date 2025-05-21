/*
 * uart.h
 *
 *  Created on: May 20, 2025
 *      Author: billcipher
 */

#ifndef INCLUDES_SOURCEHEADERS_UART_H_
#define INCLUDES_SOURCEHEADERS_UART_H_

#include "stm32f303xe.h"



//uart 1 commands (setup to interface with bno085)
//TODO create enum to pass into uart init like "UART_Init(BNO);"?
void UART1_Init(void);
void UART1_Send(uint8_t data);
uint8_t UART1_Receive(void);
void UART1_SendString(char *str);

//uart 2 commands (setup to interface with PUTTY)
void UART2_Init(void);
void UART2_Send(uint8_t data);
void UART2_SendString(char *str);

#endif /* INCLUDES_SOURCEHEADERS_UART_H_ */
