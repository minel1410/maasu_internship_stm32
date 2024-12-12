#include "gpio.h"


#include "stdint.h"
#include "stdio.h"


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
    // Config systick at 1khz = 1ms, our HSI (high speed internal oscillator = 8mhz/8khz = 1khz)
    SysTick_Config(8000);
    // Enable interupts
    __enable_irq();

    
    // Enable the clock for GPIOA
    GPIO::GPIOHandler::enableClock(GPIO::Port::A);

    // Configure PA5 as output
    GPIO::GPIOHandler::configurePin(GPIO::Port::A, GPIO::Pin::Pin5, GPIO::Mode::Output, GPIO::Pull::NoPull, GPIO::Speed::Low, GPIO::OutputType::PushPull);

    while(1)
    {
        // Set PA5
        GPIO::GPIOHandler::setPin(GPIO::Port::A, GPIO::Pin::Pin5);
        delay_ms(1000);

        // Reset PA5
        GPIO::GPIOHandler::resetPin(GPIO::Port::A, GPIO::Pin::Pin5);
        delay_ms(1000);
    }

    bool pinState = GPIO::GPIOHandler::readPin(GPIO::Port::A, GPIO::Pin::Pin5);


    return 0;
}
