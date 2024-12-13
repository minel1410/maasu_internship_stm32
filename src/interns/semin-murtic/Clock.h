#ifndef CLOCK_H
#define CLOCK_H

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
    Freq100MHz = 100000000
};

// Enum to determine if the source is an oscillator or another type
enum class SourceType {
    Oscillator,
    Other
};

// Enum for HSE bypass mode
enum class HSEBypassMode {
    Disabled,
    Enabled
};

// Clock configuration class
class Clock {
public:
    Clock(uint32_t sourceFreq, TargetFrequency targetFreq, SourceType sourceType, Microcontroller mcuType, HSEBypassMode bypassMode = HSEBypassMode::Disabled)
        : sourceFreq(sourceFreq), targetFreq(targetFreq), sourceType(sourceType), mcuType(mcuType), bypassMode(bypassMode) {}

    bool configure();

private:
    uint32_t sourceFreq;
    TargetFrequency targetFreq;
    SourceType sourceType;
    Microcontroller mcuType;
    HSEBypassMode bypassMode;
    uint32_t pllm, plln, pllp, vcoInputFreq, vcoOutputFreq;

    // Function to calculate optimal PLL parameters
    bool calculateParameters(uint32_t &pllm, uint32_t &plln, uint32_t &pllp, uint32_t &vcoInputFreq, uint32_t &vcoOutputFreq) const;

    // Function to enable and configure HSE with optional bypass
    bool initializeHSE();

    // Function to enable and configure HSI
    bool initializeHSI();

    // Function to initialize the selected clock source
    bool initializeClockSource();
};

#endif // CLOCK_H