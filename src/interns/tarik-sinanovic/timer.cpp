#include "timer.h"
#include "clock.h" 
#include "system_stm32f4xx.h" 

void enableTimerClock(TIM_TypeDef *TIMx) {
    if (TIMx == TIM1) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    } else if (TIMx == TIM2) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    } else if (TIMx == TIM3) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
    } else if (TIMx == TIM4) {
        RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
    }
}

void initPWM(TIM_TypeDef *TIMx, GPIO &gpio, GPIOConfig::AlternateFunction af, uint32_t pwmFrequency, float dutyCycle) {
    enableTimerClock(TIMx);
    gpio.setMode(GPIOConfig::Mode::AlternateFunction);
    gpio.configureAlternateFunction(af);

    configurePWMFrequency(TIMx, pwmFrequency); 
    configureDutyCycle(TIMx, channel, dutyCycle);

    TIMx->CCER |= TIM_CCER_CC1E; 
    startTimer(TIMx);
}

void configurePWMFrequency(TIM_TypeDef *TIMx, uint32_t pwmFrequency) {
    uint32_t timerFrequency = 50000000; //for apb1 bus
    uint32_t period = timerFrequency / pwmFrequency;
    uint32_t prescaler = 0;
    if (period > 65535) {
        prescaler = period / 65536;
        period = period / (prescaler + 1);
    }
    TIMx->PSC = prescaler;
    TIMx->ARR = period - 1;
}

void configureDutyCycle(TIM_TypeDef *TIMx, uint8_t channel, float dutyCycle) {
    uint32_t ccrValue = (dutyCycle / 100) * (TIMx->ARR + 1);
    if (channel == 1) {
        TIMx->CCR1 = ccrValue;
    } else if (channel == 2) {
        TIMx->CCR2 = ccrValue;
    } else if (channel == 3) {
        TIMx->CCR3 = ccrValue;
    } else if (channel == 4) {
        TIMx->CCR4 = ccrValue;
    }
}

void startTimer(TIM_TypeDef *TIMx) {
    TIMx->CR1 |= TIM_CR1_CEN;
}

void enableTimerInterrupt(TIM_TypeDef *TIMx, uint32_t priority) {
    if (TIMx == TIM1) {
        NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
        NVIC_SetPriority(TIM1_UP_TIM10_IRQn, priority);
    } else if (TIMx == TIM2) {
        NVIC_EnableIRQ(TIM2_IRQn);
        NVIC_SetPriority(TIM2_IRQn, priority);
    } else if (TIMx == TIM3) {
        NVIC_EnableIRQ(TIM3_IRQn);
        NVIC_SetPriority(TIM3_IRQn, priority);
    } else if (TIMx == TIM4) {
        NVIC_EnableIRQ(TIM4_IRQn);
        NVIC_SetPriority(TIM4_IRQn, priority);
    }

    TIMx->DIER |= TIM_DIER_UIE; 
    TIMx->CR1 |= TIM_CR1_CEN;  
}

extern "C" void TIM3_IRQHandler(void) {
    if (TIM3->SR & TIM_SR_UIF) { 
        TIM3->SR &= ~TIM_SR_UIF; 
        // Add your interrupt handling code here
    }
}