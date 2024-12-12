#include <stdint.h>
#include "stm32f411xe.h"
#include "Clock.h" // Include the Clock class header
#include "Timer.h" // Include the Timer class header

uint32_t ticks{};

// SysTick interrupt handler
extern "C" void SysTick_Handler() {
    ticks++;
}

// Delay function using SysTick
void delay_ms(const uint32_t &ms) {
    uint32_t start = ticks;
    uint32_t end = start + ms;

    // Check overflow
    if (end < start)
        while (ticks > start);

    // Wait for ticks to wrap around to zero
    while (ticks < end);
}

int main() {
    // Create a Clock object and configure the system clock
    Clock clock(8000000, TargetFrequency::Freq84MHz, SourceType::Oscillator, Microcontroller::STM32F411);
    if (!clock.configure()) {
        // Handle clock configuration failure
        while (1);
    }

    // Config SysTick at 1kHz = 1ms, our HSI (high speed internal oscillator = 8MHz/8kHz = 1kHz)
    SysTick_Config(SystemCoreClock / 1000);

    // Enable interrupts
    __enable_irq();

    // Init Timer here (instantiate Timer object with needed GPIO port and pin)
    // Example: TIM2, GPIOA pin 5, 16MHz clock, 1kHz PWM, 50% duty cycle, channel 1
    Timer timer(TIM2, GPIOA, 5, 16000, 1000, 500, 1);
    timer.enableInterrupt(1); // Enable interrupt with priority 1

    while (1) {
        // Main loop
    }

    return 0;
}