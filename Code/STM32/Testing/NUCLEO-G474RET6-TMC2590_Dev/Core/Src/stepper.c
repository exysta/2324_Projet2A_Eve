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

	//char message[20]; 		// we create a tab to stock caracters

	int inputOrder = 10; // 10 degrees for each iteration
	//int polarity = (inputOrder > 0);

	while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == GPIO_PIN_RESET) { // sensor not activate
		sendOrderStepper( inputOrder, stepper);
		HAL_Delay(1000);
	    }

	stepper->angularPosition = 0;

	HAL_Delay(3000);

	/*
	sprintf(message, "%d \r\n", position_init);
	HAL_UART_Transmit(&huart2, (uint8_t *)message ,strlen(message) , 1000);
	HAL_Delay(1000);
	*/

	HAL_UART_Transmit(&huart2, (uint8_t *)"test 1\r\n", strlen("test 1\r\n"), HAL_MAX_DELAY);

	return;

	//il faut faire en sorte de changer la polarité

}


