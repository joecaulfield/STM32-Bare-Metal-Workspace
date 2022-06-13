/*
 * uart.h
 *
 *  Created on: Jun 8, 2022
 *      Author: Joe
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f7xx.h"

#define ISR_TXE	(1U<<7)

void uart6_tx_init(void);
void uart6_rxtx_init(void);
uint8_t uart_read (USART_TypeDef *USARTx);
void uart6_tx_interrupt_init(void);

#endif /* UART_H_ */