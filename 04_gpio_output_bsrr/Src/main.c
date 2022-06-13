/* Implementing a blinking LED using the BSRR (Bit Set - Reset Register)
 * rather than via the Output Data Register
 * User LED on PI1
 */

#include "stm32f7xx.h"

#define GPIOI_CLK_EN        (1U<<8)
#define USER_LED1_MODER     (1U<<2)

int main (void)
{
	/* Enable clock access to Port I */
	RCC->AHB1ENR |= GPIOI_CLK_EN;

	/* Configure LED pins as output pins */
	GPIOI->MODER |= USER_LED1_MODER;

	while (1)
	{

		// Write bit '1' at Pos 1 (Set)
		GPIOI->BSRR = (1U<<1);
		for (int i = 0; i < 1000000; i++) {}

		// Write bit '1' at Pos 17 (Reset)
		GPIOI->BSRR = (1U<<17);
		for (int i = 0; i < 100000; i++) {}
	}

}
