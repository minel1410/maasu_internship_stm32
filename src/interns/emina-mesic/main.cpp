#include "gpio.h"
#include "usart.h"

#include <stdint.h>
#include <stdio.h>
#include <cstring> // For strlen

uint32_t ticks{};

void systick_handler()
{
    ticks++;
}

void init_clock() {
    // Enable external clock source
    RCC->CR |= RCC_CR_HSEON | RCC_CR_HSEBYP;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Enable power controller and set voltage scale mode 1
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    PWR->CR |= PWR_CR_VOS;

    // Set the regulator voltage scaling output selection
    FLASH->ACR |= FLASH_ACR_LATENCY_3WS;

    // Configure PLLM and PLLP
    RCC->PLLCFGR = (RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR = (RCC_PLLCFGR_PLLM_2 | 200 << RCC_PLLCFGR_PLLN_Pos | RCC_PLLCFGR_PLLP_0 | RCC_PLLCFGR_PLLSRC_HSE);

    // Set prescaler for APB1 so it is divided by 2 since it works on 50MHz (divided by 2 from MCU clock)
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    // Enable PLL and wait for it to be ready
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL output as system clock source
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    SystemCoreClockUpdate();
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
    init_clock();
    // Config systick for 1ms interals
    SysTick_Config(100000);
    // Enable interupts
    __enable_irq();

    
    // Enable the clock for GPIOA
    GPIO::enableClock(GPIOA);

    // Configure pins as alternate fun
    GPIO::configurePin(GPIOA, GPIO::Pin::Pin2, GPIO::Mode::Alternate, GPIO::Pull::NoPull, GPIO::Speed::High, GPIO::OutputType::PushPull, GPIO::AlternateFunction::AF7);
    GPIO::configurePin(GPIOA, GPIO::Pin::Pin3, GPIO::Mode::Alternate, GPIO::Pull::NoPull, GPIO::Speed::High, GPIO::OutputType::PushPull, GPIO::AlternateFunction::AF7);

 // Initialize USART2
    USART::initUSART(USART2, 50000000, 115200, true, false);

    // Send a string via USART using _write
    const char* message = "Hello, USART2!\n";

    while (1) {
        //_write(0, (char*)message, strlen(message));
        printf("Hello World");
        
        //Toggle GPIO pins
        GPIO::resetPin(GPIOA, GPIO::Pin::Pin5);
        delay_ms(1000);
        GPIO::setPin(GPIOA, GPIO::Pin::Pin5);
        delay_ms(1000);
    }

    return 0;
}
