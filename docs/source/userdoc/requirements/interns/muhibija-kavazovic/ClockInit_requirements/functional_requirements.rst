Functional requirements
-----------------------

.. req:: label
   :id: REQ_INT3_1732197193
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support the High-Speed Internal (HSI) oscillator as a clock source.  

.. req:: label
   :id: REQ_INT3_1732216602
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support the High-Speed External (HSE) oscillator as a clock source.

.. req:: label
   :id: REQ_INT3_1732216676
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow software selection of HSE (25 MHz) as the primary clock source by setting the HSEON bit in the RCC_CR register to 1.  

.. req:: label
   :id: REQ_INT3_1732216846
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall confirm HSE stabilization by waiting for the HSERDY bit in the RCC_CR register to be set to 1.   

.. req:: label
   :id: REQ_INT3_1732216893
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall configure the PLL to use the HSE as its input source by setting the PLLSRC bit in the RCC_PLLCFGR register to 1.

.. req:: label
   :id: REQ_INT3_1732216932
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall divide the HSE input frequency down to 1 MHz by setting the PLLM field in the RCC_PLLCFGR register to 25

.. req:: label
   :id: REQ_INT3_1732217151
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall multiply the 1 MHz intermediate frequency up to 200 MHz by setting the PLLN field in the RCC_PLLCFGR register to 200.

.. req:: label
   :id: REQ_INT3_1732217179
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall divide the 200 MHz PLL output frequency by 2 to achieve a 100 MHz system clock by setting the PLLP field in the RCC_PLLCFGR register to 00

.. req:: label
   :id: REQ_INT3_1732217216
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable the PLL by setting the PLLON bit in the RCC_CR register to 1

.. req:: label
   :id: REQ_INT3_1732217255
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall confirm PLL lock and stabilization by waiting for the PLLRDY bit in the RCC_CR register to be set to 1.


.. req:: label
   :id: REQ_INT3_1732217367
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall set the PLL output as the system clock by configuring the SW field in the RCC_CFGR register.

.. req:: label
   :id: REQ_INT3_1732217399
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall configure the prescalers to ensure that the AHB, APB1, and APB2 buses operate within their maximum allowable frequency limits.

.. req:: label
   :id: REQ_INT3_1732217431
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable clock signals for GPIO, USART, and TIM peripherals by configuring their corresponding registers (RCC_AHB1ENR, RCC_APB1ENR, and RCC_APB2ENR).  

.. req:: label
   :id: REQ_INT3_1732217474
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: IMuhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall detect and handle HSE startup failures by falling back to HSI if the HSE fails to stabilize

.. req:: label
   :id: REQ_INT3_1732217506
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall detect and handle PLL lock failures by falling back to HSI if the PLL fails to stabilize.

