/*
 * i2c.h
 *
 *  Created on: Jun 13, 2022
 *      Author: Joe
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f7xx.h"
void i2c1_master_config(void);
void i2c2_slave_config(void);

#define SLAVE_OWN_ADDRESS	0x5A

uint32_t i2c2_get_address_matchcode(void);



#endif /* I2C_H_ */
