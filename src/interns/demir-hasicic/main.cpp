#include <stdint.h>
#include <stdio.h>
#include "GPIO.h"
#include "USART.h"
#include "Timer.h"
#include "Clock.h"
#include "stm32f4xx.h"

uint32_t ticks{};

void systick_handler()
{
    ticks++;
}

void delay_ms(const uint32_t &ms)
{
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}


int main() {
     Clock clock(25000000, TargetFrequency::Freq100MHz, SourceType::Oscillator);
    clock.configure();
    SysTick_Config(100000); // 1ms tick
    // Enable clock for GPIOA and USART2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;  // Enable USART2 clock

    // Configure PA2 (TX) and PA3 (RX) as Alternate Function
    GPIOA->MODER &= ~((3 << (2 * 2)) | (3 << (2 * 3))); // Clear mode bits for PA2 and PA3
    GPIOA->MODER |= (2 << (2 * 2)) | (2 << (2 * 3));    // Set Alternate Function mode (AF)

    GPIOA->OSPEEDR |= (3 << (2 * 2)) | (3 << (2 * 3));  // High speed for PA2 and PA3
    GPIOA->PUPDR &= ~((3 << (2 * 2)) | (3 << (2 * 3))); // No pull-up/pull-down
    GPIOA->AFR[0] |= (7 << (4 * 2)) | (7 << (4 * 3));   // Set AF7 (USART2) for PA2 and PA3

    // Configure USART2
    USART2->CR1 = 0;                         // Reset control register
    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE; // Enable Transmitter and Receiver
    USART2->BRR = 100000000 / 9600;          // Set baud rate assuming 100MHz clock
    USART2->CR1 |= USART_CR1_UE;             // Enable USART2

    while (1) {
        // Transmit a string
        char message[] = "Hello, USART2!\n";
        for (uint32_t i = 0; message[i] != '\0'; ++i) {
            while (!(USART2->SR & USART_SR_TXE)); // Wait until TXE (Transmit Data Register Empty)
            USART2->DR = message[i];             // Send character
        }
        delay_ms(1000); // Delay 1 second
    }

    return 0;
}
/*
#include "gpio.h"
#include "USART.h"

int main() {
    // Initialize GPIO pins for USART2
    gpio_init(GPIOA, PIN::PIN2, GPIOMODE::AFC, OTYPE::PUSH_PULL, SPEED::HIGH, PULL::NO_PULL, ALT_FUNCTION::AF7); // TX
    gpio_init(GPIOA, PIN::PIN3, GPIOMODE::AFC, OTYPE::PUSH_PULL, SPEED::HIGH, PULL::NO_PULL, ALT_FUNCTION::AF7); // RX

    // Initialize USART2 with specific parameters
    usart_init(USART2, 9600, USART_OVERSAMPLING::OVERSAMPLING_16, USART_MODE::BOTH);

    // Transmit a message via USART2
    char message[] = "Hello, USART2!\n";
    usart_write_buffer(USART2, message, sizeof(message) - 1);

    while (1) {
        // Main loop
    }

    return 0;
}
*/