Timers in STM32 
=========================

Timers in the STM32F411 microcontroller are versatile components used for precise time-related tasks. They help with measuring elapsed time, generating pulses, and controlling time-based processes. The STM32F411 has several timers (e.g., TIM1, TIM2, TIM3), and each can be configured for different uses, such as PWM signal generation, managing interrupts, or creating precise delays.

Key Timer Functions and Applications
-------------------------------------

Timers in STM32F411 are primarily used for:
  1. **Measuring Time**: Timers can count up or down based on a clock signal, either from the system clock or an external source. This is useful for tracking time intervals and generating events based on elapsed time
  
  2. **Pulse Generation**: By configuring a timer, you can generate pulses at specific frequencies and durations, which is crucial for tasks like producing PWM signals
  
  3. **Interrupt Handling**: Timers can be set to trigger an interrupt when they reach a specific value, allowing the microcontroller to respond immediately to time-based events


**Applications**:
  - Generating fixed time intervals for delays
 
  - Handling tasks that need precise timing (e.g., motor control or LED dimming)


Introduction to PWM (Pulse Width Modulation)
---------------------------------------------

**Pulse Width Modulation (PWM)** is a technique used to generate variable output signals by adjusting the duty cycle, which is the percentage of time the signal is high within one cycle. In STM32F411, PWM signals are created using timers, which control the output on specific GPIO pins.

**Key PWM Parameters**:
  - **Duty Cycle**: The percentage of time the signal remains high during one cycle. For instance, a 50% duty cycle means the signal is high for half of its period
  
  - **Frequency**: Defines how many times the PWM signal cycles from high to low per second. This is determined by the timer’s period settings


**Common Uses**:

  - **Motor Speed Control**: Changing the duty cycle adjusts the power delivered to the motor, influencing its speed
  
  - **LED Brightness Control**: The duty cycle affects the brightness of the LED, with a higher duty cycle resulting in a brighter output

  - **Audio Signal Generation**: PWM can be used to produce audio signals with different tones and frequencies


Setting Up PWM in STM32F411 
In this example, we will configure TIM3 to generate a PWM signal with a frequency of 20 kHz and a duty cycle of 25%. Below are the step-by-step configurations, including the required register settings and calculations.

1. **Enabling the Timer Clock**
Enable the clock for TIM3 by setting the RCC_APB1ENR_TIM3EN bit. This timer operates on the APB1 bus, which has a clock frequency of 50 MHz.

2. **Configuring GPIO Pins**
Set PB0 to Alternate Function 2 (AF2) to use TIM3 Channel 3. This pin needs to be configured as an output in alternate function mode to enable PWM output.
 
3. **Configuring PWM Mode**
  1. Clear the bits in the CCMR2 register for Channel 3.
  2. Enable the OC3PE bit to activate the preload register, ensuring stable PWM signals and preventing glitches when adjusting the duty cycle.
 
4.  **Calculating the PWM Frequency**
The PWM frequency is determined by the timer period, which depends on the clock frequency and the values of the prescaler and Auto-Reload Register (ARR). The formula to calculate the period is:
    *Period = Timer Clock / Frequency*

For a 20 kHz signal with a 50 MHz clock:
    *Period = 50 000 000 / 20,000 = 2500*

Since the calculated period (2500) is within the 16-bit range (0-65535), we can set the prescaler to 0. Thus: 
- **PSC = 0** 
- **ARR = Period – 1 = 2499** 
 
5.  **Calculating the Duty Cycle**
The duty cycle determines how long the signal remains high during each PWM period. The value is set using the Capture/Compare Register (CCR). The formula for the CCR value is:
    *CCR = (25 * (ARR + 1)) / 100 = (25 * 2500) / 100 = 625*

Write this value to the CCR3 register for Channel 3.
 
6. **Enabling PWM Output**
Finally, start the timer by setting the TIM_CR1_CEN bit in the control register. 