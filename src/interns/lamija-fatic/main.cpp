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

   
    if (end < start)
        while (ticks > start);

    
    while (ticks < end);
}


void clock_init()
{
  
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));
   
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    
    PWR->CR &= ~PWR_CR_VOS;
    PWR->CR |= PWR_CR_VOS_0;
    
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;
   
    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_Msk |
                  RCC_PLLCFGR_PLLN_Msk |
                  RCC_PLLCFGR_PLLP_Msk);
  
    RCC->PLLCFGR |= ((25 << RCC_PLLCFGR_PLLM_Pos) |
                 (400 << RCC_PLLCFGR_PLLN_Pos) |
                 (1 << RCC_PLLCFGR_PLLP_Pos) |
                 RCC_PLLCFGR_PLLSRC_HSE);
    
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
   
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
   
    RCC->CR |= RCC_CR_PLLON_Msk;
    while (! (RCC->CR & RCC_CR_PLLRDY_Msk));
   
    RCC->CFGR |= (RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos);
    while (! (RCC->CFGR & RCC_CFGR_SWS_PLL));
   
    SystemCoreClockUpdate(); 
}

int main()
{
    clock_init();
    SystemInit();
    SysTick_Config(100000);
    __enable_irq();
  
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
