===========================
Informational Requirements
===========================

.. req:: label
   :id: REQ_INT3_1733078414
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO stands for General Purpose Input/Output. It refers to pins on the microcontroller that allow interaction with external devices, such as sensors, LEDs, and motors.

.. req:: label
   :id: REQ_INT3_1733078547
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Input mode: Used for reading data from external devices, such as sensors or buttons.


.. req:: label
   :id: REQ_INT3_1733078732
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    Output mode: Used for sending signals to external devices, such as turning on LEDs or controlling motors.


.. req:: label
   :id: REQ_INT3_1733078784
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The behavior of GPIO pins is controlled by various GPIO registers.


.. req:: label
   :id: REQ_INT3_1733078825
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     MODER: Configures the mode of each pin (input, output, analog, or alternate function).


.. req:: label
   :id: REQ_INT3_1733078857
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    PUPDR: Controls whether the input pins are connected to a pull-up or pull-down resistor or are floating (not connected).


.. req:: label
   :id: REQ_INT3_1733078913
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     OTYPER: Determines whether an output pin is in push-pull or open-drain mode.


.. req:: label
   :id: REQ_INT3_1733078969
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     OSPEEDR: Sets the speed of the output signal (low, medium, fast, high).


.. req:: label
   :id: REQ_INT3_1733079007
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     IDR: Reads the state of input pins (high or low).


.. req:: label
   :id: REQ_INT3_1733079458
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     ODR: Sets the state of output pins (high or low).


.. req:: label
   :id: REQ_INT3_1733079497
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     BSRR: Provides a fast way to set or reset individual pins without affecting others.


.. req:: label
   :id: REQ_INT3_1733079536
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    RCC_AHB1ENR is a register that controls clock enabling for peripherals connected to AHB1.


.. req:: label
   :id: REQ_INT3_1733079582
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Enabling clock activates GPIO port functionality and enables GPIO pin use.


.. req:: label
   :id: REQ_INT3_1733079634
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Input mode: Configured to detect external signals, often with pull-up or pull-down resistors.


.. req:: label
   :id: REQ_INT3_1733079677
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Output mode: Used to send data or signals. Pins can be set to push-pull or open-drain mode.


.. req:: label
   :id: REQ_INT3_1733079724
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Analog mode: Used for processing signals from analog sensors through ADC or DAC interfaces.


.. req:: label
   :id: REQ_INT3_1733079763
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Alternate function mode: Allows pins to interact with peripherals like UART, SPI, I2C, and PWM.


.. req:: label
   :id: REQ_INT3_1733079809
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     AFR[0] (Alternate function low register): sets alternate function for pins from 0 to 7. (0001 for USART, 0010 for SPI)


.. req:: label
   :id: REQ_INT3_1733079846
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

     AFR[1] (Alternate function high register): sets alternate function for pins from 8 to 15.
