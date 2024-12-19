#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include "stm32f4xx.h"

void enableTimerClock(TIM_TypeDef *TIMx);
void configureAlternateFunction(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t alternateFunction);
void setTimerPrescaler(TIM_TypeDef *TIMx, uint16_t prescaler);
void setTimerPeriod(TIM_TypeDef *TIMx, uint16_t period);
void setOutputCompareMode(TIM_TypeDef *TIMx, uint8_t channel, uint8_t mode);
void enableOutputComparePreload(TIM_TypeDef *TIMx, uint8_t channel);
void enableCaptureCompareOutput(TIM_TypeDef *TIMx, uint8_t channel);
void setDutyCycle(TIM_TypeDef *TIMx, uint8_t channel, uint16_t dutyCycle);
void enableTimerCounter(TIM_TypeDef *TIMx);
uint16_t calculateTimerPeriod(uint32_t timerClock, uint32_t pwmFrequency);
uint16_t calculatePrescalerValue(uint32_t inputClock, uint32_t timerClock);

#endif 