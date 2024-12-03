===============================
Informational Requirements
===============================

.. req:: label
   :id: REQ_INT3_1733152925
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The GPIO firmware provides the current logical state (high or low) for each GPIO pin configured as output or input. 


.. req:: label
   :id: REQ_INT3_1733154840
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   A moder register is a control register used in microcontrollers to configure the operating mode of GPIO pins. 


.. req:: label
   :id: REQ_INT3_1733155407
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PUPDR (Pull-up/Pull-down Resistor Configuration) register is used to configure the internal pull-up and pull-down resistors for GPIO pins in input mode.


.. req:: label
   :id: REQ_INT3_1733155631
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The input functionality is designed to ensure accurate signal detection in GPIO.



.. req:: label
   :id: REQ_INT3_1732823366
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO pins support two output configurations: push-pull and open-drain.

.. req:: label
   :id: REQ_INT3_1732824388
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Push-pull: The pin drives both high (1) and low (0) states.

.. req:: label
   :id: REQ_INT3_1732824488
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Open-drain: The pin drives only low (0) states, with a high (1) state achieved using an external pull-up resistor.

.. req:: label
   :id: REQ_INT3_1732824695
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Speed control has three types: low, medium, and high speed.

.. req:: label
   :id: REQ_INT3_1732824774
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Low speed: Suitable for low-frequency tasks like driving LEDs.

.. req:: label
   :id: REQ_INT3_1732824812
   :status: Draft  
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Medium speed: Used for general-purpose tasks that balance performance and power consumption.

.. req:: label
   :id: REQ_INT3_1732825038
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   High speed: Required for time-critical tasks like PWM or high-speed communication protocols.
