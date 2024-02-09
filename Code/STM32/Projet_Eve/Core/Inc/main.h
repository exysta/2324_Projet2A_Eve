/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Rasp_RX_Pin GPIO_PIN_0
#define Rasp_RX_GPIO_Port GPIOC
#define Rasp_TX_Pin GPIO_PIN_1
#define Rasp_TX_GPIO_Port GPIOC
#define ST_LINK_TX_Pin GPIO_PIN_0
#define ST_LINK_TX_GPIO_Port GPIOA
#define ST_LINK_RX_Pin GPIO_PIN_1
#define ST_LINK_RX_GPIO_Port GPIOA
#define FDC_1_Pin GPIO_PIN_4
#define FDC_1_GPIO_Port GPIOA
#define FDC_4_Pin GPIO_PIN_5
#define FDC_4_GPIO_Port GPIOA
#define FDC_5_Pin GPIO_PIN_6
#define FDC_5_GPIO_Port GPIOA
#define FDC_2_Pin GPIO_PIN_7
#define FDC_2_GPIO_Port GPIOA
#define FDC_3_Pin GPIO_PIN_4
#define FDC_3_GPIO_Port GPIOC
#define FDC_8_Pin GPIO_PIN_5
#define FDC_8_GPIO_Port GPIOC
#define FDC_7_Pin GPIO_PIN_0
#define FDC_7_GPIO_Port GPIOB
#define FDC_6_Pin GPIO_PIN_1
#define FDC_6_GPIO_Port GPIOB
#define GPIO_CSN1_Pin GPIO_PIN_6
#define GPIO_CSN1_GPIO_Port GPIOC
#define GPIO_CSN1C7_Pin GPIO_PIN_7
#define GPIO_CSN1C7_GPIO_Port GPIOC
#define GPIO_CSN1C8_Pin GPIO_PIN_8
#define GPIO_CSN1C8_GPIO_Port GPIOC
#define USR_LED_1_Pin GPIO_PIN_8
#define USR_LED_1_GPIO_Port GPIOA
#define USR_LED_2_Pin GPIO_PIN_9
#define USR_LED_2_GPIO_Port GPIOA
#define USR_LED_3_Pin GPIO_PIN_10
#define USR_LED_3_GPIO_Port GPIOA
#define USR_LED_4_Pin GPIO_PIN_11
#define USR_LED_4_GPIO_Port GPIOA
#define USR_BTN_2_Pin GPIO_PIN_10
#define USR_BTN_2_GPIO_Port GPIOC
#define USR_BTN_3_Pin GPIO_PIN_11
#define USR_BTN_3_GPIO_Port GPIOC
#define USR_BTN_1_Pin GPIO_PIN_12
#define USR_BTN_1_GPIO_Port GPIOC
#define Servos_Pin GPIO_PIN_6
#define Servos_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
