#include "spi.h"

// Master
#define GPIO_A_EN	(1U<<0)
#define SPI1EN		(1U<<12)

// Slave
#define GPIO_B_EN	(1U<<1)
#define SPI3EN		(1U<<15)

/* Configure GPIO Pins PA5 and PA7 for the SPI1 Master */
void spi1_config(void)
{
	/* Enable the Peripheral Clock of GPIOA */
	RCC->AHB1ENR	|= GPIO_A_EN;

	/* Configure SPI1 SCK Pin PA5 ================= */
	// Alternate Function Mode = '10'
	GPIOA->MODER &=~ (1U<<10);
	GPIOA->MODER |= (1U<<11);

	/* Select Alternate Function Mode as AF5 */
	// AF5 = '0101' on Pins 23, 22, 21, 20 of AFRL
	GPIOA->AFR[0] |= (1U<<20);
	GPIOA->AFR[0] &=~ (1U<<21);
	GPIOA->AFR[0] |= (1U<<22);
	GPIOA->AFR[0] &=~ (1U<<23);

	/* Set Pin Speed to 'Very High' */
	GPIOA->OSPEEDR |= (1U<<10);
	GPIOA->OSPEEDR |= (1U<<11);

	/* Enable Internal Pull-Down Resistor on Pin 5 */
	// Pull Down = '10' on Bit 11, 10
	GPIOA->PUPDR &=~ (1U<<10);
	GPIOA->PUPDR |= (1U<<11);

	/* Configure SPI MOSI Pin PA7 ================= */
	GPIOA->MODER &=~ (1U<<14);
	GPIOA->MODER |= (1U<<15);

	/* Select Alternate Function Type as AF5 */
	// AF5 = '0101' on Pins 31, 30, 29, 28
	GPIOA->AFR[0] |= (1U<<28);
	GPIOA->AFR[0] &=~ (1U<<29);
	GPIOA->AFR[0] |= (1U<<30);
	GPIOA->AFR[0] &=~ (1U<<31);

	/* Set Pin Speed to Very High */
	GPIOA->OSPEEDR |= (1U<<14);
	GPIOA->OSPEEDR |= (1U<<15);

	/* Enable Internal Pull Down on PA7 */
	GPIOA->PUPDR &=~ (1U<<14);
	GPIOA->PUPDR |= (1U<<15);

	/* Enable SPI1 Interrupt in NVIC */
	NVIC_EnableIRQ(SPI1_IRQn);

	/* Configure SPI1 Communication Parameters ================= */
	RCC->APB2ENR |= SPI1EN;

	/* Set Clock to fPCLK/256 */
	SPI1->CR1 |= (1U<<3);
	SPI1->CR1 |= (1U<<4);
	SPI1->CR1 |= (1U<<5);

	/* Select TX only */
	SPI1->CR1 |= (1U<<14);

	/* Select 1-Line Bidirectional Data Mode */
	SPI1->CR1 |= (1U<<15);

	/* Set CPOL to '1' and CPHA to '1' */
	SPI1->CR1 |= (1U<<0);
	SPI1->CR1 |= (1U<<1);

	/* Set SPI Data-Width to 8-Bit */
	// 8-Bit = 0111 on Bits 11, 10, 9, 8 of CR2
	SPI1->CR2 |= (1U<<8);
	SPI1->CR2 |= (1U<<9);
	SPI1->CR2 |= (1U<<10);
	SPI1->CR2 &=~ (1U<<11);

	/* Enable Software Slave Management */
	SPI1->CR1 |= (1U<<9);

	/* Enable Slave-Select-Output */
	SPI1->CR2 |= (1U<<2);

	/* Set FIFI Reception Threshold */
	SPI1->CR1 |= (1U<<12);

	/* Enable TXE Interrupt */
	SPI1->CR2 |= (1U<<7);

	/* Enable Master Mode */
	SPI1->CR1 |= (1U<<2);

}

/* Configure GPIO Pins PB3 and PB4 for the SPI3 Slave */
void spi3_config(void)
{
	/* Enable the Peripheral Clock of GPIOB */
	RCC->AHB1ENR |= GPIO_B_EN;

	/* Configure SPI3 SCK Pin PB3 ================= */
	// Alternate Function Mode = '10'
	GPIOB->MODER |= (1U<<7);
	GPIOB->MODER &=~ (1U<<6);

	/* Select Alternate Function Mode as AF6 */
	// AF6 = '0110' on Pins 15, 14, 13, 12 of AFRL
	GPIOB->AFR[0] &=~ (1U<<15);
	GPIOB->AFR[0] |= (1U<<14);
	GPIOB->AFR[0] |= (1U<<13);
	GPIOB->AFR[0] &=~ (1U<<12);

	/* Set GPIO Pin Speed to 'Very High' */
	GPIOB->OSPEEDR |= (1U<<7);
	GPIOB->OSPEEDR |= (1U<<6);

	/* Enable Internal Pull-Down on PB3 */
	GPIOB->PUPDR &=~ (1U<<6);
	GPIOB->PUPDR |= (1U<<7);

	/* Configure SPI3 MISO Pin PB4 */
	// Alternate Function Mode = '10'
	GPIOB->MODER |= (1U<<8);
	GPIOB->MODER &=~ (1U<<9);

	/* Select Alternate Type AF6 */
	// AF6 = '0110' on Pins 19, 18, 17, 16 of AFRL
	GPIOB->AFR[0] &=~ (1U<<19);
	GPIOB->AFR[0] |= (1U<<18);
	GPIOB->AFR[0] |= (1U<<17);
	GPIOB->AFR[0] &=~ (1U<<16);

	/* Set GPIO Pin Speed to 'Very High' */
	GPIOB->OSPEEDR |= (1U<<9);
	GPIOB->OSPEEDR |= (1U<<8);

	/* Enable Internal Pull-Down on PB4 */
	GPIOB->PUPDR |= (1U<<9);
	GPIOB->PUPDR &=~ (1U<<8);

	/* Enable SPI3 Interrupt in NVIC */
	NVIC_EnableIRQ(SPI3_IRQn);

	/*Enable clock access to SPI3*/
	RCC->APB1ENR |=SPI3EN;

	/*Set clock to fPCLK/256*/
	SPI3->CR1 |=(1U<<3);
	SPI3->CR1 |=(1U<<4);
	SPI3->CR1 |=(1U<<5);

	/*Set CPOL to 1 and CPHA to 1*/
	SPI3->CR1 |=(1U<<0);
	SPI3->CR1 |=(1U<<1);

	/*Set data width to 8 bit*/
	SPI3->CR2 |=(1U<<8);
	SPI3->CR2 |=(1U<<9);
	SPI3->CR2 |=(1U<<10);
	SPI3->CR2 &=~(1U<<11);

	/*Enable software slave management*/
	SPI3->CR1 |= (1U<<9);

	/*Enable Slave Select Output*/
	SPI3->CR2 |= (1U<<2);

	/*Select 1-line bidirectional data mode selected*/
	SPI3->CR1 |=(1U<<15);

	/*Select RX only*/
	SPI3->CR1 &=~(1U<<14);

	/*Set FIFO reception threshold*/
	SPI3->CR2 |=(1U<<12);

	/* Enable RXNE Interrupt */
	SPI3->CR2 |=(1U<<6);
}

void spi1_activate(void)
{
	/* Enable SPI1 */
	SPI1->CR1 |=(1U<<6);
}

void spi3_activate(void)
{
  /* Enable SPI3 */
  SPI3->CR1 |=(1U<<6);

}









