/*
 * tim.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Joe
 */


#include "tim.h"

#define	TIM1EN		(1U<<0);
#define CR1_CEN		(1U<<0);

void tim1_1hz_init(void)
{
	/* Enable Clock Access to TIM1 */
	RCC->APB2ENR |= TIM1EN;

	/* Set the Prescaler */
	TIM1->PSC = 1600 - 1; // 16,000,000 / 1600 = 10,000

	/* Set the Auto-Reload Value */
	TIM1->ARR = 10000 - 1; // 10,000 / 10,000 = 1Hz

	/* Enable Timer */
	TIM1->CR1 |= CR1_CEN;

}