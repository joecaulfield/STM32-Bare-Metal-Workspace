#include "stm32f7xx.h"


 // User LED on PI1
 // User Push-Button on PI11

#define GPIO_I_EN		(1U<<8)
#define SYSCFGEN		(1U<<14)



void pi11_exti_init(void)
{
	/* Enable clock access to Port I */
	RCC->AHB1ENR |= GPIO_I_EN;

	/* Set PI11 as Input */
	GPIOI->MODER &=~ (1U<<22);
	GPIOI->MODER &=~ (1U<<23);

	/* Enable Clock Access to SYSCFG Module */
	RCC->APB2ENR |= SYSCFGEN;

	/* Clear port selection for EXTI11 */
	SYSCFG->EXTICR[2] &=~ (1U<<12);
	SYSCFG->EXTICR[2] &=~ (1U<<13);
	SYSCFG->EXTICR[2] &=~ (1U<<14);
	SYSCFG->EXTICR[2] &=~ (1U<<15);

	/* Select PI11 for EXTI11 */
		// Bits 12, 13, 14, 15 in SYSCFG_EXTICR3
		// Set 12,13,14,15 to 1000 aka PI[x]
	SYSCFG->EXTICR[2] |= (1U<<15);

	/* Unmask EXTI11 */
		// Set Bit 11 of IMR to '1'
	EXTI->IMR |= (1U<<11);

	/* Select Falling Edge Trigger */
		// Set Bit 11 of FTSR to '1'
	EXTI->FTSR |= (1U<<11);

	/* Enable EXTI11 in NVIC */
	NVIC_EnableIRQ(EXTI15_10_IRQn);

}











