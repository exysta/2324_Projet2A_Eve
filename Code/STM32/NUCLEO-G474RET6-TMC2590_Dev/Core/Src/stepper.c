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





void stepper_Init(Stepper  *stepper, int stepperNumber ){

	stepper->stepperID = stepperNumber;
	stepper->angularPosition = 0;
	stepper->speed = 0;







}
