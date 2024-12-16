#ifndef GPIO_H
#define GPIO_H

#include "stm32f411xe.h"

namespace GPIO {
    enum class Pin {
        Pin0 = 0,
        Pin1 = 1,
        Pin2 = 2,
        Pin3 = 3,
        Pin4 = 4,
        Pin5 = 5,
        Pin6 = 6,
        Pin7 = 7,
        Pin8 = 8,
        Pin9 = 9,
        Pin10 = 10,
        Pin11 = 11,
        Pin12 = 12,
        Pin13 = 13,
        Pin14 = 14,
        Pin15 = 15
    };

    enum class Mode {
        Input = 0x00,
        Output = 0x01,
        Alternate = 0x02,
        Analog = 0x03
    };

    enum class OutputType {
        PushPull = 0x00,
        OpenDrain = 0x01
    };

    enum class Pull {
        NoPull = 0x00,
        PullUp = 0x01,
        PullDown = 0x02
    };

    enum class Speed {
        Low = 0x00,
        Medium = 0x01,
        High = 0x02,
        VeryHigh = 0x03
    };

    enum class AlternateFunction {
        AF0 = 0x00, 
        AF1 = 0x01,  
        AF2 = 0x02,  
        AF3 = 0x03,  
        AF4 = 0x04,  
        AF5 = 0x05,  
        AF6 = 0x06,  
        AF7 = 0x07,  
        AF8 = 0x08,  
        AF9 = 0x09,  
        AF10 = 0x0A,
        AF11 = 0x0B,    
        AF12 = 0x0C,
        AF13 = 0x0D,
        AF14 = 0x0E,       
        AF15 = 0x0F
    };


//Function declarations:
    void enableClock(GPIO_TypeDef* port);
    void configureMode (GPIO_TypeDef* port, Pin pin, Mode mode);
    void configurePull(GPIO_TypeDef* port, Pin pin, Pull pull);
    void configureOutputType(GPIO_TypeDef* port, Pin pin, OutputType type);
    void configureSpeed(GPIO_TypeDef* port, Pin pin, Speed speed);
    void configureAlternateFunction(GPIO_TypeDef* port, Pin pin, AlternateFunction alternate);
    void configurePin_Input(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull);
    void configurePin_Output(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type);
    void configurePin_Alternate(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type, AlternateFunction alternate);
    void configurePin(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed = Speed::Low, OutputType type = OutputType::PushPull, AlternateFunction alternate = AlternateFunction::AF0);
    void setPin(GPIO_TypeDef* port, Pin pin);
    void resetPin(GPIO_TypeDef* port, Pin pin);
    bool readPin(GPIO_TypeDef* port, Pin pin);
        
} // namespace GPIO

#endif // GPIO_H
