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
///////////////////////////////////////
#define NbOfElements(x) (sizeof(x)/sizeof(x[0]))
#define TIMEOUT 100
#define BUFFER_SIZE 32
/////////////////////////////////////// INSTRUCTION

typedef enum {
    PING = 0x01,
    READ = 0x02,
    WRITE = 0x03,
    REG_WRITE = 0x04,
    ACTION = 0x05,
    FACTORY_RESET = 0x06,
    REBOOT = 0x08,
    CLEAR = 0x10,
    CONTROL_TABLE_BACKUP = 0x20,
    STATUS_RETURN = 0x55,
    SYNC_READ = 0x82,
    SYNC_WRITE = 0x83,
    FAST_SYNC_READ = 0x8A,
    BULK_READ = 0x92,
    BULK_WRITE = 0x93,
    FAST_BULK_READ = 0x9A
} INSTRUCTION;

/////////////////////////////////////// HEADER
typedef enum{
	HEADER_1 = 0xFF,
	HEADER_2 = 0xFF,
	HEADER_3 = 0xFD,
	HEADER_4 = 0x00
} HEADER;

///////////////////////////////////////

int dyn2_send(uint8_t* buffer,uint16_t size);
uint8_t* dyn2_append_crc(uint8_t* instruction,uint16_t bufferSize);
void dyn2_led(int status,uint8_t id);
void dyn2_rotate_positionPosition(float angleInDeg);
void dyn2_debug_sendArrayAsString(uint8_t* array, int size);



#endif /* INC_DYN2_H_ */
