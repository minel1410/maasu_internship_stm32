Clock Initialization Overview
===============================

The STM32F411 microcontroller provides a versatile and configurable clock system to meet a variety of application needs. Clock initialization involves selecting and configuring the appropriate clock source, adjusting the system clock's frequency, and distributing the clock signals to various peripherals.

Key Concepts of Clock Initialization
-------------------------------------

1. **Clock Sources**:

  - **HSI (High-Speed Internal)**: A 16 MHz internal RC oscillator, fast to start and independent of external components. It is ideal for applications where precision is not critical
  - **HSE (High-Speed External)**: An external crystal oscillator (up to 25 MHz for STM32F411), providing high precision and stability. This is often used in applications requiring accurate timing
  - **LSI (Low-Speed Internal)**: A low-frequency (approximately 32 kHz) internal RC oscillator. Though less accurate, it is suitable for energy-efficient applications such as watchdog timers or real-time clock (RTC) backup
  - **LSE (Low-Speed External)**: A highly precise external crystal oscillator (32.768 kHz), typically used for RTC applications requiring long-term timing stability and synchronization


2. **RCC Register (Reset and Clock Control)**:
  - Controls clock sources and allows switching between them
  - Configures the PLL enableling generation of higher frequencies
  - In charge of reset control for AHB (Advanced High Performance) and APB (Advanced Peripheral) bus domains


3. **PLL (Phase-Locked Loop)**:
  - Enables frequency multiplication to generate higher system clock speeds
  - Parameters include dividers and multipliers to fine-tune the output frequency


Key bits:  

  - **PLLM**: Division factor for the HSE frequency before multiplication (2–63)
  - **PLLN**: Multiplication factor (50–432)
  - **PLLP**: Division factor after the PLLN result (2, 4, 6, or 8)


Configuring the PLL for 100 MHz from 25 MHz Input
--------------------------------------------------

To generate a target system frequency of 100 MHz using the HSE (25 MHz input clock), the PLL configuration involves adjusting the parameters in the RCC_PLLCFGR register. The process ensures efficient use of the microcontroller's capabilities while maintaining system stability.


Steps for Configuration
------------------------

1. **Divide the Input Clock (PLLM)**:
  - PLLM reduces the input clock frequency to match the PLL’s internal frequency range (1-2 MHz is optimal)
  - For a 25 MHz input, set `PLLM = 25`. This gives 25MHz/25 = 1MHz


2. **Multiply to Increase Frequency (PLLN)**:
  - The PLLN parameter multiplies the frequency after PLLM division
  - To reach a higher frequency, set `PLLN = 200`. This gives 1MHz*200=200MHz


3. **Divide for Final Output (PLLP)**:
  - PLLP provides the final division to achieve the desired system clock
  - For 100 MHz, set `PLLP = 2`. This gives 200MHz/2=100MHz


Register Adjustments
---------------------

- **RCC_PLLCFGR Register**:
  - `PLLM = 25`, `PLLN = 200`, and `PLLP = 2`


- **RCC_CFGR Register**:
  - Select PLL as the system clock source (`SW = 10`)