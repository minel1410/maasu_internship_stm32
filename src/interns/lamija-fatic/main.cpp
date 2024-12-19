#include <cstdio>
#include <stdint.h>
//#define STM32F411xE
#define __FPU_USED 1
#include "stm32f4xx.h"
#include "gpio.h"
#include "usart.h"

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

// Configure system clock to 100mhz
void clock_init()
{
    // Enable external clock source
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));
    // Enable power controller and set voltage scale mode 1
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    // Set the Regulator Voltage Scaling Output Selection to Scale 1 (VS1)
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= PWR_CR_VOS_0;
    // Configure flash controller for 3V3 supply and 100 Mhz -> 3 wait states
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;
    // Clear PLLM, PLLN and PLLP bits
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk |
                  RCC_PLLCFGR_PLLN_Msk |
                  RCC_PLLCFGR_PLLP_Msk);
    // Set PLLM, PLLN and PLLP, and select HSE as PLL source
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) |
                 (400 << RCC_PLLCFGR_PLLN_Pos) |
                 (1 << RCC_PLLCFGR_PLLP_Pos) |
                 RCC_PLLCFGR_PLLSRC_HSE);
    // Clear the PPRE1 bits (APB1 prescaler)
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    // Set the PPRE1 bits to divide the APB1 clock by 2
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
    // Enable PLL and wait for ready
    RCC->CR |= RCC_CR_PLLON_Msk;
    while (! (RCC->CR & RCC_CR_PLLRDY_Msk));
    // Select PLL output as system clock
    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
    while (! (RCC->CFGR & RCC_CFGR_SWS_PLL));
    // Update the internal clock frequency variable
    SystemCoreClockUpdate(); 
}
void init_tim_3()
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    // Configure alternate function
    Gpio PB0(GPIOB, 0);
    PB0.set_mode(GpioMode::GPIO_Mode_AF);
    PB0.set_alt_func(GpioAlternateFunction::GPIO_AF2);
    // Set prescaler
    TIM3->PSC = 49;
    // 50Mhz / 25khz = 
    TIM3->ARR = 19999;
    // Set duty cycle 
    TIM3->CCR3 = 0; // 0%;
    // Configure pwm mode to 1
    TIM3->CCMR2 &= ~(TIM_CCMR2_OC3M);
    TIM3->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3PE;
    // Enable capture/compare channel 3 output
    TIM3->CCER |= TIM_CCER_CC3E;
    // Enable timer
    TIM3->CR1 |= TIM_CR1_CEN;
}
int main()
{
    clock_init();
    SystemInit();
    SysTick_Config(100000);
    __enable_irq();
    // Configure USART2 on pins PA2 and PA3
    Gpio pa5(GPIOC, 13);
    pa5.set_mode(GpioMode::GPIO_Mode_OUT);
    pa5.write(1);
    
    while(1)
    {
        pa5.write(1);
        delay_ms(1000);
        pa5.write(0);
        delay_ms(1000);
        
        
    }
    return 0;
}
