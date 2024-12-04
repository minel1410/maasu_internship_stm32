GPIO on STM32F411
==================

Overview of GPIO Functionality
-----------------------------------

In STM32 microcontrollers, General-Purpose Input/Output (GPIO) pins play a crucial role in enabling communication between the microcontroller and various peripheral devices, such as LEDs, sensors, switches, and more. GPIO pins can be configured in multiple modes, allowing them to function as either inputs or outputs depending on the application's requirements. GPIO configurations are managed via specific registers, which allow flexible control over pin states and behavior.


Key Configurations of GPIO on STM32F411
---------------------------------------

1. **Input Mode:** Configures the pin to read external signals. It’s commonly used with switches and sensors.
2. **Output Mode:** Sets the pin to output a signal, often used to control devices such as LEDs.
3. **Alternate Function Mode:** Configures the pin for peripheral-specific tasks, like UART, SPI, or I2C.
4. **Analog Mode:** Used for analog functions, typically with ADC (Analog-to-Digital Converters).

Each GPIO pin on the STM32F411 can be configured for one of the above modes, along with pull-up or pull-down resistors if needed, using control registers.


Registers for GPIO Configuration
-----------------------------------

1. **Output Data Register (ODR)**

   - The ODR controls the output state of each GPIO pin.

   - Each bit in the ODR corresponds to one GPIO pin, allowing control over individual pin states.

   - Writing a 1 or 0 to a bit in the ODR sets the corresponding pin to high or low, respectively.

   - Example usage: If we want to turn an LED on and off, we can toggle the corresponding bit in the ODR to change the output level of that GPIO pin.

2. **Bit Set/Reset Register (BSRR)**

   - The BSRR allows atomic manipulation of GPIO pin states, meaning it provides a faster and safer way to modify specific bits.

   - This register is split into two 16-bit sections:

     - The first 16 bits control the "set" operation, turning specific pins high.

     - The last 16 bits control the "reset" operation, turning specific pins low.

   - Writing to the BSRR is preferred for toggling pins, as it prevents interference from simultaneous read-modify-write operations that might occur with ODR.

   - Example: To turn on an LED connected to a GPIO pin, we need to write the set bit in BSRR. To turn it off, we need to write the reset bit in BSRR.


Examples
---------

----------------------------------------
Example 1: Configure PA9 for LED Control
----------------------------------------

1. Enable the GPIOA Clock:

   .. code-block:: c

      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

2. Set PA9 as Output:

   .. code-block:: c

      GPIOA->MODER &= ~(3 << (9 * 2));
      GPIOA->MODER |= (1 << (9 * 2));

3. Turn ON the LED (Set PA9 High):

   .. code-block:: c

      GPIOA->ODR |= (1 << 9);

4. Turn OFF the LED (Set PA9 Low):

   .. code-block:: c

      GPIOA->ODR &= ~(1 << 9);

-------------------------------------
Example 2: Configure PA9 for a Button
-------------------------------------

1. Enable the GPIOA Clock:

   .. code-block:: c

      RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

2. Set PA9 as Input:

   .. code-block:: c

      GPIOA->MODER &= ~(3 << (9 * 2));

3. Enable Pull-Up or Pull-Down Resistor:

   - Use pull-up if the button connects to GND when pressed:

     .. code-block:: c

        GPIOA->PUPDR &= ~(3 << (9 * 2));  // Clear pull settings
        GPIOA->PUPDR |= (1 << (9 * 2));   // Enable pull-up resistor

   - Use pull-down if the button connects to VCC when pressed:

     .. code-block:: c

        GPIOA->PUPDR &= ~(3 << (9 * 2));  // Clear pull settings
        GPIOA->PUPDR |= (2 << (9 * 2));   // Enable pull-down resistor

4. Read Button State:
