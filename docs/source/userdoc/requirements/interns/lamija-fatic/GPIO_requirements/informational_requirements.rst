Informational Requirements
==========================

.. req:: GPIO Registers
   :id: REQ_INT3_1731028659
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   GPIOx_MODER: Configures the mode of each pin (Input, Output, Analog, Alternate Function).

   GPIOx_OTYPER: Determines the output type (Push-Pull or Open-Drain).

   GPIOx_OSPEEDR: Sets the speed of GPIO pins (Low, Medium, High, Very High).

   GPIOx_PUPDR: Configures pull-up or pull-down resistors.

   GPIOx_IDR: Reads the current state of input pins.

   GPIOx_ODR: Writes the output state of GPIO pins.

   GPIOx_BSRR: Provides atomic bitwise access to set/reset GPIO output.

   GPIOx_LCKR: Locks GPIO configurations to prevent accidental changes.

   GPIOx_AFRL/AFRH: Selects alternate functions for GPIO pins.

.. req:: GPIO Features
   :id: REQ_INT3_1731028660
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   16 Pins Per Port: Each port (e.g., GPIOA, GPIOB) can manage up to 16 pins.

   Pin Multiplexing: A single pin can perform multiple functions (e.g., GPIO, UART TX/RX).

   Edge Detection: Pins can detect rising, falling, or both edges for interrupts.

   Internal Pull-Up/Down Resistors: Avoid floating states by stabilizing pin voltage levels.

   Debouncing: Removes noise from mechanical switches or unstable inputs.

   Locking Mechanism: Freezes configurations to avoid unintended changes.

.. req:: GPIO Initialization
   :id: REQ_INT3_1731028661
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO initialization involves configuring mode, type, speed, pull resistors, and alternate functions.

   A typical initialization sequence includes:

   Enabling the clock for the desired GPIO port using RCC.

   Setting the mode (Input, Output, Alternate, Analog) via GPIOx_MODER.

   Configuring the pull resistors (None, Pull-Up, Pull-Down) via GPIOx_PUPDR.

   If necessary, setting the alternate function using GPIOx_AFRL or GPIOx_AFRH.

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

   Input Mode: Reads external signals (buttons, sensors).

   Output Mode: Drives external devices (LEDs, motors).

   Analog Mode: Used for ADC/DAC operations.

   Alternate Function Mode: Enables peripheral communication (UART, SPI, I2C).

.. req:: GPIO Safety Features
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

   Unused Pins: Should be configured as inputs with pull-down resistors to avoid floating states.

   Interrupt Handling: Pins can generate interrupts, ensuring event-driven programming.

   Low-Power Retention: Configurations are retained in low-power modes, minimizing re-initialization.

.. req:: Alternate Function Mapping
   :id: REQ_INT3_1731028664
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Each pin supports up to 16 alternate functions (AF0 to AF15).

   The specific function for each pin depends on the microcontroller's datasheet.

   Alternate functions are essential for connecting GPIO pins to peripherals like timers, communication interfaces, and ADC/DAC.

.. req:: GPIO Bitwise Operations
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

   Atomic operations are supported via the GPIOx_BSRR register.

   Lower half sets pins HIGH (1).

   Upper half resets pins LOW (0).

   This ensures no interruptions during critical state changes.

.. req:: Oscillator Pin Usage
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

   Specific GPIO pins can serve as external oscillator inputs/outputs:

   PC14/PC15: Low-Speed External (LSE) oscillator.

   PH0/PH1: High-Speed External (HSE) oscillator.

   When not used as oscillators, these pins can be configured as standard GPIO.

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

   The interrupt priority and handler are configured using NVIC registers.

   Interrupts are triggered based on edge detection (Rising, Falling, or Both).

.. req:: GPIO Pin Mapping to Physical Pins
   :id: REQ_INT3_1731028668
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Each GPIO pin corresponds to a specific physical pin on the microcontroller package.

   This mapping is detailed in the STM32F411 datasheet and is critical for hardware design.

.. req:: Power Optimization with GPIO
   :id: REQ_INT3_1731028669
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO configurations impact power consumption:

   Unused pins should be pulled down.

   Low-speed configurations reduce power usage.

   GPIO pins can wake the system from low-power modes via wake-up interrupts.

