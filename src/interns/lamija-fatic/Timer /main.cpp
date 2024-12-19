main : #include "stm32f4xx.h"
#include "usart.h"
#include "timer.h"

int main() {
    // Initialize USART2 with a baud rate of 115200
    usart2_init(115200);
    usart2_send_string("USART Initialized.\r\n");

    // Enable TIM3 clock
    enableTimerClock(TIM3);

    // Configure GPIO for TIM3 Channel 1 (PA6 as PWM output)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Enable GPIOA clock
    configureAlternateFunction(GPIOA, 6, 2); // Alternate Function 2 for TIM3_CH1

    // Timer configuration for 1kHz PWM signal
    uint16_t prescaler = calculatePrescalerValue(SystemCoreClock, 1000000); // 1 MHz timer clock
    uint16_t period = calculateTimerPeriod(1000000, 1000); // 1 kHz PWM frequency
    setTimerPrescaler(TIM3, prescaler);
    setTimerPeriod(TIM3, period);

    // Configure PWM mode and enable output
    setOutputCompareMode(TIM3, 1, 6); // PWM Mode 1
    enableOutputComparePreload(TIM3, 1);
    enableCaptureCompareOutput(TIM3, 1);

    // Set initial duty cycle to 50%
    setDutyCycle(TIM3, 1, period / 2);

    // Start the timer
    enableTimerCounter(TIM3);

    // Main loop
    while (1) {
        // Increment duty cycle for testing
        static uint16_t duty = 0;
        duty = (duty + 10) % (period + 1);
        setDutyCycle(TIM3, 1, duty);
        usart2_send_string("Duty Cycle: ");
        usart2_send_number(duty * 100 / period);
        usart2_send_string("%\r\n");
        for (volatile uint32_t i = 0; i < 1000000; i++); // Delay
    }

    return 0;
}