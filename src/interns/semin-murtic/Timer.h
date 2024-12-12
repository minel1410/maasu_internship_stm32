#ifndef TIMER_H
#define TIMER_H

#include "stm32f411xe.h"
#include <cstdint>

// Timer class to configure and control a timer for PWM generation
class Timer {
public:
    // Constructor to initialize the timer with given parameters
    Timer(TIM_TypeDef *tim, GPIO_TypeDef *gpio, uint8_t pin, uint32_t prescaler, uint32_t period, uint32_t dutyCycle, uint8_t channel);

    // Enable timer interrupt
    void enableInterrupt(uint8_t priority);

    // Timer interrupt handler
    void handleInterrupt();

    // Set the duty cycle for the PWM signal
    void setDutyCycle(uint16_t dutyCycle);

private:
    TIM_TypeDef *tim;
    GPIO_TypeDef *gpio;
    uint8_t pin;
    uint32_t prescaler;
    uint32_t period;
    uint32_t dutyCycle;
    uint8_t channel;

    // Enable the timer clock in the RCC_APB1ENR or RCC_APB2ENR register
    void enableTimerClock();

    // Configure the GPIO pin for the timer channel to alternate function mode
    void configureGPIO();

    // Set the timer prescaler to divide the input clock frequency
    void setTimerPrescaler();

    // Set the timer period to define the PWM frequency
    void setTimerPeriod();

    // Set the output compare mode to PWM Mode 1
    void setOutputCompareMode();

    // Enable the output compare preload functionality
    void enableOutputComparePreload();

    // Enable the capture/compare output for the selected timer channel
    void enableCaptureCompareOutput();

    // Enable the timer counter to start PWM generation
    void enableTimerCounter();

    // Check if the channel is valid
    bool isValidChannel(uint8_t channel);

    // Get the IRQ number for the timer
    IRQn_Type getIRQn();
};

#endif // TIMER_H