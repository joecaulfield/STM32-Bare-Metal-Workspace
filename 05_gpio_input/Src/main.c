/* Acquiring Input via User Push Button
 * User LED on PI1
 * User Push-Button on PI11
 */

#include "stm32f7xx.h"

#define GPIOE_CLK_EN        (1U<<4)
#define GPIOI_CLK_EN        (1U<<8)
#define USER_LED1_MODER     (1U<<2)
#define PIN11               (1U<<11)
#define BTN_PIN             PIN11

int main (void)
{
	/* Enable clock access to Port E */
	//RCC->AHB1ENR |= GPIOE_CLK_EN;

	/* Enable clock access to Port I */
	RCC->AHB1ENR |= GPIOI_CLK_EN;

	/* Configure LED pins as output pins */
	GPIOI->MODER |= USER_LED1_MODER;

	/* Configure PI11 Push Button as Input Pin */
	GPIOI->MODER &=~ (1U<<22);
	GPIOI->MODER &=~ (1U<<23);

	while (1)
	{
		// Check if button is pressed
		if (GPIOI->IDR & BTN_PIN)
		{
			GPIOI->BSRR = (1U<<1);
		}
		else
			GPIOI->BSRR = (1U<<17);
	}

}
