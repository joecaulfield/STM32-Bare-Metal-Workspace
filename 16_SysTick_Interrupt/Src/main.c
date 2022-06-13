#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "adc.h"
#include "systick.h"

int sensor_value;
static void systick_callback(void);

int main (void)
{
	pf9_adc3_init();
	user_leds_init();
	systick_1Hz_interrupt();

	while(1)
	{

	}
}

static void systick_callback(void)
{
	all_leds_toggle();
}

void SysTick_Handler(void)
{
	systick_callback();
}
