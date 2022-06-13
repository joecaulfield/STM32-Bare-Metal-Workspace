/* REFACTOR OF PROJECT 6 FOR USART6, AND USING UART TO USB CONVERTER!
 * Port C - PC6 RX / PC7 TX / PC8 [AF8]
 */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"

char ch;

static void usart_rx_callback(void);

int main (void)
{
	user_leds_init();
	uart6_rx_interrupt_init();

	while (1)
	{
		//ch = uart_read(USART6);

		switch(ch)
		{
		case '0':
			all_leds_off();
			break;
		case '1':
			all_leds_on();
			break;
		default:
			break;
		}
	}
}

static void usart_rx_callback(void)
{
	ch = (READ_BIT(USART6->RDR, USART_RDR_RDR) & 0XFFU);
}

void USART6_IRQHandler(void)
{
	/* Check if RXNE Interrupt has Occurred */
	if ((USART6->ISR & ISR_RXNE) == ISR_RXNE)
	{
		/* Do Something */
		usart_rx_callback();
	}
}











