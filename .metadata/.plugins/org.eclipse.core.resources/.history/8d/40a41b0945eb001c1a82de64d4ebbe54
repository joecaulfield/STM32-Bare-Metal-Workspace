#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int main (void)
{
	uart6_tx_init();
	tim1_1hz_init();

	while(1)
	{
		/* Wait for UIF */
		while(!(TIM1->SR & SR_UIF)) {}

		/* Clear UIF Bit */
		TIM1->SR &=~ SR_UIF;

		/* Print */
		printf("A second just passed.");
	}

}
