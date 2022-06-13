

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "adc.h"

int sensor_value;

int main (void)
{
	user_leds_init();
	pf9_adc3_interrupt_init();


	while(1)
	{
		//all_leds_on();
	}
}

static void adc_conversion_complete_callback()
{
	sensor_value = ADC3->DR;

	if (sensor_value > 1024)
		all_leds_on();
	else
		all_leds_off();
}

void ADC_IRQHandler(void)
{
	/* Check if End-of-Conversion Interrupt occurred */
	if ((ADC3->SR & SR_EOC) == SR_EOC)
	{
		/* Clear EOC Flag */
		ADC3->SR &=~ SR_EOC;

		/* Do Something */
		adc_conversion_complete_callback();
	}
}












