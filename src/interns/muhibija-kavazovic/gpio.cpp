// gpiocpp
#include "gpio.h"
#include <stdexcept>


GPIO::GPIO(GPIO_TypeDef* port, GPIOConfig::Pin pin)
    : m_port(port), m_pin(static_cast<uint8_t>(pin)) {}

void GPIO::enableClock() {
    if (m_port == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (m_port == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (m_port == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (m_port == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (m_port == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (m_port == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
}

void GPIO::setMode(GPIOConfig::Mode mode) {
    m_port->MODER &= ~(3U << (m_pin * 2));
    m_port->MODER |= (static_cast<uint32_t>(mode) << (m_pin * 2));
}

void GPIO::setPull(GPIOConfig::Pull pull) {
    m_port->PUPDR &= ~(3U << (m_pin * 2));
    m_port->PUPDR |= (static_cast<uint32_t>(pull) << (m_pin * 2));
}

void GPIO::setSpeed(GPIOConfig::Speed speed) {
    m_port->OSPEEDR &= ~(3U << (m_pin * 2));
    m_port->OSPEEDR |= (static_cast<uint32_t>(speed) << (m_pin * 2));
}

void GPIO::configureOutputType(GPIOConfig::OutputType type) {
    if (type == GPIOConfig::OutputType::PushPull) {
        m_port->OTYPER &= ~(1U << m_pin);
    } else {
        m_port->OTYPER |= (1U << m_pin);
    }
}

void GPIO::configureAlternateFunction(GPIOConfig::AlternateFunction af) {
    uint8_t afRegister = m_pin / 8;
    uint8_t afPosition = (m_pin % 8) * 4;

    m_port->AFR[afRegister] &= ~(0xF << afPosition);
    m_port->AFR[afRegister] |= (static_cast<uint8_t>(af) << afPosition);
}

void GPIO::write(bool state) {
    if (state) {
        m_port->BSRR = (1U << m_pin);
    } else {
        m_port->BSRR = (1U << (m_pin + 16));
    }
}

bool GPIO::read() const {
    return (m_port->IDR & (1U << m_pin)) != 0;
}

void GPIO::toggle() {
    m_port->ODR ^= (1U << m_pin);
}

void GPIO::reset() {
    m_port->MODER &= ~(3U << (m_pin * 2));
    m_port->PUPDR &= ~(3U << (m_pin * 2));
    m_port->OSPEEDR &= ~(3U << (m_pin * 2));
    m_port->ODR &= ~(1U << m_pin);
    m_port->AFR[m_pin / 8] &= ~(0xF << ((m_pin % 8) * 4));
}

void GPIO::lockPins(uint16_t pinMask) {
    m_port->LCKR = pinMask;
    m_port->LCKR |= GPIO_LCKR_LCKK;
    m_port->LCKR &= ~GPIO_LCKR_LCKK;
    m_port->LCKR |= GPIO_LCKR_LCKK;

    if ((m_port->LCKR & GPIO_LCKR_LCKK) == 0) {
        throw std::runtime_error("Locking failed");
    }
}