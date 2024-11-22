.. _non-functional_requirements:

Non-Functional requirements
===========================
 



.. req:: label
 :id: REQ_INT3_1732147460
 :status: Draft
 :date-released:
 :priority: Low
 :submitted-by: Semin Murtic
 :modified-by:
 :category: Non-Functional
 :safety-asil: 
 :references: 
 :verification-and-validation: 
 The GPIO configuration process should complete in less than 10 milliseconds.

.. req:: label
 :id: REQ_INT3_1732227725
 :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Semin Murtic
     :modified-by:
     :category: Non-Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
    Each GPIO function must use no more than 13KB of available memory to minimize the impact on system resources.

.. req:: label
   :id: REQ_INT3_1732315798
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Error handling should provide specific status codes (e.g., 0x01 for invalid pin, 0x02 for incorrect mode) to facilitate troubleshooting and debugging.


.. req:: label
   :id: REQ_INT3_1732315821
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The configuration functions should be reusable across at least 80% of different projects, with minimal changes required to accommodate different hardware configuration.


.. req:: label
   :id: REQ_INT3_1732315844
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins must function correctly under conditions of up to 10 MHz output speed without failures.

.. req:: label
   :id: REQ_INT3_1732229921
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins must handle up to 3.3V logic levels without failures.


.. req:: label
   :id: REQ_INT3_1732315872
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   All functions should be documented with clear, concise comments, with a goal of reducing time required for developers to understand or modify the code.

.. req:: label
   :id: REQ_INT3_1732315903
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The GPIO configuration code should work on all 16 pins of each available port (GPIOA, GPIOB, etc.) without any need for port-specific adjustments.


.. req:: label
   :id: REQ_INT3_1732315921
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system should be capable of providing feedback within 1 second for invalid GPIO configurations or other errors, allowing for rapid diagnosis.

   
.. req:: label
   :id: REQ_INT3_1732315940
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The GPIO configuration should support up to 4 different peripheral mappings (e.g., UART, SPI, I2C, ADC) per pin to maximize flexibility and usage scenarios.

    
.. req:: label
   :id: REQ_INT3_1732315961
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Alternate functions and modes need to be matched with the peripheral requirements for seamless operation.

.. req:: label
   :id: REQ_INT3_1732315978
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins need to be correctly configured to work with peripherals such as ADC, UART, SPI


