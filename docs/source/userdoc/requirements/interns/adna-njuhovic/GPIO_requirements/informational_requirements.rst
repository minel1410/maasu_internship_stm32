===============================
Informational Requirements
===============================

.. req:: label
   :id: REQ_INT3_1732817300
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

GPIO Pin Configuration
=======================
The GPIO pin configuration system shall support mode selection for each pin, ensuring the ability to configure each GPIO pin to one of four distinct modes: input, output, analog, and alternate function.

.. req:: label
   :id: REQ_INT3_1732817888
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

A moder register is a control register used in microcontrollers to configure the operating mode of GPIO pins. This register is essential for setting the correct functionality of the pins during initialization.

.. req:: label
   :id: REQ_INT3_1732818810
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

GPIO Pin Input Mode:
====================
GPIO pins must be able to read signals as high (1) or low (0).

.. req:: label
   :id: REQ_INT3_1732819001
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
   :id: REQ_INT3_1732818859
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

Configurable Resistors:
=======================
The pull-up or pull-down resistors must be configurable using the PUPDR register.

.. req:: label
   :id: REQ_INT3_1732819737
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

Input functionality must maintain signal accuracy.

.. req:: label
   :id: REQ_INT3_1732819784
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

GPIO pins in analog mode must support continuous signal processing for ADC (Analog to Digital) or DAC (Digital to Analog) operations.

.. req:: label
   :id: REQ_INT3_1732821083
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

GPIO pins must support alternate functions for peripherals such as UART, SPI, or I2C.

.. req:: label
   :id: REQ_INT3_1732822201
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

Pull-up resistors must ensure that the pin state defaults to high (1).

.. req:: label
   :id: REQ_INT3_1732822241
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

Pull-down resistors must ensure that the pin state defaults to low (0).

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

GPIO pins must support two output configurations: push-pull and open-drain.

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

Push-pull: The pin must drive both high (1) and low (0) states.

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
