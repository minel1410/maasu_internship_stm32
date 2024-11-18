============
Timer Lesson
============

Overview of Timers
------------------

Timers are essential peripherals in microcontrollers, including the STM32F411, that offer precise timing and counting functionalities. 
In applications requiring time delays, signal generation, or event counting, timers provide versatility and efficiency.

Timer Modes in STM32F411
------------------------

1. **Basic Mode**: 
   - Ideal for generating periodic interrupts and simple time delays.
   - Common in software timing applications requiring precision interrupts.

2. **Capture/Compare Mode**: 
   - Allows capturing external events and comparing internal counter values.
   - Suitable for measuring frequency, input capture for timing, or precise waveform generation.

3. **PWM (Pulse Width Modulation) Mode**: 
   - Generates PWM signals with adjustable frequency and duty cycle.
   - Applications include motor control and LED dimming.

4. **Encoder Mode**: 
   - Used for rotary encoder inputs to track rotational motion.
   - Applied in robotics, motor positioning, and motion tracking.

Key Timer Configurations for PWM Signal Generation
--------------------------------------------------

1. **Timer Frequency**: 
   - Derived from the microcontroller clock and prescaler.
   - Formula: ``Timer Frequency = Timer Clock / (Prescaler + 1)``

2. **PWM Frequency**: 
   - Defined by the auto-reload register (ARR) for the PWM period.
   - Formula: ``PWM Frequency = Timer Frequency / (ARR + 1)``

3. **Duty Cycle**: 
   - Controlled by the capture/compare register (CCR) to set high-time percentage.
   - Formula: ``Duty Cycle (%) = (CCR / (ARR + 1)) * 100``

4. **Output Mode**: 
   - Configures PWM output on designated pins.

Practical Example: Configuring PWM Signal Generation
----------------------------------------------------

This example configures Timer 3 on the STM32F411 to generate a PWM signal with a frequency of 1 kHz and a duty cycle of 50%.

**Example Setup**:
- Timer: Timer 3, Channel 1
- System Clock: 84 MHz
- Desired PWM Frequency: 1 kHz
- Desired Duty Cycle: 50%

.. code-block:: c

    // Enable Timer 3 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Configure the prescaler for 1 MHz timer frequency
    TIM3->PSC = 83;

    // Set ARR for 1 kHz PWM frequency
    TIM3->ARR = 999;

    // Set CCR1 for a 50% duty cycle
    TIM3->CCR1 = 500;

    // Configure PWM mode on channel 1 and enable output
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_PWM1;
    TIM3->CCER |= TIM_CCER_CC1E;

    // Start Timer 3
    TIM3->CR1 |= TIM_CR1_CEN;

**Explanation**:

1. Timer Clock Enable: Enables Timer 3.
2. Prescaler Configuration: Divides the clock for 1 MHz frequency.
3. ARR: Sets PWM frequency to 1 kHz.
4. CCR1: Sets duty cycle to 50%.
5. Start Timer: Finalizes configuration.

Applications of PWM Generation
------------------------------

1. **Motor Speed Control**: Vary duty cycle for speed adjustments.
2. **LED Brightness Control**: Adjust brightness with varying duty cycles.
3. **Audio Signal Generation**: Generate tones or modulate signals for transmission.
