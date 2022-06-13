/*
 * On-Board LED is off of PI1
 */

#define PERIPH_BASE        0x40000000UL
#define AHB1_OFFSET        0x00020000UL
#define AHB1PERIPH_BASE    PERIPH_BASE + AHB1_OFFSET
#define GPIOI_OFFSET       0x2000UL
#define GPIOI_BASE         AHB1PERIPH_BASE + GPIOI_OFFSET
#define RCC_OFFSET         0x3800UL
#define RCC_BASE           AHB1PERIPH_BASE + RCC_OFFSET
#define AHB1EN_R_OFFSET    0x30UL
#define RCC_AHB1EN_R       (* (volatile unsigned int *) (RCC_BASE + AHB1EN_R_OFFSET))	// Register
#define MODER_OFFSET       0x00UL
#define GPIOI_MODE_R       (* (volatile unsigned int *)(GPIOI_BASE + MODER_OFFSET))	// Register
#define ODR_OFFSET         0x14UL
#define GPIOI_OD_R         (* (volatile unsigned int *)(GPIOI_BASE + ODR_OFFSET))		// Register
#define GPIOI_CLK_EN       (1U<<8)
#define USER_LED1_MODER    (1U<<2)
#define USER_LED1          (1U<<1)

int main (void)
{
	/* Enable clock access to Port I */

	RCC_AHB1EN_R |= GPIOI_CLK_EN;

	/* Configure LED pins as output pins */
	GPIOI_MODE_R |= USER_LED1_MODER;

	while (1)
	{
		/* Turn on all LEDs */
		//GPIOI_OD_R |= USER_LED1;

		// Experiment 2 : Toggle

		GPIOI_OD_R ^= USER_LED1;
		for (int i = 0; i < 1000000; i++) {}
	}

}
