================================
GPIO Firmware for STM32F411 MCU
================================

1. What is GPIO?
----------------

In the STM32F411 microcontroller, the GPIO (General Purpose Input/Output) functionality
allows the user to configure pins as either input or output. This flexibility is fundamental for
interfacing the microcontroller with external devices such as LEDs, switches, sensors, and
other peripherals. Each GPIO pin can be individually configured with various parameters like
mode, output type, speed, and pull-up/pull-down resistors.

2. GPIO Functionality and Configuration
---------------------------------------

Each GPIO pin on the STM32F411 has several modes, configurable via registers:

- **Input mode**: Used for reading external signals.
- **Output mode**: Used to drive external devices, like LEDs or relays.
- **Alternate Function mode**: Used when a pin is designated for a specific peripheral (e.g.,
  UART, I2C, SPI).
- **Analog mode**: Used for analog input/output (e.g., ADC).

**Key Configurations:**

- **Pin Mode (Input/Output/Alternate/Analog)**: Configured in the GPIOx_MODER register.
- **Output Type (Push-pull/Open-drain)**: Configured in the GPIOx_OTYPER register.
- **Speed (Low/Medium/High/Very High)**: Configured in the GPIOx_OSPEEDR register.
- **Pull-up/Pull-down Resistors**: Configured in the GPIOx_PUPDR register to avoid floating inputs.

These configurations enable users to control individual pin behavior based on the connected
external device requirements.

3. GPIO Output Registers: ODR and BSRR
--------------------------------------

The STM32F411 microcontroller has several registers for managing the output on GPIO pins,
with the Output Data Register (ODR) and Bit Set/Reset Register (BSRR) being the primary ones.

### Output Data Register (ODR)

The **GPIOx_ODR** is a 16-bit register used to set or clear the output level of each GPIO pin in one
operation. Writing `1` or `0` to a specific bit in this register sets the corresponding pin to HIGH or
LOW, respectively.

- **Usage**: Directly writing to ODR controls all pins at once. If you want to control multiple pins
  simultaneously, ODR is efficient.
- **Example**: To turn on a specific pin (e.g., GPIOA pin 5), you could set the corresponding bit in
  ODR to `1`. For instance, `GPIOA->ODR |= (1 << 5);` would set pin 5 to HIGH.

### Bit Set/Reset Register (BSRR)

The **GPIOx_BSRR** is a 32-bit register that allows setting and resetting individual bits atomically.
This register provides two 16-bit halves:

- **Lower 16 bits (BS)**: Used to set pins to HIGH.
- **Upper 16 bits (BR)**: Used to reset pins to LOW.

Unlike ODR, the BSRR register is designed for atomic operations, meaning you can
simultaneously set and reset bits without affecting other bits. This is particularly useful for
avoiding unintentional changes when multiple bits need to be controlled.

- **Usage**: To set a pin to HIGH, write `1` to the bit in the lower half (BS). To reset (clear) a pin,
  write `1` to the corresponding bit in the upper half (BR).
- **Example**:
  - Set GPIOA pin 5: `GPIOA->BSRR = (1 << 5);`
  - Reset GPIOA pin 5: `GPIOA->BSRR = (1 << (5 + 16));`

4. Differences Between ODR (Output Data Register) and BSRR (Bit Set/Reset Register)
------------------------------------------------------------------------------------

The Output Data Register (ODR) and the Bit Set/Reset Register (BSRR) both control GPIO pin
outputs, but they have key differences in functionality, safety, and practical applications.

**Comparison of ODR and BSRR**

+-------------------------+--------------------------------------------+---------------------------------------------+
| **Aspect**             | **ODR (Output Data Register)**             | **BSRR (Bit Set/Reset Register)**           |
+=========================+============================================+=============================================+
| **Function**            | Controls pin states by directly setting or | Allows atomic setting and resetting of pins |
|                         | clearing bits in the register.             | through independent bit sections.           |
+-------------------------+--------------------------------------------+---------------------------------------------+
| **Atomicity**           | Non-atomic operation; affects all 16 bits  | Atomic operation; independently sets or     |
|                         | at once, which can cause unintended        | clears bits, avoiding unintended changes.   |
|                         | interference in concurrent contexts.       |                                             |
+-------------------------+--------------------------------------------+---------------------------------------------+
| **Structure**           | 16-bit register controlling HIGH/LOW state | 32-bit register with two 16-bit halves:     |
|                         | for each pin in a GPIO port.               | lower half (BS) to set bits and upper half  |
|                         |                                            | (BR) to reset bits.                         |
+-------------------------+--------------------------------------------+---------------------------------------------+
| **Best Use**            | Efficient for setting multiple pins        | Ideal for independent pin control, especially|
|                         | simultaneously when atomicity is not       | in real-time or multitasking applications   |
|                         | required.                                  | where atomic operations are essential.      |
+-------------------------+--------------------------------------------+---------------------------------------------+
| **Operation**           | Requires read-modify-write steps to        | No need for read-modify-write; each bit     |
|                         | change individual pins, which could        | corresponds to a specific action (set/reset)|
|                         | result in unwanted changes in concurrent   | ensuring that no other pin states are       |
|                         | environments.                              | unintentionally altered.                    |
+-------------------------+--------------------------------------------+---------------------------------------------+

**Summary**:

- **ODR** is suitable for quick, multi-pin changes but requires caution when used in environments
  with concurrent processes, as modifying individual pins might affect others unintentionally.
  
- **BSRR** provides more precise control with atomic operations, making it safer for use in 
  interrupt-driven or multitasking applications where independent pin control is crucial.

5. Practical Example: Toggling an LED Using ODR and BSRR
--------------------------------------------------------

Consider a setup where an LED is connected to GPIOA pin 5. We want to toggle this LED on and
off.

**Example with ODR**:

.. code-block:: c

   // Configure GPIOA pin 5 as output in MODER register
   GPIOA->MODER |= (1 << (5 * 2));  // Sets PA5 as output

   // Toggle LED
   GPIOA->ODR ^= (1 << 5);  // XOR to toggle PA5 state

In this example, the ODR register is used to toggle the output state of pin 5, thus turning the
LED on or off depending on its current state.

**Example with BSRR**:

.. code-block:: c

   // Configure GPIOA pin 5 as output in MODER register
   GPIOA->MODER |= (1 << (5 * 2));  // Sets PA5 as output

   // Set LED ON
   GPIOA->BSRR = (1 << 5);  // Sets PA5 to HIGH

   // Set LED OFF
   GPIOA->BSRR = (1 << (5 + 16));  // Resets PA5 to LOW

Here, BSRR is used to set or reset the pin without affecting other bits. This approach is
preferred in applications where atomicity is essential, such as in real-time systems or when
dealing with multiple outputs.
