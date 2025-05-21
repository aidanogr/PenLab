#include "stm32f303xe.h"
#include "uart.h"
#include "general_functions.h"
#include "bno0xx.h"
#include <stdio.h>


// Simple blocking delay (not precise, but works)
void delay(uint32_t count) {
    while(count--);
}


int main(void) {

	UART2_Init();
	UART2_SendString("Hello WOrld");
	//uart_printf("Hello WOrld");
    initialize_BNO_UART_RVC();    //configures UART1 for BNO
    while(1) {
    	print_bno_data();
    }
}
