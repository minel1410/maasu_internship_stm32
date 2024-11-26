Informational Requirements
==========================

.. req:: GPIO Registers
   :id: REQ_INT3_17310286668
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO consists of the following registers: GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR, GPIOx_IDR, GPIOx_ODR, GPIOx_BSRR, GPIOx_LCKR, GPIOx_AFRL, and GPIOx_AFRH.


.. req:: GPIO Pin Modes
   :id: REQ_INT3_1731028699
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:
   GPIO pins can be configured in given modes:Input floating, Input pull-up, Input pull-down, Analog, Output open-drain, Output push-pull, Alternate function push-pull, and Alternate function open-drain, with optional pull-up or pull-down capabilities.


.. req:: GPIOx_MODER
   :id: REQ_INT3_17310286990
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_MODER configures the mode of each pin on one of the possible modes for GPIO.

.. req:: GPIOx_OTYPER
   :id: REQ_INT3_17310286991
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_OTYPER register determines the output type (Push-Pull or Open-Drain).

.. req:: GPIOx_OSPEEDR
   :id: REQ_INT3_17310286992
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_OSPEEDR register sets the speed of GPIO pins (Low, Medium, High, Very High).

.. req:: GPIOx_PUPDR
   :id: REQ_INT3_173102869924111
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_PUPDR register configures pull-up or pull-down resistors.

.. req:: GPIOx_IDR
   :id: REQ_INT3_17310286993
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_IDR register reads the current state of input pins.

.. req:: GPIOx_ODR
   :id: REQ_INT3_17310286994
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_ODR register writes the output state of GPIO pins.

.. req:: GPIOx_BSRR
   :id: REQ_INT3_17310286995
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_BSRR is a register which allows the application to set and reset each individual bit in the output data register.

.. req:: GPIOx_LCKR
   :id: REQ_INT3_17310286996
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   The GPIOx_LCKR register is used to lock the configuration of GPIO control registers, preventing accidental changes.
   

.. req:: GPIOx_AFRL/AFRH
   :id: REQ_INT3_17310286997
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_AFRL/AFRH register selects alternate functions for GPIO pins.

.. req:: GPIO Pin Count
   :id: REQ_INT3_173102866136
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Each GPIO port can manage up to 16 pins.

.. req:: GPIO Locking Mechanism
   :id: REQ_INT3_1731028666
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO locking mechanism freezes configurations to avoid unintended changes.

.. req:: GPIO Debouncing
   :id: REQ_INT3_1731028665
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Debouncing removes noise from mechanical switches or unstable inputs on GPIO pins.

.. req:: GPIO Edge Detection
   :id: REQ_INT3_1731028663
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can detect rising, falling, or both edges for interrupt generation.

.. req:: GPIO Operating Modes
   :id: REQ_INT3_1731028662
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO has following operating modes : Input Mode, Output Mode,Analog Mode and Alternate Function mode.

.. req:: GPIO Input Mode
   :id: REQ_INT3_1731028667
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO input mode is used to read external signals, such as those from buttons or sensors.

.. req:: GPIO Output Mode
   :id: REQ_INT3_17310286685888
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO output mode is used to drive external devices, such as LEDs or motors.

.. req:: GPIO Analog Mode
   :id: REQ_INT3_173102866956
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO analog mode is used to process analog signals directly, bypassing the digital circuitry.

.. req:: Communication Protocols
   :id: REQ_INT3_1731028670119
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Communication Protocols used by GPIO pins for peripherals communication are UART,SPI and I2C.


.. req:: GPIO Alternate Function Mode
   :id: REQ_INT3_1731028670987
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO alternate function mode enables communication with peripherals.


.. req:: GPIO Safety Features
   :id: REQ_INT3_1731028663457
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO safety features include handling unused pins, interrupt handling, and configuration retention in low-power modes.

.. req:: Unused Pins Configuration
   :id: REQ_INT3_1731028664778
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Unused GPIO pins should be configured as inputs with pull-down resistors to prevent floating states and erratic behavior.

.. req:: Interrupt Handling
   :id: REQ_INT3_1731028665447
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can generate interrupts to enable event-driven programming and ensure timely responses to state changes.

.. req:: Low-Power Configuration Retention
   :id: REQ_INT3_1731028666111
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO configurations must be retained in low-power modes, minimizing re-initialization and ensuring consistent operation.

