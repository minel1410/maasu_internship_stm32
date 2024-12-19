#include "clock.h"
#include "system_stm32f4xx.h" // Include CMSIS header for SystemCoreClock

void initClock(ClockSource source, PLLSource pllSource, uint32_t pll_m, uint32_t pll_n, uint32_t pll_p) {
    setPrescalers();

    if (source == ClockSource::PLL) {
        configurePLL(pllSource, pll_m, pll_n, pll_p);
    }

    selectClockSource(source);

    // Update SystemCoreClock to reflect the new clock configuration
    SystemCoreClockUpdate();
}

void setVoltageScale(VScale scale) {
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    while (!(RCC->APB1ENR & RCC_APB1ENR_PWREN));

    PWR->CR &= ~PWR_CR_VOS;
    switch (scale) {
        case VScale::SCALE_1:
            PWR->CR |= PWR_CR_VOS_0 | PWR_CR_VOS_1;
            break;
        case VScale::SCALE_2:
            PWR->CR |= PWR_CR_VOS_1;
            break;
        case VScale::SCALE_3:
            PWR->CR |= PWR_CR_VOS_0;
            break;
    }
}

void setFlashLatency(uint32_t fLatency) {
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR |= fLatency;
}

void selectClockSource(ClockSource clockSource) {
    switch (clockSource) {
        case ClockSource::HSE:
            RCC->CR |= RCC_CR_HSEON;
            while (!(RCC->CR & RCC_CR_HSERDY));
            RCC->CFGR &= ~RCC_CFGR_SW;
            RCC->CFGR |= RCC_CFGR_SW_HSE;
            while (!(RCC->CFGR & RCC_CFGR_SWS_HSE));
            break;

        case ClockSource::PLL:
            RCC->CFGR &= ~RCC_CFGR_SW;
            RCC->CFGR |= RCC_CFGR_SW_PLL;
            while (!(RCC->CFGR & RCC_CFGR_SWS_PLL));
            break;

        case ClockSource::HSI:
        default:
            RCC->CR |= RCC_CR_HSION;
            while (!(RCC->CR & RCC_CR_HSIRDY));
            RCC->CFGR &= ~RCC_CFGR_SW;
            RCC->CFGR |= RCC_CFGR_SW_HSI;
            while (!(RCC->CFGR & RCC_CFGR_SWS_HSI));
            break;
    }
}

void configurePLL(PLLSource pllSource, uint32_t pll_m, uint32_t pll_n, uint32_t pll_p) {
    if (pllSource == PLLSource::PLL_HSE || pllSource == PLLSource::PLL_EXTERNAL) {
        RCC->CR |= RCC_CR_HSEON;
        while (!(RCC->CR & RCC_CR_HSERDY));

        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;
        RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
    } else {
        RCC->CR |= RCC_CR_HSION;
        while (!(RCC->CR & RCC_CR_HSIRDY));

        RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLSRC;
        RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI;
    }

    RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP);
    RCC->PLLCFGR |= (pll_m << RCC_PLLCFGR_PLLM_Pos | pll_n << RCC_PLLCFGR_PLLN_Pos | pll_p << RCC_PLLCFGR_PLLP_Pos);

    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));
}

void setPrescalers() {
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    RCC->CFGR &= ~RCC_CFGR_PPRE2;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
}