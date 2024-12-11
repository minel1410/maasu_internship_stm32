#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "clock.h"


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

int main()
{
    // Config systick at 1khz = 1ms, our HSI (high speed internal oscillator = 8mhz/8khz = 1khz)
    SysTick_Config(8000);
    // Enable interupts
    __enable_irq();
    
    PLLConfig pllConfig={
        .pllM =25,
        .pllN=200,
        .pllP=2
    };

    ClockStatus status =initializeClockWithRetry(&pllConfig,3);
    if(status!=CLOCK_OK){
        while(1);
    }

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER &= ~(3<<(5*2));
    GPIOA->MODER |= (1<<(5*2));

    // Init pin here (instantiate gpio object with needed GPIO port and pin)
    // We will be using the same port and pin as an example: GPIOA and pin 5
    // Set mode

    while(1)
    {
        // Write to pin
        GPIOA->ODR ^= (1<<5);
    }

    return 0;
}