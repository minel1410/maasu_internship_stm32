Non-functional Requirements
===========================

.. req:: Response Time
   :id: REQ_INT3_1731028140
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIO operations must respond within 5 clock cycles to ensure smooth operations.

.. req:: Reliability
   :id: REQ_INT3_1731028141
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO configurations must remain stable during typical operating conditions, such as normal temperature (−40°C to +85°C) and voltage ranges (3.0V to 3.6V), as well as during system soft resets, ensuring reliable functionality without unintended changes.


.. req:: Interrupt Latency
   :id: REQ_INT3_1731028143
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO interrupts must have a latency of no more than 10 microseconds, ensuring timely peripheral response.

.. req:: Compatibility
   :id: REQ_INT3_1731028144
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins must support standard 3.3V logic levels for proper interfacing.

.. req:: Noise Tolerance
   :id: REQ_INT3_1731028145
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Input signals must reject noise below 50mV, ensuring reliable detection of valid transitions.

.. req:: Drive Strength
   :id: REQ_INT3_1731028146
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO output must provide current up to 20mA.

.. req:: Peripheral Mapping
   :id: REQ_INT3_1731028147
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins must allow configuration for alternate functions such as PWM, SPI, or I2C, without conflicts between peripherals.

.. req:: Reconfiguration Speed
   :id: REQ_INT3_1731028148
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Reconfiguring a GPIO pin must not take more than 2 milliseconds to maintain real-time responsiveness.

.. req:: Debounce Delay
   :id: REQ_INT3_1731028149
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Configurable debounce delays between 1ms and 20ms must stabilize input signals for mechanical switches or sensors.


.. req:: Documentation Accuracy
   :id: REQ_INT3_1731028152
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pin-to-physical pin mappings must align with the STM32F411 datasheet, avoiding discrepancies.

.. req:: Thermal Management
   :id: REQ_INT3_1731028153
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO configurations must not cause the MCU temperature to exceed 80°C during sustained operation of peripherals.

.. req:: Pin State Preservation
   :id: REQ_INT3_1731028154
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins must preserve their configured states during temporary power fluctuations or resets.

.. req:: Dynamic Configuration
   :id: REQ_INT3_1731028155
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins must allow dynamic reconfiguration of mode without requiring a full system restart.

.. req:: Interrupt Prioritization
   :id: REQ_INT3_1731028156
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO interrupts must support up to 8 priority levels, ensuring critical events are handled first.

.. req:: Voltage Stability
   :id: REQ_INT3_1731028157
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Output voltage levels for HIGH and LOW states must remain stable within ±5% of 3.3V under varying loads.

.. req:: Low-Power Operation
   :id: REQ_INT3_1731028158
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   In standby mode, GPIO pins must consume no more than 10µA of current per pin.

.. req:: Edge Detection Reliability
   :id: REQ_INT3_1731028159
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Rising and Falling edge interrupts must detect signal transitions accurately up to 500kHz.

.. req:: Monitoring Interval
   :id: REQ_INT3_1731028161
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO state monitoring must allow a minimum polling interval of 500 microseconds for real-time applications.

.. req:: Alternate Function Timing
   :id: REQ_INT3_1731028162
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Switching between alternate functions on a GPIO pin must take no longer than 1 millisecond.

.. req:: GPIO Locking
   :id: REQ_INT3_1731028166
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   Locked GPIO configurations must only be alterable through a system-wide reset or authorized unlock sequence.

.. req:: State Change Notifications
   :id: REQ_INT3_1731028167
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Non-Functional
   :safety-asil:
   :references:
   :verification-and-validation:

    GPIO must notify the application of any state transitions, such as changes from HIGH to LOW or LOW to HIGH, within 1 millisecond, ensuring accurate and timely response to input or output events.


