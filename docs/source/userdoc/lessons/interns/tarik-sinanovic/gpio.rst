=======
GPIO
=======

Introduction to GPIO
======================

General Purpose Input/Output (GPIO) pins are integral to microcontrollers like the STM32F411. These pins allow the microcontroller to interface with external devices such as LEDs, sensors, switches, and other peripherals. The STM32F411 has a rich set of GPIO pins that can be configured as inputs or outputs, each with various modes and functionalities, making it a versatile platform for embedded applications.

GPIO Modes and Configuration
=====================================


The STM32F411 GPIO pins are highly configurable. Each pin can be set to different modes such as:

Input Mode:
-----------------
- Analog: The pin is used as an analog input. No digital functionality is provided.
- Floating: The pin is in a high-impedance state with no internal pull-up or pull-down resistors.
- Pull-up/Pull-down: The pin is configured with an internal pull-up or pull-down resistor.
Output Mode:
-------------
- Push-pull: Both high and low states can be driven by the pin. This is the most common configuration for driving LEDs and other output devices.
- Open-drain: The pin can only pull low or remain in a high-impedance state. When set to open-drain, the pin must be externally pulled up if a high state is needed.
Alternate Function Mode:
-------------------------
- This mode is used when the pin needs to perform a specific function such as UART communication, SPI, or I2C.
Analog Mode: 
-------------
- Used for ADC input or DAC output.


Each of these modes can be configured through registers like MODER, PUPDR, and OTYPER.

GPIO Registers Overview
==========================

- MODER (GPIO Mode Register): Configures the mode of each pin.
- OTYPER (GPIO Output Type Register): Sets the output type (push-pull or open-drain).
- PUPDR (GPIO Pull-up/Pull-down Register): Configures pull-up or pull-down resistors for input pins.
- IDR (GPIO Input Data Register): Reads the current value of input pins.
- ODR (GPIO Output Data Register): Controls the output state of GPIO pins.
- BSRR (Bit Set/Reset Register): Used for setting or resetting GPIO pins in a more efficient manner compared to directly modifying the ODR.

Detailed Explanation of ODR (Output Data Register)
=======================================================

The ODR (Output Data Register) is used to control the output state of GPIO pins. It is a 32-bit register, where each bit corresponds to a GPIO pin's output value.
ODR Behavior:
- Writing to the ODR: Writing a 1 to a bit in the ODR sets the corresponding GPIO pin to high (3.3V in most STM32F4 cases), while writing a 0 sets the pin to low (0V).
- Read Operation: Reading from the ODR register gives the current state of all output pins. However, it does not reflect the state of the pin as set by the other GPIO configuration registers (e.g., pull-up/down resistors).
For example, if you want to set GPIO pin 0 to high, you write 1 to bit 0 of the ODR register. Similarly, to set it to low, you write 0.

Detailed Explanation of BSRR (Bit Set/Reset Register)
======================================================
The BSRR (Bit Set/Reset Register) provides an optimized way to set or reset individual GPIO pins. It is composed of two 16-bit halves:
- Bits 0-15: These bits are used to set the corresponding GPIO pins (write a 1 to set the pin high).
- Bits 16-31: These bits are used to reset the corresponding GPIO pins (write a 1 to set the pin low).
BSRR Behavior:
- Setting a Pin: Writing a 1 to the corresponding bit in the lower 16 bits (bits 0-15) will set the GPIO pin to high.
- Resetting a Pin: Writing a 1 to the corresponding bit in the upper 16 bits (bits 16-31) will reset the GPIO pin to low.
This mechanism is more efficient than writing directly to the ODR register, especially when you need to modify only one pin, because writing to the BSRR register can set or reset a pin atomically in a single operation, while the ODR requires two separate operations.

ODR vs. BSRR: Key Differences
==================================

Efficiency:
--------------
  - ODR requires separate operations to set and reset pins.
  - BSRR allows for atomic setting and resetting of pins, making it more efficient for applications requiring frequent pin state changes.
Atomic Operation:
-------------------
  - The BSRR provides a more atomic operation when setting or resetting individual pins because it avoids the need to first read the ODR and then write back to it.
  - The ODR can lead to race conditions or issues in multi-threaded applications where pin states are read-modified-write.
Bit-level Control:
----------------------
  - ODR directly controls the output state of each pin.
  - BSRR has the unique ability to both set and reset pins in a single operation, providing better control over individual GPIO states.
Register Access:
--------------------
  - ODR is a 32-bit register used for directly controlling the output of all pins.
  - BSRR is a 32-bit register split into two halves, where one half sets the pins and the other resets them.

Examples
==========

Configuring GPIO pin for an LED on PA9:
------------------------------------------
-Enable the clock for GPIOA by setting the appropriate bit in the RCC_AHB1ENR register.
-Set PA9 as an output by modifying the GPIOA_MODER register.
-Ensure PA9 is in push-pull mode by clearing the bit in GPIOA_OTYPER.
-Optionally, set the output speed of PA9 to medium.
-Optionally, configure PA9 with no pull-up or pull-down.
-Use ODR or BSRR to set PA9 high or low to control the LED.

Configuring GPIO pin for a button on PA0:
---------------------------------------------

-Enable the clock for GPIOA.
-Set PA0 as an input.
-Enable a pull-up resistor for PA0 (optional).
-Read PA0 to check if the button is pressed.

Conclusion
============

Understanding the GPIO functionality of the STM32F411 is crucial for efficient hardware interfacing. The ODR and BSRR registers offer different methods for controlling GPIO pin states, with BSRR being the more efficient choice for setting or resetting individual pins atomically. By mastering these registers and configuring GPIOs properly, you can create reliable, low-power embedded systems.