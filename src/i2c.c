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
	I2C_InitTypeDef I2C_InitStructure;
	GPIO_InitTypeDef GPIO_InitSructure;

	// Configure SDA pin
	RCC_AHB1PeriphClockCmd(RCC_I2C_SDA_PORT, ENABLE);
	GPIO_InitSructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitSructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitSructure.GPIO_Pin = SDA_PIN;
	GPIO_InitSructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitSructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIO_SDA_PORT, GPIO_InitSructure);
	GPIO_PinAFConfig(GPIO_SDA_PORT, SDA_PinSource, GPIO_AF_I2C);

	// Configure SDA pin
	RCC_AHB1PeriphClockCmd(RCC_I2C_SCL_PORT, ENABLE);
	GPIO_InitSructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitSructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitSructure.GPIO_Pin = SCL_PIN;
	GPIO_InitSructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitSructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIO_SCL_PORT, GPIO_InitSructure);
	GPIO_PinAFConfig(GPIO_SDA_PORT, SCL_PinSource, GPIO_AF_I2C);

	// Configure I2C bus
	I2C_InitStructure.I2C_ClockSpeed = 100000;
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = ADDRESS;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_Init(I2C, &I2C_InitStructure);

	I2C_ITConfig(I2C, I2C_IT_ERR | I2C_IT_EVT | I2C_IT_BUF, ENABLE);
	I2C_Cmd(I2C, ENABLE);
	NVIC_EnableIRQ(I2C_ER_IRQn);
	NVIC_EnableIRQ(I2C_EV_IRQn);
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

