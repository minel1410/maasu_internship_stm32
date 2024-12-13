==================================================================
Non-Functional Requirements for the Clock Initialization Function
==================================================================

.. req:: label
   :id: REQ_INT3_1732751078
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must initialize the clock configuration within 2 ms under typical operating conditions.

.. req:: label
   :id: REQ_INT3_1732751108
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The stabilization waiting period for the HSE (HSERDY bit) must not exceed 1 ms.

.. req:: label
   :id: REQ_INT3_1732751118
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The stabilization waiting period for the PLL (PLLRDY bit) must not exceed 1 ms.


.. req:: label
   :id: REQ_INT3_1732751162
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock initialization function must support reconfiguration for clock frequencies between 16 MHz to 100 MHz without requiring code changes, provided valid PLLM, PLLN, and PLLP values are supplied.

.. req:: label
   :id: REQ_INT3_1732751173
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must accommodate additional clock sources (e.g., MSI, HSI), ensuring modularity.

.. req:: label
   :id: REQ_INT3_1732751183
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock frequency deviation after initialization must remain within ±0.01% of the configured 100 MHz value under standard operating conditions.

.. req:: label
   :id: REQ_INT3_1732794621
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Prescalers must be configured to maintain output frequencies of maximum 100 MHz for APB2, to ensure reliable peripheral communication.

.. req:: label
   :id: REQ_INT3_1732751348
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Prescalers must be configured to maintain output frequencies of maximum 50 MHz for APB1, to ensure reliable peripheral communication.

.. req:: label
   :id: REQ_INT3_1732751635
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The on function must use no more than 6 KB of the system's available RAM for temporary variables.

.. req:: label
   :id: REQ_INT3_1732794754
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The on function must use no more than 1 KB of program memory.


.. req:: label
   :id: REQ_INT3_1732752434
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must consume less than 1 ms of the total execution time.


.. req:: label
   :id: REQ_INT3_1732753490
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must maintain consistent behavior across at least 100,000 power cycles without degradation.

.. req:: label
   :id: REQ_INT3_1732753522
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function should be compatible with other STM32 series microcontrollers that share the RCC register structure, requiring the adjustment of register addresses for reuse.
