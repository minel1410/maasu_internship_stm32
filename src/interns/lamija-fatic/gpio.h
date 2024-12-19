#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>
#include "stm32f4xx.h"

/**
 * @enum GpioMode
 * @brief GPIO modes for pin configuration.
 */
enum class GpioMode : uint32_t
{
    GPIO_Mode_IN = 0x00,  /**< Input mode */
    GPIO_Mode_OUT = 0x01, /**< Output mode */
    GPIO_Mode_AF = 0x02,  /**< Alternate function mode */
    GPIO_Mode_AN = 0x03   /**< Analog mode */
};

/**
 * @enum GpioOutputType
 * @brief GPIO output types.
 */
enum class GpioOutputType : uint32_t
{
    GPIO_OT_PP = 0x00, /**< Push-pull output */
    GPIO_OT_OD = 0x01  /**< Open-drain output */
};

/**
 * @enum GpioSpeed
 * @brief GPIO output speeds.
 */
enum class GpioSpeed : uint32_t
{
    GPIO_Speed_2MHz = 0x00,  /**< Low speed (2 MHz) */
    GPIO_Speed_25MHz = 0x01, /**< Medium speed (25 MHz) */
    GPIO_Speed_50MHz = 0x02, /**< Fast speed (50 MHz) */
    GPIO_Speed_100MHz = 0x03 /**< High speed (100 MHz) */
};

/**
 * @enum GpioPullType
 * @brief GPIO pull types.
 */
enum class GpioPullType : uint32_t
{
    GPIO_PT_NOPULL = 0x00, /**< No pull-up or pull-down */
    GPIO_PT_UP = 0x01,     /**< Pull-up */
    GPIO_PT_DOWN = 0x02,   /**< Pull-down */
    GPIO_PT_RES = 0x03     /**< Reserved */
};

/**
 * @enum GpioAlternateFunction
 * @brief GPIO alternate functions.
 */
enum class GpioAlternateFunction : uint32_t
{
    GPIO_AF0 = 0x0,
    GPIO_AF1 = 0x1,
    GPIO_AF2 = 0x2,
    GPIO_AF3 = 0x3,
    GPIO_AF4 = 0x4,
    GPIO_AF5 = 0x5,
    GPIO_AF6 = 0x6,
    GPIO_AF7 = 0x7,
    GPIO_AF8 = 0x8,
    GPIO_AF9 = 0x9,
    GPIO_AF10 = 0xA,
    GPIO_AF11 = 0xB,
    GPIO_AF12 = 0xC,
    GPIO_AF13 = 0xD,
    GPIO_AF14 = 0xE,
    GPIO_AF15 = 0xF
};

/**
 * @class Gpio
 * @brief Class for configuring and controlling GPIO pins.
 */
class Gpio
{
private:
    GPIO_TypeDef *m_gpio; /**< Pointer to the GPIO port */
    uint32_t m_pin;       /**< Pin number */

public:
    /**
     * @brief Constructor to initialize GPIO with the specified port and pin.
     * @param gpio Pointer to the GPIO port.
     * @param pin Pin number.
     */
    Gpio(GPIO_TypeDef *gpio, const uint32_t &pin);

    /**
     * @brief Set the mode for the GPIO pin.
     * @param mode Desired mode for the pin.
     */
    void set_mode(const GpioMode &mode);

    /**
     * @brief Set the pull type for the GPIO pin.
     * @param pullType Desired pull type for the pin.
     */
    void set_input_pull(const GpioPullType &pullType);

    /**
     * @brief Set the output type for the GPIO pin.
     * @param outputType Desired output type for the pin.
     */
    void set_output_type(const GpioOutputType &outputType);

    /**
     * @brief Set the output speed for the GPIO pin.
     * @param speed Desired speed for the pin.
     */
    void set_output_speed(const GpioSpeed &speed);

    /**
     * @brief Set the alternate function for the GPIO pin.
     * @param altFunc Desired alternate function for the pin.
     */
    void set_alt_func(const GpioAlternateFunction &altFunc);

    /**
     * @brief Write a value to the GPIO pin.
     * @param value Boolean value to be written to the pin (true for high, false for low).
     */
    void write(const bool &value);

    /**
     * @brief Read the current value of the GPIO pin.
     * @return Boolean value representing the pin state (true for high, false for low).
     */
    bool read();
};

#endif