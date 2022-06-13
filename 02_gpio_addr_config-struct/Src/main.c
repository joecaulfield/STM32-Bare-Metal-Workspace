
#include <stdint.h>

#define PERIPH_BASE         0x40000000UL

#define AHB1_OFFSET         0x00020000UL
#define AHB1PERIPH_BASE     PERIPH_BASE + AHB1_OFFSET

#define GPIOI_OFFSET        0x2000UL
#define GPIOI_BASE          (AHB1PERIPH_BASE + GPIOI_OFFSET)

#define RCC_OFFSET          0x3800UL
#define RCC_BASE            (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOI_CLK_EN        (1U<<8)
#define USER_LED1_MODER     (1U<<2)
#define USER_LED1           (1U<<1)

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;
} RCC_TypeDef;

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;

} GPIO_TypeDef;

#define GPIOI	((GPIO_TypeDef *) GPIOI_BASE)
#define RCC		((RCC_TypeDef *) RCC_BASE)

int main (void)
{
	/* Enable clock access to Port I */
	RCC->AHB1ENR |= GPIOI_CLK_EN;

	/* Configure LED pins as output pins */
	GPIOI->MODER |= USER_LED1_MODER;

	while (1)
	{
		//GPIOI_OD_R ^= USER_LED1;
		GPIOI->ODR ^= USER_LED1;
		for (int i = 0; i < 20000; i++) {}
	}

}












