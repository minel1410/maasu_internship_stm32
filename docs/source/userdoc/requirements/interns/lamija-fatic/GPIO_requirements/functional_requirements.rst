Functional Requirements
===================

.. req:: Input Mode Configuration
   :id: REQ_INT3_1731028084
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must provide the ability to configure GPIO pins in input mode.
   
   Precondition: GPIO pin must be available for configuration.
   
   Action: The system sets the GPIO pin mode to input using the GPIOx_MODER register.
   
   Expected Result: The pin functions as an input, capturing external signals.

.. req:: Output Mode Configuration
   :id: REQ_INT3_17310280859
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must provide the ability to configure GPIO pins in output mode.
   
   Precondition: GPIO pin must be available for configuration.
   
   Action: The system sets the GPIO pin mode to output using the GPIOx_MODER register.
   
   Expected Result: The pin functions as an output, sending signals to external components.

.. req:: Alternate Function Mode Configuration
   :id: REQ_INT3_173102808713
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must provide the ability to configure GPIO pins in alternate function mode.
   
   Precondition: GPIO pin must be available for configuration.
   
   Action: The system sets the GPIO pin mode to alternate function using the GPIOx_MODER and GPIOx_AFRL/GPIOx_AFRH registers.
   
   Expected Result: The pin operates in alternate function mode, supporting peripheral communication.

.. req:: Push-Pull Output Configuration
   :id: REQ_INT3_173102808812
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must allow setting GPIO output type to Push-Pull.
   
   Precondition: The GPIO pin is configured as an output.
   
   Action: The system updates the GPIOx_OTYPER register to set the pin as Push-Pull.
   
   Expected Result: The GPIO pin outputs signals using a Push-Pull configuration, enabling both high and low drive states.

.. req:: Open-Drain Output Configuration
   :id: REQ_INT3_1731028089
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must allow setting GPIO output type to Open-Drain.
   
   Precondition: The GPIO pin is configured as an output.
   
   Action: The system updates the GPIOx_OTYPER register to set the pin as Open-Drain.
   
   Expected Result: The GPIO pin outputs signals using an Open-Drain configuration, relying on an external pull-up resistor for the high state.

.. req:: Low Speed Configuration  
   :id: REQ_INT3_173102809012
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must support configuration of GPIO pins to operate at Low speed.  

   Precondition: User specifies Low speed for a GPIO pin.  

   Action: The system writes the corresponding value for Low speed to the GPIOx_OSPEEDR register.  

   Expected Result: The GPIO pin operates at Low speed, minimizing power consumption and noise.  

.. req:: Analog Mode Configuration
    :id: REQ_INT3_173102808614
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Lamija Fatić
    :modified-by:
    :category: Functional
    :safety-asil:
    :references:
    :verification-and-validation:

    The system must provide the ability to configure GPIO pins in analog mode.

    Precondition: GPIO pin must be available for configuration.

    Action: The system sets the GPIO pin mode to analog using the GPIOx_MODER register.

    Expected Result: The pin functions as an analog interface for ADC/DAC operations.


.. req:: Medium Speed Configuration  
   :id: REQ_INT3_1731028091  
   :status: Draft  
   :date-released:  
   :priority: Low 
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must support configuration of GPIO pins to operate at Medium speed.  

   Precondition: User specifies Medium speed for a GPIO pin.  

   Action: The system writes the corresponding value for Medium speed to the GPIOx_OSPEEDR register.  

   Expected Result: The GPIO pin operates at Medium speed, balancing performance and power consumption.  

.. req:: High Speed Configuration  
   :id: REQ_INT3_173102809211  
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must support configuration of GPIO pins to operate at High speed.  

   Precondition: User specifies High speed for a GPIO pin.  

   Action: The system writes the corresponding value for High speed to the GPIOx_OSPEEDR register.  

   Expected Result: The GPIO pin operates at High speed, providing quick response for time-critical applications.
   
.. req:: Very High Speed Configuration  
   :id: REQ_INT3_1731028093  
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must support configuration of GPIO pins to operate at Very High speed.  

   Precondition: User specifies Very High speed for a GPIO pin.  

   Action: The system writes the corresponding value for Very High speed to the GPIOx_OSPEEDR register.  

   Expected Result: The GPIO pin operates at Very High speed, ensuring the fastest signal transitions for high-performance applications.  

.. req:: Detecting GPIO Pin HIGH State  
   :id: REQ_INT3_173102809411 
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must detect when a GPIO pin is in the HIGH state.  

   Precondition: The GPIO pin is configured in input mode.  

   Action: The system reads the GPIOx_IDR register and checks if the corresponding bit is set to HIGH.  

   Expected Result: The system correctly identifies and reports the HIGH state of the pin.  

