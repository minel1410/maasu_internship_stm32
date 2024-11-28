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
   The **typical operating conditions** of the system are 25°C with a 3.3V supply.


.. req:: label
   :id: REQ_INT3_1732702736
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **RCC Register** (Reset and Clock Control) controls clock sources and allows switching between them. It configures the PLL enableling generation of higher frequencies. The RCC Register is charge of reset control for AHB (Advanced High Performance) and APB (Advanced Peripheral) bus domains. 

.. req:: label
   :id: REQ_INT3_1732702714
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **AHB** (Advanced High-Performance Bus) is a high-speed bus that connects the CPU to peripherals such as memory interfaces, DMA controllers, and interrupt controllers. It operates at the same frequency as the system clock, enabling fast data transfers and supports a single master (the processor) and multiple slaves (peripherals or memory controllers).

.. req:: label
   :id: REQ_INT3_1732743911
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **APB** (Advanced Peripheral Bus) is a low-speed bus designed for peripherals that do not require high bandwidth, such as UART, I2C, SPI, and GPIO. It operates at a divided frequency of the system clock, which is configurable via prescalers. APB1 and APB2 buses are available, where APB1 is clocked at a lower frequency (up to 50 MHz), and APB2 has a maximum frequency of 100 MHz.

.. req:: label
   :id: REQ_INT3_1732802082
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Prescalers are used to divide the input clock frequency, providing appropriate clock speeds for different parts of the microcontroller, such as buses.
   
.. req:: label
   :id: REQ_INT3_1732745166
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **HSE** (High-Speed External) is an external crystal oscillator (up to 25 MHz for STM32F411), providing high precision and stability. It is often used in applications requiring accurate timing.


.. req:: label
   :id: REQ_INT3_1732745250
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **RCC_CR Register** (Clock Control Register) is central to managing and controlling the activation and readiness of various clock sources in the STM32F411xC. This register contains the HSEON, HSERDY and PLL bit.
   
   
.. req:: label
   :id: REQ_INT3_1732799454
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   When the **RCC_CR_HSEON** (High-Speed External Oscillator Enable) bit is set, the hardware begins stabilizing the external clock source. 
   
.. req:: label
   :id: REQ_INT3_1732799588
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CR_HSERDY** (High-Speed External Oscillator Ready) bit indicates whether the HSE clock source has stabilized and is ready to be used. 
   
.. req:: label
   :id: REQ_INT3_1732799696
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CR_PLLON** (PLL Enable) bit enables the PLL, which multiplies and divides the input frequency to generate the desired clock frequency.  
 
.. req:: label
   :id: REQ_INT3_1732745947
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **PLL** (Phase-Locked Loop) enables frequency multiplication to generate higher system clock speeds. It's key bits are PLLM, PLLN, PLLP. 
   
   
.. req:: label
   :id: REQ_INT3_1732799788
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **PLLM** is the division factor for the HSE frequency before multiplication. 
   **PLLN** is the multiplication factor. 
   **PLLP** is the division factor after the PLLN result.

.. req:: label
   :id: REQ_INT3_1732747113
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **RCC_PLLCFGR Register** (PLL Configuration Register) configures the PLL, which generates the main system clock by applying multiplication and division to the input frequency. 
   
.. req:: label
   :id: REQ_INT3_1732799984
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_PLLCFGR_PLLSRC** (PLL Clock Source) bit selects the PLL input source.  
   
.. req:: label
   :id: REQ_INT3_1732799851
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_PLLCFGR_PLLM** (Main PLL Divider) bit sets the division factor for the input clock to generate the PLL input frequency. 
   
.. req:: label
   :id: REQ_INT3_1732799876
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_PLLCFGR_PLLN** (Main PLL Multiplier) bit sets the multiplication factor for the PLL input frequency, generating the VCO frequency. 
   
.. req:: label
   :id: REQ_INT3_1732799894
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_PLLCFGR_PLLP** (Main PLL Output Divider) bit sets the division factor for the VCO output frequency to produce the main system clock.

.. req:: label
   :id: REQ_INT3_1732747483
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **RCC_CFGR Register** (Clock Configuration Register) selects the system clock source and configures prescalers for the AHB, APB1, and APB2 buses.
   
.. req:: label
   :id: REQ_INT3_1732800081
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CFGR_SW** (System Clock Switch) bit selects the system clock source.
   
.. req:: label
   :id: REQ_INT3_1732800098
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CFGR_SWS** (System Clock Switch Status) bit indicates the current system clock source.
   
.. req:: label
   :id: REQ_INT3_1732800389
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CFGR_HPRE** (AHB Prescaler) bit sets the prescaler for the AHB bus clock.
   
.. req:: label
   :id: REQ_INT3_1732800404
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CFGR_PPRE1** (APB1 Low-Speed Prescaler) bit sets the prescaler for the APB1 bus. The APB1 clock can go up to 50 MHz.
   
.. req:: label
   :id: REQ_INT3_1732800424
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **RCC_CFGR_PPRE2** (APB2 High-Speed Prescaler) bit sets the prescaler for the APB2 bus. The APB2 clock can go up to 100 MHz.
   
.. req:: label
   :id: REQ_INT3_1732748298
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The **SystemCoreClockUpdate() Function** updates the SystemCoreClock variable to reflect the current system clock frequency.