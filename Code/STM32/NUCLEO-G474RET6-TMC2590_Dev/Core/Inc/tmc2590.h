/*
 * tmc2590.h
 *
 *  Created on: Nov 16, 2023
 *      Author: nicolas
 */

#ifndef INC_TMC2590_H_
#define INC_TMC2590_H_

#include "main.h"

#define SPI_BUFFER_SIZE 10

typedef struct __TMC2590_HandleTypeDef{
	SPI_HandleTypeDef *hspi;
	uint16_t gpio_pin_nCS;
	GPIO_TypeDef *gpio_port_nCS;
	uint16_t gpio_pin_drv_enn;
	GPIO_TypeDef *gpio_port_drv_enn;
	uint8_t spiTxBuffer[SPI_BUFFER_SIZE];
	uint8_t spiRxBuffer[SPI_BUFFER_SIZE];
}TMC2590_HandleTypeDef;

extern TMC2590_HandleTypeDef htmc2590;

void tmc2590_Init(TMC2590_HandleTypeDef *htmc2590, SPI_HandleTypeDef *hspi, GPIO_TypeDef *gpio_port_nCS, uint16_t gpio_pin_nCS, GPIO_TypeDef *gpio_port_drv_enn, uint16_t gpio_pin_drv_enn);
void tmc2590_SetnCS(TMC2590_HandleTypeDef *htmc2590, FlagStatus status);
void tmc2590_SetPowerEnable(TMC2590_HandleTypeDef *htmc2590, FlagStatus status);
HAL_StatusTypeDef tmc2590_TransmitReceive(TMC2590_HandleTypeDef *htmc2590, int size);
HAL_StatusTypeDef tmc2590_SetTxBuffer(TMC2590_HandleTypeDef *htmc2590, uint8_t *pData, int size);
HAL_StatusTypeDef tmc2590_PrintReport(TMC2590_HandleTypeDef *htmc2590);


#endif /* INC_TMC2590_H_ */
