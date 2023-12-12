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





void stepper_Init(Stepper *stepper1){

	stepper1->stepperID = 1;
	while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) != 0){
		sendOrderStepper(20);
	}
	stepper1->angularPosition = 0;

}
