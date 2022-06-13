#include "rcc.h"


/* Enable clock access to AHB1 */
void set_ahb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB1ENR, periphs);
}

/* Enable clock access to AHB2 */
void set_ahb2_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->AHB2ENR, periphs);
}

/* Enable clock access to APB1 */
void set_apb1_periph_clock(uint32_t periphs)
{
	SET_BIT(RCC->APB1ENR, periphs);
}

/* Enable clock access to APB2 */
void set_apb2_periph_clock(uint32_t periphs)
	{
		SET_BIT(RCC->APB2ENR, periphs);
	}
