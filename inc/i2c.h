/*
 * i2c.h
 *
 *  Created on: 18 янв. 2019 г.
 *      Author: Николай
 */

#ifndef I2C_H_
#define I2C_H_

#include "stm32f4xx.h"

/* info about I2C block
 * I2C1_1 PB6(SCL)  PB7(SDA)
 * I2C1_2 PB8(SCL)  PB9(SDA)
 * I2C2   PB10(SCL) PB11(SDA)
 * I2C3   PA8(SCL)  PC9(SDA)
 */

/* define I2C block*/
#define I2C1_1_BUS
//#define I2C1_2_BUS
//#define I2C2_BUS
//#define I2C3_BUS

#if defined(I2C1_1_BUS)
#define I2C					I2C1
#define SDA					PB7
#define SCL					PB6
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C1
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#endif

#if defined(I2C1_2_BUS)
#define I2C					I2C1
#define SDA					PB9
#define SCL					PB8
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C1
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#endif

#if defined(I2C2_BUS)
#define I2C					I2C2
#define SDA					PB11
#define SCL					PB10
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOB
#define RCC_I2C				RCC_APB1Periph_I2C2
#define GPIO_SDA_PORT		GPIOB
#define GPIO_SCL_PORT		GPIOB
#endif

#if defined(I2C3_BUS)
#define I2C					I2C3
#define SDA					PC9
#define SCL					PA8
#define RCC_I2C_SDA_PORT	RCC_AHB1Periph_GPIOC
#define RCC_I2C_SCL_PORT	RCC_AHB1Periph_GPIOA
#define RCC_I2C				RCC_APB1Periph_I2C3
#define GPIO_SDA_PORT		GPIOC
#define GPIO_SCL_PORT		GPIOA
#endif

void initI2C(void);
void sendI2C(uint8_t*);
void receiveI2C(uint8_t*);

#endif /* I2C_H_ */
