/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32wbxx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
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

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern UART_Emul_HandleTypeDef  UartEmulHandle;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/* USER CODE BEGIN 1 */
/**
  * @brief UART Emulation MSP Initialization
  *        This function configures the UART Emulation resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - Port for UART Emulation
  *           - Pin Tx and Rx
  * @param  htim: UART Emulation handle pointer
  * @retval None
  */
void HAL_UART_Emul_MspInit(UART_Emul_HandleTypeDef *huart)
{
  GPIO_InitTypeDef   GPIO_InitStruct;

  /*##-1- Enable peripherals and GPIO Clocks #######################*/
  /* Enable clock for UART Emul */
  __UART_EMUL_CLK_ENABLE();

  /* Enable GPIO TX/RX clock */
  UART_EMUL_TX_GPIO_CLK_ENABLE();
  UART_EMUL_RX_GPIO_CLK_ENABLE();

  /* Initialize UART Emulation port name */
  UartEmulHandle.TxPortName = UART_EMUL_TX_PORT;
  UartEmulHandle.RxPortName = UART_EMUL_RX_PORT;

  /*Initialize UART Emulation pin number for Tx */
  UartEmulHandle.Init.RxPinNumber = UART_EMUL_RX_PIN;
  UartEmulHandle.Init.TxPinNumber = UART_EMUL_TX_PIN;

  /* Configure GPIO for UART Emulation Tx */
  GPIO_InitStruct.Pin    = UART_EMUL_TX_PIN;
  GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull   = GPIO_NOPULL;
  GPIO_InitStruct.Speed  = GPIO_SPEED_HIGH;

  HAL_GPIO_Init(UART_EMUL_TX_PORT, &GPIO_InitStruct);
  HAL_GPIO_WritePin(UartEmulHandle.TxPortName, UartEmulHandle.Init.TxPinNumber, GPIO_PIN_SET);

  /* Configure GPIOC for UART Emulation Rx */
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pin  = UART_EMUL_RX_PIN;

  HAL_GPIO_Init(UART_EMUL_RX_PORT, &GPIO_InitStruct);

  /*##-2- Enable NVIC for line Rx  #################################*/
  /* Enable and set EXTI Line Interrupt to the highest priority */
  HAL_NVIC_SetPriority(UART_EMUL_EXTI_IRQ, 0, 0);
  HAL_NVIC_EnableIRQ(UART_EMUL_EXTI_IRQ);
}
/* USER CODE END 1 */
