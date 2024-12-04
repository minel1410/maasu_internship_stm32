.. _GPIO:

====
GPIO
====

General-Purpose I/O (GPIO) Port Registers
=========================================

Each General-Purpose Input/Output (GPIO) port in the STM32 microcontrollers has several registers that are used for configuring and controlling the pins. These registers allow the user to set pin modes, configure output types and speeds, enable pull-up/pull-down resistors, read input values, and control pin states. Here's a breakdown of the key registers for a GPIO port:

Configuration Registers
=======================

GPIOx_MODER (Mode Register)
---------------------------

This register is used to configure the mode of each GPIO pin. The mode can be:

- **00**: Input mode
- **01**: Output mode
- **10**: Alternate function mode
- **11**: Analog mode

GPIOx_OTYPER (Output Type Register)
-----------------------------------

This register controls the output type for each pin. It can be:

- **0**: Push-pull output
- **1**: Open-drain output

GPIOx_OSPEEDR (Output Speed Register)
-------------------------------------

This register configures the output speed for each pin. The options include:

- **00**: Low speed
- **01**: Medium speed
- **10**: High speed
- **11**: Very high speed

GPIOx_PUPDR (Pull-up/Pull-down Register)
----------------------------------------

This register configures the internal pull-up or pull-down resistors for each pin:

- **00**: No pull-up, no pull-down
- **01**: Pull-up
- **10**: Pull-down
- **11**: Reserved

Data Registers
==============

GPIOx_IDR (Input Data Register)
-------------------------------

This register contains the value of the input pins. Each bit corresponds to the input state of a specific GPIO pin:

- **0**: Pin is low
- **1**: Pin is high

GPIOx_ODR (Output Data Register)
--------------------------------

This register holds the output values for the GPIO pins. Each bit corresponds to the output state of a specific pin:

- **0**: Pin is low
- **1**: Pin is high

Set/Reset Register
==================

GPIOx_BSRR (Bit Set/Reset Register)
-----------------------------------

This register allows setting or resetting individual GPIO pins. The first 16 bits are used to set the corresponding pin, and the last 16 bits are used to reset the corresponding pin:

- Writing a **1** to a bit in the first 16 bits sets the corresponding pin.
- Writing a **1** to a bit in the last 16 bits resets the corresponding pin.

Lock Register
=============

GPIOx_LCKR (Lock Register)
--------------------------

This register is used to lock the configuration of GPIO pins. Once a pin is locked, its configuration cannot be changed except through a reset. The lock sequence is:

1. Write **1** to the **LCKK** bit (bit 16).
2. Write the desired pin configuration to the **LCK[15:0]** bits.
3. Write **1** to the **LCKK** bit again.
4. The **LCK** bit for a pin is locked when it becomes **1** after the second write to **LCKK**.

Alternate Function Selection Registers
======================================

GPIOx_AFRL (Alternate Function Low Register)
--------------------------------------------

This register is used for selecting alternate functions for pins 0 to 7. Each pair of bits (**AF[1:0]**) determines the alternate function for each pin:

- Example: If pin 0 is configured for an alternate function, its corresponding bits in **AFRL** define which alternate function is used.

GPIOx_AFRH (Alternate Function High Register)
---------------------------------------------
This register is used for selecting alternate functions for pins 8 to 15. Each pair of bits (**AF[1:0]**) corresponds to the alternate function selection for these pins.