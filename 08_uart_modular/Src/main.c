/* REFACTOR OF PROJECT 6 FOR USART6, AND USING UART TO USB CONVERTER!
 * Port C - PC6 / PC7 / PC8 [AF8]
 */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"




int main (void)
{
	int x;
	uart6_tx_init();

	while (1)
	{
		printf("Testing UART!!\n\r");

		for (int i = 0; i < 9000; i++)
		{
			x++;
		}
	}
}












