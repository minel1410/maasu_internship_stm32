.. _functional_requirements:

Functional requirements
=======================


.. req:: label
   :id: REQ_INT3_1732272300
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    Each pin needs to be configured individually to operate in input, output, alternate function, or analog mode, depending on the application requirements.


.. req:: label
    :id: REQ_INT3_1732147094
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Semin Murtic
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: 
    :verification-and-validation: 

     The system shall provide functionality to enable the clock for a specific GPIO port by setting the corresponding bit in the RCC->AHB1ENR register. 
  
  

.. req:: label
    :id: REQ_INT3_1732226959
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Semin Murtic
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: 
    :verification-and-validation: 

     System must support enabling clocks for all available GPIO ports
.. req:: label
   :id: REQ_INT3_1732314479
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   System must ensure the clock enable process is completed before proceeding with any GPIO configuration
        
.. req:: label
   :id: REQ_INT3_1732314507
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow each GPIO pin to be configured in one of four modes by updating the MODER register
 
.. req:: label
   :id: REQ_INT3_1732314540
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The pin mode configuration must validate the mode value and the pin number before applying changes.

.. req:: label
   :id: REQ_INT3_1732314562
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow configuration of the GPIO output type using the OTYPER register.
          
.. req:: label
   :id: REQ_INT3_1732314594
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Register shall support Push-pull Mode (0). 
     
.. req:: label
   :id: REQ_INT3_1732314613
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   It shall allow independent configuration of each pin on the port.

.. req:: label
   :id: REQ_INT3_1732314650
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow the user to define the output speed for each GPIO pin by updating the OSPEEDR register. 
     
.. req:: label
   :id: REQ_INT3_1732314669
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Ensure the speed settings match the timing requirements.
   
.. req:: label
   :id: REQ_INT3_1732314705
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must support the configuration of internal pull-up by modifying the PUPDR register, 
    
.. req:: label
   :id: REQ_INT3_1732314739
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    The system must support the configuration of internal pull-down resistors by modifying the PUPDR register, 
   
.. req:: label
   :id: REQ_INT3_1732314752
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The function shall allow independent resistor configuration for each pin.

.. req:: label
   :id: REQ_INT3_1732314780
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   For pins configured in alternate function mode, the system shall allow the alternate function to be set by updating the AFRL (for pins 0–7) 

.. req:: label
   :id: REQ_INT3_1732314800
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   System shall provide a way to assign an alternate function to a pin using its function number.

.. req:: label
   :id: REQ_INT3_1732314824
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow direct control of the GPIO pin output state by modifying the Output Data Register (ODR) to directly set pin value

.. req:: label
   :id: REQ_INT3_1732314854
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall allow direct control of the GPIO pin output state by modifying the Output Data Register (ODR) to directly reset pin value

  
.. req:: label
    :id: REQ_INT3_1732227467
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Semin Murtic
    :modified-by:
    :category: Functional
    :safety-asil: 
    :references: 
    :verification-and-validation: 
    
    The system shall use Bit Set/Reset Register (BSRR) to atomically set state of GPIO pins.
.. req:: label
   :id: REQ_INT3_1732315259
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall use Bit Set/Reset Register (BSRR) to atomically reset state of GPIO pins.

.. req:: label
   :id: REQ_INT3_1732315280
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   A method for toggling the pin state shall also be provided.

.. req:: label
   :id: REQ_INT3_1732315297
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    The system shall encapsulate each configuration step (e.g., enabling the clock, setting the pin mode, configuring pull-up/pull-down) into separate reusable functions. 

.. req:: label
   :id: REQ_INT3_1732315323
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each function shall validate input parameters.

.. req:: label
   :id: REQ_INT3_1732315350
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each function shall return an appropriate status code for error handling.
    
         
.. req:: label
   :id: REQ_INT3_1732315372
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall include a delay function that pauses execution for a specified number of milliseconds. 

.. req:: label
   :id: REQ_INT3_1732315389
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The delay function shall be implemented using a simple loop mechanism or a timer for better accuracy.

        
