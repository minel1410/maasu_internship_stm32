#include "gpio.h"
//#include "stm32f4xx.h"
//#include "stm32f411xe.h"

namespace GPIO {

// Get the GPIO register base from the Port enum
GPIO_TypeDef* getPortBase(Port port) {
    switch (port) {
        case Port::A: return GPIOA;
        case Port::B: return GPIOB;
        case Port::C: return GPIOC;
        case Port::D: return GPIOD;
        case Port::E: return GPIOE;
        case Port::H: return GPIOH;
        default: return 0;
    }
}

void GPIOHandler::enableClock(Port port) {
    switch (port) {
        case Port::A: RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; break;
        case Port::B: RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; break;
        case Port::C: RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; break;
        case Port::D: RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; break;
        case Port::E: RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; break;
        case Port::H: RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN; break;
    }
}

void GPIOHandler::configurePin_Input(GPIO_TypeDef* portBase, uint8_t pinNumber, Pull pull){
    // Configure Pull-Up/Pull-Down
    portBase->PUPDR &= ~(0x03 << (pinNumber * 2));
    portBase->PUPDR |= static_cast<uint32_t>(pull) << (pinNumber * 2);
}

void GPIOHandler::configurePin_Output(GPIO_TypeDef* portBase, uint8_t pinNumber, Pull pull, Speed speed, OutputType type){
    // Configure Pull-Up/Pull-Down
    portBase->PUPDR &= ~(0x03 << (pinNumber * 2));
    portBase->PUPDR |= static_cast<uint32_t>(pull) << (pinNumber * 2);

    // Configure Output Type
    portBase->OTYPER &= ~(1 << pinNumber);
    portBase->OTYPER |= static_cast<uint32_t>(type) << pinNumber;

    // Configure Speed
    portBase->OSPEEDR &= ~(0x03 << (pinNumber * 2));
    portBase->OSPEEDR |= static_cast<uint32_t>(speed) << (pinNumber * 2);
}

void GPIOHandler::configurePin_Alternate(GPIO_TypeDef* portBase, uint8_t pinNumber, Pull pull, Speed speed, OutputType type, AlternateFunction alternate){
    // Configure Pull-Up/Pull-Down
    portBase->PUPDR &= ~(0x03 << (pinNumber * 2));
    portBase->PUPDR |= static_cast<uint32_t>(pull) << (pinNumber * 2);

    // Configure Output Type
    portBase->OTYPER &= ~(1 << pinNumber);
    portBase->OTYPER |= static_cast<uint32_t>(type) << pinNumber;

    // Configure Speed
    portBase->OSPEEDR &= ~(0x03 << (pinNumber * 2));
    portBase->OSPEEDR |= static_cast<uint32_t>(speed) << (pinNumber * 2);

    uint8_t alternateNumber = static_cast<uint8_t>(alternate);

    if (pinNumber < 8) {
        //AF has 4 bits
        // Use AFR[0] for pins 0-7
        portBase->AFR[0] &= ~(0xF << (pinNumber * 4)); 
        portBase->AFR[0] |= (alternateNumber << (pinNumber * 4)); 
    } else {
        // Use AFR[1] for pins 8-15
        uint32_t pinIndex = pinNumber - 8;  // Adjust pinNumber for pins 8-15
        portBase->AFR[1] &= ~(0xF << (pinIndex * 4)); 
        portBase->AFR[1] |= (alternateNumber << (pinIndex * 4)); 
    }
} //end configurePin_Alternate



void GPIOHandler::configurePin(Port port, Pin pin, Mode mode, Pull pull, Speed speed, OutputType type, AlternateFunction alternate) {
    GPIO_TypeDef* portBase = getPortBase(port);
    uint8_t pinNumber = static_cast<uint8_t>(pin);

    // Configure Mode 
    portBase->MODER &= ~(0x03 << (pinNumber * 2));
    portBase->MODER |= static_cast<uint32_t>(mode) << (pinNumber * 2);

    if (mode == Mode::Input) {
        configurePin_Input(portBase, pinNumber, pull);
        return;
    }

    if (mode == Mode::Output) {
        configurePin_Output(portBase, pinNumber, pull, speed, type);
        return; 
    }
    
    if (mode == Mode::Alternate) {
        configurePin_Alternate(portBase, pinNumber, pull, speed, type, alternate);
        return; 
    }

} // end configurePin

// Set a GPIO pin using the BSRR register
void GPIOHandler::setPin(Port port, Pin pin) {
    GPIO_TypeDef* portBase = getPortBase(port);
    portBase->BSRR = (1 << static_cast<uint8_t>(pin)); // Set the corresponding bit BS
    // If BS and BR are set, BS has priority
}

// Reset a GPIO pin using the BSRR register
void GPIOHandler::resetPin(Port port, Pin pin) {
    GPIO_TypeDef* portBase = getPortBase(port);
    portBase->BSRR = (1 << (static_cast<uint8_t>(pin) + 16)); // Reset the corresponding bit BR
}

bool GPIOHandler::readPin(Port port, Pin pin) {
    GPIO_TypeDef* portBase = getPortBase(port);
    uint8_t pinNumber = static_cast<uint8_t>(pin);

    // Read the IDR register 
    return (portBase->IDR & (1 << pinNumber));
}


} // namespace GPIO
