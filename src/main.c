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
			
uint32_t delay = 0;

void SysTick_Handler(void){
	if (delay > 0){
			delay--;
		}
}

void delay_ms(uint32_t value){
	delay = value;
	while(delay){}
}

int main(void)
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);

	while(1) {
	}
}
