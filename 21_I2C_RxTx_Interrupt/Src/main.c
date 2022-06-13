/* Simple Demonstration of SPI Configuration and Communication.
 * This project is configured for the STM32 144-Nucleo Discovery Board. */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "spi.h"
#include "i2c.h"

/* Buffer Used for Transmission */
const uint8_t msg[] = "HELLO";

/* Pointer to MSG Array */
uint8_t* p_tx_buff = (uint8_t*)msg;

/* Size of Tx Buffer */
uint8_t tx_size = sizeof(msg);

/* Index of Tx Array */
volatile uint8_t tx_idx = 0;

/* Buffer used for Reception */
uint8_t rx_buff[sizeof(msg)];

/* Index of Rx Array */
volatile uint8_t rx_idx = 0;

static void handle_i2c_master(void);

int main (void)
{

	uart6_tx_init();
	i2c2_slave_config();
	i2c1_master_config();
	handle_i2c_master();

	while (1)
	{

	}
}

static void handle_i2c_master(void)
{
	/* Set Slave Address */
	I2C1->CR2 |= SLAVE_OWN_ADDRESS;

	/* Set 7-Bits Address Mode */
	I2C1->CR2 &=~ (1U<<11);

	/* Set Transfer Size */
	I2C1->CR2 |= (tx_size<<16);

	/* Set Automatic End Mode */
	I2C1->CR2 |= (1U<<25);

	/* Generate Start Condition */
	I2C1->CR2 |= (1U<<13);

	/* Loop Until Stop is Detected */
	while(!(I2C1->ISR & (1U<<5)))
	{
		/* Check for TXIF Flag in ISR Register */
		if (I2C1->ISR && (1U<<1))
		{
			/* Write data in Transmit Data Register.
			 * TXIS flag is cleared by writing in the TXDR Register */
			I2C1->TXDR = (*p_tx_buff++);
		}
	}

	/* Clear Stop Flag */
	I2C1->ICR |= (1U<<5);
}

void slave_reception_callback(void)
{
	/* Read character in Receive Data register.
	RXNE flag is cleared by reading data in RXDR register */

	/*Read first 8 bits */
	rx_buff[rx_idx++] = (I2C2->RXDR & 0xFF);
}

void slave_complete_callback(void)
{
	printf("Transmission complete...\n\r");
}

void I2C2_EV_IRQHandler(void)
{
	/* Check ADDR flag value in ISR register */
	if(I2C2->ISR & (1U<<3))
	{
		/* Verify the Address Match with the OWN Slave address */
		if(i2c2_get_address_matchcode() == SLAVE_OWN_ADDRESS)
		{
			/* Clear ADDR flag value in ISR register */
			I2C2->ICR |= (1U<<3);

			/* Enable Receive Interrupt */
			I2C2->CR1 |=(1U<<2);
		}
	}

	/* Check RXNE flag value in ISR register */
	else if(I2C2->ISR & (1U<<2))
	{
		//Do something..
		slave_reception_callback();
	}

	/* Check STOP flag value in ISR register */
	else if(  I2C2->ISR & (1U<<5))
	{
		I2C2->ICR |= (1U<<5);

		//Do something...
		slave_complete_callback();
	}

	else{
		//Implement error
	}
}














