=============
Timer
=============

Introduction to Timers
=========================

Timers are peripherals used for time-dependent tasks such as:
- Generating delays.
- Measuring input events.
- Producing PWM (Pulse Width Modulation) signals.

Modes of Timers
=================

1. Basic Mode: Simple time measurement or delays.
2. PWM Mode: Generate PWM signals for controlling motors, LEDs, etc.
3. Capture/Compare Mode: Measure input signal timings or generate output signals with specific delays.

Key Timer Configurations
============================

1. Prescaler (PSC): Divides the input clock frequency to reduce the timer frequency.
2. TimerFrequency=SystemClockPrescaler+1TimerFrequency = \frac{SystemClock}{Prescaler + 1}TimerFrequency=Prescaler+1SystemClock
3. Auto-Reload Register (ARR): Sets the maximum timer count. When the timer reaches this value, it resets and triggers an event.
4. Capture/Compare Register (CCR): Defines the duty cycle in PWM mode.
5. Control Registers:
  - CR1: Enables the timer (CEN bit) and configures counter mode.
  - DIER: Enables interrupts (e.g., update interrupt via UIE bit).

Example
===========
Configure TIM3 to generate a PWM signal with a frequency of 20 kHz and a 25% duty cycle. TIM3 is on APB1 bus which has a max frequency of 50 MHz.
1. Enable Clock - RCC_APB1ENR_TIM3EN to enable the clock for TIM3.
2. Configure GPIO pins - Set the correct pin to alternate function for TIM3.
3. Set PWM mode - Clear bits in CCMR2 register for channel 3 and enable OC3PE.
4. Set frequency - Period = Timer Frequency / Desired Frequency
In this case Period = 50000000 / 20000 , which results in 2500.
ARR = Period - 1
5. Calculate duty cycle - CCR = (Duty Cycle x (ARR + 1)) / 100
In this case, the result is 625 and we write it in CCR3.
6. Enable PWM - Set TIM_CR1_CEN to start the timer and enable PWM output.