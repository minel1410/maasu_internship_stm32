======================
Clock initialization
======================

Introduction
===============

Clock initialization is essential for configuring STM32 microcontrollers for accurate and efficient operation. It involves selecting appropriate clock sources, configuring voltage scaling, and optimizing performance while minimizing power consumption. Proper clock setup ensures the microcontroller functions effectively for time-sensitive tasks.

Key Terms and Abbreviations
==============================

RCC (Reset and Clock Control)
----------------------------------
- The RCC manages the clock sources and reset functionalities within the microcontroller.

Registers
--------------
- CR (Control Register): Controls clock sources and oscillators.
- APB1ENR: Enables clocks for peripherals connected to the APB1 bus.

Clock Sources
-----------------
- HSI (High-Speed Internal): Internal clock, typically 8 MHz.
- HSE (High-Speed External): External clock source, used for more accuracy.
- LSI (Low-Speed Internal): Internal clock for low-power applications.
- LSE (Low-Speed External): External clock, used for the RTC.

PLL (Phase-Locked Loop)
---------------------------
- Used to multiply the clock frequency for higher performance. Configured via RCC_PLLCFGR register, adjusting multipliers and dividers (PLLM, PLLN, PLLP).

Clock Configuration Process
=============================

PLL Configuration Example
-----------------------------
The PLL multiplies the input clock frequency to generate a higher system clock. The general formula is:
  - CO Clock = PLL Input × (PLLN / PLLM)
- PLL Output = VCO Clock / PLLP

Key Bits in PLL Configuration
------------------------------
- PLLM: Main clock multiplier.
- PLLN: PLL multiplier.
- PLLP: Divider for the output clock.
Importance of Clock Initialization
===================================
Accuracy: Ensures precise timing for time-sensitive applications.
Performance: Optimizes the microcontroller’s processing speed and response time.
Power Efficiency: Proper clock setup can help reduce power consumption, especially in low-power modes.

Steps to configure the frequency of 100MHz from a 25MHz oscillator frequency
==============================================================================
- We need to set up the PLL with specific values for PLLM, PLLN, PLLP.
- We need to divide the HSE oscillator frequency in order to get the frequency to 1MHz so we set PLLM=25MHz.
- Then we set PLLN=200MHz in order to multiply the VCO input. The result is 200MHz.
- Then we need to divide it in order to get 100MHz, so we set PLLP=2MHz.

Conclusion
=============

Clock initialization is a critical step in setting up STM32 microcontrollers for effective operation. By configuring the clock sources, PLL, voltage scaling, and flash memory wait states, the microcontroller can be optimized for both performance and power efficiency. Proper clock setup ensures the microcontroller operates reliably and efficiently across various applications.
