.. _Clock:
=====
Clock
=====

Overview
========

The STM32F411 microcontroller provides a variety of clock sources to support flexibility and optimal configuration for different application requirements. External oscillators (HSE and LSE) are known for their precision and stability, making them ideal for applications demanding high timing accuracy, such as precise timekeeping or synchronized data transmission. Conversely, internal oscillators (HSI and LSI) offer the advantage of quick startup and independence from external components, which is beneficial for applications that prioritize lower power consumption and do not require high precision. This range of clock options enables customization of designs to balance performance, energy efficiency, and system complexity according to the needs of the project.

High-Speed Clock Sources
========================

HSI (High-Speed Internal Oscillator)
------------------------------------

- **Frequency**: 16 MHz
- **Accuracy**: As an RC-based oscillator, the HSI is less precise than external oscillators (e.g., HSE)
- **Startup Time**: Quick startup, making it ideal for scenarios where fast clock initialization is important
- **Power Consumption**: Generally lower than external oscillators, contributing to energy-efficient designs
- **Usage**:
  - Commonly used as an initial or fallback clock source
  - Does not rely on external components, which enhances system reliability
  - Suitable for applications where high precision is not critical, such as basic timing functions or power-sensitive tasks
- **Configuration Flexibility**: Can be switched to or from other clock sources to adapt to changing application needs

HSE (High-Speed External Oscillator)
------------------------------------

- **Frequency**: Typically operates between 8 MHz and 25 MHz (STM32F411 "Black Pill" uses 25 MHz crystal)
- **Accuracy**: The HSE is more accurate than internal oscillators, such as the HSI, due to its use of an external crystal
- **Applications**: 
  - Ideal for applications requiring precise frequency control
  - Often used with a PLL to generate higher frequencies, ensuring stable performance for tasks like communication and motor control

Low-Speed Clock Sources
=======================

LSI (Low-Speed Internal Oscillator)
------------------------------------

- **Frequency**: 32 kHz
- **Accuracy**: Less accurate and stable than external oscillators due to its RC-based design
- **Applications**:
  - Primarily used as a backup clock source for real-time clocks (RTC) and watchdog timers
  - Well-suited for power-efficient applications where high precision is not a priority

LSE (Low-Speed External Oscillator)
------------------------------------

- **Frequency**: 32.768 kHz, commonly used in real-time clock (RTC) applications
- **Accuracy**: Provides high precision and excellent long-term stability due to the use of an external crystal
- **Startup Time**: Slower compared to internal oscillators but offers reliable and stable performance over time
- **Power Consumption**: Designed for low power usage, making it ideal for battery-operated and energy-efficient systems
- **Usage**:
  - Essential for RTC applications where maintaining accurate and stable timekeeping is crucial
  - Commonly used in clocks, calendars, and systems requiring precise time synchronization
- **Reliability**: Ensures consistent and accurate time management in embedded systems dependent on long-term timing accuracy
- **Integration**: Can be used alongside other clock sources for redundancy or enhanced features like timestamping and wake-up functionality in low-power modes

RCC (Reset and Clock Control) Register
======================================

The RCC Clock Control Register (RCC_CR) is a key register in the STM32F411 microcontroller that manages and controls the behavior of various clock sources. It enables or disables internal and external oscillators and PLLs, monitors their status, and handles security functions.

RCC_CR Features:
----------------

- **Enabling/Disabling Clock Sources**: Controls the activation of internal oscillators (HSI), external oscillators (HSE), and phase-locked loops (PLL, PLLI2S)
- **Clock Status Monitoring**: Provides flags to check the readiness (e.g., HSIRDY, HSERDY, PLLRDY) of various clock sources
- **Clock Configuration**: Allows selection and adjustment of clock characteristics, such as enabling bypass modes or fine-tuning internal oscillators
- **Clock Security System (CSS)**: Manages the clock security feature to protect against failures in the external clock source (HSE)
- **Power Modes Support**: Adjusts clock settings during transitions to power-saving modes, such as Stop or Standby, to reduce power consumption

 RCC_CR Bit Names and Descriptions
----------------------------------
- **PLLI2SRDY**: Indicates if the PLLI2S clock is locked (set by hardware)
- **PLLI2SON**: Enables/disables the PLLI2S (set/cleared by software)
- **PLLRDY**: Indicates if the main PLL clock is locked (set by hardware)
- **PLLON**: Enables/disables the main PLL (set/cleared by software)
- **CSSON**: Enables the clock security system (set/cleared by software)
- **HSEBYP**: Bypasses the HSE oscillator with an external clock (set/cleared by software)
- **HSICAL[7:0]**: Internal high-speed clock calibration value (automatically initialized at startup)
- **HSITRIM[4:0]**: Programmable trimming for the internal high-speed clock
- **HSIRDY**: Indicates if the HSI clock is stable and ready (set by hardware)
- **HSION**: Enables/disables the HSI oscillator (set/cleared by software)

