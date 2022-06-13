
#include "stm32f7xx.h"

#ifndef TIM_H_
#define TIM_H_


void tim1_1hz_init(void);
void tim1_1hz_interrupt_init(void);

#define SR_UIF		(1U<<0)


#endif /* TIM_H_ */
