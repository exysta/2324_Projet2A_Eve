/*
 * constants.c
 *
 *  Created on: Feb 9, 2024
 *      Author: Lucas
 */


///////////////////////////
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "constants.h"

///////////////////////////////////////
#define NbOfElements(x) (sizeof(x)/sizeof(x[0]))
#define TIMEOUT 100
#define BUFFER_SIZE 32

/////////////////////////////////////// MOTOR

void init_XL430(MOTOR *motor, int baudrate, UART_HandleTypeDef uart, int id) {
    motor->model = XL430;
    motor->baudrate = baudrate;
    motor->uart = uart;
    motor->id = id;
}

// Function to initialize XL320 motor
void init_XL320(MOTOR *motor, int baudrate, UART_HandleTypeDef uart, int id) {
    motor->model = XL320;
    motor->baudrate = baudrate;
    motor->uart = uart;
    motor->id = id;
}

/////////////////////////////////////// INSTRUCTION

const uint8_t PING = 0x01;
const uint8_t READ = 0x02;
const uint8_t WRITE = 0x03;
const uint8_t REG_WRITE = 0x04;
const uint8_t ACTION = 0x05;
const uint8_t FACTORY_RESET = 0x06;
const uint8_t REBOOT = 0x08;
const uint8_t CLEAR = 0x10;
const uint8_t CONTROL_TABLE_BACKUP = 0x20;
const uint8_t STATUS_RETURN = 0x55;
const uint8_t SYNC_READ = 0x82;
const uint8_t SYNC_WRITE = 0x83;
const uint8_t FAST_SYNC_READ = 0x8A;
const uint8_t BULK_READ = 0x92;
const uint8_t BULK_WRITE = 0x93;
const uint8_t FAST_BULK_READ = 0x9A;



const uint8_t HEADER_1 = 0xFF;
const uint8_t HEADER_2 = 0xFF;
const uint8_t HEADER_3 = 0xFD;
const uint8_t HEADER_4 = 0x00;


/////////////////////////////////////// ADDRESSES XL430
//EEPROM
const uint8_t XL430_ADDRESS_ID = 0x07;
const uint8_t XL430_ADDRESS_BAUDRATE = 0x08;
const uint8_t XL430_ADDRESS_OPERATING_MODE = 0x0B;


//RAM
const uint8_t XL430_ADDRESS_TORQUE = 0x40;
const uint8_t XL430_ADDRESS_LED = 0x41;
const uint8_t XL430_ADDRESS_POSITION = 0x74;

/////////////////////////////////////// ADDRESSES XL320
//EEPROM
const uint8_t XL320_ADDRESS_ID = 0x03;
const uint8_t XL320_ADDRESS_BAUDRATE = 0x04;
//RAM
const uint8_t XL320_ADDRESS_TORQUE = 0x18;
const uint8_t XL320_ADDRESS_LED = 0x19;
const uint8_t XL320_ADDRESS_POSITION = 0x1E;
const uint8_t XL320_ADDRESS_MOVING_SPEED = 0x1E;


/////////////////////////////////////// ERRORS


const int ERROR_LED_VALUE = -1;
const int ERROR_TORQUE_VALUE = -1;


///////////////////////////////////////

const uint8_t BROADCAST_ID = 0xFE;

const uint8_t TORQUE_ON = 0x01;
const uint8_t LED_ON = 0x01;

const uint8_t TORQUE_OFF = 0x00;
const uint8_t LED_OFF = 0x00;



///////////////////////////////////////
