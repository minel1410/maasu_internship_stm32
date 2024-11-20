GPIO for STM32F411 MCU
================================

Introduction
------------

General-Purpose Input/Output (GPIO) pins are critical in microcontroller applications for interacting with peripherals and external devices. GPIO pins in STM32F411 can be configured for various functions: input, output, alternate function, and analog.
GPIO pins in STM32F411 are versatile interfaces that can function as digital inputs or outputs and support alternate functions and analog configurations. Correctly configuring these pins is critical for interfacing with other hardware components or systems.

Configurations
--------------

**Pin Modes:**

- **Input Mode:** Used to read digital signals from external devices like buttons or sensors.
- **Output Mode:** Drives GPIO pins high (3.3V) or low (0V) to control actuators such as LEDs or motors.
- **Alternate Function Mode:** Connects GPIO pins to on-chip peripherals like UART, SPI, or I2C.
- **Analog Mode:** Disables digital logic and is used for ADCs or DACs.

**Output Type:**

- **Push-Pull:** The default mode for output, where the pin actively drives both high and low signals.
- **Open-Drain:** Suitable for wired-AND connections, requiring an external pull-up resistor.

**Speed:**

- Configurable speeds (Low, Medium, High, Very High) define the slew rate of output signals, affecting how fast the pin can switch.

**Pull-Up/Pull-Down Resistors:**

- Built-in resistors used to stabilize the pin state when configured as input, preventing floating signals.

Registers for GPIO Control
--------------------------

RCC_AHB1ENR Register
The RCC_AHB1ENR register controls the clock enabling for peripherals connected to the AHB1 bus, including GPIO ports. By enabling the clock for a specific GPIO port, you activate its functionality and gain access to its pins.
- Size: 32 bits, with each bit corresponding to a clock enable for a particular peripheral.
- Usage: To use a specific GPIO port, set the corresponding bit to 1 in the RCC_AHB1ENR register, enabling its clock and functionality.

GPIOx_MODER (Mode Register)
The GPIOx_MODER register configures the mode of each pin in the port. It consists of 32 bits, with two bits allocated for each pin.
- Bit Configuration:
  - 00: Input mode
  - 01: Output mode
  - 10: Alternate function mode (used for connecting with peripherals like USART, SPI, etc.)
  - 11: Analog mode (used for ADC, DAC, or to save power)
This register allows precise control over the behavior of each GPIO pin, depending on the required functionality.

GPIOx_OTYPER (Output Type Register)
The GPIOx_OTYPER register sets the output type for each pin in the port. It is a 32-bit register, where each pin is assigned one bit.
- Bit Configuration:
  - 0: Push-pull output – used for standard output applications.
  - 1: Open-drain output – used when the output can be connected to multiple devices or for buses like I2C.
This register is essential for configuring how each pin drives signals, especially in applications requiring shared connections or specific output characteristics.

GPIOx_OSPEEDR (Output Speed Register)
The GPIOx_OSPEEDR register configures the signal speed for each pin. It is a 32-bit register, where each pin is represented by two bits.
- Bit Configuration:
  - 00: Low speed
  - 01: Medium speed
  - 10: High speed
  - 11: Very high speed
This register allows you to adjust the speed of signal transitions based on the requirements of your application, ensuring optimal performance and minimal power consumption when needed.

GPIOx_PUPDR (Pull-up/Pull-down Register)
The GPIOx_PUPDR register configures the internal pull-up or pull-down resistors on each pin. It is a 32-bit register, with each pin having two bits assigned.
- Bit Configuration:
  - 00: No pull-up or pull-down resistor
  - 01: Activates the pull-up resistor
  - 10: Activates the pull-down resistor
This register is used to manage the default logic state of GPIO pins to prevent floating states when the pin is configured as input.

GPIOx_ODR (Output Data Register)
The GPIOx_ODR register is used to set the output values (0 or 1) on GPIO pins configured as outputs. It is a 32-bit register, where each pin is assigned one bit. Writing 1 to a bit drives the corresponding pin high (logic level 1), and writing 0 drives it low (logic level 0).
 When you write to the ODR register, the microcontroller outputs the specified logic level on the corresponding pin. This register is commonly used for tasks like turning LEDs on or off, controlling digital signals for peripherals, and managing pin states in embedded applications. Direct control through the ODR is straightforward but should be handled carefully in real-time applications to ensure data consistency.

GPIOx_BSRR (Bit Set/Reset Register)
The GPIOx_BSRR register is used to set or reset specific pins on a GPIO port atomically, without affecting the rest of the pins or needing to modify the entire ODR value. This register provides efficient and race-condition-free pin control.
- Size: 32 bits. The first 16 bits (BSy) are used to set pins, and the next 16 bits (BRy) are used to reset pins.
- Functionality:
  - BSy (Bit Set y): Writing 1 to this bit sets pin y to a high value (logic level 1).
  - BRy (Bit Reset y): Writing 1 to this bit resets pin y to a low value (logic level 0).
- Set Operation: Writing 1 to any bit in the lower 16 bits of BSRR sets the corresponding pin high. For example, writing 0x00000004 sets pin 2 high.
- Reset Operation: Writing 1 to any bit in the upper 16 bits resets the corresponding pin. For example, writing 0x00040000 resets pin 2.
This atomic operation ensures consistent and safe updates in concurrent or real-time systems, making BSRR ideal for applications where precise timing and pin control are required.

Differences Between ODR and BSRR
- ODR: Directly sets or clears all pin states. It is simpler but not atomic, which may cause issues in multi-threaded environments.
- BSRR: Designed for atomic operations. It’s more efficient in scenarios where pin state changes must be executed without interruption.
Practical Applications Using Registers
--------------------------------------

1. **Controlling an LED Using ODR**
2. **Using BSRR for Safe Pin Control**

Advanced GPIO Features
----------------------

1. **Alternate Function Configuration**
2. **Speed and Drive Strength**