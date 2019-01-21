/*
 * i2c.h
 *
 *  Created on: 18 янв. 2019 г.
 *      Author: Николай
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx.h"

/* define one of I2C bus*/
/* info about I2C bus
 * I2C1_1 PB6(SCL)  PB7(SDA)
 * I2C1_2 PB8(SCL)  PB9(SDA)
 * I2C2   PB10(SCL) PB11(SDA)
 * I2C3   PA8(SCL)  PC9(SDA)
 */
#define I2C1_1_BUS
//#define I2C1_2_BUS
//#define I2C2_BUS
//#define I2C3_BUS

/* define ADDRESS I2C*/
#define ADDRESS				0x30

#if defined(I2C1_1_BUS)
#define I2C					I2C1
#define SDA_PIN				GPIO_Pin_7
#define SCL_PIN				GPIO_Pin_6
#define SDA_PinSource		GPIO_PinSource7
#define SCL_PinSource		GPIO_PinSource6
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C1
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#define GPIO_AF_I2C			GPIO_AF_I2C1
#define I2C_EV_IRQn			I2C1_EV_IRQn
#define I2C_ER_IRQn			I2C1_ER_IRQn
#endif

#if defined(I2C1_2_BUS)
#define I2C					I2C1
#define SDA_PIN				GPIO_Pin_9
#define SCL_PIN				GPIO_Pin_8
#define SDA_PinSource		GPIO_PinSource9
#define SCL_PinSource		GPIO_PinSource8
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C1
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#define GPIO_AF_I2C			GPIO_AF_I2C1
#define I2C_EV_IRQn			I2C1_EV_IRQn
#define I2C_ER_IRQn			I2C1_ER_IRQn
#endif

#if defined(I2C2_BUS)
#define I2C					I2C2
#define SDA_PIN				GPIO_Pin_11
#define SCL_PIN				GPIO_Pin_10
#define SDA_PinSource		GPIO_PinSource11
#define SCL_PinSource		GPIO_PinSource10
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C2
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#define GPIO_AF_I2C			GPIO_AF_I2C2
#define I2C_EV_IRQn			I2C2_EV_IRQn
#define I2C_ER_IRQn			I2C2_ER_IRQn
#endif

#if defined(I2C3_BUS)
#define I2C					I2C3
#define SDA_PIN				GPIO_Pin_9
#define SCL_PIN				GPIO_Pin_8
#define SDA_PinSource		GPIO_PinSource9
#define SCL_PinSource		GPIO_PinSource8
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOC
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOA
#define RCC_I2C				RCC_APB1Periph_I2C3
#define GPIO_SDA_PORT		GPIOC
#define GPIO_SCL_PORT		GPIOA
#define GPIO_AF_I2C			GPIO_AF_I2C3
#define I2C_EV_IRQn			I2C3_EV_IRQn
#define I2C_ER_IRQn			I2C3_ER_IRQn
#endif

void initI2C(void);
void sendI2C(uint8_t*);
void receiveI2C(uint8_t*);

#endif /* I2C_H_ */
