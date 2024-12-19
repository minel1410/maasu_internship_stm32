#include "stm32f4xx.h"
#include <stdint.h>

// Requirement: EnableTimerClock
// The TIMxEN bit in the RCC_APB1ENR or RCC_APB2ENR register must be set to enable the timer clock.
void enableTimerClock(TIM_TypeDef *TIMx) {
    if (TIMx == TIM1 || TIMx == TIM9 || TIMx == TIM10 || TIMx == TIM11) {
        RCC->APB2ENR |= (1 << (((uint32_t)TIMx - (uint32_t)TIM1) / 0x400));
    } else {
        RCC->APB1ENR |= (1 << (((uint32_t)TIMx - (uint32_t)TIM2) / 0x400));
    }
}

// Requirement: ConfigureAlternateFunction
// The AFRL or AFRH field in the GPIOx_AFR register must be configured to AF1, AF2, or AF3, based on the timer and channel.
void configureAlternateFunction(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t alternateFunction) {
    if (pin < 8) {
        GPIOx->AFR[0] &= ~(0xF << (pin * 4));
        GPIOx->AFR[0] |= (alternateFunction << (pin * 4));
    } else {
        GPIOx->AFR[1] &= ~(0xF << ((pin - 8) * 4));
        GPIOx->AFR[1] |= (alternateFunction << ((pin - 8) * 4));
    }
    GPIOx->MODER &= ~(3 << (pin * 2));
    GPIOx->MODER |= (2 << (pin * 2)); // Set to Alternate Function Mode
}

// Requirement: SetTimerPrescaler
// The PSC register must be written to divide the timer’s input clock frequency.
void setTimerPrescaler(TIM_TypeDef *TIMx, uint16_t prescaler) {
    TIMx->PSC = prescaler;
}

// Requirement: SetTimerPeriod
// The ARR register must be configured to define the timer period based on the desired PWM frequency and prescaler value.
void setTimerPeriod(TIM_TypeDef *TIMx, uint16_t period) {
    TIMx->ARR = period;
}

// Requirement: SetOutputCompareMode
// The OCxM bits in the CCMR1 or CCMR2 register must be set to 110 for PWM Mode 1 or 111 for PWM Mode 2.
void setOutputCompareMode(TIM_TypeDef *TIMx, uint8_t channel, uint8_t mode) {
    if (channel <= 2) {
        uint8_t shift = (channel - 1) * 8;
        TIMx->CCMR1 &= ~(0x7 << (shift + 4));
        TIMx->CCMR1 |= (mode << (shift + 4));
        TIMx->CCMR1 |= (1 << (shift + 3)); // Enable preload
    } else {
        uint8_t shift = (channel - 3) * 8;
        TIMx->CCMR2 &= ~(0x7 << (shift + 4));
        TIMx->CCMR2 |= (mode << (shift + 4));
        TIMx->CCMR2 |= (1 << (shift + 3)); // Enable preload
    }
}

// Requirement: EnableOutputComparePreload
// The OCxPE (Output Compare Preload Enable) bit in the CCMR1 or CCMR2 register must be set.
void enableOutputComparePreload(TIM_TypeDef *TIMx, uint8_t channel) {
    if (channel <= 2) {
        TIMx->CCMR1 |= (1 << ((channel - 1) * 8 + 3));
    } else {
        TIMx->CCMR2 |= (1 << ((channel - 3) * 8 + 3));
    }
}

// Requirement: EnableCaptureCompareOutput
// The CCxE bit in the CCER register must be set to enable the output for the selected timer channel.
void enableCaptureCompareOutput(TIM_TypeDef *TIMx, uint8_t channel) {
    TIMx->CCER |= (1 << ((channel - 1) * 4));
}

// Requirement: SetDutyCycle
// The calculated duty-cycle value must be written to the CCRx register to set the PWM signal’s duty cycle.
void setDutyCycle(TIM_TypeDef *TIMx, uint8_t channel, uint16_t dutyCycle) {
    if (channel == 1) {
        TIMx->CCR1 = dutyCycle;
    } else if (channel == 2) {
        TIMx->CCR2 = dutyCycle;
    } else if (channel == 3) {
        TIMx->CCR3 = dutyCycle;
    } else if (channel == 4) {
        TIMx->CCR4 = dutyCycle;
    }
}

// Requirement: EnableTimerCounter
// The CEN bit in the TIM_CR1 register must be set to start the timer and begin PWM generation.
void enableTimerCounter(TIM_TypeDef *TIMx) {
    TIMx->CR1 |= TIM_CR1_CEN;
}

// Requirement: ClearTimerConfiguration
// The TIM_CCMR register must be cleared before setting the output compare mode.
void clearTimerConfiguration(TIM_TypeDef *TIMx, uint8_t channel) {
    if (channel <= 2) {
        TIMx->CCMR1 &= ~((0x7 << 4) | (1 << 3)); // Clear OCxM and OCxPE bits
    } else {
        TIMx->CCMR2 &= ~((0x7 << 4) | (1 << 3)); // Clear OCxM and OCxPE bits
    }
}

// Requirement: CalculateTimerPeriod
// The function must calculate the timer period based on the desired PWM frequency.
uint16_t calculateTimerPeriod(uint32_t timerClock, uint32_t pwmFrequency) {
    return (uint16_t)((timerClock / pwmFrequency) - 1);
}

// Requirement: CalculatePrescalerValue
// The function must calculate the prescaler value for the timer.
uint16_t calculatePrescalerValue(uint32_t inputClock, uint32_t timerClock) {
    return (uint16_t)((inputClock / timerClock) - 1);
}

// Requirement: WriteCCRValue
// The function must write the calculated CCR value to the timer CCR register.
void writeCCRValue(TIM_TypeDef *TIMx, uint8_t channel, uint16_t value) {
    setDutyCycle(TIMx, channel, value);
}