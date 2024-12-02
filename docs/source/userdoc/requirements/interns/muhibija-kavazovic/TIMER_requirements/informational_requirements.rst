--------------------------
Informational requirements
--------------------------

.. req:: label
   :id: REQ_INT3_1732967373
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **The Timer module** is a key peripheral in STM32F411 microcontrollers, designed to perform operations such as delay generation, event counting, frequency measurement, and Pulse Width Modulation (PWM) signal generation.

.. req:: label
   :id: REQ_INT3_1732967420
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Timer modules depend on the **system clock** for their operation. Proper configuration of the system clock is crucial to ensure accurate timing, particularly in applications requiring precise control, such as motor speed regulation and signal generation.

.. req:: label
   :id: REQ_INT3_1733096231
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM1, TIM9, TIM10, and TIM11 are located on the APB2 bus.

.. req:: label
   :id: REQ_INT3_1733096491
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TIM2, TIM3, TIM4, and TIM5 are located on the APB1 bus.

.. req:: label
   :id: REQ_INT3_1733096547
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Each Timer module supports up to four independent channels for PWM signal generation.


.. req:: label
     :id: REQ_INT3_1733144970
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Muhibija Kavazovic
     :modified-by:
     :category: Informational
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     **TIM1 Pin Mapping (AF1)**
      - Channel 1: PA8 (AF1)

      - Channel 2: PA9 (AF1)

      - Channel 3: PA10 (AF1)

      - Channel 4: PA11 (AF1)
  
.. req:: label
   :id: REQ_INT3_1733145222
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM2 Pin Mapping (AF1)**

      - Channel 1: A0 (AF1), PA5 (AF1)

      - Channel 2: PA1 (AF1)

      - Channel 3: PA2 (AF1)

      - Channel 4: PA3 (AF1)

.. req:: label
   :id: REQ_INT3_1733145302
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM3 Pin Mapping (AF2)**

   - Channel 1: PA6, PB4 (AF2)

   - Channel 2: PA7, PB5 (AF2)

   - Channel 3: PB0, PC8 (AF2)

   - Channel 4: PB1, PC9 (AF2)

.. req:: label
   :id: REQ_INT3_1733145369
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM4 Pin Mapping (AF2)**

    - Channel 1: PB6, PD12 (AF2)

    - Channel 2: PB7, PD13 (AF2)

    - Channel 3: PB8, PD14 (AF2)

    - Channel 4: PB9, PD15 (AF2)


.. req:: label
   :id: REQ_INT3_1732967451
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM5 Pin Mapping (AF2)**

    - Channel 1: PA0 (AF2)

    - Channel 2: PA1 (AF2)

    - Channel 3: PA2 (AF2)

    - Channel 4: PA3 (AF2)

.. req:: label
   :id: REQ_INT3_1733146550
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM9 Pin Mapping (AF3)**

    - Channel 1: PA2 (AF3)

    - Channel 2: PA3 (AF3)

.. req:: label
   :id: REQ_INT3_1733146661
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM10 Pin Mapping (AF3)**

    - Channel 1: PB8 (AF3)

.. req:: label
   :id: REQ_INT3_1733146753
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **TIM11 Pin Mapping (AF3)**

    - Channel 1: PB9 (AF3)


.. req:: label
   :id: REQ_INT3_1733146409
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 


   Registers that are key to configuring and operating the Timer Module for generating PWM signals:

   - **Prescaler Register (PSC)**

   - **Auto-Reload Register (ARR)**

   - **Capture/Compare Register (CCR)**

.. req:: label
   :id: REQ_INT3_1732968752
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Prescaler Register (PSC) divides the input clock frequency to achieve a lower timer frequency. The division factor is determined by the value written to the PSC register as PSC+1. 
   For example, if the system clock is **16 MHz** and **PSC=15**, the timer clock becomes 16 MHz/(15+1)= **1 MHz**.

.. req:: label
   :id: REQ_INT3_1732968891
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Auto-Reload Register (ARR) defines the maximum count value the timer can reach before it resets. This value directly determines the period of the PWM signal. For instance, if the timer clock is **1 MHz** and **ARR=999**, the PWM signal period is 1/(999+1)= **1 kHz**.

.. req:: label
   :id: REQ_INT3_1732968992
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Capture/Compare Register specifies the duration the output remains "ON" during one PWM period. This value is calculated based on the input duty cycle and the ARR value: 

    .. math::

      CCR = \left( \frac{\text{Duty Cycle (%)}}{100} \right) \times (ARR + 1)

   For example, if a duty cycle is **25%** and **ARR=999**:

    .. math::

      CCR = \left( \frac{25}{100} \right) \times (999+1) = 250

.. req:: label
   :id: REQ_INT3_1732969125
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Registers used for PWM configuration include:

   - **Capture/Compare Mode Register (CCMR):** Defines the mode of operation (e.g., PWM Mode 1).

   - **Capture/Compare Enable Register (CCER):** Activates or deactivates output for Timer channels.

   - **Control Register (CR1):** Starts or stops the Timer counter.

.. req:: label
   :id: REQ_INT3_1732969319
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Capture/Compare Mode Register (CCMR) controls the configuration of TIMER channels. 
   **TIM_CCMR1** configures channels 1 and 2, while **TIM_CCMR2** configures channels 3 and 4. 
   **PWM Mode 1** is activated by setting the OCxM bits to 110.

   This register defines the mode of operation for each channel, such as PWM mode or input/output signal measurement.

.. req:: label
   :id: REQ_INT3_1732969440
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Capture/Compare Enable Register (CCER) enables or disables output functionalities for specific TIMER channels. Activation fields include:

    - **TIM_CCER_CC1E** for channel 1, 
    - **TIM_CCER_CC2E** for channel 2, 
    - **TIM_CCER_CC3E** for channel 3,
    - **TIM_CCER_CC4E** for channel 4.

.. req:: label
   :id: REQ_INT3_1732969541
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The Control Register (CR1) starts the TIMER counter by setting the CEN bit in the TIM_CR1 register.

.. req:: label
   :id: REQ_INT3_1732969608
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

    PWM frequency is calculated using the following formula:

   .. math::

      f_{PWM} = \frac{f_{TIM}}{(ARR + 1) \times (PSC + 1)}

   Where:

   - **f_TIM:** Timer input clock frequency.
   - **ARR:** Auto-reload register value.
   - **PSC:** Prescaler value.

.. req:: label
   :id: REQ_INT3_1732970657
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Timer channels are independently configurable, allowing simultaneous PWM signal generation with different frequencies and duty cycles. 
   For example, TIM1 supports four channels that can operate independently or in coordination.

.. req:: label
   :id: REQ_INT3_1732971244
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   PWM signals have numerous applications, such as motor speed control, where varying **duty cycles adjust speed**; 
   LED dimming, where **duty cycles control brightness**; and generating signals for communication protocols like UART or SPI.

.. req:: label
   :id: REQ_INT3_1732971670
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Error handling is important to keep the Timer working correctly. 
   Invalid settings, like duty cycles not between 0% and 100%, should be detected and blocked. If the system clock changes, Timer parameters like PSC, ARR, and CCR must be updated to keep the timing accurate.



