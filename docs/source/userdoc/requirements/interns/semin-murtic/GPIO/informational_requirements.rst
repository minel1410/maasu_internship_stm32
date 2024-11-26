.. _informational_requirements:

Informational requirements
==========================



.. req:: label
   :id: REQ_INT3_1732149913
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation:

   STMF2F411 microcontroller has 6 ports: A, B, C, D, E, and H

.. req:: label
   :id: REQ_INT3_1732656386
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each port in STMF2F411 consists of 16 pins, altough some pins may not be available for use
 
 
.. req:: label
   :id: REQ_INT3_1732225413
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   RCC register is used to configure the system clock source, manage peripheral clocks, control resets, adjust voltage regulator settings

.. req:: label
   :id: REQ_INT3_1732225508
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    AHB1ENR is used to enable and disable the clock for pheripherals connected to the AHB1 bus

.. req:: label
   :id: REQ_INT3_1732225887
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
  
   Without enabling the clock, no access to the GPIO configuration registers is possible.


.. req:: label
   :id: REQ_INT3_1732225921
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   MODER register is used to configure the mode of each GPIO pin, allowing them to function as input, output, analog, or alternate function.



.. req:: label
   :id: REQ_INT3_1732272672
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Modes need to be chosen based on the use case: input (00), output (01), alternate function (10), or analog (11)

  
.. req:: label
   :id: REQ_INT3_1732315465
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Possible output types for GPIO pins are: Push-Pull and open-drain
     
  

.. req:: label
   :id: REQ_INT3_1732315482
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   OTYPER is used to configure the output type of each GPIO pin

.. req:: label
   :id: REQ_INT3_1732315503
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Push-pull is needed for standard output signals

    
.. req:: label
   :id: REQ_INT3_1732315520
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Open-Drain is needed for interfaces like I2C.


.. req:: label
   :id: REQ_INT3_1732315545
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The OSPEEDR register needs to be configured to set the output speed of a pin.

 
   
.. req:: label
   :id: REQ_INT3_1732315564
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Speed settings has options for low, medium, high, and very high speeds.

    
.. req:: label
   :id: REQ_INT3_1732315584
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   PUPDR is used to configure internal pull-up and pull-down resistors for each GPIO pin.

    

.. req:: label
   :id: REQ_INT3_1732315610
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Pull-up is needed to keep the pin high, pull-down is needed to keep it low


.. req:: label
   :id: REQ_INT3_1732315631
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   For pins configured in alternate function mode, there is a need to use the AFR register to assign the correct peripheral function.

  
.. req:: label
   :id: REQ_INT3_1732315648
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each pins alternate function needs to be carefully mapped to its intended peripheral

.. req:: label
   :id: REQ_INT3_1732315668
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The output state of GPIO pins needs to be controlled through the ODR or BSRR 

      
   
.. req:: label
   :id: REQ_INT3_1732315686
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The use of atomic operations in the BSRR register is needed to avoid conflicts in multitasking systems.

  
.. req:: label
   :id: REQ_INT3_1732315702
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Electrical characteristics like voltage levels, current limits, and protection mechanisms need to be considered during GPIO configuration.
  
 
.. req:: label
   :id: REQ_INT3_1732315719
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Status codes shall be 0x01(Invalid pin), 0x02(incorrect mode), 0x03(Operation timeout), 0x04(Unsupported function), 0x05(General error)



.. req:: label
   :id: REQ_INT3_1732230084
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Communication protocols are: UART, SPI, I2C, CAN, USB.
