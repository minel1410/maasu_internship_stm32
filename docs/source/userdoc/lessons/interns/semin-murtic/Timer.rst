.. _Timer:


=====
Timer
=====

Overview
========
Timers on the STM32F411 microcontroller are used for various purposes, including measuring time, generating precise time intervals, creating signals, and managing time-dependent processes. The STM32F411 has several timers (e.g., TIM1, TIM2, TIM3, etc.) that can be used for different tasks such as generating PWM signals, triggering interrupts based on time intervals, and more.

Timer Functionalities
=====================
1. **Time Measurement:**
   Timers are used to count time intervals. The STM32F411 timer can use either the system clock or an external signal to trigger the counter, which can then generate time-based interrupts or execute processes based on time.

2. **Pulse Generation:**
   Timers can generate precise pulses with defined periods and frequencies, often used for applications like PWM.

3. **Interrupts:**
   Timers allow generating interrupts when the counter reaches a predefined value.

Timer Use Cases
===============
- **Generating Accurate Time Intervals:**
  Timers can be used for creating delays or controlling the execution speed of programs. They provide precise time intervals for various tasks.

- **Managing Time-Dependent Processes:**
  For example, a timer can trigger specific functions at regular time intervals, such as activating an event every few milliseconds.

PWM (Pulse Width Modulation)
=============================
PWM is a technique used to generate variable output signals with different duty cycles (the percentage of time the signal is high). On STM32F411, PWM can be generated using timers, which control output signals on GPIO pins.

Key PWM Parameters
==================
- **Duty Cycle:**
  The duty cycle of a PWM signal represents the percentage of time the signal is high (active) within one period. For example, a 50% duty cycle means the signal is high for 50% of the time and low for the other 50%.

- **Frequency:**
  The frequency of the PWM signal determines how many times per second the signal transitions between high and low states. On STM32F411, the frequency is determined by the timer's period.

PWM Applications
================
- **Motor Speed Control:**
  PWM signals can be used to control the speed of DC motors. Increasing the duty cycle increases the motor's speed, while decreasing it slows the motor down.

- **LED Brightness Control:**
  PWM is used to control the brightness of LEDs. Increasing the duty cycle makes the LED brighter, and decreasing it makes the LED dimmer.

- **Sound Generation:**
  PWM can be used to generate sound signals of different frequencies and tones.

- **Servo Motor Control:**
  PWM can also be used to regulate the position of a servo motor by varying the duty cycle.

PWM Initialization Process
==========================
1. **Enable the Timer Clock:**
   Enable the clock for the appropriate timer to ensure it functions correctly. Each timer has a corresponding bit in the RCC (Reset and Clock Control) register, which must be set to activate the timer.
   Example: For TIM1, set `RCC_APB2ENR_TIM1EN`, and for TIM2, set `RCC_APB1ENR_TIM2EN`.

2. **Configure GPIO Pins:**
   Select the appropriate GPIO pins for the timer's function and enable the alternate functions (AF) for those pins. Refer to the datasheet for detailed pin mappings and alternate functions.

3. **Set Frequency and Duty Cycle:**
   To set the frequency, adjust the **Prescaler** and **ARR** (Auto-Reload Register). The **Prescaler** divides the timer clock, and the **ARR** defines the period of the PWM signal. The duty cycle is set by adjusting the **CCR** (Capture/Compare Register), which controls how long the signal stays high during each period.

4. **Enable PWM Mode:**
   Enable the output compare mode and configure the timer's channels for PWM output. This is done through the **CCMR** (Capture/Compare Mode Register) and **CCER** (Capture/Compare Enable Register).

Timer Frequency and Prescaler Calculation
=========================================
1. **Determine Timer Frequency:**
   STM32F411 timers on different APBs (APB1 or APB2) run at different clock frequencies:
   - Timers on APB1 (e.g., TIM2, TIM3, TIM4, TIM5) run at 50 MHz.
   - Timers on APB2 (e.g., TIM1, TIM9, TIM10, TIM11) run at 100 MHz.

2. **Calculate Timer Period and PWM Frequency:**
   To set the desired PWM frequency, the timer's period is calculated by dividing the timer's clock frequency by the desired PWM frequency:
   - `Period = Timer Frequency / Desired PWM Frequency`

   Example: If you want a PWM frequency of 1 kHz using a 50 MHz timer:
   - `Period = 50,000,000 / 1,000 = 50,000`

3. **Set Prescaler and ARR:**
   - The prescaler divides the timer frequency to ensure the period fits within the valid range of the timer's ARR (Auto-Reload Register). If the calculated period exceeds the timer's maximum value (65535 for a 16-bit timer), the prescaler is adjusted.
   - `Prescaler = Timer Frequency / (Desired Frequency * Max ARR)`
   - `ARR = [(Timer Frequency) / (Desired Frequency * Prescaler)] - 1`

4. **Write Values to Registers:**
   - **Prescaler Register (PSC):** Set the prescaler value.
   - **ARR Register:** Set the calculated period value.

Duty Cycle Calculation
======================
The duty cycle defines how long the signal stays high in each period. For instance, a 25% duty cycle means the signal is high for 25% of the period.

1. **Duty Cycle Calculation:**
   The **CCR** (Capture/Compare Register) value that defines the duty cycle is calculated as:
   - `CCR = (Duty Cycle * (ARR + 1)) / 100`

   Example: For a 25% duty cycle and an ARR value of 2500:
   - `CCR = (25 * (2500 + 1)) / 100 = 625`

2. **Set CCR:**
   Write the calculated **CCR** value to the appropriate **CCR** register (e.g., CCR1, CCR2, etc.).

Center-Aligned vs. Edge-Aligned Mode
====================================
1. **Center-Aligned Mode:**
   In this mode, the timer counts both upwards and downwards within the PWM period, generating a symmetric signal.

2. **Edge-Aligned Mode:**
   In this mode, the timer counts from 0 to ARR, and when it reaches ARR, it resets, producing a signal with transitions at the edges of the period. This is the default mode for PWM generation.

Example: Generating a 20 kHz PWM with a 25% Duty Cycle on TIM3
================================================================
1. **Enable Clock:** Set `RCC_APB1ENR_TIM3EN` to enable the clock for TIM3 (50 MHz).
2. **Configure GPIO Pins:** Set the alternate function for PB0 to AF2 (for TIM3).
3. **Set PWM Mode:** Clear the appropriate bits in the **CCMR2** register for channel 3. Enable **OC3PE** for stable PWM operation.
4. **Set Frequency:**
   - `Period = 50,000,000 / 20,000 = 2500`
   - `Prescaler = 0` (since the period is within the 16-bit range).
   - `ARR = 2500 - 1 = 2499`
5. **Calculate Duty Cycle:**
   - `CCR = (25 * (2499 + 1)) / 100 = 625`
   Write 625 to **CCR3**.
6. **Enable PWM:** Set `TIM_CR1_CEN` to start the timer and enable PWM output.