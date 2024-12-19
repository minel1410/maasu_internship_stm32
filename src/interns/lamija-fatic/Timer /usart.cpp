#include "usart.h"
#include "stm32f4xx.h"

// USART Initialization
void usart2_init(uint32_t baud_rate) {
    // Enable clock for USART2 and GPIOA
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA2 (TX) and PA3 (RX) as Alternate Function
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (3 * 2))); // Clear mode for PA2 and PA3
    GPIOA->MODER |= ((2 << (2 * 2)) | (2 << (3 * 2)));  // Set alternate function
    GPIOA->AFR[0] |= (7 << (4 * 2)) | (7 << (4 * 3));   // Set AF7 for USART2

    // Configure USART2
    USART2->BRR = SystemCoreClock / baud_rate; // Set baud rate
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable transmitter and receiver
    USART2->CR1 |= USART_CR1_UE; // Enable USART
}

// Transmit a single character
void usart2_send_char(char c) {
    while (!(USART2->SR & USART_SR_TXE)); // Wait until TX buffer is empty
    USART2->DR = c;
}

// Transmit a string
void usart2_send_string(const char *str) {
    while (*str) {
        usart2_send_char(*str++);
    }
}

// Transmit a number
void usart2_send_number(uint32_t num) {
    char buffer[10];
    sprintf(buffer, "%lu", num); // Convert number to string
    usart2_send_string(buffer);
}