.. req:: Alternate Function Mode Configuration
    :id: REQ_INT3_173102808711
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Lamija Fatić
    :modified-by:
    :category: Functional
    :safety-asil:
    :references:
    :verification-and-validation:

    The system must provide the ability to configure GPIO pins in alternate function mode.

    Precondition: GPIO pin must be available for configuration.

    Action: The system sets the GPIO pin mode to alternate function using the GPIOx_MODER and GPIOx_AFRL/GPIOx_AFRH registers.

    Expected Result: The pin operates in alternate function mode, supporting peripheral communication


.. req:: Detecting GPIO Pin LOW State  
   :id: REQ_INT3_1731028095  
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must detect when a GPIO pin is in the LOW state.  

   Precondition: The GPIO pin is configured in input mode.  

   Action: The system reads the GPIOx_IDR register and checks if the corresponding bit is set to LOW.  

   Expected Result: The system correctly identifies and reports the LOW state of the pin.  


.. req:: Setting GPIO Pin to HIGH State  
   :id: REQ_INT3_1731028096  
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must provide functionality to set GPIO pins to the HIGH state.  

   Precondition: The GPIO pin is configured as an output.  

   Action: The system writes the appropriate value to the GPIOx_BSRR register to set the pin to HIGH.  

   Expected Result: The GPIO pin outputs a HIGH signal (logical 1).  

.. req:: Setting GPIO Pin to LOW State  
   :id: REQ_INT3_1731028097  
   :status: Draft  
   :date-released:  
   :priority: Low  
   :submitted-by: Lamija Fatić  
   :modified-by:  
   :category: Functional  
   :safety-asil:  
   :references:  
   :verification-and-validation:  

   The system must provide functionality to set GPIO pins to the LOW state.  

   Precondition: The GPIO pin is configured as an output.  

   Action: The system writes the appropriate value to the GPIOx_BSRR register to reset the pin to LOW.  

   Expected Result: The GPIO pin outputs a LOW signal (logical 0).  

.. req:: Internal Resistor Configuration
   :id: REQ_INT3_1731028098
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must support enabling or disabling internal pull-up or pull-down resistors for GPIO pins.

   Precondition: User specifies the desired resistor type (Pull-Up, Pull-Down, or None).

   Action: The system configures the GPIOx_PUPDR register to set the resistor mode.

   Expected Result: The GPIO pin operates with the configured internal resistor mode.

.. req:: Rising Edge Interrupt Configuration
   :id: REQ_INT3_1731028099
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must enable edge-triggered interrupts on GPIO pins for Rising edges.
   
   Precondition: The GPIO pin is configured as an input.
   
   Action: The system configures the EXTI registers to detect a Rising edge.
   
   Expected Result: An interrupt is triggered when a Rising edge is detected on the pin.

.. req:: Falling Edge Interrupt Configuration
   :id: REQ_INT3_1731028100
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must enable edge-triggered interrupts on GPIO pins for Falling edges.
   
   Precondition: The GPIO pin is configured as an input.
   
   Action: The system configures the EXTI registers to detect a Falling edge.
   
   Expected Result: An interrupt is triggered when a Falling edge is detected on the pin.

.. req:: Both Edges Interrupt Configuration
    :id: REQ_INT3_1731028101
    :status: Draft
    :date-released:
    :priority: Low
    :submitted-by: Lamija Fatić
    :modified-by:
    :category: Functional
    :safety-asil:
    :references:
    :verification-and-validation:
    
    The system must enable edge-triggered interrupts on GPIO pins for Both edges.
    
    Precondition: The GPIO pin is configured as an input.
    
    Action: The system configures the EXTI registers to detect both Rising and Falling edges.
    
    Expected Result: An interrupt is triggered when either a Rising or Falling edge is detected on the pin.

.. req:: Locking GPIO Settings
   :id: REQ_INT3_1731028102
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must allow locking GPIO pin configurations to prevent accidental modifications.
   
   Precondition: User requests a lock operation on specific GPIO pins.
   
   Action: The system executes the lock sequence on the GPIOx_LCKR register.
   
   Expected Result: The GPIO pin configuration is locked and cannot be changed until reset.

.. req:: Alternate Function Assignment for UART
   :id: REQ_INT3_1731028103
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must support assigning GPIO pins to alternate functions for UART communication.
   
   Precondition: User specifies the UART peripheral for a GPIO pin.
   
   Action: The system updates the appropriate bits in the GPIOx_AFRL or GPIOx_AFRH register to assign the UART function.
   
   Expected Result: The GPIO pin is configured for UART communication and interacts with the UART peripheral.

.. req:: Alternate Function Assignment for SPI
   :id: REQ_INT3_1731028104
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must support assigning GPIO pins to alternate functions for SPI communication.
   
   Precondition: User specifies the SPI peripheral for a GPIO pin.
   
   Action: The system updates the appropriate bits in the GPIOx_AFRL or GPIOx_AFRH register to assign the SPI function.
   
   Expected Result: The GPIO pin is configured for SPI communication and interacts with the SPI peripheral.