.. req:: Alternate Function Range
   :id: REQ_INT3_1731028667787
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Each GPIO pin supports up to 16 alternate functions, ranging from AF0 to AF15.

.. req:: GPIO Bitwise Handling
   :id: REQ_INT3_1731028675522
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The GPIOx_BSRR register allows setting or resetting individual bits of the GPIOx_ODR register in a single operation, ensuring efficient and safe bit-level modifications.

.. req:: Oscillators
   :id: REQ_INT3_1731028668125
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The available oscillators for the STM32F411 microcontroller are the Low-Speed External (LSE) oscillator and the High-Speed External (HSE) oscillator.



.. req:: GPIO Oscillator Pins
   :id: REQ_INT3_1731028666324
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins associated with oscillator functionality are:  PC14/PC15: Low-Speed External (LSE) oscillator and PH0/PH1: High-Speed External (HSE) oscillator.


.. req:: GPIO and Interrupt Handling
   :id: REQ_INT3_1731028667
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   External interrupts can be configured for GPIO pins via the EXTI (External Interrupt) controller.

.. req:: GPIO  Resistor Configuration
   :id: REQ_INT3_1731028671147
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Pull-up or pull-down resistors can be configured using the GPIOx_PUPDR register to stabilize signal levels and prevent floating states.

.. req:: Output Mode Configuration
   :id: REQ_INT3_1731028671
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can be set to output mode via the GPIOx_MODER register to drive external components like LEDs or motors.

.. req:: Peripherals
   :id: REQ_INT3_1731028672478
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The available peripherals include Analog-to-Digital Converter (ADC), Digital-to-Analog Converter (DAC), Timers, Universal Asynchronous Receiver-Transmitter (UART), Serial Peripheral Interface (SPI), Inter-Integrated Circuit (I2C), and External Oscillators.


.. req:: Analog Mode Configuration
   :id: REQ_INT3_1731028672
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Analog mode enables GPIO pins to interface with ADC/DAC peripherals by disabling the digital logic on the pin.


.. req:: Push-Pull Output Configuration
   :id: REQ_INT3_1731028674
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Push-pull configuration enables GPIO pins to actively drive both high and low states.


.. req:: Open-Drain Output Configuration
   :id: REQ_INT3_1731028675
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Open-drain configuration allows GPIO pins to pull the signal low while relying on an external pull-up resistor for the high state.


.. req:: GPIO pins Speed 
   :id: REQ_INT3_173102867747888
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins support two main speed Low speed which minimizes power consumption and noise, and Very High speed, which ensures the fastest transitions for high-performance applications.


.. req:: Detecting GPIO Pin State (HIGH/LOW)
   :id: REQ_INT3_1731028677
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The current state of a GPIO pin is captured in the GPIOx_IDR register, which reflects the voltage level at the pin.


.. req:: Edge-Triggered Interrupts
   :id: REQ_INT3_1731028680
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can generate interrupts on Rising, Falling, or Both edges, configured via the EXTI registers.


.. req:: Real-Time Monitoring
   :id: REQ_INT3_1731028683
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Real-time monitoring involves periodically polling the GPIOx_IDR register to detect state changes.

.. req:: Timestamping Events
   :id: REQ_INT3_1731028684
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO interrupts can be timestamped to log when specific events occur, aiding in debugging and performance analysis.


.. req:: Debouncing Signals
   :id: REQ_INT3_1731028685
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Signal debouncing filters out noise or fluctuations caused by mechanical switches or unstable inputs.


.. req:: Safe Configuration of Unused Pins
   :id: REQ_INT3_1731028686
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Unused GPIO pins are typically configured as inputs with pull-down resistors to avoid floating states.


.. req:: Event Notifications for State Changes
   :id: REQ_INT3_1731028689
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can notify the application of state changes via interrupts or status flags.

.. req:: Error Detection for GPIO Configuration
   :id: REQ_INT3_1731028690
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Errors in GPIO configuration, such as invalid register values, can be logged for debugging.

.. req:: Low Power Retention
   :id: REQ_INT3_1731028691
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins retain their configuration and state in low-power modes, ensuring system stability during power-saving operations.


.. req:: Real-Time ADC Readings
   :id: REQ_INT3_1731028693
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   ADC data from analog GPIO pins can be read continuously for real-time applications and requires setting the pins to analog mode and enabling the ADC module for data conversion.


