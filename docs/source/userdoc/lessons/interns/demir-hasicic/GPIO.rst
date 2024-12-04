GPIO
====

General Overview of GPIO
------------------------

General-Purpose Input/Output (GPIO) pins are fundamental interfaces in embedded systems, enabling the microcontroller to interact with external hardware. In the STM32F411 microcontroller, GPIO pins are versatile, capable of operating in input, output, analog, or alternate function modes. These configurations are crucial for tasks such as controlling LEDs, reading sensor data, and enabling communication protocols like UART, SPI, or I2C.

GPIO Registers
--------------

GPIO functionality is governed by a set of registers that define the behavior of each pin. These include:

1. **MODER (Mode Register)**:
   - Determines the mode of each pin (input, output, analog, or alternate function).
   - Each pin is controlled by two bits:
     - ``00``: Input mode.
     - ``01``: Output mode.
     - ``10``: Alternate function mode.
     - ``11``: Analog mode.

2. **PUPDR (Pull-Up/Pull-Down Register)**:
   - Configures internal resistors for each pin.
   - Bit settings:
     - ``00``: No pull-up or pull-down (floating).
     - ``01``: Pull-up.
     - ``10``: Pull-down.

3. **OTYPER (Output Type Register)**:
   - Configures the output type as:
     - **Push-Pull**: Actively drives high and low signals.
     - **Open-Drain**: Requires an external pull-up resistor for the high state.

4. **OSPEEDR (Output Speed Register)**:
   - Sets the output speed (low, medium, fast, or high). The options are:
     - ``00``: Low speed
     - ``01``: Medium speed
     - ``10``: High speed
     - ``11``: Very high speed

5. **AFR (Alternate Function Register)**:
   - The Alternate Function Register (AFR) allows GPIO pins to interface with various on-chip peripherals, such as UART, SPI, I2C, PWM, and timers. Each pin can be multiplexed to serve multiple roles, and the AFR determines which alternate function to activate.
   - The AFR is divided into two registers:
     - **AFRL**: For pins 0 to 7.
     - **AFRH**: For pins 8 to 15.

6. **IDR (Input Data Register)**:
   - The Input Data Register (IDR) provides real-time information about the state of GPIO pins configured as inputs.
   - Each bit in the IDR corresponds to a specific GPIO pin, with ``1`` indicating a high logic level and ``0`` a low logic level.

7. **ODR (Output Data Register)**:
   - The ODR controls the logical state (high or low) of GPIO pins when configured in output mode.
   - Writing ``1`` or ``0`` to a specific bit sets the corresponding pin to high or low.

8. **BSRR (Bit Set/Reset Register)**:
   - The BSRR provides an efficient way to set or reset individual pins without affecting others.
   - Lower 16 bits are for setting pins, and upper 16 bits are for resetting pins.
   - This enables atomic operations, ensuring that simultaneous pin manipulations remain error-free.

Example Configurations
----------------------

**Configuring a GPIO Pin for an LED on PA9**:

- Enable the clock for GPIOA using ``RCC_AHB1ENR``.
- Set the mode to output by configuring ``GPIOA_MODER``.
- Configure the output type as push-pull in ``GPIOA_OTYPER``.
- Set the desired output speed in ``GPIOA_OSPEEDR``.
- Optionally, configure a pull-up resistor in ``GPIOA_PUPDR``.
- Toggle the LED state using ``GPIOA_ODR`` or ``GPIOA_BSRR``.

**Configuring a GPIO Pin for a Button on PA0**:

- Enable the clock for GPIOA using ``RCC_AHB1ENR``.
- Set the pin to input mode by configuring ``GPIOA_MODER``.
- Configure a pull-up or pull-down resistor in ``GPIOA_PUPDR`` to prevent floating states.
- Read the button state using ``GPIOA_IDR``.

Conclusion
----------

GPIO configuration in the STM32F411 microcontroller is essential for interacting with external components and peripherals. The microcontroller's GPIO pins can be configured in different modes to support various functions, including input, output, analog, and alternate functions. Registers like **MODER**, **PUPDR**, **OTYPER**, **OSPEEDR**, **AFR**, **IDR**, **ODR**, and **BSRR** provide control over each pin’s behavior, enabling flexibility and efficiency in design.
