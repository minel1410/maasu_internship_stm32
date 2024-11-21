Informational Requirements for Clock Initialization Function
================================================================
.. req:: label
   :id: REQ_INT3_1732225359
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The informational requirements outline key details about the operating conditions, clock and bus systems, and register configurations of the STM32F411 microcontroller. They include descriptions of system clocks (RCC, HSE, PLL), bus architectures (AHB, APB), and specific registers (RCC_CR, RCC_CFGR, RCC_PLLCFGR) for clock control and configuration.​


1. The **typical operating conditions** of the system are 25°C with a 3.3V supply.


2. **RCC Register (Reset and Clock Control):**
    - Controls clock sources and allows switching between them.
    - Configures the PLL enableling generation of higher frequencies
    - In charge of reset control for AHB (Advanced High Performance) and APB (Advanced Peripheral) bus domains. 

3. **AHB (Advanced High-Performance Bus):**
    - A high-speed bus that connects the CPU to high-performance peripherals such as memory interfaces, DMA controllers, and core system peripherals.
    - Operates at the same frequency as the system clock, enabling fast data transfers.
    - Supports a single master (the processor) and multiple slaves (peripherals or memory controllers).
    - Commonly used for high-bandwidth operations like memory access or peripheral interconnects.

4. **APB (Advanced Peripheral Bus):**
    - A low-speed bus designed for peripherals that do not require high bandwidth, such as UART, I2C, SPI, and GPIO.
    - Operates at a divided frequency of the system clock (configurable via prescalers).
    - Consumes less power than AHB, making it suitable for energy-efficient designs.
    - APB1 and APB2 buses are available, where APB1 is clocked at a lower frequency for low-speed peripherals, and APB2 runs faster for higher-performance peripherals.

5. **HSE (High-Speed External):**
    - An external crystal oscillator (up to 25 MHz for STM32F411), providing high precision and stability. 
    - Often used in applications requiring accurate timing.

6. **RCC_CR Register (Clock Control Register)**

    The RCC_CR register is central to managing and controlling the activation and readiness of various clock sources in the STM32F411xC.
  
  a. **HSEON (High-Speed External Oscillator Enable):**
    - The system must set the HSEON bit to 1 to enable the HSE (High-Speed External) clock source in order to use it.
    - The HSE is typically driven by an external crystal oscillator (commonly 4–26 MHz) or an external clock signal, depending on the hardware design.
    - When the HSEON bit is set, the hardware begins stabilizing the external clock source.

  b. **HSERDY (High-Speed External Oscillator Ready):**
    - This status bit indicates whether the HSE clock source has stabilized and is ready to be used.
    - The system must wait for the HSERDY bit to be set to 1 before using the HSE clock as an input for the system clock or PLL.
    - If the HSERDY bit does not set within the expected stabilization time, the external clock source may be faulty, requiring fallback to another clock source such as the HSI.
  
  c. **PLLON (PLL Enable):**
    - This bit enables the PLL (Phase-Locked Loop), which multiplies and divides the input frequency to generate the desired clock frequency.  
 
7. **PLL (Phase-Locked Loop):**
    - Enables frequency multiplication to generate higher system clock speeds.
    - Parameters include dividers and multipliers to fine-tune the output frequency.


Key bits: 
  a. **PLLM**: Division factor for the HSE frequency before multiplication (2–63). 
  b. **PLLN**: Multiplication factor (50–432). 
  c. **PLLP**: Division factor after the PLLN result (2, 4, 6, or 8).

8. **RCC_PLLCFGR Register (PLL Configuration Register)**

    This register configures the PLL, which generates the main system clock by applying multiplication and division to the input frequency.  
 
  a. **PLLSRC (PLL Clock Source):**  
    - This bit selects the PLL input source:  
      - 0: HSI (16 MHz internal clock)  
      - 1: HSE (external clock or crystal oscillator)  
   
  b. **PLLM (Main PLL Divider):**  
    - This field sets the division factor for the input clock to generate the PLL input frequency.  
    - The input frequency must be between 1 and 2 MHz. For example, if using a 25 MHz HSE, setting PLLM to 25 ensures a 1 MHz input.
   
  c. **PLLN (Main PLL Multiplier):**  
    - This field sets the multiplication factor for the PLL input frequency, generating the VCO frequency.  
    - For example, if the input is 1 MHz and PLLN is 200, the VCO frequency will be 200 MHz.  
   
  d. **PLLP (Main PLL Output Divider):**  
    - This field sets the division factor for the VCO output frequency to produce the main system clock.  
    - Possible values include 2, 4, 6, or 8. For example, with a 200 MHz VCO and PLLP = 2, the system clock will be 100 MHz.  
 
9. **RCC_CFGR Register (Clock Configuration Register)**
    This register selects the system clock source and configures prescalers for the AHB, APB1, and APB2 buses.  
 
  a. **SW (System Clock Switch):**  
    - This field selects the system clock source:  
      - 00: HSI  
      - 01: HSE  
      - 10: PLL  
    - The system must set this field appropriately, depending on the chosen clock source.
   
  b. **SWS (System Clock Switch Status):**  
    - This field indicates the current system clock source, confirming the switch to the desired source.
   
  c. **HPRE (AHB Prescaler):**  
    - This field sets the prescaler for the AHB bus clock. Options include no division (full speed) and divisions by powers of 2, up to 512.  
    - For example, setting HPRE to 0 means no division, and the AHB clock runs at the same frequency as the system clock.
   
  d. **PPRE1 (APB1 Low-Speed Prescaler):**  
    - This field sets the prescaler for the APB1 bus, which supports lower-speed peripherals. It can be configured to divide the clock frequency by 2, 4, 8, or 16.  
   
  e. **PPRE2 (APB2 High-Speed Prescaler):**  
    - Similar to APB1, but for high-speed peripherals, allowing no division or division by 2, 4, 8, or 16.
   
10. **SystemCoreClockUpdate() Function**
  - Updates the SystemCoreClock variable to reflect the current system clock frequency.
  - Reads clock configuration registers (e.g., RCC_CFGR, RCC_PLLCFGR) to recalculate the system clock.
  - Should be called after modifying clock settings like clock source, PLL, or prescalers.
  - Ensures accurate timing for peripherals and delays by keeping the clock value up to date.