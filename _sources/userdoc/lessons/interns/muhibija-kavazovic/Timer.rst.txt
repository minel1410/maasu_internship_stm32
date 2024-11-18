Timer on STM32F411
==================

Overview of Timer Functionality
-------------------------------

Timers in STM32F411 are versatile peripherals used for:

- Generating precise delays

- Measuring input signal characteristics

- Producing PWM (Pulse Width Modulation) signals for motor control or LED brightness adjustment

-----------
Timer Modes
-----------

- Input Capture: Measures signal properties like frequency or pulse width.

- Output Compare: Generates output signals at specific intervals.

- PWM Mode: Generates PWM signals with adjustable frequency and duty cycle.


Key Configurations for PWM Signal Generation
--------------------------------------------

1. **Prescaler**
   - The prescaler divides the timer's clock frequency to reduce it and ensure the PWM signal period falls within a valid range (0–65535 for a 16-bit timer).
   - Formula:

     .. math::

        Prescaler = \frac{Timer\ Frequency}{Desired\ Frequency \times Max\ ARR}

   - If the calculated period exceeds 65535, the prescaler must be increased to reduce the period and fit it within the 16-bit range.

2. **Auto-Reload Register (ARR)**
   - ARR defines the period of the PWM signal and is calculated after setting the prescaler.
   - Formula:

     .. math::

        ARR = \left[ \frac{Timer\ Frequency}{Prescaler \times Desired\ Frequency} \right] - 1

   - The ARR value directly determines the timer’s maximum count value and ensures the PWM signal's accurate period.

3. **Compare Register (CCR)**

   - Determines the duty cycle by specifying how long the signal stays high within one period.

4. **Control Registers**

   - TIM_CR1: Enables the timer and configures basic settings.

   - TIM_CCER: Enables the output compare channel.

   - TIM_CCMR: Configures PWM mode.



Practical Example: Configuring PWM on Timer 2
----------------------------------------------

Configure Timer 2 to generate a PWM signal with a frequency of 1 kHz and a 50% duty cycle, assuming the system clock is 16 MHz.

1. Calculate the Prescaler:

   - Using the formula:

     .. math::

        Prescaler = \frac{Timer\ Frequency}{Desired\ Frequency \times Max\ ARR}

   - Assume Max ARR = 65535 and Desired Frequency = 1000 Hz:

     .. math::

        Prescaler = \frac{16000000}{1000 \times 65535} \approx 2.44

   - Choose Prescaler = 3 (rounding up ensures the frequency fits within the timer range).

2. Calculate the ARR Value:

   - Using the formula:

     .. math::

        ARR = \left[ \frac{Timer\ Frequency}{Prescaler \times Desired\ Frequency} \right] - 1

   - Substituting values:

     .. math::

        ARR = \left[ \frac{16000000}{3 \times 1000} \right] - 1 = 5332

3. Timer Configuration in Code:

   .. code-block:: c

      RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;  // Enable TIM2 clock

      TIM2->PSC = 3 - 1;                   // Set prescaler to 3 (subtract 1 for zero-based indexing)
      TIM2->ARR = 5332;                    // Set ARR for a 1 kHz frequency
      TIM2->CCR1 = 2666;                   // Set CCR1 for 50% duty cycle (ARR / 2)

      TIM2->CCMR1 |= (6 << TIM_CCMR1_OC1M_Pos);  // PWM mode 1
      TIM2->CCER |= TIM_CCER_CC1E;               // Enable output for channel 1

      TIM2->CR1 |= TIM_CR1_CEN;            // Enable the timer


Summary
-------

Timers in STM32F411 are highly configurable and essential for generating PWM signals. The prescaler and ARR values ensure the timer operates within its hardware limits, while CCR adjusts the duty cycle.

