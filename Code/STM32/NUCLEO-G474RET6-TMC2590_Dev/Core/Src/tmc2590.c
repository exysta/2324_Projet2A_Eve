/*
 * tmc2590.c
 *
 *  Created on: Nov 17, 2023
 *      Author: nicolas
 */

#include "tmc2590.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "tim.h"

TMC2590_HandleTypeDef htmc2590;

const char transmit_ok[] = "Transmission SPI done\r\n";
const char stringReportHeader[] = "SPI Tx/Rx Buffers\r\n";
uint8_t perioedElapsed_IT = 0;

// Configuration sendOrderStepper
int index_sin_loop = 0;
uint8_t currentCoilA;
uint8_t currentCoilB;
uint8_t polarityCoilA;
uint8_t polarityCoilB;
uint32_t drvCtrlCommand;







const uint8_t sinTable[256] = {
		1, 	2,	4,	5,	7,	8,	10,	11,	13,	14,	16,	17,	19,	21,	22,	24,	25,	27,	28,	30,	31,	33,	34,	36,	37,	39,	40,	42,	43,	45,	46,	48,
		49,	51,	52, 54,	55,	57,	58,	60,	61,	62,	64,	65,	67,	68,	70,	71,	73,	74,	76,	77,	79,	80,	81,	83,	84,	86,	87,	89,	90,	91,	93,	94,
		96,	97,	98,	100,101,103,104,105,107,108,109,111,112,114,115,116,118,119,120,122,123,124,126,127,128,129,131,132,133,135,136,137,
		138,140,141,142,143,145,146,147,148,150,151,152,153,154,156,157,158,159,160,161,163,164,165,166,167,168,169,170,172,173,174,175,
		176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,201,202,203,204,205,206,
		207,207,208,209,210,211,212,212,213,214,215,215,216,217,218,218,219,220,220,221,222,223,223,224,225,225,226,226,227,228,228,229,
		229,230,231,231,232,232,233,233,234,234,235,235,236,236,237,237,238,238,238,239,239,240,240,240,241,241,241,242,242,242,243,243,
		243,244,244,244,244,245,245,245,245,246,246,246,246,246,247,247,247,247,247,247,247,247,248,248,248,248,248,248,248,248,248,248};

void tmc2590_Init(TMC2590_HandleTypeDef *phtmc2590, SPI_HandleTypeDef *hspi, GPIO_TypeDef *gpioPortNCS, uint16_t gpioPinNCS, GPIO_TypeDef *gpioPortDrvEnN, uint16_t gpioPinDrvEnN){
	uint8_t pData[3];
	phtmc2590->hspi = hspi;
	phtmc2590->gpioPinNCS = gpioPinNCS;
	phtmc2590->gpioPortNCS = gpioPortNCS;
	phtmc2590->gpioPinDrvEnN = gpioPinDrvEnN;
	phtmc2590->gpioPortDrvEnN = gpioPortDrvEnN;

	tmc2590_SetPowerEnable(phtmc2590, SET);
	tmc2590_SetnCS(phtmc2590, SET);

	phtmc2590->drvCtrlRegister 			= 0x00000; // No Current
	phtmc2590->chopConfRegister			= 0b10011000000000001111; // 100 10
	phtmc2590->smartEnRegister 			= 0b10100000000000000000; // 101 0
	phtmc2590->stallGuardCtrlRegister 	= 0b11000000000000011111;//0xD001F; // 110 1---- 11111
	phtmc2590->drvConfRegister 			= 0b11100000011110110000;//0xE0480; // 1110 0000 0100 1000 0000

	tmc2590_SetTxBufferInt32(phtmc2590, phtmc2590->drvCtrlRegister);
	tmc2590_TransmitReceive(phtmc2590, TMC2590_CMD_SIZE);
	tmc2590_SetTxBufferInt32(phtmc2590, phtmc2590->chopConfRegister);
	tmc2590_TransmitReceive(phtmc2590, TMC2590_CMD_SIZE);
	tmc2590_SetTxBufferInt32(phtmc2590, phtmc2590->smartEnRegister);
	tmc2590_TransmitReceive(phtmc2590, TMC2590_CMD_SIZE);
	tmc2590_SetTxBufferInt32(phtmc2590, phtmc2590->stallGuardCtrlRegister);
	tmc2590_TransmitReceive(phtmc2590, TMC2590_CMD_SIZE);
	tmc2590_SetTxBufferInt32(phtmc2590, phtmc2590->drvConfRegister);
	tmc2590_TransmitReceive(phtmc2590, TMC2590_CMD_SIZE);

	HAL_TIM_Base_Start_IT(&htim2);

}

void tmc2590_SetnCS(TMC2590_HandleTypeDef *phtmc2590, FlagStatus status){
	HAL_GPIO_WritePin(phtmc2590->gpioPortNCS, phtmc2590->gpioPinNCS, status);
}

void tmc2590_SetPowerEnable(TMC2590_HandleTypeDef *phtmc2590, FlagStatus status){
	HAL_GPIO_WritePin(phtmc2590->gpioPortDrvEnN, phtmc2590->gpioPinDrvEnN, 1-status);
}


