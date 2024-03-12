/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "tmc2590.h"
#include "stepper.h"

#define ADC_CHANNEL_ADC1_IN10   ADC_CHANNEL_10
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  Stepper stepper1;

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */


  int position_angular_1;
  char message[20];




  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_SPI3_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

	/*HAL_UART_Transmit(&huart3, (uint8_t *)"*********************\r\n", 23, 100);
	HAL_UART_Transmit(&huart3, (uint8_t *)"* TMC2590 Test Code *\r\n", 23, 100);
	HAL_UART_Transmit(&huart3, (uint8_t *)"*********************\r\n", 23, 100);
	 */

  int order = 20;
  tmc2590_Init(&htmc2590, &hspi3, nCS_GPIO_Port, nCS_Pin, DRV_ENN_GPIO_Port, DRV_ENN_Pin);

  	//HAL_UART_Transmit(&huart3,"debut\r\n", strlen("debut\r\n"), HAL_MAX_DELAY);

  	//fonction d'init


  	stepper_Init(&stepper1);
  	HAL_Delay(1000);
  	stepper1.angularPositionMax = 180;



    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */


  	while (1)
  	{

  		// Add code to choose nCS

  		//tmc2590_dumpRegister(&htmc2590);  //Report doesn't work - Fail to turn if ON

  		 //code for stepper that advances 90 degrees (works)

  		sendOrderStepper(order,&stepper1);
  		HAL_Delay(1000);
  		stepper1.angularPosition += order;

  		HAL_UART_Transmit(&huart2, (uint8_t *)"test 2\r\n", strlen("test 2\r\n"), HAL_MAX_DELAY);

  		//voir la position

		position_angular_1 = stepper1.angularPosition;
		sprintf(message, "%d \r\n", position_angular_1);
		HAL_UART_Transmit(&huart2, (uint8_t *)message ,strlen(message) , HAL_MAX_DELAY);
		HAL_Delay(1000);





		//tmc_2590_Select(int number_motor);

		/*if(index_sin_loop < 256){
			currentCoilA = sinTable[index_sin_loop];
			currentCoilB = sinTable[256-index_sin_loop];
			polarityCoilA = 0;
			polarityCoilB = 1;
		}
		else if(index_sin_loop < 512){
			currentCoilA = sinTable[512-index_sin_loop];
			currentCoilB = sinTable[index_sin_loop-256];
			polarityCoilA = 0;
			polarityCoilB = 0;
		}
		else if(index_sin_loop < 768){
			currentCoilA = sinTable[index_sin_loop-512];
			currentCoilB = sinTable[768-index_sin_loop];
			polarityCoilA = 1;
			polarityCoilB = 0;
		}
		else{
			currentCoilA = sinTable[1024-index_sin_loop];
			currentCoilB = sinTable[index_sin_loop-768];
			polarityCoilA = 1;
			polarityCoilB = 1;
		}


		drvCtrlCommand = (polarityCoilA << 17) | (currentCoilA << 9) | (polarityCoilB << 8) | (currentCoilB << 0);
		tmc2590_SetTxBufferInt32(&htmc2590, drvCtrlCommand);
		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE); */
		//tmc2590_PrintReport(&htmc2590);


		//		tmc2590_SetTxBuffer(&htmc2590, pData, TMC2590_CMD_SIZE);
		//		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		//		tmc2590_PrintReport(&htmc2590);

		//		tmc2590_dumpRegister(&htmc2590);
		//		0x3FE00;
		//		0x001FF;
		//		0x1FE00;
		//		0x000FF;

		//		tmc2590_SetTxBufferInt32(&htmc2590, 0x3FE00);
		//		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		//		HAL_Delay(1);
		//		tmc2590_SetTxBufferInt32(&htmc2590, 0x001FF);
		//		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		//		HAL_Delay(1);
		//		tmc2590_SetTxBufferInt32(&htmc2590, 0x1FE00);
		//		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		//		HAL_Delay(1);
		//		tmc2590_SetTxBufferInt32(&htmc2590, 0x000FF);
		//		tmc2590_TransmitReceive(&htmc2590, TMC2590_CMD_SIZE);
		//		HAL_Delay(1);

		//		HAL_Delay(100);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV6;
  RCC_OscInitStruct.PLL.PLLN = 85;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
