/*
	ADC_IN0		ARD A0		PA0
	ADC_IN8		ARD A1		PF10
	ADC_IN7		ARD A2		PF9
	ADC_IN6		ARD A3		PF8

	PF9 is ADC3_IN7 accessed by ARD A2
 */


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include "stm32f7xx.h"

void pf9_adc3_init(void);
uint32_t adc_get_data(void);
void pf9_adc3_interrupt_init(void);
#define SR_EOC			(1U<<1)

#endif /* ADC_H_ */
