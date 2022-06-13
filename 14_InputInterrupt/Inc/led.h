

#ifndef LED_H_
#define LED_H_

#include "stdint.h"

#define USER_LED1			(1U<<1)
#define USER_LED1_MODER		(1U<<2)
#define GPIOI_CLK_EN		(1U<<8)

typedef uint32_t ledType;

void user_leds_init(void);
void all_leds_on(void);
void all_leds_off(void);
void all_leds_toggle(void);

#endif /* LED_H_ */
