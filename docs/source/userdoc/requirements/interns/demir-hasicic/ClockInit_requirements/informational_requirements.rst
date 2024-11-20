==========================
Informational Requirements
==========================
.. req:: label
   :id: REQ_INT3_1732139624
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

1. **RCC (Reset and Clock Control) Register**
   - The RCC register is responsible for controlling and configuring the clock system of the STM32F411 microcontroller. It manages clock sources, system clock selection, and prescalers for peripheral buses.

2. **CR (Control Register) Subregister**
   - The CR subregister enables or disables various clock sources, such as HSI, HSE, and PLL, and monitors their readiness through specific status bits.

3. **PLLCFGR (PLL Configuration Register) Subregister**
   - The PLLCFGR subregister allows configuration of the PLL by setting multipliers, dividers, and selecting the input clock source. It determines the final PLL output frequency.

4. **CFGR (Clock Configuration Register) Subregister**
   - The CFGR subregister configures the system clock source (HSI, HSE, or PLL) and sets prescalers for the AHB, APB1, and APB2 buses.

5. **HSI (High-Speed Internal Oscillator)**
   - The HSI provides a fixed internal clock frequency of 16 MHz and serves as the default clock source upon reset.

6. **HSE (High-Speed External Oscillator)**
   - The HSE is an external clock source with a typical range of 4 MHz to 26 MHz, offering high precision and stability.

7. **PLL (Phase-Locked Loop)**
   - The PLL multiplies the frequency of its input clock (HSI or HSE) to generate higher frequencies for the system clock. It is highly configurable through the PLLCFGR subregister.

8. **AHB (Advanced High-Performance Bus)**
   - The AHB connects the core processor to high-speed peripherals and system memory. It runs at the system clock frequency (up to 100 MHz in STM32F411).

9. **APB1 (Advanced Peripheral Bus 1)**
   - The APB1 bus operates at half the frequency of the AHB bus and supports low-speed peripherals like TIM2, TIM3, and USART2 (up to 50 MHz).

10. **APB2 (Advanced Peripheral Bus 2)**
    - The APB2 bus runs at the same frequency as the AHB bus and supports high-speed peripherals like TIM1, TIM8, and USART1 (up to 100 MHz).

11. **HSERDY Bit**
    - The HSERDY bit in the CR subregister indicates the readiness of the HSE oscillator. It is set when the oscillator is stable and ready for use.

12. **SW Field**
    - The SW field in the CFGR subregister selects the system clock source, enabling dynamic switching between HSI, HSE, or PLL.

13. **SWS Field**
    - The SWS field in the CFGR subregister reflects the currently active system clock source.

14. **Prescalers**
    - Prescalers (HPRE, PPRE1, and PPRE2) divide the system clock frequency to provide appropriate speeds for the AHB, APB1, and APB2 buses.

15. **PLL General Formula**
    - The PLL output frequency is calculated using the formula::

        f_PLL = (f_input / M) * N / P

      - M: PLLM divider (input frequency reduction)
      - N: PLLN multiplier (frequency multiplication)
      - P: PLLP divider (post-scaling to system clock frequency)

16. **SystemCoreClockUpdate**
    - The SystemCoreClockUpdate() function updates the SystemCoreClock variable by reading RCC register settings and recalculating the current system clock frequency.
