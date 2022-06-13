#include "led.h"
#include "stm32f7xx.h"

void user_leds_init(void)
{
	RCC->AHB1ENR |= GPIOI_CLK_EN;

	GPIOI->MODER |= USER_LED1_MODER;
}

void all_leds_on(void)
{
	GPIOI->ODR |= USER_LED1;
}

void all_leds_off(void)
{
	GPIOI->ODR &=~ USER_LED1;
}
