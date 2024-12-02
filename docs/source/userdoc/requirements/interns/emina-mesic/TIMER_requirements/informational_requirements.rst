Informational Requirements for the Timer Module
=================================================

.. req:: label
   :id: REQ_INT3_1732897578
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Timers in the STM32F411 microcontroller are versatile components used for precise time-related tasks. They help with measuring elapsed time, generating pulses, and controlling time-based processes. 

.. req:: label
   :id: REQ_INT3_1732897596
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The STM32 microcontrollers include general-purpose timers, advanced-control timers (for PWM), and  dedicated timers.

.. req:: label
   :id: REQ_INT3_1732897628
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   General-purpose timers TIM2, TIM3, TIM4, and TIM5 are versatile and support PWM generation, input capture, output compare, and event counting. 

.. req:: label
   :id: REQ_INT3_1732897641
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The advanced-control timer TIM1 is designed for complex tasks like motor control and advanced PWM generation with features like complementary outputs and dead-time insertion. 

.. req:: label
   :id: REQ_INT3_1732897656
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Complementary outputs refer to two outputs that are opposite in polarity, typically used in applications like motor control or H-bridge circuits, where one output is high while the other is low. 

.. req:: label
   :id: REQ_INT3_1732897673
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Dead-time insertion introduces a small delay between switching the complementary outputs to prevent short circuits, ensuring that both outputs are never high simultaneously.

.. req:: label
   :id: REQ_INT3_1732897701
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Smaller dedicated timers TIM9, TIM10, and TIM11 are used for specific purposes, such as single-channel PWM or precise time-based operations.

.. req:: label
   :id: REQ_INT3_1732897713
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   In the STM32F411, APB1 timers include TIM2, TIM3, TIM4, and TIM5, operating at a frequency of up to 50 MHz, while APB2 timers include TIM1, TIM9, TIM10, and TIM11, running at a frequency of up to 100 MHz.

.. req:: label
   :id: REQ_INT3_1732897727
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each timer has dedicated output pins that support alternate functions for tasks like PWM or input capture.

.. req:: label
   :id: REQ_INT3_1732897741
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Timer pins are configured for alternate functions using the AF settings in the GPIO registers.

.. req:: label
   :id: REQ_INT3_1732897783
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Enabling the timer clock for TIM2, TIM3, TIM4, and TIM5 can be done by setting the TIMxEN bit in the RCC_APB1ENR register ('x' represents the timer number).

.. req:: label
   :id: REQ_INT3_1732897798
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   Enabling the timer clock for TIM1, TIM9, TIM10, and TIM11 can be done by setting the TIMxEN bit in the RCC_APB2ENR register ('x' represents the timer number).

.. req:: label
   :id: REQ_INT3_1732897825
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1 has four channels.

.. req:: label
   :id: REQ_INT3_1732897832
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1_CH1 is available on pins PA8 and PE9.

.. req:: label
   :id: REQ_INT3_1732897858
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1_CH2 is available on pins PA9 and PE11.

.. req:: label
   :id: REQ_INT3_1732897998
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1_CH3 is available on pins PA10 and PE13.

.. req:: label
   :id: REQ_INT3_1732898008
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1_CH4 is available on pins PA11 and PE14.

.. req:: label
   :id: REQ_INT3_1732898041
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM2 has four channels.

.. req:: label
   :id: REQ_INT3_1732898061
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM2_CH1 is available on pins PA0, PA5, and PA15.

.. req:: label
   :id: REQ_INT3_1732898232
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM2_CH2 is available on pins PA1 and PB3.

.. req:: label
   :id: REQ_INT3_1732898242
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   TIM2_CH3 is available on pins PA2 and PB10.

.. req:: label
   :id: REQ_INT3_1732898269
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM2_CH4 is available on pins PA3 and PB11.

.. req:: label
   :id: REQ_INT3_1732898293
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM3 has four channels.

.. req:: label
   :id: REQ_INT3_1732898318
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM3_CH1 is available on pins PA6, PB4, and PC6.

.. req:: label
   :id: REQ_INT3_1732898407
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM3_CH2 is available on pins PA7, PB5, and PC7.

.. req:: label
   :id: REQ_INT3_1732898417
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM3_CH3 is available on pins PB0 and PC8.

.. req:: label
   :id: REQ_INT3_1732898436
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM3_CH4 is available on pins PB1 and PC9.

.. req:: label
   :id: REQ_INT3_1732898513
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM4 has four channels.

.. req:: label
   :id: REQ_INT3_1732898525
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM4_CH1 is available on pins PB6 and PD12.

.. req:: label
   :id: REQ_INT3_1732898536
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM4_CH2 is available on pins PB7 and PD13.

.. req:: label
   :id: REQ_INT3_1732898550
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM4_CH3 is available on pins PB8 and PD14.

.. req:: label
   :id: REQ_INT3_1732898597
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM4_CH4 is available on pins PB9 and PD15.

.. req:: label
   :id: REQ_INT3_1732898631
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM5 has four channels.

.. req:: label
   :id: REQ_INT3_1732898653
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM5_CH1 is available on pin PA0.

.. req:: label
   :id: REQ_INT3_1732898686
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM5_CH2 is available on pin PA1.

.. req:: label
   :id: REQ_INT3_1732898690
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM5_CH3 is available on pin PA2.

.. req:: label
   :id: REQ_INT3_1732898715
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM5_CH4 is available on pin PA3.

.. req:: label
   :id: REQ_INT3_1732898740
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM9 has two channels.

.. req:: label
   :id: REQ_INT3_1732898755
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM9_CH1 is available on pins PA2 and PE5.

.. req:: label
   :id: REQ_INT3_1732898773
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM9_CH2 is available on pins PA3 and PE6.

