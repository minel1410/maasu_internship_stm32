#include <stdio.h>
#include "stm32f4xx.h"
#include <stdint.h>
#include "clock.h"
#include "gpio.h"
#include "timer.h"
 
int main() {
    // Step 1: Initialize system clock (HSE as PLL source)
    initClock(
        ClockSource::PLL,    // Use PLL as the clock source
        PLLSource::PLL_HSE,  // Use HSE as the PLL input source
        25,                  // PLL_M: Divides HSE frequency (25 MHz input)
        200,                 // PLL_N: Multiplier to reach 200 MHz
        2,                   // PLL_P: Divides PLL output to reach 100 MHz
        VScale::SCALE_1,     // Voltage scaling
        3                    // Flash latency (based on 100 MHz system clock)
    );
 
    // Step 2: Configure GPIO for TIM3 Channel 3 (e.g., PB0)
    GPIO pwmPin(GPIOB, GPIOConfig::Pin::P0); // TIM3_CH3 on PB0
    pwmPin.enableClock();
    pwmPin.setMode(GPIOConfig::Mode::AlternateFunction);
    pwmPin.configureAlternateFunction(GPIOConfig::AlternateFunction::AF2); // AF2 for TIM3_CH3
 
    // Step 3: Initialize and start PWM on TIM3 Channel 3
    initPWM(
        TIM3,                           // Timer instance
        pwmPin,                         // GPIO for TIM3_CH3
        GPIOConfig::AlternateFunction::AF2, // Alternate function
        20000,                          // 20 kHz PWM frequency
        25.0                            // 25% duty cycle
    );
 

    while (1) {
 
    }
}