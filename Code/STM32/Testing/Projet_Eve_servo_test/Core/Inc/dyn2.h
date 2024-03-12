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
#include <math.h>
#include "constants.h"



int dyn2_send(uint8_t* buffer,uint16_t size);
uint8_t* dyn2_read(uint8_t ID,uint8_t address,int NParam);
uint8_t* dyn2_append_crc(uint8_t* instruction,uint16_t bufferSize);
int dyn2_led(MOTOR motor,int status);
int dyn2_torque(MOTOR motor,int mode);
void dyn2_position(MOTOR motor,float angleInDeg);
void dyn2_debug_sendArrayAsString(uint8_t* array, int size);



#endif /* INC_DYN2_H_ */
