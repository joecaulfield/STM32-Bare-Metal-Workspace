/* Simple Demonstration of SPI Configuration and Communication.
 * This project is configured for the STM32 144-Nucleo Discovery Board. */

#include "stm32f7xx.h"
#include <stdio.h>
#include "uart.h"
#include "led.h"
#include "spi.h"

/* Buffer for Transmit Data */
uint8_t tx_buff[] = "Hello from SPI";

/* Need to compute the size of TX Buffer */
uint8_t tx_size = sizeof(tx_buff);

/* Index to track the TX Buffer */
volatile uint8_t tx_idx = 0;

/* RX Buffer.  Must be same size as TX Buffer */
uint8_t rx_buff[sizeof(tx_buff)];

/* Index to track the RX Buffer */
volatile uint8_t rx_idx = 0;

int main (void)
{
	/* Configure Master */
	spi1_config();

	/* Configure Slave */
	spi3_config();

	/* Enable Slave (RX) */
	spi3_activate();

	/* Enable Master (TX) */
	spi1_activate();

	while (1)
	{

	}
}

void SPI1_callback(void)
{
	/* Pointer to the SPI1 Data Register */
	volatile uint8_t *spidr = ((volatile uint8_t*) &SPI1->DR);

	/* Store Character and Increment */
	*spidr = tx_buff[tx_idx++];
}

void SPI3_callback(void)
{
	rx_buff[rx_idx++] = SPI3->DR;
}


/* Transmit */
void SPI1_IRQHandler(void)
{
	/* Check for TXE Flag in ISR Register */
	if (SPI1->SR & (1U<<1))
	{
		/* Do Something */
		SPI1_callback();
	}
}

/* Receive */
void SPI3_IRQHandler(void)
{
	/* Check for RXNE Flag in ISR Register */
	if (SPI3->SR & (1U<<0))
	{
		/* Do Something */
		SPI3_callback();
	}
}