HAL_StatusTypeDef tmc2590_TransmitReceive(TMC2590_HandleTypeDef *phtmc2590, int size){
	HAL_StatusTypeDef status;

	tmc2590_SetnCS(phtmc2590, RESET);
	status = HAL_SPI_TransmitReceive(phtmc2590->hspi, phtmc2590->spiTxBuffer, phtmc2590->spiRxBuffer, size, HAL_MAX_DELAY);
	tmc2590_SetnCS(phtmc2590, SET);

	if(status == HAL_OK){
		//HAL_UART_Transmit(&hlpuart1, (uint8_t *)transmit_ok, sizeof(transmit_ok), 100);
	}
	else{

	}

	return status;
}



void tmc2590_SetTxBuffer(TMC2590_HandleTypeDef *phtmc2590, uint8_t *pData, int size){
	memcpy(phtmc2590->spiTxBuffer, pData, size);
}

void tmc2590_SetTxBufferInt32(TMC2590_HandleTypeDef *phtmc2590, uint32_t data){
	phtmc2590->spiTxBuffer[0] = (data >> 16) & 0xFF;
	phtmc2590->spiTxBuffer[1] = (data >> 8) & 0xFF;
	phtmc2590->spiTxBuffer[2] = (data >> 0) & 0xFF;
}

void tmc2590_PrintReport(TMC2590_HandleTypeDef *phtmc2590){
	char string[64];
	int stringLength, i;
	HAL_UART_Transmit(&hlpuart1, stringReportHeader, sizeof(stringReportHeader), 100);
	stringLength = snprintf(string, 64, "      Tx  |  Rx \r\n");
	HAL_UART_Transmit(&hlpuart1, string, stringLength, 100);

	for(i = 0; i < SPI_BUFFER_SIZE; i++){
		stringLength = snprintf(string, 64, "%2d : 0x%2x | 0x%2x\r\n", i, phtmc2590->spiTxBuffer[i], phtmc2590->spiRxBuffer[i]);
		HAL_UART_Transmit(&hlpuart1, string, stringLength, 100);
	}
}

void tmc2590_dumpRegister(TMC2590_HandleTypeDef *phtmc2590){

	int readRegisterSelection = 0;

	phtmc2590->drvConfRegister = 0xE044D + (readRegisterSelection << 4);
	uint8_t pData[TMC2590_CMD_SIZE];
	pData[0] = phtmc2590->drvConfRegister >> 16;
	pData[1] = (phtmc2590->drvConfRegister >> 8) & 0xFF;
	pData[2] = phtmc2590->drvConfRegister & 0xFF;
	tmc2590_SetTxBuffer(&htmc2590, pData, TMC2590_CMD_SIZE);
	tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);

	for(readRegisterSelection; readRegisterSelection<4; readRegisterSelection++){
		phtmc2590->drvConfRegister = 0xE044D + (readRegisterSelection << 4);
		uint8_t pData[TMC2590_CMD_SIZE];
		pData[0] = phtmc2590->drvConfRegister >> 16;
		pData[1] = (phtmc2590->drvConfRegister >> 8) & 0xFF;
		pData[2] = phtmc2590->drvConfRegister & 0xFF;
		tmc2590_SetTxBuffer(&htmc2590, pData, TMC2590_CMD_SIZE);
		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		tmc2590_PrintReport(&htmc2590);
	}

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		perioedElapsed_IT = 1;
	}
}

void sendOrderStepper(int numberStepper, int inputOrder){

	/* Tous les 1024 il fait un degré
	// 90° c'est 90*1024 dans le while autout de ça
	// On mets le tout dans une fonction tmc2590_sendOrder(int angle, int number_motor)
	// chooseMotor(int numbermotor){
	 * if (compris entre 1 & 3){
	 * motor send order
	 * else
	 * tmc2590_sendOrder
	 *
	 */
	int polarity = (inputOrder<0);
	int order = (int) abs(inputOrder)*142.2; //Facteur pour passer des angles aux microsteps. 12800/90
	int indice = 0;
	while (indice != order){
		if(perioedElapsed_IT){
				if(index_sin_loop < 256){
					currentCoilA = sinTable[index_sin_loop];
					currentCoilB = sinTable[256-index_sin_loop];
					polarityCoilA = polarity;
					polarityCoilB = 1;
				}
				else if(index_sin_loop < 512){
					currentCoilA = sinTable[512-index_sin_loop];
					currentCoilB = sinTable[index_sin_loop-256];
					polarityCoilA = polarity;
					polarityCoilB = 0;
				}
				else if(index_sin_loop < 768){
					currentCoilA = sinTable[index_sin_loop-512];
					currentCoilB = sinTable[768-index_sin_loop];
					polarityCoilA = 1 - polarity;
					polarityCoilB = 0;
				}
				else{
					currentCoilA = sinTable[1024-index_sin_loop];
					currentCoilB = sinTable[index_sin_loop-768];
					polarityCoilA = 1 - polarity;
					polarityCoilB = 1;
				}
				index_sin_loop = (index_sin_loop+1)%1024;
				indice++;

				drvCtrlCommand = (polarityCoilA << 17) | (currentCoilA << 9) | (polarityCoilB << 8) | (currentCoilB << 0);
				tmc2590_SetTxBufferInt32(&htmc2590, drvCtrlCommand);
				tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
				perioedElapsed_IT = 0;
			}
	}
}