.. req:: label
   :id: REQ_INT3_1732898806
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM10 has one channel.

.. req:: label
   :id: REQ_INT3_1732898818
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM10_CH1 is available on pin PB8.

.. req:: label
   :id: REQ_INT3_1732898832
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM11 has one channel.

.. req:: label
   :id: REQ_INT3_1732898842
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM11_CH1 is available on pin PB9.

.. req:: label
   :id: REQ_INT3_1732899018
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each timer in the STM32F411 can have up to two Capture/Compare Mode Registers (CCMRs), depending on how many channels the timer supports. 

.. req:: label
   :id: REQ_INT3_1732899027
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMx_CCMR1 register is used to configure channels 1 and 2. ('x' represents the timer number)

.. req:: label
   :id: REQ_INT3_1732899023
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMx_CCMR2 register is responsible for configuring channels 3 and 4. ('x' represents the timer number)

.. req:: label
   :id: REQ_INT3_1732899087
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCMR register configures the timer channels, including PWM mode, output compare settings, and capture/compare functionality. 

.. req:: label
   :id: REQ_INT3_1732899073
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMx_CCMRy register bits include OCxM (output compare mode) and OCxPE (preload enable).('x' represents the timer number, 'y' depends on the channel)

.. req:: label
   :id: REQ_INT3_1732899068
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Pulse Width Modulation (PWM) is a technique for generating variable output signals by modifying the duty cycle. In STM32F411, PWM signals are created using timers, which control the output on specific GPIO pins.

.. req:: label
   :id: REQ_INT3_1732899062
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Duty Cycle is the percentage of time the signal remains high during one cycle. For instance, a 50% duty cycle means the signal is high for half of its period.

.. req:: label
   :id: REQ_INT3_1732899058
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Frequency defines how many times the PWM signal cycles from high to low per second.

.. req:: label
   :id: REQ_INT3_1732899054
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Period defines the length of time for one full cycle of the signal — from the start of one pulse to the start of the next pulse.

.. req:: label
   :id: REQ_INT3_1732899218
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   PWM generation can use different modes, such as edge-aligned or center-aligned mode, typically configured using advanced-control timers like TIM1.

.. req:: label
   :id: REQ_INT3_1732899229
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The center-aligned mode is a timer mode used to generate a symmetric PWM signal. In this mode, the timer counts up to a specified value and then counts back down, completing a full cycle within the PWM period.

.. req:: label
   :id: REQ_INT3_1732899244
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The edge-aligned mode is a timer mode used to generate a standard PWM signal. In this mode, the timer counts in a single direction (either up or down) during the PWM period.

.. req:: label
   :id: REQ_INT3_1732899288
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   To set the PWM frequency, the prescaler and ARR registers need to be configured. These two parameters together define the period and frequency of the PWM signal.

.. req:: label
   :id: REQ_INT3_1732899281
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The timer frequency depends on the APB bus the timer is on (either 50 MHz or 100 MHz).

.. req:: label
   :id: REQ_INT3_1732899273
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The period of the PWM signal is calculated by dividing the timer frequency by the desired PWM signal frequency. Period = Timer Frequency / Desired Frequency. 

.. req:: label
   :id: REQ_INT3_1732899266
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The prescaler reduces the timer frequency to ensure the PWM signal period falls within the valid range of 0 to 65535 for a 16-bit timer. 

.. req:: label
   :id: REQ_INT3_1732899259
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   ARR is the Auto-Reload Register value that determines the timer period.

.. req:: label
   :id: REQ_INT3_1732899328
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The formula for calculating the prescaler: Prescaler = Timer Frequency / (Desired Frequency * Max ARR). Where Max ARR is 65535. 

.. req:: label
   :id: REQ_INT3_1732902472
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The prescaler can be set between 0 and 65535.

.. req:: label
   :id: REQ_INT3_1732899344
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The ARR value is calculated using the formula: ARR = [Timer Frequency / (Desired Frequency * Prescaler) ] − 1.

.. req:: label
   :id: REQ_INT3_1732902534
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The ARR value can be set between 0 and 65535 (for a 16-bit timer).

.. req:: label
   :id: REQ_INT3_1732899371
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Prescaler Register (TIMx_PSC) stores the calculated prescaler value. ('x' represents the timer number)

.. req:: label
   :id: REQ_INT3_1732899364
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Auto-Reload Register (TIMx_ARR) stores the calculated ARR value. ('x' represents the timer number)

.. req:: label
   :id: REQ_INT3_1732899356
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCR (Capture/Compare Register) determines the duty cycle of the PWM signal.

.. req:: label
   :id: REQ_INT3_1732899353
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCR (Capture/Compare Register) value is calculated as: CCR = [Duty Cycle * (ARR+1)] / 100.

.. req:: label
   :id: REQ_INT3_1732899348
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The calculated CCR value is written into the corresponding TIMx_CCRy register. ( 'x' represents the timer number, 'y' is the channel number)

.. req:: label
   :id: REQ_INT3_1732899403
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The TIMx_CR1 register is the main control register for configuring and controlling the timer's behavior. ('x' represents the timer number) 

.. req:: label
   :id: REQ_INT3_1732899412
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIMx_CR1_CEN (Counter Enable) bit controls whether the timer is running or stopped. ('x' represents the timer number)

.. req:: label
   :id: REQ_INT3_1732899426
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   CCER (Capture/Compare Enable Register) register enables the activation of channels for output functionality. 

.. req:: label
   :id: REQ_INT3_1732899438
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The CCER register determines the operating mode of the channel, such as PWM, input capture, or output signal for time measurement.

.. req:: label
   :id: REQ_INT3_1732899398
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM_CCER_CCyE bit is used to enable the timer channels for output. ('y' represents the channel number)
