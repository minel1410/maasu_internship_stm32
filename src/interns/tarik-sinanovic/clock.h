#ifndef CLOCK_H
#define CLOCK_H

#include "stm32f411xe.h"

enum class ClockSource {
    HSI,
    HSE,
    PLL
};

enum class VScale {
    SCALE_1,
    SCALE_2,
    SCALE_3
};

enum class PLLSource {
    PLL_HSI,
    PLL_HSE,
    PLL_EXTERNAL
};

void initClock(ClockSource source, PLLSource pllSource = PLLSource::PLL_HSI, uint32_t pll_m = 0, uint32_t pll_n = 0, uint32_t pll_p = 0);
void setVoltageScale(VScale scale);
void setFlashLatency(uint32_t fLatency);
void selectClockSource(ClockSource clockSource);
void setPrescalers();
void configurePLL(PLLSource pllSource, uint32_t pll_m, uint32_t pll_n, uint32_t pll_p);

#endif