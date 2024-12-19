#ifndef TIMER_H
#define TIMER_H

#include "stm32f411xe.h"
#include "gpio.h"

void initPWM(TIM_TypeDef *TIMx, GPIO &gpio, GPIOConfig::AlternateFunction af, uint32_t pwmFrequency, float dutyCycle);
void enableTimerClock(TIM_TypeDef *TIMx);
void configurePWMFrequency(TIM_TypeDef *TIMx, uint32_t pwmFrequency);
void configureDutyCycle(TIM_TypeDef *TIMx, uint8_t channel, float dutyCycle);
void startTimer(TIM_TypeDef *TIMx);
void enableTimerInterrupt(TIM_TypeDef *TIMx, uint32_t priority);

#endif