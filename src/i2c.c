/*
 * i2c.c
 *
 *  Created on: 18 янв. 2019 г.
 *      Author: Николай
 */

#include "i2c.h"

/**
  * @brief  Initializes I2C module
  * @param  None
  * @retval None
  */
void initI2C() {
	I2C_InitTypeDef I2C_InitStruct;

}

/**
  * @brief	Function send message from buffer.
  * If transmit is success function delete message in buffer.
  * @param  buffer is an array where the message is stored
  * @retval None
  */
void sendI2C(uint8_t* buffer) {

}

/**
  * @brief	Function receive message and save in buffer.
  * @param  buffer is an array where the message is saved
  * @retval None
  */
void receiveI2C(uint8_t* buffer) {

}