.. req:: Alternate Function Assignment for I2C
   :id: REQ_INT3_1731028105
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functiona
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must support assigning GPIO pins to alternate functions for I2C communication.
   
   Precondition: User specifies the I2C peripheral for a GPIO pin.
   
   Action: The system updates the appropriate bits in the GPIOx_AFRL or GPIOx_AFRH register to assign the I2C function.
   
   Expected Result: The GPIO pin is configured for I2C communication and interacts with the I2C peripheral. 

.. req:: Real-Time Monitoring
   :id: REQ_INT3_1731028106
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:
   
   The system must continuously monitor the logical state of GPIO pins and provide real-time updates.
   
   Precondition: Monitoring is enabled for selected GPIO pins.
   
   Action: The system polls GPIOx_IDR register at regular intervals and reports changes.
   
   Expected Result: Real-time state updates are provided for the monitored GPIO pins.  

.. req:: Timestamping Events
   :id: REQ_INT3_1731028135
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must log timestamps for each GPIO pin interrupt.

   Precondition: GPIO pin is configured to generate interrupts.

   Action: The system records the timestamp when an interrupt occurs.

   Expected Result: Interrupt events are logged with precise timestamps.

.. req:: Debouncing Signals
   :id: REQ_INT3_1731028136
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must filter noise on GPIO input signals using debounce functionality.

   Precondition: GPIO pin is subject to noisy signals.

   Action: The system applies debounce logic to stabilize the input state.

   Expected Result: Noise is suppressed, and only valid state changes are registered.

.. req:: Input State Detection
   :id: REQ_INT3_1731028137
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must detect input states (HIGH/LOW) on GPIO pins.

   Precondition: GPIO pin is configured as an input.

   Action: The system reads from the GPIOx_IDR register to capture the state.

   Expected Result: The system reports the correct state of the GPIO pin.

.. req:: Safe Configuration of Unused Pins
   :id: REQ_INT3_1731028138
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must configure unused GPIO pins in a safe state.

   Precondition: GPIO pins are marked as unused.

   Action: The system configures unused pins as input with pull-down resistors.

   Expected Result: Unused GPIO pins are safely configured to avoid floating states. 


.. req:: Controlling Fan Speed
   :id: REQ_INT3_1731028126
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must allow controlling fan speed using PWM signals on GPIO pins.

   Precondition: GPIO pin is configured for PWM and connected to the fan control circuit.

   Action: The system adjusts the PWM duty cycle to regulate fan speed.

   Expected Result: The fan speed changes according to the configured PWM signal.

.. req:: Generating Interrupts on Rising Edge
   :id: REQ_INT3_1731028127
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must generate interrupts on Rising edges for input GPIO pins.

   Precondition: GPIO pin is configured as input with interrupts enabled.

   Action: The system configures the EXTI registers to detect a Rising edge.

   Expected Result: An interrupt is triggered when a Rising edge is detected on the GPIO pin.

.. req:: Generating Interrupts on Falling Edge
   :id: REQ_INT3_1731028128
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must generate interrupts on Falling edges for input GPIO pins.

   Precondition: GPIO pin is configured as input with interrupts enabled.

   Action: The system configures the EXTI registers to detect a Falling edge.

   Expected Result: An interrupt is triggered when a Falling edge is detected on the GPIO pin.

.. req:: Event Notifications for State Changes
   :id: REQ_INT3_1731028129
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must notify the application when GPIO pin states change.

   Precondition: GPIO pins are monitored for state transitions.

   Action: The system detects a state change and sends a notification.

   Expected Result: The application receives real-time notifications for GPIO state changes.

.. req:: Error Detection for GPIO Configuration
   :id: REQ_INT3_1731028130
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must detect invalid GPIO configurations and notify the user.

   Precondition: User attempts an invalid GPIO operation.

   Action: The system checks the configuration and reports any errors.

   Expected Result: Errors are detected and logged for debugging purposes.

.. req:: Low Power Retention
   :id: REQ_INT3_1731028131
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins must retain their states in low-power modes.

   Precondition: The system enters a low-power state.

   Action: GPIO pins are configured to retain their states during low-power operation.

   Expected Result: GPIO pins maintain their configured state without loss of functionality.

 .. req:: Real-Time ADC Readings
    :id: REQ_INT3_1731028133
    :status: Draft
    :date-released:
    :priority: Medium
    :submitted-by: Lamija Fatić
    :modified-by:
    :category: Functional
    :safety-asil:
    :references:
    :verification-and-validation:

    The system must provide continuous ADC readings from analog GPIO pins.

    Precondition: GPIO pin is configured for analog input and connected to an ADC module.

    Action: The system fetches ADC data and updates the application in real-time.

    Expected Result: Continuous ADC readings are available without delays.

.. req:: Physical Pin Mapping
   :id: REQ_INT3_1731028134
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must provide a mapping between physical pin numbers and their GPIO assignments.

   Precondition: The user requests the mapping information.

   Action: The system retrieves and displays the pin-to-GPIO mapping from internal configuration.

   Expected Result: Accurate mapping information is displayed for each pin.

