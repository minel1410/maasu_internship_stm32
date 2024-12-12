#include "stm32f411xe.h"

// Enum for selecting the microcontroller type
enum class Microcontroller {
    STM32F411,
    OtherMCU
    // Add other microcontroller types here
};

// Enum for selecting the clock source
enum class ClockSource {
    HSE, // High-Speed External
    HSI, // High-Speed Internal
    PLL  // Phase-Locked Loop
};

// Enum for selecting the target frequency
enum class TargetFrequency {
    Freq64MHz = 64000000,
    Freq84MHz = 84000000,
    Freq100MHz=100000000
};

// Enum to determine if the source is an oscillator or another type
enum class SourceType {
    Oscillator,
    Other
};

// Structure to hold parameters for calculation
struct ClockParameters {
    uint32_t source_freq;
    TargetFrequency target_freq;
    SourceType source_type;
    Microcontroller mcu_type;

    // Function to calculate optimal parameters
    void calculate_parameters(uint32_t &pllm, uint32_t &plln, uint32_t &pllp, uint32_t &vco_input_freq, uint32_t &vco_output_freq) const {
        uint32_t target_freq = static_cast<uint32_t>(this->target_freq);

        pllp = 2; // Initial PLLP value

        // Calculate PLL parameters
        pllm = source_freq / 1000000; // Set PLLM to scale source clock to 1 MHz
        vco_input_freq = source_freq / pllm; // VCO input frequency = Source / PLLM
        plln = target_freq / vco_input_freq; // Multiplier to achieve target frequency
        vco_output_freq = vco_input_freq * plln; // VCO output frequency

        // Adjust pllp to achieve the target frequency
        while ((vco_output_freq / pllp) != target_freq && pllp <= 8) {
            pllp += 2;
        }

        // Check VCO output frequency (must be in range 100 MHz to 432 MHz for STM32F411)
        if (mcu_type == Microcontroller::STM32F411) {
            if (vco_output_freq < 100000000 || vco_output_freq > 432000000) {
                while (1); // Invalid configuration
            }

            // Check target frequency (max 168 MHz for STM32F411)
            if (target_freq > 168000000) {
                while (1); // Invalid configuration
            }
        } else {
            // Add checks for other microcontrollers here
            
        }
    }
};

void SystemClock_Config(uint32_t source_freq, TargetFrequency target_freq, SourceType source_type, Microcontroller mcu_type) {
    uint32_t pllm, plln, pllp, vco_input_freq, vco_output_freq;
    ClockParameters params = {source_freq, target_freq, source_type, mcu_type};
    params.calculate_parameters(pllm, plln, pllp, vco_input_freq, vco_output_freq);

    // Enable HSE (High-Speed External) clock
    if (source_type == SourceType::Oscillator) {
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
}


int main() {
    // Example: Configure system clock for STM32F411 with HSE as source and 84 MHz target frequency
    SystemClock_Config(8000000, TargetFrequency::Freq84MHz, SourceType::Oscillator, Microcontroller::STM32F411);
    while (1) {
        // Main loop
    }
}