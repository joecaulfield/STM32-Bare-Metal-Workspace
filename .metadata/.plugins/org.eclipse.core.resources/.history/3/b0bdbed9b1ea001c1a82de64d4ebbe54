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

	while(1)
	{
		printf("A second just passed.");
	}

	systickDelayMs(1000);
}

static void systick_callback(void)
{
	/* Do Something */
}

void SysTick_Handler(void)
{
	systick_callback();
}
