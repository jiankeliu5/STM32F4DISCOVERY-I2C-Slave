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

	initI2C();

	while(1) {
		i2cMessage = receiveI2C();
		if (i2cMessage->flagInputMessage) {
			i2cMessage->flagInputMessage = false;
			sendI2C(i2cMessage->data_in, i2cMessage->size);
		}
	}
}
