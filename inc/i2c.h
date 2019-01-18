/*
 * i2c.h
 *
 *  Created on: 18 ���. 2019 �.
 *      Author: �������
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx.h"

void initI2C(void);
void sendI2C(uint8_t*);
void receiveI2C(uint8_t*);

#endif /* I2C_H_ */
