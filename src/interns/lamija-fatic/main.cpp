#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "clock.h"

#include "usart.h"
#include "timer.h"


volatile uint32_t ticks=0;

void Systick_Handler(void)
{
    ticks++;
}

void delay_ms(uint32_t ms)
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

    

       PLLConfig pllConfig={
        .pllM =25,
        .pllN=200,
        .pllP=PLLP_DIV2 
    };
    ClockStatus status=initializeClock(&pllConfig);
    if(status != CLOCK_OK){
        while (1);
    }
    // Config systick at 1khz = 1ms, our HSI (high speed internal oscillator = 8mhz/8khz = 1khz)
    SysTick_Config(8000);
    // Enable interupts
    __enable_irq();
    
 

   

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
        delay_ms(200);
    }

    return 0;
}







