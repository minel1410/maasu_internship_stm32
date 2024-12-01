---------------------------
Non-functional requirements
---------------------------

.. req:: label
   :id: REQ_INT3_1732971921
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall ensure that the generated PWM frequency does not deviate by more than ±1% from the user-specified value.

.. req:: label
   :id: REQ_INT3_1732972904
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the duty cycle to be configured with a resolution of 1%, providing precise control over the PWM output signal.

.. req:: label
   :id: REQ_INT3_1732972955
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support PWM signal generation for frequencies ranging from 1 Hz to 50 kHz.

.. req:: label
   :id: REQ_INT3_1732972998
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Timer module shall operate continuously for at least 24 hours without errors or unexpected interruptions.

.. req:: label
   :id: REQ_INT3_1732973122
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Timer module shall maintain accurate and stable operation, including generating correct PWM signals, without errors or interruptions, at ambient temperatures between -40°C and 85°C.

.. req:: label
   :id: REQ_INT3_1732973148
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall reset the Timer module by disabling the counter, clearing the configuration registers (PSC, ARR, CCR), and setting all outputs to their default inactive states if the specified duty cycle is outside the valid range of 0% to 100%.

.. req:: label
   :id: REQ_INT3_1732973291
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Timer Module shall operate without interfering with the performance of other peripherals, such as GPIO or USART, when used simultaneously.

.. req:: label
   :id: REQ_INT3_1732973338
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall configure the Timer module and begin generating a PWM signal within 5 milliseconds of activation.
