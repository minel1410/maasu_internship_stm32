STM32 Clock Initialization 
==========================
STM32F411 provides various clock sources to ensure flexibility and optimal configuration according to application needs. The precision and stability of external sources (HSE and LSE) make them ideal for applications where timing accuracy is critical, while internal oscillators (HSI and LSI) offer fast startup and reduced dependency on external components, making them suitable for applications with lower requirements for precision and energy consumption.

STM32F411 provides various clock sources to ensure flexibility and optimal configuration according to application needs. The precision and stability of external sources (HSE and LSE) make them ideal for applications where timing accuracy is critical, while internal oscillators (HSI and LSI) offer fast startup and reduced dependency on external components, making them suitable for applications with lower requirements for precision and energy consumption.

High-Speed Clock Sources
-------------------------

**HSI (High-Speed Internal):**

- **Description:** HSI is a high-frequency internal oscillator.
- **Frequency:** 16 MHz.
- **Accuracy:** As an RC oscillator, HSI is less precise compared to external oscillators like HSE. Nevertheless, its accuracy is sufficient for many applications.
- **Usage:** HSI is often used as a startup or backup clock source because it doesn’t rely on external components and has a faster startup time. It is suitable for applications where clock precision is not critical.

**HSE (High-Speed External):**

- **Description:** HSE is a high-frequency external oscillator, typically an externally connected crystal or oscillator.
- **Frequency:** Usually between 8 and 25 MHz (25 MHz for STM32F411 Black Pill).
- **Accuracy:** Highly accurate compared to internal oscillators like HSI, providing a stable and precise frequency using an external crystal.
- **Usage:** Ideal for applications where frequency accuracy is crucial. HSE is often used with the PLL to generate higher frequencies.

Low-Speed Clock Sources
------------------------

**LSI (Low-Speed Internal):**

- **Description:** LSI is a low-frequency internal oscillator.
- **Frequency:** Approximately 32 kHz.
- **Accuracy:** As an RC oscillator, LSI has lower accuracy and stability compared to external oscillators.
- **Usage:** Mainly used as a backup clock source for the real-time clock (RTC) and for the watchdog timer, where high precision is not essential, but low power consumption is important.

**LSE (Low-Speed External):**

- **Description:** LSE is a low-frequency external oscillator, typically a 32.768 kHz crystal oscillator.
- **Frequency:** 32.768 kHz (commonly used for RTC applications).
- **Accuracy:** Very accurate and stable, thanks to the external crystal.
- **Usage:** Used for RTC applications that require long-term stability and precise timekeeping, such as in clocks or time synchronization applications.

RCC Register
------------

The RCC register is a crucial component of STM32 microcontrollers, responsible for configuring and managing the system clock and resetting peripheral devices. The RCC module allows users to:

- **Select Clock Source:** Choose between internal (HSI) and external (HSE) oscillators.
- **Configure PLL:** Generate higher frequencies from the selected clock source.
- **Use Prescalers:** Divide frequencies for various buses (AHB, APB1, APB2).
- **Manage Peripheral Clocks:** Enable or disable clock signals for peripherals to save power.

RCC_CR (Clock Control Register)
-------------------------------

The RCC register is a crucial component of STM32 microcontrollers, responsible for configuring and managing the system clock and resetting peripheral devices. The RCC module allows users to:
- Select Clock Source: Choose between internal (HSI) and external (HSE) oscillators.
- Configure PLL: Generate higher frequencies from the selected clock source.
- Use Prescalers: Divide frequencies for various buses (AHB, APB1, APB2).
- Manage Peripheral Clocks: Enable or disable clock signals for peripherals to save power.

RCC_PLLCFGR (PLL Configuration Register)
----------------------------------------

The RCC register is a crucial component of STM32 microcontrollers, responsible for configuring and managing the system clock and resetting peripheral devices. The RCC module allows users to:
- Select Clock Source: Choose between internal (HSI) and external (HSE) oscillators.
- Configure PLL: Generate higher frequencies from the selected clock source.
- Use Prescalers: Divide frequencies for various buses (AHB, APB1, APB2).
- Manage Peripheral Clocks: Enable or disable clock signals for peripherals to save power.

RCC_CFGR (Clock Configuration Register)
---------------------------------------
Description: The RCC_CFGR register configures the system clock source and sets prescalers for the main buses (AHB, APB1, and APB2).
Key Bits:
- SW: Selects the system clock source (00 for HSI, 01 for HSE, 10 for PLL).
- SWS: Displays the currently active system clock source.
- HPRE: Prescaler for the AHB bus.
- PPRE1: Prescaler for the APB1 bus (maximum 50 MHz).
- PPRE2: Prescaler for the APB2 bus (maximum 100 MHz).

RCC_AHB1ENR, RCC_APB1ENR, RCC_APB2ENR (Peripheral Clock Enable Registers)
--------------------------------------------------------------------------

These registers enable or disable the clock for peripheral devices connected to various buses (AHB1, APB1, and APB2). Setting the appropriate bit activates the functionality of a specific peripheral.

**Structure:**

- **RCC_AHB1ENR:** Used to enable peripherals on the AHB1 bus, such as GPIO ports (A-H), CRC module, DMA controllers, etc.
- **RCC_APB1ENR:** Enables peripheral devices on the APB1 bus (e.g., TIM2, TIM3, USART2, I2C1).
- **RCC_APB2ENR:** Enables peripherals on the APB2 bus (e.g., ADC1, USART1, SPI1).

SystemCoreClockUpdate() Function
--------------------------------

The `SystemCoreClockUpdate()` function is part of the CMSIS (Cortex Microcontroller Software Interface Standard) library used by STM32 devices for hardware abstraction.

**Functionality:**

- Updates the global `SystemCoreClock` variable, representing the current system clock frequency.
- Calculates the system clock frequency based on the settings in the RCC registers.
- Ensures accurate timing information.

Configuration of the PLL
------------------------

The PLL in the STM32F411 microcontroller is used to increase the input clock frequency to a desired higher output frequency, which drives the core, peripherals, and buses efficiently.

**Steps to Configure the PLL for 100 MHz Output:**

1. **Enable the Clock Source:**
   - Ensure the 25 MHz external oscillator (HSE) is operational.

2. **Configure PLL Registers:**
   - **PLLM (Main Prescaler):** Divides the input clock to a suitable lower frequency. For a 25 MHz input, set `PLLM = 25` to get 1 MHz.
   - **PLLN (Multiplier):** Multiplies the 1 MHz signal. To achieve 100 MHz, set `PLLN = 400`.
   - **PLLP (Output Divider):** Divides the multiplied frequency to reach the target clock. Here, set `PLLP = 4` to obtain 100 MHz.

3. **Apply Configuration:**
   - Set these values in the `RCC_PLLCFGR` register.
   - Enable the PLL using the `RCC_CR` register and wait for the PLL to lock by checking the PLL ready flag.

4. **Switch the System Clock:**
   - Once the PLL is stable, set it as the system clock source in the `RCC_CFGR` register.