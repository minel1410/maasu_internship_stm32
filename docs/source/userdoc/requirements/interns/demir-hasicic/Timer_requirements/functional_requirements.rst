==========================
Functional Requirements
==========================
.. req:: EnableTimerClock
   :id: REQ_INT3_1733094026
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMxEN bit in the RCC_APB1ENR or RCC_APB2ENR register must be set to enable the timer clock.

.. req:: ConfigureAlternateFunction
   :id: REQ_INT3_1733094064
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The AFRL or AFRH field in the GPIOx_AFR register must be configured to AF1, AF2, or AF3, based on the timer and channel.

.. req:: SetTimerPrescaler
   :id: REQ_INT3_1733094116
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PSC register must be written to divide the timer’s input clock frequency to ensure the PWM period fits within the valid range of a 16-bit timer.

.. req:: SetTimerPeriod
   :id: REQ_INT3_1733094148
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The ARR register must be configured to define the timer period based on the desired PWM frequency and the prescaler value.

.. req:: SetOutputCompareMode
   :id: REQ_INT3_1733094173
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The OCxM bits in the CCMR1 or CCMR2 register must be set to 110 for PWM Mode 1 or 111 for PWM Mode 2 to configure the timer channel's output behavior.

.. req:: EnableOutputComparePreload
   :id: REQ_INT3_1733094233
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The OCxPE (Output Compare Preload Enable) bit in the CCMR1 or CCMR2 register must be set to enable the preload functionality for the CCR register, ensuring synchronized updates with the timer counter and preventing glitches in the PWM signal.

.. req:: EnableCaptureCompareOutput
   :id: REQ_INT3_1733094287
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCxE bit in the CCER register must be set to enable the output for the selected timer channel.

.. req:: SetDutyCycle
   :id: REQ_INT3_1733094378
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The calculated duty-cycle value must be written to the CCRx register to set the PWM signal's duty cycle.

.. req:: EnableTimerCounter
   :id: REQ_INT3_1733094514
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CEN bit in the TIM_CR1 register must be set to start the timer and begin PWM generation.
