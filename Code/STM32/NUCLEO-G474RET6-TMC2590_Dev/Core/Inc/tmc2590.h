/*
 * tmc2590.h
 *
 *  Created on: Nov 16, 2023
 *      Author: nicolas
 */

#ifndef INC_TMC2590_H_
#define INC_TMC2590_H_

#include "main.h"
#include "stepper.h"

#define SPI_BUFFER_SIZE 6
#define TMC2590_CMD_SIZE 3

// Register Command values
// Driver Control Register in SPI MODE (SDOFF = 1)
#define DRV_CTRL_HEADER 		(0x00000 << 18)
#define PHA_POLARITY_P			(0x00000 << 17)
#define PHA_POLARITY_N 			(0x00001 << 17)
#define PHB_POLARITY_P			(0x00000 << 8)
#define PHB_POLARITY_N 			(0x00001 << 8)

// Chopper Configuration Register
#define CHOP_CONF_HEADER 		(0x00004 << 17)
#define BLANKING_TIME_16T		(0x00000 << 15)
#define BLANKING_TIME_24T		(0x00001 << 15)
#define BLANKING_TIME_36T		(0x00010 << 15)
#define BLANKING_TIME_54T		(0x00011 << 15)
#define CHOP_MODE_STD			(0x00000 << 14)
#define CHOP_MODE_FAST_DECAY	(0x00001 << 14)
#define RND_TOFF_OFF			(0x00000 << 13)
#define RND_TOFF_ON	    		(0x00001 << 13)
// To be completed ...

// Smart Enable Register
#define SMART_EN_HEADER 	0x00005 << 17


// StallGuard2 and Current Setting Register
#define SGCS_CONF_HEADER 	0x00006 << 17


// Driver Configuration Register
#define DRV_CONF_HEADER 	0x00007 <<17

typedef struct __TMC2590_HandleTypeDef{
	SPI_HandleTypeDef *hspi;
	uint16_t gpioPinNCS;
	GPIO_TypeDef *gpioPortNCS;
	uint16_t gpioPinDrvEnN;
	GPIO_TypeDef *gpioPortDrvEnN;
	uint8_t spiTxBuffer[SPI_BUFFER_SIZE];
	uint8_t spiRxBuffer[SPI_BUFFER_SIZE];
	uint32_t drvCtrlRegister;
	uint32_t chopConfRegister;
	uint32_t smartEnRegister;
	uint32_t stallGuardCtrlRegister;
	uint32_t drvConfRegister;
}TMC2590_HandleTypeDef;



extern TMC2590_HandleTypeDef htmc2590;


extern const uint8_t sinTable[256];
extern uint8_t perioedElapsed_IT;

void tmc2590_Init(TMC2590_HandleTypeDef *phtmc2590, SPI_HandleTypeDef *hspi, GPIO_TypeDef *gpioPortNCS, uint16_t gpioPinNCS, GPIO_TypeDef *gpioPortDrvEnN, uint16_t gpioPinDrvEnN);
void tmc2590_SetnCS(TMC2590_HandleTypeDef *phtmc2590, FlagStatus status);
void tmc2590_SetPowerEnable(TMC2590_HandleTypeDef *phtmc2590, FlagStatus status);
HAL_StatusTypeDef tmc2590_TransmitReceive(TMC2590_HandleTypeDef *phtmc2590, int size);
void tmc2590_SetTxBuffer(TMC2590_HandleTypeDef *phtmc2590, uint8_t *pData, int size);
void tmc2590_SetTxBufferInt32(TMC2590_HandleTypeDef *phtmc2590, uint32_t data);
void tmc2590_PrintReport(TMC2590_HandleTypeDef *phtmc2590);
void tmc2590_dumpRegister(TMC2590_HandleTypeDef *phtmc2590);
int sendOrderStepper(int inputOrder, Stepper * stepper);



#endif /* INC_TMC2590_H_ */
