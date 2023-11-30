/*
 * send_dynamixel.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Lucas
 */
#include "crc.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "stm32h7xx.h"
extern UART_HandleTypeDef huart3;


void send_dynamixel(uint8_t instruction[], size_t array_size){
	  uint8_t instruction_sent[array_size];
	  memcpy(instruction_sent, instruction, array_size);
	  unsigned short crc = update_crc(0, instruction_sent, array_size-2);//initializing the message with 4 crc bytes at 0 so we take array_size-2 to not count them in the CRC calculation
	  unsigned char crc_l = (unsigned char)(crc & 0x00FF);
	  unsigned char crc_h = (unsigned char)((crc >> 8) & 0x00FF);
	  instruction_sent[array_size -2]=crc_l;
	  instruction_sent[array_size - 1]=crc_h;
	  //while(!__HAL_UART_GET_FLAG(&huart3, UART_FLAG_TXE));
	  HAL_UART_Transmit(&huart3,instruction_sent,sizeof(instruction_sent),10);
}


