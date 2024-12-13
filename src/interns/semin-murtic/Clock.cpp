#include "Clock.h"

bool Clock::configure() {
    // Initialize the selected clock source
    if (!initializeClockSource()) {
        return false;
    }

    // If PLL is selected, configure PLL
    if (sourceType == SourceType::Oscillator) {
        // Calculate PLL parameters
        if (!calculateParameters(pllm, plln, pllp, vcoInputFreq, vcoOutputFreq)) {
            return false;
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
    } else {
        // If not using PLL, set system clock source directly
        if (sourceType == SourceType::Oscillator) {
            RCC->CFGR &= ~RCC_CFGR_SW;
            RCC->CFGR |= RCC_CFGR_SW_HSE;

            // Wait until HSE is used as system clock
            int timeout = 1000000;
            while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE) {
                if (--timeout == 0) {
                    return false; // System clock switch timeout
                }
            }

            // Update SystemCoreClock variable
            SystemCoreClock = sourceFreq;
        } else if (sourceType == SourceType::Other) {
            RCC->CFGR &= ~RCC_CFGR_SW;
            RCC->CFGR |= RCC_CFGR_SW_HSI;

            // Wait until HSI is used as system clock
            int timeout = 1000000;
            while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI) {
                if (--timeout == 0) {
                    return false; // System clock switch timeout
                }
            }

            // Update SystemCoreClock variable
            SystemCoreClock = 16000000; // Default HSI frequency for STM32F411
        } else {
            return false; // Unsupported clock source
        }
    }

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

bool Clock::initializeHSE() {
    // Enable HSE
    RCC->CR |= RCC_CR_HSEON;

    // Configure HSE bypass if enabled
    if (bypassMode == HSEBypassMode::Enabled) {
        RCC->CR |= RCC_CR_HSEBYP;
    } else {
        RCC->CR &= ~RCC_CR_HSEBYP;
    }

    // Wait until HSE is ready
    int timeout = 1000000;
    while (!(RCC->CR & RCC_CR_HSERDY)) {
        if (--timeout == 0) {
            return false; // HSE failed to start
        }
    }

    return true;
}

bool Clock::initializeHSI() {
    // Enable HSI
    RCC->CR |= RCC_CR_HSION;

    // Wait until HSI is ready
    int timeout = 1000000;
    while (!(RCC->CR & RCC_CR_HSIRDY)) {
        if (--timeout == 0) {
            return false; // HSI failed to start
        }
    }

    return true;
}

bool Clock::initializeClockSource() {
    switch (sourceType) {
        case SourceType::Oscillator:
            return initializeHSE();
        case SourceType::Other:
            return initializeHSI();
        default:
            return false; // Unsupported clock source
    }
}