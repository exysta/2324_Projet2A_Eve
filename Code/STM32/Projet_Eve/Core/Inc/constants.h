/*
 * constants.h
 *
 *  Created on: Feb 9, 2024
 *      Author: Lucas
 */

#ifndef INC_CONSTANTS_H_
#define INC_CONSTANTS_H_
 ///////////////////////////
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
///////////////////////////////////////
#define NbOfElements(x) (sizeof(x)/sizeof(x[0]))
#define TIMEOUT 100
#define BUFFER_SIZE 32
/////////////////////////////////////// INSTRUCTION

extern const uint8_t PING;
extern const uint8_t READ;
extern const uint8_t WRITE;
extern const uint8_t REG_WRITE;
extern const uint8_t ACTION;
extern const uint8_t FACTORY_RESET;
extern const uint8_t REBOOT;
extern const uint8_t CLEAR;
extern const uint8_t CONTROL_TABLE_BACKUP;
extern const uint8_t STATUS_RETURN;
extern const uint8_t SYNC_READ;
extern const uint8_t SYNC_WRITE;
extern const uint8_t FAST_SYNC_READ;
extern const uint8_t BULK_READ;
extern const uint8_t BULK_WRITE;
extern const uint8_t FAST_BULK_READ;


/////////////////////////////////////// HEADER
extern const uint8_t HEADER_1;
extern const uint8_t HEADER_2;
extern const uint8_t HEADER_3;
extern const uint8_t HEADER_4;

/////////////////////////////////////// ADDRESSES
extern const uint8_t ADDRESS_TORQUE;
extern const uint8_t ADDRESS_LED;
extern const uint8_t ADDRESS_POSITION;
/////////////////////////////////////// ERRORS


extern const int ERROR_LED_VALUE;
extern const int ERROR_TORQUE_VALUE;


///////////////////////////////////////

extern const uint8_t BROADCAST_ID;

extern const uint8_t TORQUE_ON ;
extern const uint8_t LED_ON;

extern const uint8_t TORQUE_OFF;
extern const uint8_t LED_OFF;



///////////////////////////////////////

#endif /* INC_CONSTANTS_H_ */
