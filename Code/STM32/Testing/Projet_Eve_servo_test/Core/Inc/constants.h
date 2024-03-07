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
/////////////////////////////////////// STRUCTURES
// Enum defining motor models
enum MOTOR_MODEL {
    XL430,
    XL320
};

// Struct defining a motor
typedef struct MOTOR {
    enum MOTOR_MODEL model; // Type corresponds to the model of the motor (either XL320 or XL430)
    int baudrate;
    UART_HandleTypeDef uart;
    int id;
} MOTOR; // Typedef the struct to simplify its use

void init_XL430(MOTOR *motor, int baudrate, UART_HandleTypeDef uart, int id);
void init_XL320(MOTOR *motor, int baudrate, UART_HandleTypeDef uart, int id);


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

/////////////////////////////////////// ADDRESSES XL430
extern const uint8_t XL430_ADDRESS_ID;
extern const uint8_t XL430_ADDRESS_BAUDRATE;
extern const uint8_t XL430_ADDRESS_OPERATING_MODE;

extern const uint8_t XL430_ADDRESS_TORQUE;
extern const uint8_t XL430_ADDRESS_LED;
extern const uint8_t XL430_ADDRESS_POSITION;
/////////////////////////////////////// ADDRESSES XL320
extern const uint8_t XL320_ADDRESS_ID;
extern const uint8_t XL320_ADDRESS_BAUDRATE;

extern const uint8_t XL320_ADDRESS_TORQUE;
extern const uint8_t XL320_ADDRESS_LED;
extern const uint8_t XL320_ADDRESS_POSITION;
extern const uint8_t XL320_ADDRESS_MOVING_SPEED;


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
