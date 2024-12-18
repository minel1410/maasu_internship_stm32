#include "gpio.h"

namespace GPIO {

    void enableClock(GPIO_TypeDef* port) {
        if (port == GPIOA)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
        else if(port == GPIOB)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; 
        else if(port == GPIOC)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
        else if(port == GPIOD)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; 
        else if(port == GPIOE)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; 
        else if(port == GPIOH)
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN; 
    }

    void configureMode (GPIO_TypeDef* port, Pin pin, Mode mode){ 
        uint8_t pinNumber = static_cast<uint8_t>(pin);
        port->MODER &= ~(0x03 << (pinNumber * 2));
        port->MODER |= static_cast<uint32_t>(mode) << (pinNumber * 2);
    }

    void configurePull(GPIO_TypeDef* port, Pin pin, GPIO::Pull pull) {
        uint8_t pinNumber = static_cast<uint8_t>(pin);
        port->PUPDR &= ~(0x03 << (pinNumber * 2)); // Clear the bits
        port->PUPDR |= static_cast<uint32_t>(pull) << (pinNumber * 2); // Set the pull configuration
    }

    void configureOutputType(GPIO_TypeDef* port, Pin pin, GPIO::OutputType type) {
        uint8_t pinNumber = static_cast<uint8_t>(pin);
        port->OTYPER &= ~(1 << pinNumber); // Clear the bit
        port->OTYPER |= static_cast<uint32_t>(type) << pinNumber; // Set the output type
    }

    void configureSpeed(GPIO_TypeDef* port, Pin pin, GPIO::Speed speed) {
        uint8_t pinNumber = static_cast<uint8_t>(pin);
        port->OSPEEDR &= ~(0x03 << (pinNumber * 2)); // Clear the bits
        port->OSPEEDR |= static_cast<uint32_t>(speed) << (pinNumber * 2); // Set the speed
    }

    void configureAlternateFunction(GPIO_TypeDef* port, Pin pin, GPIO::AlternateFunction alternate) {
        uint8_t pinNumber = static_cast<uint8_t>(pin);
        uint8_t alternateNumber = static_cast<uint8_t>(alternate);
        if (pinNumber < 8) {
            // Use AFR[0] for pins 0-7
            port->AFR[0] &= ~(0xF << (pinNumber * 4)); // Clear the bits
            port->AFR[0] |= (alternateNumber << (pinNumber * 4)); // Set the alternate function
        } else {
            // Use AFR[1] for pins 8-15
            uint32_t pinIndex = pinNumber - 8;  // Adjust pinNumber for pins 8-15
            port->AFR[1] &= ~(0xF << (pinIndex * 4)); // Clear the bits
            port->AFR[1] |= (alternateNumber << (pinIndex * 4)); // Set the alternate function
        }
    }

    void configurePin_Input(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull){
        configureMode(port, pin, mode);
        configurePull(port, pin ,pull);
    }

    void configurePin_Output(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type){
        configureMode(port, pin, mode);
        configurePull(port, pin ,pull);
        configureOutputType(port, pin, type);
        configureSpeed(port, pin, speed);
    }

    void configurePin_Alternate(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type, AlternateFunction alternate){
        configureMode(port, pin, mode);
        configurePull(port, pin ,pull);
        configureOutputType(port, pin, type);
        configureSpeed(port, pin, speed);
        configureAlternateFunction(port, pin, alternate);
    } 

    void configurePin(GPIO_TypeDef* port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type, AlternateFunction alternate) {
        if (mode == Mode::Input) {
            configurePin_Input(port, pin, mode, pull);
            return;
        }

        if (mode == Mode::Output) {
            configurePin_Output(port, pin, mode, pull, speed, type);
            return; 
        }
        
        if (mode == Mode::Alternate) {
            configurePin_Alternate(port, pin, mode, pull, speed, type, alternate);
            return; 
        }

    } // end configurePin

    // Set a GPIO pin using the BSRR register
    void setPin(GPIO_TypeDef* port, Pin pin) {
        port->BSRR = (1 << static_cast<uint8_t>(pin)); // Set the corresponding bit BS
        // If BS and BR are set, BS has priority
    }

    // Reset a GPIO pin using the BSRR register
    void resetPin(GPIO_TypeDef* port, Pin pin) {
        port->BSRR = (1 << (static_cast<uint8_t>(pin) + 16)); // Reset the corresponding bit BR
    }

    bool readPin(GPIO_TypeDef* port, Pin pin) {
        uint8_t pinNumber = static_cast<uint8_t>(pin);

        // Read the IDR register 
        return (port->IDR & (1 << pinNumber));
    }
    
} // namespace GPIO
