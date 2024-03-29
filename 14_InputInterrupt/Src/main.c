#include "stm32f7xx.h"
#include <stdio.h>
//#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

int main (void)
{
	//uart6_tx_init();

	pi11_exti_init();
	user_leds_init();

	while(1)
	{
		//all_leds_on();
	}

}

static void user_btn_callback(void)
{
	//printf("Button Pressed");
	all_leds_toggle();
}

void EXTI15_10_IRQHandler(void)
{
	if ((EXTI->PR & PIN11) != 0)
	{
		/* Clear PR Flag */
		EXTI->PR |= PIN11;

		// Do Something
		user_btn_callback();
	}
}
