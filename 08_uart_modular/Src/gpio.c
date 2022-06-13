#include "gpio.h"

/* Set Port Mode */
void set_pin_mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
	// Clear the relevant bits & set new bits

	MODIFY_REG(	GPIOx->MODER,
				(0x3 << POSITION_VAL(Pin) * 2U),
				(Mode << POSITION_VAL(Pin) * 2U)
			  );
}