RCC_PLLCFGR (PLL Configuration Register)
=========================================

PLLM (Bits 5:0)
---------------
- **Description**: Division factor for the main PLL input clock
- **Range**: 2 ≤ PLLM ≤ 63

PLLN (Bits 14:6)
----------------
- **Description**: Multiplication factor for the main PLL (VCO output frequency)
- **Range**: 50 ≤ PLLN ≤ 432

PLLP (Bits 17:16)
-----------------
- **Description**: Division factor for the main PLL output clock (system clock)
- **Possible Values**: 
  - 00: PLLP = 2
  - 01: PLLP = 4
  - 10: PLLP = 6
  - 11: PLLP = 8

RCC Clock Configuration Register (RCC_CFGR)
===========================================

SW (System Clock Switch)
------------------------
- **Purpose**: Selects the system clock source.
- **Values**:
  - 00: HSI oscillator selected
  - 01: HSE oscillator selected
  - 10: PLL selected
  - 11: Not allowed

SWS (System Clock Switch Status)
--------------------------------
- **Purpose**: Indicates which clock source is currently used.
- **Values**:
  - 00: HSI oscillator used
  - 01: HSE oscillator used
  - 10: PLL used

HPRE (AHB Prescaler)
--------------------
- **Purpose**: Controls the division factor for the AHB clock.
- **Possible Values**: Divided by 2, 4, 8, etc.

PPRE1 (APB Low-Speed Prescaler)
-------------------------------
- **Purpose**: Controls the APB low-speed clock division factor.
- **Values**: Divided by 2, 4, 8, 16.

PPRE2 (APB High-Speed Prescaler)
--------------------------------
- **Purpose**: Controls the APB high-speed clock division factor.
- **Values**: Divided by 2, 4, 8, 16.

SystemCoreClockUpdate()
=======================

The `SystemCoreClockUpdate()` function is part of the CMSIS library, which is used for hardware abstraction in STM32 microcontrollers. It is implemented in the `system_stm32f4xx.c` file.

- **Purpose**: Updates the `SystemCoreClock` variable to reflect the current system clock frequency
- **How it Works**: The function calculates the current frequency based on the settings in the RCC registers.
- **Why It Is Used**: Ensures that the software always has the correct system clock frequency, which is essential for accurate timing, peripheral configuration, and proper system behavior.

Steps to Configure Clock for 100 MHz Output from 25 MHz Input
============================================================

To achieve a frequency of 100 MHz using the HSE with an input frequency of 8 MHz, we use the following PLL parameter settings in the `RCC_PLLCFGR` register:

- **PLLM = 25**: Reduces the input clock from 25 MHz to 1 MHz (25 MHz / 25 = 1 MHz).
- **PLLN = 200**: Multiplies the result to reach 200 MHz (1 MHz * 200 = 200 MHz).
- **PLLP = 2**: Divides 200 MHz by 2 to achieve 100 MHz (200 MHz / 2 = 100 MHz).

Summary
-------
The use of these settings is primarily to configure the System Clock (SYSCLK) of a microcontroller, such as those in the STM32 series, to run at a higher frequency suitable for the desired performance.

Here's how these PLL settings are used:

1. **Achieving Higher Clock Speeds**: The internal system clock needs to run at higher frequencies to improve the performance and processing speed of the microcontroller. By configuring the PLL (Phase-Locked Loop) settings in the `RCC_PLLCFGR` register, you can scale up the input frequency to a much higher system clock frequency.
2. **Optimizing Performance**: A system clock of 100 MHz provides a good balance between performance and power consumption, making the microcontroller capable of handling more complex tasks and real-time operations efficiently.
3. **Clock Source for Peripherals**: The system clock is also used as the main clock source for various peripherals (e.g., timers, ADCs, communication interfaces). Configuring the clock at 100 MHz ensures that peripherals can operate at higher speeds, enabling faster data processing and response times.
4. **Maintaining Stability**: Properly setting the PLL parameters ensures that the clock configuration remains stable and avoids jitter or instability, which is essential for applications that require precise timing (e.g., signal processing, communication protocols, and control systems).

Conclusion
----------
Using these PLL configurations allows the microcontroller to reach a system clock frequency of 100 MHz, enhancing overall performance and enabling the microcontroller to handle demanding applications with improved efficiency.