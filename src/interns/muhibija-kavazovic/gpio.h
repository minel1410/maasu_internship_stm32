#pragma once
#include "stm32f411xe.h"


namespace GPIOConfig {

    enum class Mode { Input, Output, AlternateFunction, Analog };

    enum class Pull { None, PullUp, PullDown };

    enum class Speed { Low, Medium, High, VeryHigh };

    enum class OutputType { PushPull, OpenDrain };

    enum class AlternateFunction : uint8_t {
        AF0 = 0,  // System
        AF1 = 1,  // TIM1, TIM2
        AF2 = 2,  // TIM3..5
        AF3 = 3,  // TIM9..11
        AF4 = 4,  // I2C1..3
        AF5 = 5,  // SPI1, SPI2
        AF6 = 6,  // SPI3
        AF7 = 7,  // USART1..3
        AF8 = 8,  // UART4, UART5, USART6
        AF9 = 9,  // CAN1, CAN2, TIM12..14
        AF10 = 10, // OTG_FS, OTG_HS
        AF11 = 11, // Ethernet
        AF12 = 12, // FSMC, SDIO, OTG_HS
        AF13 = 13, // DCMI
        AF14 = 14, // Reserved
        AF15 = 15  // Eventout
    };

    enum class Pin : uint8_t {
        P0 = 0, P1 = 1, P2 = 2, P3 = 3, P4 = 4, P5 = 5, P6 = 6, P7 = 7,
        P8 = 8, P9 = 9, P10 = 10, P11 = 11, P12 = 12, P13 = 13, P14 = 14, P15 = 15
    };
}

class GPIO {
public:
    GPIO(GPIO_TypeDef* port, GPIOConfig::Pin pin);

    void enableClock();
    void setMode(GPIOConfig::Mode mode);
    void setPull(GPIOConfig::Pull pull);
    void setSpeed(GPIOConfig::Speed speed);
    void configureOutputType(GPIOConfig::OutputType type);
    void configureAlternateFunction(GPIOConfig::AlternateFunction af);

    void write(bool state);
    bool read() const;
    void toggle();

    void reset();
    void lockPins(uint16_t pinMask);

private:
    GPIO_TypeDef* m_port;
    uint8_t m_pin;
};