/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <stdio.h>
#include <math.h>
#include <string.h>

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
I2C_HandleTypeDef hi2c1;

I2S_HandleTypeDef hi2s3;

RNG_HandleTypeDef hrng;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

//int arr1[] = {1577, 3104, 1722, 165, 1060, 2094, 1990, 1658, 3210, 1242, 1952, 1466, 2389, 894, 2067, 570, 1154, 572, 3095, 388, 2532, 3274, 1026, 2181, 2888, 3318, 2465, 601, 1270, 404, 2989, 302, 2801, 1352, 1933, 2292, 412, 1449, 1778, 1295, 2502, 2623, 837, 2263, 1953, 1813, 2135, 1066, 255, 3297, 2247, 57, 382, 2947, 1633, 2909, 3215, 2736, 2561, 4, 2506, 2021, 1364, 999, 2991, 1332, 2882, 257, 782, 2324, 908, 977, 3290, 583, 3289, 2224, 1834, 373, 329, 1310, 2080, 2004, 446, 1234, 2257, 1192, 2894, 511, 2242, 1362, 2213, 832, 3274, 2470, 2241, 2406, 1178, 1822, 375, 2442, 3268, 1576, 1298, 2357, 991, 1189, 753, 775, 764, 135, 2509, 2689, 1065, 1951, 282, 367, 2780, 3103, 533, 612, 158, 328, 2864, 2214, 2799, 1602, 2888, 2148, 1128, 2137, 3324, 964, 881, 2783, 2415, 1717, 2374, 1127, 1845, 2017, 2704, 2626, 2868, 3249, 1463, 337, 1328, 2509, 472, 1992, 2404, 2581, 1373, 779, 995, 66, 2996, 1110, 479, 2889, 903, 1523, 3254, 698, 1362, 1745, 254, 412, 3207, 599, 2857, 896, 185, 2350, 2597, 2188, 2466, 2787, 303, 109, 509, 2600, 772, 2483, 2359, 490, 1602, 374, 1516, 475, 149, 2480, 88, 797, 757, 2941, 507, 1962, 862, 2978, 3279, 250, 2782, 93, 2229, 1743, 2541, 415, 1064, 286, 904, 294, 2649, 1233, 1434, 1786, 738, 250, 2062, 1913, 161, 2443, 413, 2864, 1602, 816, 1065, 1468, 2996, 1926, 2333, 693, 2857, 2755, 833, 3143, 237, 3230, 2769, 648, 663, 1402, 2168, 1026, 480, 2444, 1811, 2726, 716, 54, 1931, 2790, 1678, 2331, 2083, 1275};
//int arr2[] = {1896, 2511, 1529, 1094, 567, 762, 2771, 26, 1385, 2059, 1899, 2476, 331, 1368, 2270, 2525, 2867, 167, 2982, 1552, 693, 2881, 1851, 2969, 1730, 643, 689, 974, 210, 454, 542, 2073, 2418, 259, 3171, 2819, 1571, 3234, 3056, 416, 1192, 839, 2761, 918, 2972, 3248, 1727, 359, 3164, 1092, 859, 1624, 1151, 1399, 3315, 176, 817, 2903, 21, 1684, 224, 1551, 2014, 569, 96, 969, 1739, 3015, 458, 2444, 15, 496, 3130, 2370, 809, 831, 1352, 33, 342, 545, 2210, 71, 2051, 347, 2346, 2034, 2201, 811, 1720, 281, 1630, 787, 2616, 3133, 382, 2870, 2374, 595, 706, 2494, 2947, 168, 221, 1105, 2273, 2798, 2483, 611, 3052, 1099, 3018, 2356, 140, 496, 2889, 1648, 969, 662, 2503, 2068, 176, 3014, 1498, 2761, 2138, 2417, 2315, 3172, 2816, 355, 1422, 450, 2392, 1497, 1848, 860, 1647, 814, 2352, 3054, 75, 1552, 3274, 2489, 1346, 2, 1775, 457, 874, 908, 1818, 1104, 1330, 363, 1258, 2578, 1166, 422, 2119, 3211, 225, 104, 1562, 3197, 2295, 3307, 1755, 2037, 1417, 2905, 3185, 1016, 2318, 3021, 271, 1740, 2653, 945, 392, 3115, 1642, 2088, 1527, 2295, 1512, 569, 2734, 1189, 700, 2837, 1060, 120, 206, 3316, 707, 1077, 672, 492, 2484, 607, 48, 199, 249, 1844, 854, 3221, 1592, 1205, 2504, 60, 3271, 1452, 1167, 576, 1969, 2301, 1137, 562, 354, 3061, 2277, 1212, 2850, 483, 268, 1720, 1848, 583, 2882, 2301, 3130, 3255, 1568, 2409, 3288, 692, 2716, 2930, 1122, 3160, 2446, 2492, 2025, 1428, 406, 198, 1133, 2166, 525, 709, 3270, 2579, 345, 664, 3195, 3234};
//int result1[256], result2[256], result3[256], result4[256];

