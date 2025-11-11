#ifndef NEXSTAR_CONFIG_H
#define NEXSTAR_CONFIG_H

// STM32 HAL Configuration for UART and GPIO pins

#include "stm32f1xx_hal.h"

// UART configuration
#define UART_BAUD_RATE 9600
#define UART_INSTANCE USART1

void UART_Init(void) {
    UART_HandleTypeDef huart;
    huart.Instance = UART_INSTANCE;
    huart.Init.BaudRate = UART_BAUD_RATE;
    huart.Init.WordLength = UART_WORDLENGTH_8B;
    huart.Init.StopBits = UART_STOPBITS_1;
    huart.Init.Parity = UART_PARITY_NONE;
    huart.Init.Mode = UART_MODE_TX_RX;
    huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart);
}

// GPIO configuration
#define GPIO_PIN_LED GPIO_PIN_5
#define GPIO_PORT_LED GPIOA

void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_LED;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIO_PORT_LED, &GPIO_InitStruct);
}

#endif // NEXSTAR_CONFIG_H
