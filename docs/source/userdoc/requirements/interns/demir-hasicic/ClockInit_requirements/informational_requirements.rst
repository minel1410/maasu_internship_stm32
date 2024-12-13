==========================
Informational Requirements
==========================
.. req:: RCCRegister
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

   The RCC (Reset and Clock Control) is responsible for controlling and configuring the clock system of the STM32F411 microcontroller. It manages clock sources, system clock selection, and prescalers for peripheral buses.

.. req:: ControlRegister
   :id: REQ_INT3_1732213194
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CR (Control Register) enables or disables various clock sources, such as HSI, HSE, and PLL, and monitors their readiness.

.. req:: PLLConfigurationRegister
   :id: REQ_INT3_1732213228
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLCFGR (PLL Configuration Register) allows configuration of the PLL by setting multipliers, dividers, and selecting the input clock source. It determines the final PLL output frequency.

.. req:: ClockSources
   :id: REQ_INT3_1732213600
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Possible clock sources for the STM32F411 microcontroller include HSI (High-Speed Internal Oscillator), HSE (High-Speed External Oscillator), and PLL (Phase-Locked Loop).

.. req:: ClockConfigurationRegister
   :id: REQ_INT3_1732213243
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CFGR (Clock Configuration Register) configures the system clock source and sets prescalers for the AHB, APB1, and APB2 buses.

.. req:: HighSpeedInternalOscillator
   :id: REQ_INT3_1732213258
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSI (High-Speed Internal Oscillator) provides a fixed internal clock frequency of 16 MHz and serves as the default clock source upon reset.

.. req:: HighSpeedExternalOscillator
   :id: REQ_INT3_1732213270
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSE (High-Speed External Oscillator) is an external clock source with a typical range of 4 MHz to 26 MHz, offering high precision and stability.

.. req:: PhaseLockedLoop
   :id: REQ_INT3_1732213291
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLL (Phase-Locked Loop) multiplies the frequency of its input clock (HSI or HSE) to generate higher frequencies for the system clock. It is highly configurable through the PLLCFGR register.

.. req:: PLLFormula
   :id: REQ_INT3_1732213487
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   The PLL output frequency is calculated using the formula::

       f_PLL = (f_input / M) * N / P

     - M: PLLM divider (input frequency reduction)
     - N: PLLN multiplier (frequency multiplication)
     - P: PLLP divider (post-scaling to system clock frequency)

.. req:: AdvancedHighPerformanceBus
   :id: REQ_INT3_1732213389
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   The AHB (Advanced High-Performance Bus) connects the core processor to high-speed peripherals and system memory. It runs at the system clock frequency (up to 100 MHz in STM32F411).

.. req:: AdvancedPeripheralBus1
   :id: REQ_INT3_1732213402
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The APB1 (Advanced Peripheral Bus 1) bus operates at half the frequency of the AHB bus and supports low-speed peripherals like TIM2, TIM3, and USART2 (up to 50 MHz).

.. req:: AdvancedPeripheralBus2
   :id: REQ_INT3_1732213415
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The APB2 (Advanced Peripheral Bus 2) bus runs at the same frequency as the AHB bus and supports high-speed peripherals like TIM1, TIM8, and USART1 (up to 100 MHz).

.. req:: HSERDYBit
   :id: REQ_INT3_1732213433
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSERDY bit in the CR register indicates the readiness of the HSE oscillator. It is set when the oscillator is stable and ready for use.

.. req:: SWField
   :id: REQ_INT3_1732213445
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SW field in the CFGR register selects the system clock source, enabling dynamic switching between HSI, HSE, or PLL.

.. req:: SWSField
   :id: REQ_INT3_1732213459
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SWS field in the CFGR register reflects the currently active system clock source.

.. req:: ClockPrescalers
   :id: REQ_INT3_1732213474
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Prescalers (HPRE, PPRE1, and PPRE2) divide the system clock frequency to provide appropriate speeds for the AHB, APB1, and APB2 buses.

.. req:: SystemCoreClockUpdate
   :id: REQ_INT3_1732213505
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SystemCoreClockUpdate() function updates the SystemCoreClock variable by reading RCC register settings and recalculating the current system clock frequency.
