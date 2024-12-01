=============================
Informational Requirements
=============================

.. req:: RCCRegister
   :id: REQ_INT3_1733093382
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Reset and Clock Control (RCC) register manages the clock configuration for the STM32F411 microcontroller, including enabling clock signals for timers and peripheral buses.
      
.. req:: AdvancedPeripheralBus1
   :id: REQ_INT3_1733093366
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   The APB1 (Advanced Peripheral Bus 1) supports low-speed peripherals TIM2, TIM3, TIM4, and TIM5 (50 MHz bus).

.. req:: AdvancedPeripheralBus2
   :id: REQ_INT3_1733093347
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The APB2 (Advanced Peripheral Bus 2) supports high-speed peripherals TIM1, TIM9, TIM10, and TIM11 (100 MHz bus).

.. req:: TimerClockEnableBits
   :id: REQ_INT3_1733093331
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMxEN bits in the RCC_APB1ENR and RCC_APB2ENR registers enable the clock for specific timers:
      
      - APB1 Timers:
         - TIM2EN (bit 0): Enables TIM2 clock.
         - TIM3EN (bit 1): Enables TIM3 clock.
         - TIM4EN (bit 2): Enables TIM4 clock.
         - TIM5EN (bit 3): Enables TIM5 clock.
      - APB2 Timers:
         - TIM1EN (bit 0): Enables TIM1 clock.
         - TIM9EN (bit 16): Enables TIM9 clock.
         - TIM10EN (bit 17): Enables TIM10 clock.
         - TIM11EN (bit 18): Enables TIM11 clock.

.. req:: GPIOConfiguration (GPIOx_MODER)
   :id: REQ_INT3_1733095231
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   The GPIOx_MODER register configures the operating mode of GPIO pins. Each pin can be set to:
      
      - Input mode.
      - General-purpose output mode.
      - Alternate function mode.
      - Analog mode.


.. req:: GPIOAlternateFunctionRegister (GPIOx_AFR)
   :id: REQ_INT3_1733093297
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The GPIOx_AFR (Alternate Function Register) determines the alternate function of GPIO pins, enabling features such as PWM, input capture, and communication protocols. The register is divided into two sections:
     
      - AFRL: Configures alternate functions for GPIO pins 0–7.
      - AFRH: Configures alternate functions for GPIO pins 8–15.
   Each pin can be assigned one of 16 alternate functions (AF0 to AF15).

.. req:: TimerAlternateFunctionMapping
   :id: REQ_INT3_1733093279
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   STM32F411 timers rely on alternate functions to enable features like PWM generation and input capture. The alternate function assignments for timers are:

      - AF1: Used by TIM1 and TIM2 for channels CH1–CH4.
      - AF2: Used by TIM3 and TIM4 for channels CH1–CH4.
      - AF3: Used by TIM9, TIM10, and TIM11

.. req:: PSC (Prescaler Register)
   :id: REQ_INT3_1733093263
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The PSC register divides the timer’s input clock frequency to lower the effective timer frequency.

   Formula:
   Prescaler = Timer Frequency / (Desired Frequency × ARR_max).

   Where:
     
      - Timer Frequency: The clock driving the timer.
      - Desired Frequency: The target frequency.
      - ARR_max: Maximum value of the Auto-Reload Register (ARR) (65535).



.. req:: PWMMode
   :id: REQ_INT3_1733093244
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Pulse Width Modulation (PWM) mode allows the timer to generate a signal with a variable duty cycle. This is achieved by comparing the counter value with the Capture/Compare Register (CCRx). PWM mode can operate in two configurations:
      
      - PWM Mode 1: Output is high when the counter is less than CCRx and low otherwise.
      - PWM Mode 2: Output is low when the counter is less than CCRx and high otherwise.


.. req:: OCxMConfiguration
   :id: REQ_INT3_1733091758
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The OCxM (Output Compare Mode) bits in the CCMR register configure the behavior of the timer output in PWM mode:
      
      - 110: PWM Mode 1 (output high when counter < CCRx, low otherwise).
      - 111: PWM Mode 2 (output low when counter < CCRx, high otherwise).

.. req:: OCxPEConfiguration
   :id: REQ_INT3_1733091828
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The OCxPE (Output Compare Preload Enable) bit in the CCMR register enables buffering of the CCRx register. This ensures that updates to the CCRx value are synchronized with the timer counter, preventing glitches in the PWM signal.

.. req:: CCxEConfiguration
   :id: REQ_INT3_1733091856
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCxE (Capture/Compare Enable) bit activates the output on the selected timer channel. When this bit is set, the timer output signal is routed to the associated GPIO pin for use in PWM or other timer-based applications.

.. req:: DutyCycleConfiguration
   :id: REQ_INT3_1733093406
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The duty cycle is the percentage of time a PWM signal remains high during one period.
   
   Formula for Duty Cycle (%):
   Duty Cycle = (CCRx / (ARR + 1)) × 100.
   
   Formula for CCRx:
   CCRx = (Duty Cycle × (ARR + 1)) / 100.

   Channel Mapping for CCRx Registers:
     
      - CCR1: Channel 1.
      - CCR2: Channel 2.
      - CCR3: Channel 3.
      - CCR4: Channel 4.

.. req:: TimerControlRegister (TIM_CR1)
   :id: REQ_INT3_1733093427
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIM_CR1 register is responsible for configuring core timer operations, such as counter activation, alignment modes, and update event control. This register ensures proper timer functionality by managing the following operations:
      
      - Counter Activation (CEN bit)
      - Alignment modes

.. req:: Counter Enable (CEN) Bit
   :id: REQ_INT3_1733091570
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CEN (Counter Enable) bit in the TIM_CR1 register controls the start and stop of the timer counter:
      
      - Set to 1: Starts the timer counter, allowing it to increment based on the configured clock frequency, prescaler, and ARR values.
      - Set to 0: Stops the timer counter, halting PWM signal generation or other timer-based operations.
