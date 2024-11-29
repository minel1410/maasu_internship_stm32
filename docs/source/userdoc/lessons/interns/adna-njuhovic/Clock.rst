====================
Clock Initialization
====================

Overview of Clock Initialization in the STM32F411
-------------------------------------------------

Clock initialization in the STM32F411 is crucial for setting the operational speed of the
microcontroller and ensuring reliable peripheral communication. STM32F411 provides flexible
clock source options and prescalers to adjust the clock frequency as needed for application
requirements. Here are the primary components and steps involved in this process:

1. **Clock Sources:**

   - **High-Speed Sources:**
     - **HSI (High-Speed Internal)**: A 16 MHz RC oscillator, quick to start but less precise.
       Useful in applications where timing accuracy is not critical.
     - **HSE (High-Speed External)**: An external crystal or oscillator, typically between 8 and
       25 MHz (often 25 MHz in STM32F411 applications). HSE is highly stable and accurate, 
       ideal for applications where clock precision is key.

   - **Low-Speed Sources:**
     - **LSI (Low-Speed Internal)**: Runs at approximately 32 kHz and is used for low-power
       applications, such as the watchdog timer.
     - **LSE (Low-Speed External)**: A 32.768 kHz crystal oscillator, suitable for real-time clock
       (RTC) applications where timing accuracy is essential over long periods.

2. **Reset and Clock Control (RCC):**

   - The RCC module enables clock selection, adjustment, and control across the system. It
     manages clock signals for the CPU, buses, and peripherals, making it central to achieving
     optimal performance and power management.

   - Key RCC Registers:
     - **RCC_CR (Clock Control Register)**: Controls the activation of HSI, HSE, and PLL oscillators.
       Contains bits to enable oscillators and check stability flags (e.g., `HSERDY` for HSE stability).
     - **RCC_PLLCFGR (PLL Configuration Register)**: Configures the PLL parameters, allowing
       the user to adjust the input frequency and set multipliers and dividers to achieve target
       frequencies.
     - **RCC_CFGR (Clock Configuration Register)**: Defines the system clock source and prescalers
       for the AHB and APB buses.

3. **Prescalers:**

   - The RCC offers prescalers that divide clock frequencies for different system components, 
     such as the Advanced High-Performance Bus (AHB) and the Advanced Peripheral Buses (APB1 
     and APB2). For example, APB1 operates with a maximum clock of 50 MHz, while APB2 supports 
     up to 100 MHz.

4. **Phase-Locked Loop (PLL):**

   - The PLL is a programmable clock multiplier used to reach higher frequencies by configuring
     the source input, dividers, and multipliers. This is especially useful for generating high 
     frequencies from a lower input clock, necessary for high-speed processing.

Configuring the PLL to Obtain 100 MHz from a 25 MHz Input
---------------------------------------------------------

To achieve a 100 MHz system clock from a 25 MHz external clock source, the following settings should be applied to the PLL parameters in the `RCC_PLLCFGR` register:

1. Enable and Stabilize HSE:
   - Set the `HSEON` bit in the `RCC_CR` register to enable the High-Speed External (HSE) clock.
   - Check the `HSERDY` flag to confirm that the HSE oscillator is stable before proceeding.

2. Configure PLL Parameters:
   - **PLLM (Prescaler):** To meet the recommended input frequency range for the PLL, divide the 25 MHz HSE clock down to approximately 1-2 MHz. Set `PLLM = 12`, 
     which divides 25 MHz by 12 to yield approximately 2.08 MHz input to the PLL.
   - **PLLN (Multiplier):** Set `PLLN = 192` to multiply the 2.08 MHz input by 192, producing a high intermediate frequency of 400 MHz.
   - **PLLP (Post-divider):** Set `PLLP = 4`, which divides the 400 MHz by 4, resulting in the target 100 MHz system clock frequency.

3. Enable the PLL and Set it as the System Clock:
   - Enable the PLL by setting the `PLLON` bit in `RCC_CR` and wait for the `PLLRDY` flag to confirm stability.
   - In `RCC_CFGR`, configure the PLL as the system clock source by setting the `SW` bits to `10`, activating the PLL as the main clock.

Significance of This Configuration
----------------------------------

Configuring the PLL to achieve a 100 MHz clock frequency allows the STM32F411 to operate at
its full performance potential, essential for time-sensitive tasks like high-speed data processing,
advanced motor control, or communication protocols (e.g., USB, CAN). High frequencies enable
faster instruction execution and peripheral handling, supporting applications where timing
precision and processing power are essential.

In summary, STM32F411's clock system enables flexibility to meet different application requirements.
Proper clock initialization, including selecting an optimal clock source and configuring the PLL, is
crucial to balance performance, precision, and power efficiency across various microcontroller
operations.
