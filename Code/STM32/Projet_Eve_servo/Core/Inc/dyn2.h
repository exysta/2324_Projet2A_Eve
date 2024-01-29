/*
 * dyn2.h
 *
 *  Created on: Nov 23, 2023
 *      Author: Lucas
 */

#ifndef INC_DYN2_H_
#define INC_DYN2_H_


#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usart.h"
#include <stdint.h>
#define BUFFER_SIZE 32

int dyn2_send(uint8_t buffer[BUFFER_SIZE]);
void dyn2_led(int status);

void dyn2_rotate_positionPosition(float angleInDeg);
void dyn2_debug_sendArrayAsString(uint8_t* array, int size);



#endif /* INC_DYN2_H_ */
