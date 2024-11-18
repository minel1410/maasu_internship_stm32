Timer
========
Timers in STM32 microcontrollers are versatile peripherals used for precise time-based operations, signal generation, and event counting. This lesson covers the initialization, configuration, and application of Pulse Width Modulation (PWM) using timers in the STM32F411 series.

Initialization Process
----------------------

1. **Clock Enablement**:
   - Use the RCC (Reset and Clock Control) registers to enable the timer’s clock.

2. **GPIO Configuration**:
   - Map the timer channels to appropriate GPIO pins in Alternate Function (AF) mode using the datasheet.

3. **PWM Mode Setup**:
   - Configure PWM mode in the Capture/Compare Mode Register (CCMR).
   - Enable the output using the Capture/Compare Enable Register (CCER).

Setting PWM Frequency
---------------------

1. **Determine Timer Clock Frequency**:
   - APB1 timers run at 50 MHz; APB2 timers run at 100 MHz.

2. **Calculate Prescaler and ARR Values**:
   - Use the formula: ``ARR = (Timer Clock / (Frequency * Prescaler)) - 1``.

3. **Configure Timer Registers**:
   - Write the calculated prescaler (PSC) and ARR values to the respective timer registers.

Configuring Duty Cycle
----------------------

1. **Calculate CCR Value**:
   - Formula: ``CCR = (Duty Cycle * (ARR + 1)) / 100``.

2. **Update CCR Registers**:
   - Write the computed value to the channel’s CCR register.

Enabling/Disabling PWM
----------------------

1. **Enable PWM**:
   - Set the timer’s enable bits in the control register.

2. **Disable PWM**:
   - Clear the enable bits to stop PWM output.

Modes: Center-Aligned vs Edge-Aligned
-------------------------------------

- **Edge-Aligned Mode**: Default; the timer counts up to ARR and resets.
- **Center-Aligned Mode**: The timer counts up and down, providing symmetrical signals.

Example: Configuring TIM3 for PWM
---------------------------------

**Objective**: Configure TIM3 Channel 3 to generate a 20 kHz signal with a 25% duty cycle.

1. **Clock Enablement**:
   .. code-block:: c

      RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

2. **GPIO Configuration**:
   .. code-block:: c

      GPIOB->MODER |= (0x2 << (2 * 0)); // Set PB0 as Alternate Function
      GPIOB->AFR[0] |= (0x2 << (4 * 0)); // Set AF2 for TIM3

3. **Set Frequency and ARR**:
   .. code-block:: c

      TIM3->PSC = 0; // No prescaler
      TIM3->ARR = 2499; // For 20 kHz frequency

4. **Set Duty Cycle**:
   .. code-block:: c

      TIM3->CCR3 = 625; // For 25% duty cycle

5. **Enable PWM**:
   .. code-block:: c

      TIM3->CR1 |= TIM_CR1_CEN;

Key Timer Registers
-------------------

- **ARR (Auto-Reload Register)**: Sets timer period.
- **PSC (Prescaler)**: Divides timer clock.
- **CCMR (Capture/Compare Mode Register)**: Configures PWM mode.
- **CCR (Capture/Compare Register)**: Sets duty cycle.

Conclusion
----------

This guide covered PWM configuration for STM32 microcontrollers, including clock enablement, GPIO mapping, and PWM settings. An example demonstrated TIM3’s setup for a specific frequency and duty cycle. Mastering these concepts enables precise control over peripherals in embedded systems.