.. req:: Input Mode Configuration
   :id: REQ_INT3_1731028670
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins can be set to input mode using the GPIOx_MODER register. In this mode, the pin captures external signals.

   Input mode supports optional pull-up or pull-down resistors, configured via the GPIOx_PUPDR register.

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

   Output mode supports push-pull and open-drain configurations, configured via the GPIOx_OTYPER register.

   Drive strength and speed are controlled using the GPIOx_OSPEEDR register.

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

   This mode is set using the GPIOx_MODER register and is used in applications requiring precise analog signal handling.

.. req:: Alternate Function Mode Configuration
   :id: REQ_INT3_1731028673
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pins support alternate functions for peripherals like UART, SPI, and I2C.

   Configuration involves setting the GPIOx_MODER register to alternate function mode and selecting the specific function via the GPIOx_AFRL or GPIOx_AFRH registers.

   Each pin supports up to 16 alternate functions (AF0 to AF15).

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

   This is suitable for connecting directly to LEDs or other components requiring strong drive signals.

   Configuration is performed using the GPIOx_OTYPER register.

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

   Configuration is performed using the GPIOx_OTYPER register.

.. req:: Speed Configuration
   :id: REQ_INT3_1731028676
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   GPIO pin speed settings affect the rate of signal transitions and are configured using the GPIOx_OSPEEDR register.

   Low speed minimizes power consumption and noise, while Very High speed ensures the fastest transitions for high-performance applications.

   Speed configuration is critical for timing-sensitive applications like high-speed communication protocols.

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

   This information is used in input mode to determine whether the signal is HIGH (logic 1) or LOW (logic 0).

.. req:: Setting GPIO Pin State (HIGH/LOW)
   :id: REQ_INT3_1731028678
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The output state of a GPIO pin is controlled via the GPIOx_BSRR register, which allows atomic bit-level operations.

   Writing a bit in the lower half of GPIOx_BSRR sets the pin HIGH, while writing in the upper half resets the pin to LOW.

.. req:: Internal Resistor Configuration
   :id: REQ_INT3_1731028679
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Pull-up and pull-down resistors are controlled via the GPIOx_PUPDR register, providing flexibility for input modes.

   Pull-up keeps the signal HIGH when unconnected, while pull-down forces it LOW, preventing floating states.

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

   This feature is used for event-driven applications, such as detecting button presses or state changes in external devices.

   Interrupt priorities are managed via the NVIC configuration.

.. req:: Locking GPIO Settings
   :id: REQ_INT3_1731028681
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The GPIOx_LCKR register allows locking GPIO configurations, preventing accidental changes.

   Once locked, pin configurations remain fixed until the next system reset.

.. req:: Alternate Function Assignment for UART, SPI, I2C
   :id: REQ_INT3_1731028682
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Alternate functions enable GPIO pins to interface with peripherals like UART, SPI, and I2C.

   Configuration involves setting the alternate function via the GPIOx_AFRL/GPIOx_AFRH registers and ensuring the appropriate peripheral is enabled in the RCC.

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

   Timestamps are typically stored in a dedicated log buffer.

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

   Implemented either in hardware or software, debouncing ensures stable and reliable state detection.

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

   This reduces power consumption and prevents erratic behavior.

.. req:: PWM Configuration
   :id: REQ_INT3_1731028687
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   PWM signals are generated using timers and output on GPIO pins configured for alternate function mode.

   Duty cycle adjustments control brightness, speed, or position.

   GPIO pins must be mapped to a timer capable of generating PWM signals.

.. req:: Generating Interrupts on Rising/Falling Edge
   :id: REQ_INT3_1731028688
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Rising and Falling edge interrupts allow precise detection of signal transitions.

   Configured via the EXTI and NVIC registers, these interrupts enable event-driven GPIO usage.

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

   Special registers manage the retention of states.

.. req:: Analog Mode Support
   :id: REQ_INT3_1731028692
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Analog mode is required for ADC/DAC operations, where the digital circuitry is bypassed to allow analog signal processing.

   This is set via the GPIOx_MODER register.

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

   ADC data from analog GPIO pins can be read continuously for real-time applications.

   This requires proper setup of ADC peripherals and corresponding GPIO pins in analog mode.

.. req:: Physical Pin Mapping
   :id: REQ_INT3_1731028694
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Each GPIO pin is associated with a specific physical pin on the microcontroller package.

   The mapping is detailed in the device datasheet and configured through internal registers.