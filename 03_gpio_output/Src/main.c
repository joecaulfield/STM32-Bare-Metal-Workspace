/* Implementing the same main() function as Project #2 but using the STM32F7
 * header, rather than building the register structs from scratch.
 */

#include "stm32f7xx.h"

#define GPIOI_CLK_EN        (1U<<8)
#define USER_LED1_MODER     (1U<<2)
#define USER_LED1           (1U<<1)

int main (void)
{
	/* Enable clock access to Port I */
	RCC->AHB1ENR |= GPIOI_CLK_EN;

	/* Configure LED pins as output pins */
	GPIOI->MODER |= USER_LED1_MODER;

	while (1)
	{
		//GPIOI_OD_R ^= USER_LED1;
		GPIOI->ODR ^= USER_LED1;
		for (int i = 0; i < 1000000; i++) {}
	}

}
