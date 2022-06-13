

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "adc.h"

int sensor_value;

int main (void)
{
	pf9_adc3_init();

	while(1)
	{
		sensor_value = adc_get_data();
	}
}












