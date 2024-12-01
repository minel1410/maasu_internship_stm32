Functional requirements
-----------------------

.. req:: label
   :id: REQ_INT3_1732966802
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable the Timer peripheral by setting the specific enable bit (e.g., TIM1EN for TIM1) in the RCC_APB1ENR or RCC_APB2ENR register, as defined in the informational requirements.

.. req:: label
   :id: REQ_INT3_1732966837
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall calculate the prescaler (PSC) value based on the formula provided in the informational requirements and the specified PWM frequency passed as a parameter. The calculated value shall then be written to the PSC register of the selected Timer module.

.. req:: label
   :id: REQ_INT3_1732966929
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall calculate the value of the Auto-Reload Register (ARR) using the formula provided in the informational requirements and the PWM frequency specified as a parameter. The calculated value shall then be written to the ARR register of the specified Timer module.

.. req:: label
   :id: REQ_INT3_1732966971
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall calculate the value of the Capture/Compare Register (CCR) based on the duty cycle passed as a parameter and the previously calculated ARR value. The calculated CCR value shall then be written to the CCR register of the specified Timer channel.

.. req:: label
   :id: REQ_INT3_1732967007
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall configure the OCxM bits in the TIM_CCMR1 register to 110 to enable PWM Mode 1 for the selected Timer channel.

.. req:: label
   :id: REQ_INT3_1732967046
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall activate the PWM output by setting the CC1E, CC2E, CC3E, or CC4E bit in the TIM_CCER register, depending on the selected Timer channel.

.. req:: label
   :id: REQ_INT3_1732967080
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall start the Timer counter by setting the CEN bit in the TIM_CR1 register after completing the configuration.

.. req:: label
   :id: REQ_INT3_1732967114
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall return a success status if the PWM configuration matches the user-specified frequency and duty cycle, ensuring the correct values are written to the Timer registers (PSC, ARR, CCR).

.. req:: label
   :id: REQ_INT3_1732967149
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall return an error code and stop configuration if the specified duty cycle is outside the valid range of 0% to 100%.

.. req:: label
   :id: REQ_INT3_1732967196
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall disable the PWM output by clearing the CCxE bit in the TIM_CCER register for the specified Timer channel when the PWM signal is no longer required.

