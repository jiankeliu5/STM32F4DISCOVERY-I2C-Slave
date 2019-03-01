/**
  ******************************************************************************
  * @file    main.c
  * @author  niktyugay
  * @version V1.0
  * @date    17-January-2019
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "i2c.h"
			
uint32_t delay = 0;
I2CInterface* i2cMessage;

GPIO_InitTypeDef button;

void SysTick_Handler(void){
	if (delay > 0){
		delay--;
	}
}

void delay_ms(uint32_t value){
	delay = value;
	while(delay){}
}

int main(void) {
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	button.GPIO_Mode = GPIO_Mode_IN;
	button.GPIO_OType = GPIO_OType_PP;
	button.GPIO_Pin = GPIO_Pin_0;
	button.GPIO_PuPd = GPIO_PuPd_DOWN;
	button.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOA, &button);

	initI2C();

	while(1) {

		if ((i2cMessage = receiveI2C())->flagInputMessage) {
			i2cMessage->flagInputMessage = false;
		}

		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == Bit_SET) {
			sendI2C(i2cMessage->data_in, i2cMessage->size);
		}
	}
}
