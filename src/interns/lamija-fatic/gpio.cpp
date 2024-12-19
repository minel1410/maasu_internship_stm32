#include "gpio.h"

Gpio::Gpio(GPIO_TypeDef *gpio, const uint32_t &pin) : m_gpio (gpio), m_pin (pin)
{
    // Use constructor for enabling clock for GPIOX port
    // Save pointer to GPIO in variable, and save pin value in variable
    // Fill the missing parameters
    // Tip: you can create multiple parameter/s for specific config (ex. input mode, or output mode)

    if (gpio == GPIOA) 
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    else if (gpio == GPIOB) 
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    else if (gpio == GPIOC)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    else if (gpio == GPIOD) 
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    else if (gpio == GPIOE) 
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    else if (gpio == GPIOH)
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    else {
        // handle for an invalid gpio pointer
    }
}


void Gpio::set_mode(const GpioMode &mode)
{
    // MODER -> mode register
    m_gpio->MODER &= ~(0x3UL << m_pin * 2);  // Reset mode register for GPIOX port
    m_gpio->MODER |= (static_cast<uint32_t>(mode) << (m_pin * 2));  // Set mode register to desirable mode
    // Fill the missing parameter/s 
}

void Gpio::set_input_pull(const GpioPullType &pull)
{
    // PUPDR -> pull up/pull down register
    m_gpio->PUPDR &= ~(0x3UL << (m_pin * 2));  // Reset PUPDR
    m_gpio->PUPDR |= (static_cast<uint32_t>(pull) << (m_pin * 2));  // Set PUPDR to desirable mode (pull up, pull down, or floating)
    // Fill the missing parameter/s 
}

void Gpio::set_output_type(const GpioOutputType &type)
{
    // OTYPER -> output type register
    m_gpio->OTYPER &= ~(0x1UL << m_pin);  // Reset OTYPER
    m_gpio->OTYPER |= (static_cast<uint32_t>(type) << m_pin);  // Set OTYPER to desirable type (Push-pull, open-drain)
    // Fill missing parameter/s
}

void Gpio::set_output_speed(const GpioSpeed &speed)
{
    // OSPEEDR -> Output speed register
    m_gpio->OSPEEDR &= ~(0x3UL << (m_pin * 2));   // Reset OSPEEDR
    m_gpio->OSPEEDR |= (static_cast<uint32_t>(speed) << (m_pin * 2));  // Set OSPEEDR to desirable speed (low, medium, fast, high)
    // Fill missing parameter/s
}

void Gpio::set_alt_func(const GpioAlternateFunction &af)
{
    if(m_pin < 8) {
        m_gpio->AFR[0] &= ~(0xFUL << (m_pin * 4));
        m_gpio->AFR[0] |= (static_cast<uint32_t>(af) << (m_pin * 4));
    } else {
        m_gpio->AFR[1] &= ~(0xFUL << ((m_pin - 8) * 4));
        m_gpio->AFR[1] |= (static_cast<uint32_t>(af) << ((m_pin - 8) * 4));

    }
    // Alternate function register is composed of 2 registers: low and high
    // It is defined as array AFR[0] and AFR[1]
    // Configure appropriate Alternate function for peripheral you need
    // alternate function number can be found in reference manual at page 150
    // Fill missing parameter
}

void Gpio::write(const bool &value)
{
    if (value)
        m_gpio->BSRR = (0x1UL << m_pin);        // Set pin
    else
        m_gpio->BSRR = (0x1UL << (m_pin + 16)); // Reset pin

    // we use BSRR instead of ODR because it allows setting and
    // resetting the pins without the need to change the entire
    // register
    // this allows efficacy and minimises the error possibility
    // in a multi-interrupt environemnt
}

bool Gpio::read()
{
    return (m_gpio->IDR & (0x1UL << m_pin)) ? 1 : 0;
    // Use IDR register to read from pin
}
