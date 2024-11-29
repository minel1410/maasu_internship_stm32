Non-Functional Requirements for the Timer Module
=================================================

.. req:: label
   :id: REQ_INT3_1732900228
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must enable the timer clock in less than 1 ms.

.. req:: label
   :id: REQ_INT3_1732900256
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function must configure the GPIO pin in less than 2 ms.

.. req:: label
   :id: REQ_INT3_1732900252
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The voltage on the pin should stay within 0 to 3.3V to ensure safe operation.

.. req:: label
   :id: REQ_INT3_1732900249
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The period calculation must be completed with an error margin of less than 1%.

.. req:: label
   :id: REQ_INT3_1732900245
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The prescaler calculation must be completed with an error margin of less than 1%.

.. req:: label
   :id: REQ_INT3_1732900234
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The ARR value calculation must be completed with an error margin of less than 1%.

.. req:: label
   :id: REQ_INT3_1732900354
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCR value must be completed with an error margin of less than 1%.

.. req:: label
   :id: REQ_INT3_1732900399
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   All calculations should be completed in less than 10 ms.

.. req:: label
   :id: REQ_INT3_1732900443
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer must be initiated in less than 1 ms.

.. req:: label
   :id: REQ_INT3_1732900459
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must be able to operate for at least 10 million cycles without failure.

.. req:: label
   :id: REQ_INT3_1732900856
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer module should operate with a maximum resource consumption of 5% CPU utilization during PWM operations.

.. req:: label
   :id: REQ_INT3_1732900896
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer module should use less than 12.8 KB of RAM for the timer configuration.

.. req:: label
   :id: REQ_INT3_1732902339
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer module must support PWM frequencies ranging from 1 Hz to 1,53 MHz.

.. req:: label
   :id: REQ_INT3_1732902372
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer module must provide a 16-bit resolution for PWM signal generation, allowing for precise control over the duty cycle with a minimum step size of 0.0015% (1/65536).

