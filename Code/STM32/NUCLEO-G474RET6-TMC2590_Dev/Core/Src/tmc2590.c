/*
 * tmc2590.c
 *
 *  Created on: Nov 16, 2023
 *      Author: nicolas
 */

#include "tmc2590.h"
#include "usart.h"
#include "gpio.h"

TMC2590_HandleTypeDef htmc2590;

const char transmit_ok[] = "Transmission SPI done\r\n";
const char stringReportHeader[] = "SPI Tx/Rx Buffers\r\n";

void tmc2590_Init(TMC2590_HandleTypeDef *htmc2590, SPI_HandleTypeDef *hspi, GPIO_TypeDef *gpio_port_nCS, uint16_t gpio_pin_nCS, GPIO_TypeDef *gpio_port_drv_enn, uint16_t gpio_pin_drv_enn){
	htmc2590->hspi = hspi;
	htmc2590->gpio_pin_nCS = gpio_pin_nCS;
	htmc2590->gpio_port_nCS = gpio_port_nCS;
	htmc2590->gpio_pin_drv_enn = gpio_pin_drv_enn;
	htmc2590->gpio_port_drv_enn = gpio_port_drv_enn;

	tmc2590_SetPowerEnable(htmc2590, SET);
	tmc2590_SetnCS(htmc2590, SET);
}

void tmc2590_SetnCS(TMC2590_HandleTypeDef *htmc2590, FlagStatus status){
	HAL_GPIO_WritePin(htmc2590->gpio_port_nCS, htmc2590->gpio_pin_nCS, status);
}

void tmc2590_SetPowerEnable(TMC2590_HandleTypeDef *htmc2590, FlagStatus status){
	HAL_GPIO_WritePin(htmc2590->gpio_port_drv_enn, htmc2590->gpio_pin_drv_enn, 1-status);
}


HAL_StatusTypeDef tmc2590_TransmitReceive(TMC2590_HandleTypeDef *htmc2590, int size){
	HAL_StatusTypeDef status;

	tmc2590_SetnCS(htmc2590, RESET);
	status = HAL_SPI_TransmitReceive(htmc2590->hspi, htmc2590->spiTxBuffer, htmc2590->spiRxBuffer, size, HAL_MAX_DELAY);
	tmc2590_SetnCS(htmc2590, SET);

	if(status == HAL_OK){
		HAL_UART_Transmit(&hlpuart1, (uint8_t *)transmit_ok, sizeof(transmit_ok), 100);
	}
	else{

	}

	return status;
}

HAL_StatusTypeDef tmc2590_SetTxBuffer(TMC2590_HandleTypeDef *htmc2590, uint8_t *pData, int size){
	memcpy(htmc2590->spiTxBuffer, pData, size);
}

HAL_StatusTypeDef tmc2590_PrintReport(TMC2590_HandleTypeDef *htmc2590){
	char string[64];
	int stringLength, i;
	HAL_UART_Transmit(&hlpuart1, stringReportHeader, sizeof(stringReportHeader), 100);
	stringLength = snprintf(string, 64, "      Tx  |  Rx \r\n");
	HAL_UART_Transmit(&hlpuart1, string, stringLength, 100);

	for(i = 0; i < SPI_BUFFER_SIZE; i++){
		stringLength = snprintf(string, 64, "%2d : 0x%2x | 0x%2x\r\n", i, htmc2590->spiTxBuffer[i], htmc2590->spiRxBuffer[i]);
 		HAL_UART_Transmit(&hlpuart1, string, stringLength, 100);
	}


}


//void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
/*
 * tmc2590.c
 *
 *  Created on: Nov 17, 2023
 *      Author: nicolas
 */


