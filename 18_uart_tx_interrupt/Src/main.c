/* REFACTOR OF PROJECT 6 FOR USART6, AND USING UART TO USB CONVERTER!
 * Port C - PC6 RX / PC7 TX / PC8 [AF8]
 */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"

static void USART_callback(void);

char ch;

int main (void)
{
	user_leds_init();
	uart6_tx_interrupt_init();

	while (1)
	{

	}
}

static void USART_callback(void)
{
	/* Write value into transmit data register */
	USART6->TDR = 'A';
}

void USART6_IRQHandler(void)
{
	/* Check if TXE Interrupt Occurred */
	if ((USART6->ISR & ISR_TXE) == ISR_TXE)
	{
		/* Do Something */
		USART_callback();
	}
}









