/*
 * i2c.c
 *
 *  Created on: 18 янв. 2019 г.
 *      Author: Николай
 */

#include "i2c.h"


uint8_t data_out[SIZE_OUTPUT_BUFFER];
uint8_t indexOfBuffer = 0;
uint8_t sizeOutputMessage = 0;
uint8_t errStatus = 0;

I2CInterface i2cInputBuffer;

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
	GPIO_Init(GPIO_SDA_PORT, &GPIO_InitSructure);
	GPIO_PinAFConfig(GPIO_SDA_PORT, SDA_PinSource, GPIO_AF_I2C);

	// Configure SDA pin
	RCC_AHB1PeriphClockCmd(RCC_I2C_SCL_PORT, ENABLE);
	GPIO_InitSructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitSructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitSructure.GPIO_Pin = SCL_PIN;
	GPIO_InitSructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitSructure.GPIO_Speed = GPIO_High_Speed;
	GPIO_Init(GPIO_SCL_PORT, &GPIO_InitSructure);
	GPIO_PinAFConfig(GPIO_SDA_PORT, SCL_PinSource, GPIO_AF_I2C);

	// Configure I2C bus
	RCC_APB1PeriphClockCmd(RCC_I2C, ENABLE);
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

	uint8_t i = 0;
	for (i = 0; i < sizeof(i2cInputBuffer.data_in); i++) {
		i2cInputBuffer.data_in[i] = 0;
	}
	i2cInputBuffer.size = 0;
}

/**
  * @brief	Function send message from buffer.
  * If transmit is success function delete message in buffer.
  * @param  buffer is an array where the message is stored
  * @retval None
  */
void sendI2C(uint8_t* buffer, uint8_t size) {
	uint8_t j = 0;
	for (j = 0; j < size; j++) {
		data_out[j] = buffer[j];
		buffer[j]  = 0;
	}
	sizeOutputMessage = size;
	indexOfBuffer = 0;
}

/**
  * @brief	Function receive message and save in buffer.
  * @param  buffer is an array where the message is saved
  * @retval None
  */
I2CInterface* receiveI2C() {
	return &i2cInputBuffer;
}
/**
  * @brief	Function event handler.
  * @param  None
  * @retval None
  */
void I2C1_EV_IRQHandler() {
	if(I2C_GetITStatus(I2C, I2C_IT_ADDR) == SET) {
		(void)(I2C->SR2);
	}
	// receive mode
	if(I2C_GetITStatus(I2C, I2C_IT_RXNE) == SET) {
		i2cInputBuffer.data_in[indexOfBuffer++] = I2C->DR;
		i2cInputBuffer.size = indexOfBuffer;
	}
	// transmit mode
	if (I2C_GetFlagStatus(I2C, I2C_FLAG_TRA) == SET) {
		if(I2C_GetITStatus(I2C, I2C_IT_TXE) == SET) {
			I2C->DR = data_out[indexOfBuffer++];
			if (indexOfBuffer == sizeOutputMessage) {
				sizeOutputMessage = 0;
				indexOfBuffer = 0;
			}
		}
	}
	if(I2C_GetITStatus(I2C, I2C_IT_STOPF) == SET) {
		I2C_Cmd(I2C, ENABLE);
		if(indexOfBuffer > 0) {
			i2cInputBuffer.flagInputMessage = true;
		}
	}
}

/**
  * @brief	Function error handler.
  * @param  None
  * @retval None
  */
void I2C1_ER_IRQHandler() {
	if(I2C_GetITStatus(I2C1, I2C_IT_OVR)) {
		errStatus = 1;
		I2C_ClearFlag(I2C1, I2C_FLAG_OVR);
	}
	else if(I2C_GetITStatus(I2C1, I2C_IT_AF)) {
		errStatus = 2;
		I2C_ClearFlag(I2C1, I2C_FLAG_AF);
	}
	else if(I2C_GetITStatus(I2C1, I2C_IT_ARLO)) {
		errStatus = 3;
		I2C_ClearFlag(I2C1, I2C_FLAG_ARLO);
	}
	else if(I2C_GetITStatus(I2C1, I2C_IT_BERR)) {
		errStatus = 4;
		I2C_ClearFlag(I2C1, I2C_FLAG_BERR);
	}
}

