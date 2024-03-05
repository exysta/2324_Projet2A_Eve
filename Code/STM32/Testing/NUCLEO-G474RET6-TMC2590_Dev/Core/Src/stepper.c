/*
 * stepper.c
 *
 *  Created on: Dec 5, 2023
 *      Author: arthur, marie
 */


#include "tmc2590.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "tim.h"
#include "stepper.h"


void stepper_Init(Stepper * stepper){

	int inputOrder = 10; // 10 degrees for each iteration
	int polarity = (inputOrder > 0);

	while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) { // sensor not activate
		sendOrderStepper( inputOrder, stepper);
		HAL_Delay(1000);
	    }
	int position_init = 0;
	stepper->angularPosition = position_init;

	HAL_Delay(3000);

	//il faut faire en sorte de changer la polarité

}


