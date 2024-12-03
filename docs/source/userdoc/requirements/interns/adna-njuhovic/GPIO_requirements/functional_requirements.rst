===============================
Functional Requirements
===============================


.. req:: label
   :id: REQ_INT3_1733150675
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each pin needs to be configured individually to operate in input, output, alternate function, or analog mode.



.. req:: label
   :id: REQ_INT3_1733150719
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   System must ensure the clock enable process is completed before proceeding with any GPIO configuration.



.. req:: label
   :id: REQ_INT3_1733150849
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall provide functionality to enable the clock for a specific GPIO port by setting the corresponding bit in the RCC-›AHB1ENR register.


.. req:: label
   :id: REQ_INT3_1733150895
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow the user to configure each pin as either an input or output.


.. req:: label
   :id: REQ_INT3_1733150940
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   System must support enabling clocks for all available GPIO ports.




.. req:: label
   :id: REQ_INT3_1733150994
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow each GPIO pin to be configured in one of four modes by updating the MODER register.




.. req:: label
   :id: REQ_INT3_1733151043
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the user to read the current state (HIGH or LOW) of any pin, regardless of whether it is configured as an input or output.




.. req:: label
   :id: REQ_INT3_1733151084
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must support the use of internal pull-up and pull-down resistors for input pins to stabilize the input signals.





.. req:: label
   :id: REQ_INT3_1733151135
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall provide functionality to disable GPIO pins, effectively turning them off when not in use to save power.





.. req:: label
   :id: REQ_INT3_1733151195
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the user to configure the output speed (low, medium, high) for each GPIO pin configured as an output.



.. req:: label
   :id: REQ_INT3_1733151264
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins must trigger interrupts based on developer-defined conditions: rising, falling edge.



.. req:: label
   :id: REQ_INT3_1733151320
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins must support configurable output speed via the OSPEEDR register.




