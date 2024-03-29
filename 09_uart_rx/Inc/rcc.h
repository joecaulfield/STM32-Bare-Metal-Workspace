/*
 * rcc.h
 *
 *  Created on: Jun 8, 2022
 *      Author: Joe
 */

#ifndef RCC_H_
#define RCC_H_

#include "stm32f7xx.h"
#include <stdint.h>

void set_apb2_periph_clock(uint32_t periphs);
void set_ahb1_periph_clock(uint32_t periphs);

#endif /* RCC_H_ */
