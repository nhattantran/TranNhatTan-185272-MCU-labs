/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t cathodeLed[12] = {
	0x800,	//1
	0x400, 	//2
	0x200, 	//3
	0x100, 	//4
	0x080,  //5
	0x040,	//6
	0x020,	//7
	0x010,	//8
	0x008,	//9
	0x004,	//10
	0x002,	//11
	0x001	//12
};


void updateLed(uint16_t number) {
	HAL_GPIO_WritePin(GPIOA, led_1_Pin, (number>>11)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_2_Pin, (number>>10)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_3_Pin, (number>>9)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_4_Pin, (number>>8)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_5_Pin, (number>>7)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_6_Pin, (number>>6)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_7_Pin, (number>>5)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_8_Pin, (number>>4)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_9_Pin, (number>>3)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_10_Pin, (number>>2)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_11_Pin, (number>>1)&0x01);
	HAL_GPIO_WritePin(GPIOA, led_12_Pin, (number>>0)&0x01);
}

void clearAllClock() {
	HAL_GPIO_WritePin(GPIOA, led_1_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_2_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_3_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_4_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_5_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_6_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_7_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_8_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_9_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_10_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_11_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, led_12_Pin, 0);
}

void setNumberOnClock(int number) {
	if (number == 1) {
			HAL_GPIO_WritePin(GPIOA, led_1_Pin, 1);
		}
		if (number == 2) {
				HAL_GPIO_WritePin(GPIOA, led_2_Pin, 1);
			}
		if (number == 3) {
				HAL_GPIO_WritePin(GPIOA, led_3_Pin, 1);
			}
		if (number == 4) {
				HAL_GPIO_WritePin(GPIOA, led_4_Pin, 1);
			}
		if (number == 5) {
				HAL_GPIO_WritePin(GPIOA, led_5_Pin, 1);
			}
		if (number == 6) {
				HAL_GPIO_WritePin(GPIOA, led_6_Pin, 1);
			}
		if (number == 7) {
				HAL_GPIO_WritePin(GPIOA, led_7_Pin, 1);
			}
		if (number == 8) {
				HAL_GPIO_WritePin(GPIOA, led_8_Pin, 1);
			}
		if (number == 9) {
				HAL_GPIO_WritePin(GPIOA, led_9_Pin, 1);
			}
		if (number == 10) {
				HAL_GPIO_WritePin(GPIOA, led_10_Pin, 1);
			}
		if (number == 11) {
				HAL_GPIO_WritePin(GPIOA, led_11_Pin, 1);
			}
		if (number == 12) {
				HAL_GPIO_WritePin(GPIOA, led_12_Pin, 1);
			}
}

void clearNumberOnClock(int number) {
	if (number == 1) {
		HAL_GPIO_WritePin(GPIOA, led_1_Pin, 0);
	}
	if (number == 2) {
			HAL_GPIO_WritePin(GPIOA, led_2_Pin, 0);
		}
	if (number == 3) {
			HAL_GPIO_WritePin(GPIOA, led_3_Pin, 0);
		}
	if (number == 4) {
			HAL_GPIO_WritePin(GPIOA, led_4_Pin, 0);
		}
	if (number == 5) {
			HAL_GPIO_WritePin(GPIOA, led_5_Pin, 0);
		}
	if (number == 6) {
			HAL_GPIO_WritePin(GPIOA, led_6_Pin, 0);
		}
	if (number == 7) {
			HAL_GPIO_WritePin(GPIOA, led_7_Pin, 0);
		}
	if (number == 8) {
			HAL_GPIO_WritePin(GPIOA, led_8_Pin, 0);
		}
	if (number == 9) {
			HAL_GPIO_WritePin(GPIOA, led_9_Pin, 0);
		}
	if (number == 10) {
			HAL_GPIO_WritePin(GPIOA, led_10_Pin, 0);
		}
	if (number == 11) {
			HAL_GPIO_WritePin(GPIOA, led_11_Pin, 0);
		}
	if (number == 12) {
			HAL_GPIO_WritePin(GPIOA, led_12_Pin, 0);
		}
}
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int counter = 0;
  int hour = 1;
  int min = 0;
  while (1)
  {
    /* USER CODE END WHILE */
	  if (counter == 12) {
		  counter = 1;
		  if (hour != 12 && min != 12) clearNumberOnClock(12);
		  setNumberOnClock(counter);
		  if (min == 12) {
			  min = 1;
			  if (hour != 12) clearNumberOnClock(12);
			  setNumberOnClock(min);
			  if (hour == 12) {
				  hour = 1;
				  clearNumberOnClock(12);
				  setNumberOnClock(hour);
			  } else {
				  if (min != hour && counter != hour) clearNumberOnClock(hour);
				  hour++;
				  setNumberOnClock(hour);
			  }
		  } else {
			  if (hour != min && counter != min) clearNumberOnClock(min);
			  min++;
			  setNumberOnClock(min);
		  }
	  } else {
		  if (hour != counter && min != counter) clearNumberOnClock(counter);
		  counter++;
		  setNumberOnClock(counter);
	  }

	  HAL_Delay(100);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led_1_Pin|led_2_Pin|led_3_Pin|led_4_Pin
                          |led_5_Pin|led_6_Pin|led_7_Pin|led_8_Pin
                          |led_9_Pin|led_10_Pin|led_11_Pin|led_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_1_Pin led_2_Pin led_3_Pin led_4_Pin
                           led_5_Pin led_6_Pin led_7_Pin led_8_Pin
                           led_9_Pin led_10_Pin led_11_Pin led_12_Pin */
  GPIO_InitStruct.Pin = led_1_Pin|led_2_Pin|led_3_Pin|led_4_Pin
                          |led_5_Pin|led_6_Pin|led_7_Pin|led_8_Pin
                          |led_9_Pin|led_10_Pin|led_11_Pin|led_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
