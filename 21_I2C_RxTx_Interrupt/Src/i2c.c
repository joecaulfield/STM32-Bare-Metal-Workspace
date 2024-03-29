/* SCL on PB.10, SDA on PB.11 */


#include "i2c.h"

#define GPIO_B_EN		(1U<<1)
#define I2C1EN			(1U<<21)
#define I2C2EN			(1U<<22)
#define I2C_TIMING		0x00303D5B

static void i2c2_setOwnAddress1(uint32_t OwnAddress1, uint32_t OwnAddrSize);

/* Configure I2C-1 as Master, I2C-2 as Slave */
void i2c2_slave_config(void)
{
	/* Enable clock for GPIOB */
	RCC->AHB1ENR |= GPIO_B_EN;

	/****** Configure SCL Line *****/

	/* Configure PB.10 Mode to Alternate Function */
	GPIOB->MODER &=~ (1U<<20);
	GPIOB->MODER |= (1U<<21);

	/* Select Alternate Function Type as AF4 (I2C2 SCL) */
	GPIOB->AFR[1] &=~(1U<<8);
	GPIOB->AFR[1] &=~(1U<<9);
	GPIOB->AFR[1] |= (1U<<10);
	GPIOB->AFR[1] &=~(1U<<11);

	/* Set Pin Output Type to Open-Drain */
	GPIOB->OTYPER |=(1U<<10);

	/* Enable Internal Pull-Ups */
	GPIOB->PUPDR |=(1U<<20);
	GPIOB->PUPDR &=~(1U<<21);

	/****** Configure SDA Line *****/

	/* Configure PB.11 Mode to Alternate Function */
	GPIOB->MODER &=~(1U<<22);
	GPIOB->MODER |=(1U<<23);

	/* Select Alternate Function Type as AF4 (I2C2 SCL) */
	GPIOB->AFR[1] &=~(1U<<12);
	GPIOB->AFR[1] &=~(1U<<13);
	GPIOB->AFR[1] |= (1U<<14);
	GPIOB->AFR[1] &=~(1U<<15);

	/* Set Pin Output Type to Open-Drain */
	GPIOB->OTYPER |=(1U<<11);

	/* Enable Internal Pull-Ups */
	GPIOB->PUPDR |=(1U<<22);
	GPIOB->PUPDR &=~(1U<<23);

	/****** Configure I2C Parameters *****/

	/*Enable clock access to the I2C module*/
	RCC->APB1ENR |= I2C2EN;

	/*Enable I2C interrupt in the NVIC*/
	NVIC_EnableIRQ(I2C2_EV_IRQn);

	/*Disable I2C module*/
	I2C2->CR1 &=~(1U<<0);

	/*Set device address*/
	i2c2_setOwnAddress1(SLAVE_OWN_ADDRESS, 0);

	/*Enable Own Address 1*/
	I2C2->OAR1 |=(1U<<15);

	/*Enable I2C module*/
	I2C2->CR1 |= (1U<<0);

	/*Enable ADDR interrupt*/
	I2C2->CR1 |= (1U<<3);

	/*Enable NACK interrupt*/
	I2C2->CR1 |= (1U<<4);

	/*Enable STOP interrupt*/
	I2C2->CR1 |= (1U<<5);
}


/*SCL on PB.6, SDA on PB.9*/

void i2c1_master_config(void)
{

	/*Enable clock for GPIOB*/
	RCC->AHB1ENR |=GPIO_B_EN;

	/* Configure SCL Pin as : Alternate function, Open drain, Pull up */
	GPIOB->MODER &=~(1U<<12);
	GPIOB->MODER |=(1U<<13);

	GPIOB->AFR[0] &=~(1U<<24);
	GPIOB->AFR[0] &=~(1U<<25);
	GPIOB->AFR[0] |= (1U<<26);
	GPIOB->AFR[0] &=~(1U<<27);

	GPIOB->OTYPER |=(1U<<6);

	GPIOB->PUPDR |=(1U<<12);
	GPIOB->PUPDR &=~(1U<<13);

	/* Configure SDA Pin as : Alternate function, Open drain, Pull up */

	GPIOB->MODER &=~(1U<<18);
	GPIOB->MODER |=(1U<<19);

	GPIOB->AFR[1] &=~(1U<<4);
	GPIOB->AFR[1] &=~(1U<<5);
	GPIOB->AFR[1] |= (1U<<6);
	GPIOB->AFR[1] &=~(1U<<7);

	GPIOB->OTYPER |=(1U<<9);

	GPIOB->PUPDR |=(1U<<18);
	GPIOB->PUPDR &=~(1U<<19);

	/*************Configure I2C Parameters************/

	RCC->APB1ENR |= I2C1EN;

	I2C1->CR1 &= ~(1U<<0);

	/*Set timing*/
	I2C1->TIMINGR = I2C_TIMING;

	/*Enable I2C1*/
	I2C1->CR1 |= (1U<<0);

}

static void i2c2_setOwnAddress1(uint32_t OwnAddress1, uint32_t OwnAddrSize)
{
	MODIFY_REG(I2C2->OAR1, I2C_OAR1_OA1 | I2C_OAR1_OA1MODE, OwnAddress1 | OwnAddrSize);
}

uint32_t i2c2_get_address_matchcode(void)
{
 return (uint32_t)(READ_BIT(I2C2->ISR, I2C_ISR_ADDCODE) >> I2C_ISR_ADDCODE_Pos << 1);
}











