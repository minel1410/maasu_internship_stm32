#include "Clock.h"

bool Clock::configure() {
    if (!calculateParameters(pllm, plln, pllp, vcoInputFreq, vcoOutputFreq)) {
        return false;
    }

    // Enable HSE (High-Speed External) clock
    if (sourceType == SourceType::Oscillator) {
        RCC->CR |= RCC_CR_HSEON;
        while (!(RCC->CR & RCC_CR_HSERDY));
    }

    // Configure PLL
    RCC->PLLCFGR = (pllm << RCC_PLLCFGR_PLLM_Pos) |
                   (plln << RCC_PLLCFGR_PLLN_Pos) |
                   (((pllp / 2) - 1) << RCC_PLLCFGR_PLLP_Pos) |
                   RCC_PLLCFGR_PLLSRC_HSE;

    // Enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL as system clock source
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

    // Update SystemCoreClock variable
    SystemCoreClockUpdate();

    return true;
}

bool Clock::calculateParameters(uint32_t &pllm, uint32_t &plln, uint32_t &pllp, uint32_t &vcoInputFreq, uint32_t &vcoOutputFreq) const {
    uint32_t targetFreq = static_cast<uint32_t>(this->targetFreq);

    pllp = 2; // Initial PLLP value

    // Calculate PLL parameters
    pllm = sourceFreq / 1000000; // Set PLLM to scale source clock to 1 MHz
    vcoInputFreq = sourceFreq / pllm; // VCO input frequency = Source / PLLM
    plln = targetFreq / vcoInputFreq; // Multiplier to achieve target frequency
    vcoOutputFreq = vcoInputFreq * plln; // VCO output frequency

    // Adjust pllp to achieve the target frequency
    while ((vcoOutputFreq / pllp) != targetFreq && pllp <= 8) {
        pllp += 2;
    }

    // Check VCO output frequency (must be in range 100 MHz to 432 MHz for STM32F411)
    if (mcuType == Microcontroller::STM32F411) {
        if (vcoOutputFreq < 100000000 || vcoOutputFreq > 432000000) {
            return false; // Invalid configuration
        }

        // Check target frequency (max 168 MHz for STM32F411)
        if (targetFreq > 168000000) {
            return false; // Invalid configuration
        }
    } else {
        // Add checks for other microcontrollers here
    }

    return true;
}