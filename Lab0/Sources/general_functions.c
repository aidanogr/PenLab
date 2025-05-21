/*
 * general_functions.c
 *
 *	quick functions for debugging, timer, etc.
 *  Created on: May 20, 2025
 *      Author: billcipher
 */
#include "general_functions.h"

void uart_printf(char* string) {
	UART2_Init();
	UART1_SendString(string);
}



