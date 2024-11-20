STM32F411 Timer
===============

Introduction
------------

Timers on the STM32F411 microcontroller are essential components used to handle a variety of time-related tasks, such as precise time measurement, signal generation, and control of processes requiring defined time intervals.
 The STM32F411 features several timers (like TIM1, TIM2, TIM3, etc.), which can be configured for a wide range of applications. These include generating Pulse Width Modulation (PWM) signals for motor control, creating accurate delays, and triggering interrupts based on specific timing events.
 Additionally, timers support advanced functions like input capture and output compare, making them versatile tools in embedded systems.

Functionalities of STM32 Timer
------------------------------

**Functionalities:**

Time Measurement: The timer on the STM32F411 can be configured to count time intervals accurately, using either the system clock or an external signal as a reference. This allows for precise timing operations, such as generating time-based interrupts to execute specific tasks or processes at set intervals.
Pulse Generation: Timers can produce pulses with a defined period and frequency. This is particularly useful for applications requiring PWM (Pulse Width Modulation) signals, commonly used for motor control or LED brightness adjustments.
Interrupts: Timers are capable of triggering interrupts when the counter reaches a specified value, enabling timely execution of interrupt service routines for handling events or processes. Additionally, timers support advanced modes like input capture (for measuring signal timing) and output compare (for event synchronization), making them flexible for various real-time applications.

**Advantages:**

1. **Time Measurement:** Ensures accurate timing for periodic interrupts and time-based task management.
2. **Pulse Generation:** Provides precise control over pulse signals, critical for motor speed regulation or LED dimming.
3. **Interrupt Handling:** Facilitates responsive handling of tasks and synchronization using advanced modes like input capture and output compare.

Pulse Width Modulation (PWM)
----------------------------

PWM is a technique used to create variable output signals by adjusting the duty cycle, which is the percentage of time the signal remains active in a given period. On the STM32F411, PWM generation is managed by timers that control signal output on GPIO pins. This method is essential for controlling motors, adjusting LED brightness, or any application requiring precise signal modulation. 
The timers in STM32F411 can be configured to produce PWM signals with different frequencies and duty cycles, offering flexibility for diverse real-time applications.
**Parameters:**

1. **Duty Cycle:** Percentage of the period the signal remains high.
   - Example: A 50% duty cycle results in equal high/low intervals.
2. **Frequency:** Determines how many cycles occur per second, controlled by the timer's period settings.

**Use Cases:**

Motor Speed Control: PWM signals are used to control the speed of DC motors effectively. By adjusting the duty cycle, the average voltage applied to the motor is varied, thus increasing or decreasing the motor speed. A higher duty cycle results in a faster motor, while a lower duty cycle reduces the speed.
LED Brightness Control: PWM can modulate LED brightness by altering the duty cycle. A higher duty cycle makes the LED brighter, whereas a lower duty cycle dims the LED.
Audio Signals: PWM can generate audio signals of varying frequencies, useful for creating tones and beeps in devices.
Servo Motor Positioning: PWM is also essential in positioning servo motors. By setting the pulse width precisely, the servo motor's angle can be controlled accurately, crucial for applications in robotics and automated systems.

Process of Initialization
--------------------------

**Main Steps:**

  **1.Enabling the Clock for the TIMER: Before configuring the TIMER, ensure that the appropriate clock signal is enabled using the RCC registers. This step powers the timer and makes it ready for configuration.**
  **2.Configuring the Corresponding GPIO Pins: Set the GPIO pins in the alternate function mode to handle PWM output signals. These pins should be mapped correctly to the timer channels.**
  **3.Setting the Frequency: Configure the timer's prescaler and auto-reload register to set the desired frequency of the PWM signal, ensuring precision based on your application's requirements.**
  **4.Adjusting the Duty Cycle: Define the pulse width by setting the timer's capture/compare register. The duty cycle controls the "active" time of the signal, essential for applications like motor speed or LED brightness control.**
  **5.Configuring PWM Mode: Set the timer in PWM mode, which defines how the timer generates the PWM signal. Make sure to select the correct mode and enable the timer to start generating the signal.**
Configuration
-------------

Enabling a Clock for a Timer:

To enable a timer on the STM32 microcontroller, it's essential to activate the corresponding clock source. Each timer has a unique bit in the RCC (Reset and Clock Control) register that must be set to provide power and start its operation. Setting the appropriate bit in the RCC register allows the timer to receive power and become operational.
For example, enabling TIM1 requires setting the RCC_APB2ENR_TIM1EN bit in the APB2ENR register, while TIM2 requires setting the RCC_APB1ENR_TIM2EN bit in the APB1ENR register. This ensures that the desired timer receives the necessary clock signal to function effectively.
**Configuration of GPIO Pins:**

To ensure proper configuration based on the selected TIMER, it is crucial to enable the correct GPIO pins and assign appropriate alternate functions to these pins. This step allows the TIMER's output or input signals to function correctly. For reference, the STM32F411 datasheet or the corresponding documentation on the official GitHub repository provides a comprehensive overview of pin mapping and alternate functions, detailing which pins should be configured for specific TIMER operations.
**Configuration of PWM Mode:**

- **Capture/Compare Mode Register (CCMR):**
  - Configures timer channels for PWM generation.
  - **TIM_CCMR1:** Controls channels 1 and 2.
  - **TIM_CCMR2:** Controls channels 3 and 4.

- **Capture/Compare Enable Register (CCER):**
  - Enables output for channels.
  - **TIM_CCER_CC1E:** Enables channel 1 output.
  - **TIM_CCER_CC2E:** Enables channel 2 output.

**Duty Cycle:**

The **duty cycle** determines the high-state duration as a percentage of the total period. It is calculated using:

.. image:: path_to_image

Where **ARR** is the auto-reload register. Load the calculated value into the capture/compare register (CCR).

CA and EA Modes
---------------

**Center-Aligned Mode:**
The center-aligned mode allows for a symmetric PWM signal because the timer counts both up and down within the PWM period. This configuration creates a waveform symmetric around the center of the period. This setup is ideal for generating balanced signals and can be adjusted using appropriate control bits in the timer register.
**Edge-Aligned Mode:**
In the edge-aligned mode, the timer counts from zero up to the ARR value and then resets, creating waveforms with transitions at the edges of the period. This is the default mode for most PWM configurations and can also be set using specific control bits in the timer register.

Example
-------

**Generating a PWM Signal (20 kHz, 25% Duty Cycle) Using TIM3**

1. **Enable the Clock for TIM3:**
   - Set `RCC_APB1ENR_TIM3EN` in the RCC register.

2. **Configure GPIO Pins:**
   - Set PA6 (TIM3 Channel 1) in alternate function mode (AF).
   - Configure the pin in `GPIOx_AFR`.

3. **Set Frequency:**
   - Use the formula for PWM frequency to calculate prescaler (PSC) and auto-reload register (ARR).

   .. image:: path_to_frequency_formula

   Example Values:
   - **PSC:** 83
   - **ARR:** 49

4. **Set Duty Cycle:**
   - Calculate the CCR value for 25% duty cycle.

   .. image:: path_to_duty_cycle_formula

   Example Value:
   - **CCR:** 12

5. **Configure TIM3 in PWM Mode:**
   - Set PWM mode in `TIM3_CCMR1`.
   - Enable the channel in `TIM3_CCER`.
   - Start the timer by setting `TIM3_CR1`.

This configuration generates a PWM signal with a 20 kHz frequency and a 25% duty cycle on TIM3 Channel 1.