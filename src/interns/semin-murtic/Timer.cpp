#include "Timer.h"

// Constructor to initialize the timer with given parameters
Timer::Timer(TIM_TypeDef *tim, GPIO_TypeDef *gpio, uint8_t pin, uint32_t prescaler, uint32_t period, uint32_t dutyCycle, uint8_t channel) 
    : tim(tim), gpio(gpio), pin(pin), prescaler(prescaler), period(period), dutyCycle(dutyCycle), channel(channel) {
    if (!isValidChannel(channel)) {
        // Handle invalid channel error
        while (1);
    }
    enableTimerClock();
    configureGPIO();
    setTimerPrescaler();
    setTimerPeriod();
    setOutputCompareMode();
    enableOutputComparePreload();
    enableCaptureCompareOutput();
    setDutyCycle(dutyCycle);
    enableTimerCounter();
}

// Enable timer interrupt
void Timer::enableInterrupt(uint8_t priority) {
    tim->DIER |= TIM_DIER_UIE; // Enable update interrupt
    NVIC_SetPriority(getIRQn(), priority);
    NVIC_EnableIRQ(getIRQn());
}

// Timer interrupt handler
void Timer::handleInterrupt() {
    if (tim->SR & TIM_SR_UIF) {
        tim->SR &= ~TIM_SR_UIF; // Clear update interrupt flag
        // Handle timer update event
    }
}

// Enable the timer clock in the RCC_APB1ENR or RCC_APB2ENR register
void Timer::enableTimerClock() {
    if (tim == TIM2 || tim == TIM3 || tim == TIM4 || tim == TIM5) {
        RCC->APB1ENR |= (1 << ((reinterpret_cast<uint32_t>(tim) - TIM2_BASE) / 0x400));
    } else {
        RCC->APB2ENR |= (1 << ((reinterpret_cast<uint32_t>(tim) - TIM1_BASE) / 0x400));
    }
}

// Configure the GPIO pin for the timer channel to alternate function mode
void Timer::configureGPIO() {
    // Enable GPIO clock
    if (gpio == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (gpio == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (gpio == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    // Add more GPIO ports as needed

    // Set pin to alternate function mode
    gpio->MODER &= ~(3 << (2 * pin));
    gpio->MODER |= (2 << (2 * pin));

    // Set alternate function to AF1 for TIM2, adjust as needed for other timers
    if (tim == TIM2) {
        if (pin < 8) {
            gpio->AFR[0] |= (1 << (4 * pin));
        } else {
            gpio->AFR[1] |= (1 << (4 * (pin - 8)));
        }
    }
    // Add alternate function configuration for other timers as needed
}

// Set the timer prescaler to divide the input clock frequency
void Timer::setTimerPrescaler() {
    tim->PSC = prescaler - 1;
}

// Set the timer period to define the PWM frequency
void Timer::setTimerPeriod() {
    tim->ARR = period - 1;
}

// Set the output compare mode to PWM Mode 1
void Timer::setOutputCompareMode() {
    if (channel == 1 || channel == 2) {
        tim->CCMR1 |= (6 << (4 * (channel - 1))); // PWM Mode 1
    } else {
        tim->CCMR2 |= (6 << (4 * (channel - 3))); // PWM Mode 1
    }
}

// Enable the output compare preload functionality
void Timer::enableOutputComparePreload() {
    if (channel == 1 || channel == 2) {
        tim->CCMR1 |= (1 << (3 + 8 * (channel - 1))); // OCxPE
    } else {
        tim->CCMR2 |= (1 << (3 + 8 * (channel - 3))); // OCxPE
    }
}

// Enable the capture/compare output for the selected timer channel
void Timer::enableCaptureCompareOutput() {
    tim->CCER |= (1 << (4 * (channel - 1))); // CCxE
}

// Set the duty cycle for the PWM signal
void Timer::setDutyCycle(uint16_t dutyCycle) {
    this->dutyCycle = dutyCycle;
    switch (channel) {
        case 1: tim->CCR1 = dutyCycle; break;
        case 2: tim->CCR2 = dutyCycle; break;
        case 3: tim->CCR3 = dutyCycle; break;
        case 4: tim->CCR4 = dutyCycle; break;
        default: break; // Handle invalid channel
    }
}

// Enable the timer counter to start PWM generation
void Timer::enableTimerCounter() {
    tim->CR1 |= TIM_CR1_CEN;
}

// Check if the channel is valid
bool Timer::isValidChannel(uint8_t channel) {
    return (channel >= 1 && channel <= 4);
}

// Get the IRQ number for the timer
IRQn_Type Timer::getIRQn() {
    if (tim == TIM1) return TIM1_UP_TIM10_IRQn;
    if (tim == TIM2) return TIM2_IRQn;
    if (tim == TIM3) return TIM3_IRQn;
    if (tim == TIM4) return TIM4_IRQn;
    if (tim == TIM5) return TIM5_IRQn;
    // Add more timers as needed
    return NonMaskableInt_IRQn; // Default to a non-maskable interrupt if not found
}