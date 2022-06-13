/* REFACTOR OF PROJECT 6 FOR USART6, AND USING UART TO USB CONVERTER!
 * Port C - PC6 RX / PC7 TX / PC8 [AF8]
 */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"

char ch;

int main (void)
{
	user_leds_init();
	uart6_rxtx_init();

	while (1)
	{
		ch = uart_read(USART6);

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












