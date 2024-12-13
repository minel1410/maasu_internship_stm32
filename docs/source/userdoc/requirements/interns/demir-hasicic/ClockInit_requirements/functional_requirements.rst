==========================
Functional Requirements
==========================

.. req:: EnableHSEOscillator
   :id: REQ_INT3_1732140048
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSEON bit in the RCC_CR register must be set to enable the HSE oscillator.

.. req:: VerifyHSEStability
   :id: REQ_INT3_1732215721
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSERDY bit in the RCC_CR register must be checked to confirm the stability of the HSE oscillator.

.. req:: ConfigurePLLM
   :id: REQ_INT3_1732216124
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLM field in the RCC_PLLCFGR register must be configured to divide the input clock frequency by 25 to achieve a 1 MHz VCO input frequency.

.. req:: ConfigurePLLN
   :id: REQ_INT3_1732216146
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLN field in the RCC_PLLCFGR register must be configured to multiply the VCO input frequency by 200 to achieve a 200 MHz VCO output frequency.

.. req:: ConfigurePLLP
   :id: REQ_INT3_1732216165
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLP field in the RCC_PLLCFGR register must be configured to divide the VCO output frequency by 2 to achieve a 100 MHz system clock.

.. req:: VerifyPLLStability
   :id: REQ_INT3_1732216188
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLRDY bit in the RCC_CR register must be checked to confirm that the PLL generates a stable clock signal, with an output frequency of 100 MHz.

.. req:: SetSystemClockSource
   :id: REQ_INT3_1732216207
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SW field in the RCC_CFGR register must be set to select the PLL as the system clock source.

.. req:: VerifySystemClockSource
   :id: REQ_INT3_1732216226
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SWS field in the RCC_CFGR register must be checked to confirm that the PLL is the active system clock source.

.. req:: ConfigureAHBPrescaler
   :id: REQ_INT3_1732216248
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HPRE field in the RCC_CFGR register must be set to 0 (no division).

.. req:: VerifyAHBClockFrequency
   :id: REQ_INT3_1732216266
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The AHB clock frequency must be verified to operate at 100 MHz.

.. req:: ConfigureAPB1Prescaler
   :id: REQ_INT3_1732216282
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PPRE1 field in the RCC_CFGR register must be configured to 4, to divide the clock by 2 for the APB1 prescaler.

.. req:: VerifyAPB1Frequency
   :id: REQ_INT3_1732216298
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The APB1 clock frequency must be verified to operate at 50 MHz.

.. req:: ConfigureAPB2Prescaler
   :id: REQ_INT3_1732216322
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PPRE2 field in the RCC_CFGR register must be configured to 0 (no division) for the APB2 prescaler.

.. req:: VerifyAPB2Frequency
   :id: REQ_INT3_1732216337
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The APB2 clock frequency must be confirmed to operate at 100 MHz.

.. req:: ValidateHSEConfiguration
   :id: REQ_INT3_1732216352
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The HSERDY bit in the RCC_CR register must be set, indicating the HSE oscillator is stable.

.. req:: ValidatePLLStability
   :id: REQ_INT3_1732216368
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PLLRDY bit in the RCC_CR register must be set, ensuring that the PLL is stable.

.. req:: ValidateSystemClockSource
   :id: REQ_INT3_1732216383
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SWS field in the RCC_CFGR register must indicate that the PLL is selected as the active system clock source.

.. req:: VerifyClockFrequencies
   :id: REQ_INT3_1732216402
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock frequencies for the AHB, APB1, and APB2 buses must be verified to operate at 100 MHz, 50 MHz, and 100 MHz, respectively.

.. req:: UpdateSystemCoreClock
   :id: REQ_INT3_1732216416
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The SystemCoreClock variable must reflect the system clock frequency of 100 MHz, by reading the RCC register settings and calculating the resulting frequency based on the configured SW, HPRE, PPRE1, and PPRE2 fields.
