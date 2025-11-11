#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"  // Adjust include for your specific STM32 series

void UART2_Init(void) {
    // Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Set PA2 and PA3 to alternate function (UART2 TX/RX)
    GPIOA->MODER &= ~(0xF); // Clear MODE bits for PA2 and PA3
    GPIOA->MODER |= 0xA;    // Set PA2, PA3 to Alternate function mode
    GPIOA->AFR[0] |= 0x77;  // Set AF7 (USART2) for PA2 and PA3

    // Enable clock for UART2
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    // Configure UART2 
    USART2->BRR = 0x1A0; // Assume 9600 baud rate, assuming 16 MHz clock
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; // Enable TX, RX and USART
}

void UART2_SendChar(char c) {
    while (!(USART2->SR & USART_SR_TXE)); // Wait until TX is empty
    USART2->DR = c; // Send character
}

int main(void) {
    UART2_Init(); // Initialize UART2
    while (1) {
        UART2_SendChar('H'); // Send a character
        UART2_SendChar('i');
        UART2_SendChar('\n');
        for (volatile int i = 0; i < 100000; i++); // Delay loop
    }
}