int randArr[256], r1[256], r2[256];

//int iteration = 10;
double double_precision = 1000;
//char arrNum = 1;
int last_gpio_exti = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_RNG_Init(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

void printArray(int arr[], char arrName[], int arrSize);
void arrCopy(const int from[], int to[], int arrSize);
int bit_reverse_7(int num);
int positive_modulo(int num, int modulus);
int modular_power(int x, int y, int modulus);
void ntt(int arr[], int result[]);
void intt(int arr[], int result[]);

//void multiple_calculations_arr1(int iter);
//void multiple_calculations_arr2(int iter);
//void doArr1();
//void doArr2();

//void turn_on_one_LED_board(int ledNum);

//void timing_and_iteration_of_arr1_and_arr2();

void generate_random_array(int arr[], int size, uint32_t min, uint32_t max);
void random_array_ntt_intt();

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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

//  HAL_TIM_Base_Start(&htim2);
//  int elapsed_time;
//  HAL_TIM_Base_Start(&htim2);
//  elapsed_time = __HAL_TIM_GET_COUNTER(&htim2);
//  HAL_Delay(2100);
//  elapsed_time = __HAL_TIM_GET_COUNTER(&htim2) - elapsed_time;
//
//  char str[100];
//  sprintf(str, "%.3f", ((double)elapsed_time / double_precision));
//  HAL_UART_Transmit(&huart2, (const uint8_t*)str, strlen(str), 200);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */

//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
//    HAL_Delay(1000);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
//    HAL_Delay(1000);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
//    HAL_Delay(1000);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
//    HAL_Delay(1000);
//    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);


//    uint32_t myRandNum;
//    HAL_RNG_GenerateRandomNumber(&hrng, &myRandNum);
//    myRandNum %= 3329;
//    char str[5];
//    sprintf(str, "%d\n", (int)myRandNum);
//    HAL_UART_Transmit(&huart2, (const uint8_t*)str, strlen(str), 200);
//    HAL_Delay(1000);
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  /* USER CODE BEGIN I2S3_Init 0 */

  /* USER CODE END I2S3_Init 0 */

  /* USER CODE BEGIN I2S3_Init 1 */

  /* USER CODE END I2S3_Init 1 */
  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_ENABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_96K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S3_Init 2 */

  /* USER CODE END I2S3_Init 2 */

}

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
static void MX_RNG_Init(void)
{

  /* USER CODE BEGIN RNG_Init 0 */

  /* USER CODE END RNG_Init 0 */

  /* USER CODE BEGIN RNG_Init 1 */

  /* USER CODE END RNG_Init 1 */
  hrng.Instance = RNG;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RNG_Init 2 */

  /* USER CODE END RNG_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 84 - 1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10000000 - 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CS_I2C_SPI_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BOOT1_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin LD5_Pin LD6_Pin
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : OTG_FS_OverCurrent_Pin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void printArray(int arr[], char arrName[], int arrSize) {
	char stringToPrint[2000], temp[100];
    sprintf(stringToPrint, "%s = {", arrName);
    int i;

    for (i = 0; i < (arrSize - 1); i++) {
        sprintf(temp, "%d, ", arr[i]);
        strcat(stringToPrint, temp);
    }

    if (arrSize != 0) {
        sprintf(temp, "%d}\n\n", arr[arrSize - 1]);
        strcat(stringToPrint, temp);
        HAL_UART_Transmit(&huart2, (const uint8_t*)stringToPrint, strlen(stringToPrint), 200);
    }
}

void arrCopy(const int from[], int to[], int arrSize) {
    int i;

    for (i = 0; i < arrSize; i++)
        to[i] = from[i];
}

int bit_reverse_7(int num) {
//    if (num > 127 || num < 0) {
//        printf("The value should be a number from 0 to 127.\nProvided value: %d", num);
//        exit(1);
//    }

    char binary[8];
    int bit_presenter = 64, i, result = 0;

    for (i = 0; i < 7; i++) {
        if (num >= bit_presenter) {
            binary[i] = '1';
            num -= bit_presenter;
        } else
            binary[i] = '0';

        bit_presenter >>= 1;
    }
    binary[7] = '\0';

    for (i = 0; i < 7; i++)
        if (binary[i] == '1')
            result += (int)pow(2, i);

    return result;
}

int positive_modulo(int num, int modulus) {
    int result = num % modulus;

    if (result < 0)
        result += modulus;

    return result;

//    return ((num % modulus) + modulus) % modulus;

//    int m = num % modulus;
//    return m + ((m >> 31) & modulus);

//    return num % modulus;
}

int modular_power(int x, int y, int modulus) {
    int result = 1;
    x = positive_modulo(x, modulus);

    if (x == 0)
        return 0;

    while (y > 0) {
        if (y & 1)                  // If y is odd
            result = positive_modulo((result * x), modulus);

        // y should be even now
        y >>= 1;                    // y /= 2
        x = positive_modulo((x * x), modulus);
    }

    return result;
}

void ntt(int arr[], int result[]) {
    int len, start, i = 1;
    arrCopy(arr, result, 256);

    for (len = 128; len >= 2; len >>= 1) {
        for (start = 0; start < 256; start += (len << 1)) {
            int j, zeta = modular_power(17, bit_reverse_7(i), 3329);
            i++;

            for (j = start; j < (start + len); j++) {
                int t = positive_modulo((zeta * result[j + len]), 3329);
                result[j + len] = positive_modulo(result[j] - t, 3329);
                result[j] = positive_modulo((result[j] + t), 3329);
            }
        }
    }
}

void intt(int arr[], int result[]) {
    int len, start, i = 127;
    arrCopy(arr, result, 256);

    for (len = 2; len <= 128; len <<= 1) {
        for (start = 0; start < 256; start += len << 1) {
            int j, zeta = modular_power(17, bit_reverse_7(i), 3329);
            i--;

            for (j = start; j < (start + len); j++) {
                int t = result[j];
                result[j] = positive_modulo((t + result[j + len]), 3329);
                result[j + len] = positive_modulo((zeta * (result[j + len] - t)), 3329);
            }
        }
    }

    for (i = 0; i < 256; i++)
        result[i] = positive_modulo((result[i] * 3303), 3329);
}

//void multiple_calculations_arr1(int iter) {
//	int i, j, sum[256];
//	char str[100];
//	sprintf(str, "Average result of performing NTT and INTT on arr1 after %d times", iter);
//
//	for (i = 0; i < 256; i++)
//		sum[i] = 0;
//
//	for (i = 0; i < iter; i++) {
//		ntt (arr1, result1);
//		intt(result1, result2);
//
//		for (j = 0; j < 256; j++)
//			sum[j] += result2[j];
//	}
//
//	for (i = 0; i < 256; i++)
//		sum[i] /= iter;
//
//	printArray(sum, str, 256);
//}
//
//void multiple_calculations_arr2(int iter) {
//	int i, j, sum[256];
//	char str[100];
//	sprintf(str, "Average result of performing NTT and INTT on arr2 after %d times", iter);
//
//	for (i = 0; i < 256; i++)
//		sum[i] = 0;
//
//	for (i = 0; i < iter; i++) {
//		ntt (arr2, result3);
//		intt(result3, result4);
//
//		for (j = 0; j < 256; j++)
//			sum[j] += result4[j];
//	}
//
//	for (i = 0; i < 256; i++)
//		sum[i] /= iter;
//
//	printArray(sum, str, 256);
//}
//
//void doArr1() {
//	HAL_TIM_Base_Start(&htim2);
//	int ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
//	ntt (arr1, result1);
//	ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - ntt_timeLapse;
//
//	int intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
//	intt(result1, result2);
//	intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - intt_timeLapse;
//	HAL_TIM_Base_Stop(&htim2);
//
//	char arr1Name[] = "Arr1", ntt1Name[] = "NTT of arr1", intt1Name[] = "INTT of result1", str[100];
//	printArray(arr1, arr1Name, 256);
//	printArray(result1, ntt1Name, 256);
//	printArray(result2, intt1Name, 256);
//
//	sprintf(str, "It took %.3f milliseconds to do NTT and %.3f milliseconds to do INTT operations on arr1.\n\n", ((double)ntt_timeLapse / double_precision), ((double)intt_timeLapse / double_precision));
//	HAL_UART_Transmit(&huart2, (const uint8_t*)str, strlen(str), 200);
//}
//
//void doArr2() {
//	HAL_TIM_Base_Start(&htim2);
//	int ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
//	ntt (arr2, result3);
//	ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - ntt_timeLapse;
//
//	int intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
//	intt(result3, result4);
//	intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - intt_timeLapse;
//	HAL_TIM_Base_Stop(&htim2);
//
//	char arr2Name[] = "Arr2", ntt2Name[] = "NTT of arr2", intt2Name[] = "INTT of result3", str[100];
//	printArray(arr2, arr2Name, 256);
//	printArray(result3, ntt2Name, 256);
//	printArray(result4, intt2Name, 256);
//
//	sprintf(str, "It took %.3f milliseconds to do NTT and %.3f milliseconds to do INTT operations on arr2.\n\n", ((double)ntt_timeLapse / double_precision), ((double)intt_timeLapse / double_precision));
//	HAL_UART_Transmit(&huart2, (const uint8_t*)str, strlen(str), 200);
//}
//
//void turn_on_one_LED_board(int LED_num) {
//	switch (LED_num) {
//	case 1:
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//		break;
//	case 2:
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//		break;
//	case 3:
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//		break;
//	case 4:
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
//		break;
//	default:
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
//	}
//}
//
//void timing_and_iteration_of_arr1_and_arr2() {
//	switch (arrNum) {
//	case 1:
//		turn_on_one_LED_board(1);
//		doArr1();
//		arrNum++;
//		break;
//	case 2:
//		turn_on_one_LED_board(2);
//		doArr2();
//		arrNum++;
//		break;
//	case 3:
//		turn_on_one_LED_board(3);
//		multiple_calculations_arr1(iteration);
//		arrNum++;
//		break;
//	case 4:
//		turn_on_one_LED_board(4);
//		multiple_calculations_arr2(iteration);
//		arrNum = 1;
//		break;
//	}
//}

void generate_random_array(int arr[], int size, uint32_t min, uint32_t max) {
	int i;
	uint32_t randNum;

	for (i = 0; i < size; i++) {
		HAL_RNG_GenerateRandomNumber(&hrng, &randNum);
		randNum = (randNum % (max - min + 1)) + min;
		arr[i] = (int)randNum;
	}
}

void random_array_ntt_intt() {
	generate_random_array(randArr, 256, 0, 3328);

	HAL_TIM_Base_Start(&htim2);
	int ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
	ntt (randArr, r1);
	ntt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - ntt_timeLapse;

	int intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2);
	intt(r1, r2);
	intt_timeLapse = __HAL_TIM_GET_COUNTER(&htim2) - intt_timeLapse;
	HAL_TIM_Base_Stop(&htim2);

	char arr1Name[] = "randArr", ntt1Name[] = "NTT of randArr", intt1Name[] = "INTT of r1", str[100];
	printArray(randArr, arr1Name, 256);
	printArray(r1, ntt1Name, 256);
	printArray(r2, intt1Name, 256);

	sprintf(str, "It took %.3f milliseconds to do NTT and %.3f milliseconds to do INTT operations on randArr.\n\n", ((double)ntt_timeLapse / double_precision), ((double)intt_timeLapse / double_precision));
	HAL_UART_Transmit(&huart2, (const uint8_t*)str, strlen(str), 200);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == GPIO_PIN_0) {
		if (last_gpio_exti + 200 > HAL_GetTick())
			return;
		last_gpio_exti = HAL_GetTick();

//		timing_and_iteration_of_arr1_and_arr2();

		random_array_ntt_intt();
	}
}

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
