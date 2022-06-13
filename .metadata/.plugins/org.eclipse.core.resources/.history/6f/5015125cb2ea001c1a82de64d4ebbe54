#include "systick.h"
#include "stm32f7xx.h"

#define SYSTICK_LOAD_VAL		16000
#define CTRL_ENABLE				(1U<<0)
#define CTRL_CLKSRC				(1U<<2)
#define CTRL_COUNTFLAG			(1U<<16)

#define ONE_SEC_LOAD			16000000
#define CTRL_TICKINT			(1U<<1)


void systickDelayMs(int delay)
{
	/***** Reload the number of clocks per millisecond *****/
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	/***** Clear the Current Value Register *****/
	SysTick->VAL = 0;

	/***** Select Clock Source and Enable SysTick *****/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	/***** Implement Delay *****/
	for(int i = 0; i < delay; i++)
	{
		// Wait until Count Flag is set
		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0) {}
	}

	SysTick->CTRL = 0;
}

void systick_1Hz_interrupt(void)
{
	/* Reload the number of clocks per millisecond */
	SysTick->LOAD = SYSTICK_LOAD_VAL - 1;

	/* Clear the Current Value Register */
	SysTick->VAL = 0;

	/* Select Clock Source and Enable SysTick */
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC;

	/* Enable Systick Interrupt */
	SysTick->CTRL |= CTRL_TICKINT;
}
