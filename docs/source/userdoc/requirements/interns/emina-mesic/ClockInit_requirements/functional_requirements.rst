===============================================================
Functional Requirements for the Clock Initialization Function
===============================================================

.. req:: label
   :id: REQ_INT3_1732703613
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must enable the HSE clock source by setting the ``HSEON`` bit in the ``RCC_CR`` register to 1.

.. req:: label
   :id: REQ_INT3_1732703644
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   The function must set the ``PLLSRC`` bit in the ``RCC_PLLCFGR`` register to **1** to select HSE as the PLL input source.

.. req:: label
   :id: REQ_INT3_1732703671
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   The function must set the ``PLLM`` value in the ``RCC_PLLCFGR`` register to **25**.
  
.. req:: label
   :id: REQ_INT3_1732703739
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must set the ``PLLN`` value in the ``RCC_PLLCFGR`` register to **200**.

.. req:: label
   :id: REQ_INT3_1732703759
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must set the ``PLLP`` value in the ``RCC_PLLCFGR`` register to **2**.

.. req:: label
   :id: REQ_INT3_1732703775
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must enable the PLL by setting the ``PLLON`` bit in the ``RCC_CR`` register to **1**.

.. req:: label
   :id: REQ_INT3_1732703807
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must set the system clock to PLL by setting the ``SW`` bits in the ``RCC_CFGR`` register to **10**.
 
.. req:: label
   :id: REQ_INT3_1732703832
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must configure the ``HPRE`` bits in the ``RCC_CFGR`` register to set the AHB prescaler to **1**.

.. req:: label
   :id: REQ_INT3_1732703880
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must configure the ``PPRE1`` bits in the ``RCC_CFGR`` register to set the APB1 prescaler to **2**.

.. req:: label
   :id: REQ_INT3_1732703921
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must configure the ``PPRE2`` bits in the ``RCC_CFGR`` register to set the APB2 prescaler to **1**.


.. req:: label
   :id: REQ_INT3_1732704074
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must implement a timeout mechanism of 1 ms to allow for the stabilization of the HSE and PLL.

.. req:: label
   :id: REQ_INT3_1732703947
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall verify that the ``HSERDY`` bit in the ``RCC_CR`` register is set to **1**.

.. req:: label
   :id: REQ_INT3_1732704107
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   If the ``HSERDY`` bit is not set to ``1`` within the timeout period of 1 ms, the function must trigger an error-handling mechanism.


.. req:: label
   :id: REQ_INT3_1732703968
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall verify that the ``PLLRDY`` bit in the ``RCC_CR`` register is set to **1**.

.. req:: label
   :id: REQ_INT3_1732704127
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   If the ``PLLRDY`` bit is not set within the timeout period of 1 ms, the function must trigger an error-handling mechanism.

.. req:: label
   :id: REQ_INT3_1732703982
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall verify that the ``SWS`` bits in the ``RCC_CFGR`` register are set to **10**.

.. req:: label
   :id: REQ_INT3_1732704000
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall call the *SystemCoreClockUpdate()* function.

.. req:: label
   :id: REQ_INT3_1732704470
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The error-handling mechanism must retry the failed operation up to 3 times.

.. req:: label
   :id: REQ_INT3_1732704139
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   If the error-handling retry attempts fail the 3rd time, the function must return an error code indicating a clock initialization failure.
