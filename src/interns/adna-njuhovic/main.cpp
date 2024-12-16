#include "stm32f4xx.h" // STM32 HAL header
#include <stdint.h>    // For fixed-width integer types
#include "clockinit.h" // Including init_clock function

// SysTick counter
volatile uint32_t sysTickCounter = 0;

// SysTick handler function
extern "C" void SysTick_Handler(void) {
    sysTickCounter++;
}

// Function for delay in milliseconds
void delay_ms(uint32_t ms) {
    uint32_t start = sysTickCounter;
    while ((sysTickCounter - start) < ms);
}

int main(void) {
    // Initialize the system using the new system_init function
    system_init();

    // Initialize SysTick for 1ms ticks
    if (SysTick_Config(SystemCoreClock / 1000)) {
        while (1);
    }

    while (1) {
        delay_ms(1000); // 1-second delay
    }

    return 0;
}


