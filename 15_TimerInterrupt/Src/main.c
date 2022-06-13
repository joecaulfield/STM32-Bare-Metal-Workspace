#include "stm32f7xx.h"
#include <stdio.h>
//#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

static void tim1_update_callback(void);

int main (void)
{
	//uart6_tx_init();

	user_leds_init();
	tim1_1hz_interrupt_init();

	while(1)
	{

	}

}

static void tim1_update_callback(void)
{
	/* Do Something */
	all_leds_toggle();
}

void TIM1_UP_TIM10_IRQHandler(void)
{
	/* Check whether update interrupt is pending */
	if ((TIM1->SR * SR_UIF) !=0)
	{
		/* Clear the update interrupt flag */
		TIM1->SR &=~ SR_UIF;

		/* Do something */
		tim1_update_callback();

	}
}