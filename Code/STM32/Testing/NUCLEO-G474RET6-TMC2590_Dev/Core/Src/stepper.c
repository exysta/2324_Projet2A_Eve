/*
 * stepper.c
 *
 *  Created on: Dec 5, 2023
 *      Author: arthu
 */


#include "tmc2590.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "tim.h"
#include "stepper.h"


void stepper_Init(Stepper * stepper){

	stepper->angularPostionMax = 360;
	stepper->angularPosition = 360;
	stepper->stepperID = 1;
	while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == 0){
		sendOrderStepper(-20,stepper);
		HAL_Delay(10);
	}
	stepper->angularPosition = 0;

}
