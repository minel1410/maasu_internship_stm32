==========================
MCU (Microcontroller Unit)
==========================

Fundamental Elements
--------------------

The MCU (Microcontroller Unit) is an embedded system that integrates the processor core,
memory, and peripherals onto a single chip. The selected MCU for our project is the STM32F411,
based on the Cortex-M4 architecture.

The Cortex-M4 is a 32-bit microcontroller architecture developed by ARM Holdings. Key features include:

1. **Performance**: ARMv7-M architecture with a 3-stage pipeline (Fetch, Decode, Execute).
2. **DSP Capabilities**: Includes single-cycle multiply-accumulate (MAC) instruction for DSP applications.
3. **Floating Point Unit**: Provides hardware support for floating-point operations.
4. **Memory Protection Unit (MPU)**: Allows memory protection and access control.
5. **Nested Vector Interrupt Controller (NVIC)**: Supports up to 240 interrupts with configurable priority levels.
6. **Debugging and Trace Support**: Features hardware debugging capabilities.
7. **Low Power Consumption**: Designed to be power-efficient.

STM32F411 Overview
-------------------

The STM32F411 microcontrollers are part of the STM32 Dynamic Efficiency™ series, offering a
balance between performance and power efficiency. These devices are packaged in compact
3 x 3 mm sizes, with features like:

- **Arm® 32-bit Cortex®-M4 CPU with FPU**, operating at up to 100 MHz.
- **ART Accelerator** for fast flash memory execution.
- **Memory**: Up to 512 KB of flash memory and 128 KB of SRAM.
- **Power Management**: Low power consumption (100 μA/MHz in run mode, down to 9 μA in deep stop mode).
- **Analog Features**: 12-bit, 2.4 MSPS A/D converter with up to 16 channels.
- **Timers & DMA**: Up to 11 timers (16-bit and 32-bit options) and general-purpose DMA with FIFO support.
- **Debugging & Communication**: Serial Wire Debug (SWD), JTAG, and ETM support, with up to 13 communication interfaces (I2C, USART, SPI, USB 2.0).
- **Other Features**: CRC unit, unique 96-bit ID, RTC with subsecond accuracy, and hardware calendar.

The STM32F411 microcontroller is ECOPACK2 compliant, designed for efficiency in compact embedded systems.

Introduction to GPIO
--------------------

General-Purpose Input/Output (GPIO) pins act as a communication link between the
microcontroller and external components. Each GPIO pin can be set as output (to send data)
or input (to receive data), allowing interaction with devices like sensors, LEDs, motors, etc.

GPIO Registers control pin operations, with each GPIO port having a set of registers. Key registers include:

- **MODER (Mode Register)**: Defines pin mode (input, output, analog, or alternate function).
  - 00: Input mode
  - 01: General-purpose output mode
  - 10: Alternate function mode
  - 11: Analog mode

- **PUPDR (Pull-Up/Pull-Down Register)**: Controls pin input state.
  - 00: Floating
  - 01: Pull-up
  - 10: Pull-down

- **OTYPER (Output Type Register)**: Defines output pin type.
  - Push-Pull: Drives high and low signals.
  - Open-Drain: Only drives low; requires external pull-up for high.

- **OSPEEDR (Output Speed Register)**: Sets pin output speed (low, medium, high).
- **AFR (Alternate Function Register)**: Configures alternate functions (e.g., USART, SPI).
- **IDR (Input Data Register)**: Reads the current state of input pins.
- **ODR (Output Data Register)**: Sets the state of output pins.
- **BSRR (Bit Set/Reset Register)**: Allows atomic setting/resetting of individual pins.

GPIO Modes and Configurations
-----------------------------

- **Input Mode**: Configures the pin to receive external signals.
- **Output Mode**: Configures the pin to send signals, in either push-pull or open-drain mode.
- **Analog Mode**: Sets the pin for analog functions (e.g., ADCs, DACs).
- **Alternate Function Mode**: Enables interfacing with peripherals like USART, SPI, I2C, etc.

Configuring GPIO in Embedded Development
----------------------------------------

Effective GPIO configuration requires understanding modes and registers. For example:
- To set a pin as output, configure the MODER register, set OTYPER for output type, and adjust OSPEEDR.
- For input mode, use the PUPDR register to enable pull-up/pull-down resistors as needed.

GPIO in Practical Applications
------------------------------

- **Digital Control**: Manages LEDs, relays, motors, etc., with input pins for sensor states.
- **Signal Monitoring**: Monitors high/low states (e.g., door sensors) using input pins.
- **Communication**: Supports protocols like UART, SPI, I2C in alternate function mode.
- **PWM (Pulse Width Modulation)**: Generates PWM signals for motor control or LED dimming.
- **Interrupt Handling**: Configures GPIO pins to trigger interrupts on specific events.

Optimizing GPIO Usage
---------------------

For real-time reliability, the BSRR register is preferred for atomic pin operations, ensuring
precise control during interrupts.

Key Takeaways
-------------

GPIOs are essential in embedded systems for efficient hardware control. Mastery of GPIO
configuration enables responsive and reliable system development.
