USART on STM32F411
===================

Overview of USART Functionality
-------------------------------

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is a key feature in STM32F411 for serial communication. It enables bidirectional data exchange between the microcontroller and external devices like computers, sensors, or other microcontrollers.


Common Use Cases
-----------------

- Debugging via a serial monitor

- Communication with peripheral devices

- Wireless data transmission modules (e.g., Bluetooth or Wi-Fi)


Key Configurations
------------------

1. **Baud rate:** The speed of data transmission.

2. **Data format:** Frame format (number of data bits, parity, and stop bits).

3. **Control registers:**  Settings for enabling transmission, reception, and interrupts.


USART Modes: Synchronous vs Asynchronous
-----------------------------------------

Asynchronous Mode

- Uses only two lines: TX (transmit) and RX (receive).

- The transmitter and receiver operate independently, with communication timing controlled by the baud rate.

- Commonly used in standard UART communication (e.g., serial terminals).

Synchronous Mode

- Uses an additional clock line (SCLK) for synchronized communication between the transmitter and receiver.

- The transmitter generates the clock, ensuring precise timing for data exchange.

- Suitable for high-speed communication or scenarios where the clock signal needs to be shared.

Enabling Synchronous Mode

- Set the USART_CR2.CLKEN bit to enable the clock signal.

- Configure the clock polarity (CPOL) and phase (CPHA) in USART_CR2.



Registers and Settings for USART Communication
----------------------------------------------

1. **Baud Rate Configuration**

   The baud rate is set in the USART_BRR (Baud Rate Register). The exact formula to calculate the baud rate includes oversampling and is defined as:

   .. math::

      Baud\ Rate = \frac{f_{PCLK}}{8 \times (2 - OVER8) \times USARTDIV}

   Where:

   - f_PCLK: Peripheral clock frequency (APB1 or APB2 clock, depending on the USART instance).

   - OVER8: Over-sampling factor (0 for 16x, 1 for 8x).

   - USARTDIV: Value set in the USART_BRR register, determined by the desired baud rate.

   If OVER8 = 0, the formula simplifies to:

   .. math::

      Baud\ Rate = \frac{f_{PCLK}}{16 \times USARTDIV}

2. Control Registers

   - USART_CR1 (Control Register 1): Enables USART, selects word length, parity control, and interrupts.

   - USART_CR2 (Control Register 2): Configures stop bits, synchronous mode settings, and clock options.

   - USART_CR3 (Control Register 3): Configures flow control and DMA settings.



3. Data Register

   - USART_DR: Used for reading received data or writing data to be transmitted.



Practical Example: Setting Up USART for Asynchronous Communication
------------------------------------------------------------------

1. Enable USART Clock

   .. code-block:: c

      RCC->APB2ENR |= RCC_APB2ENR_USART1EN;  // Enable USART1 clock

2. Configure GPIO Pins for USART

   .. code-block:: c

      GPIOA->MODER |= (2 << (9 * 2)) | (2 << (10 * 2));  // Set PA9 and PA10 to alternate function mode
      GPIOA->AFR[1] |= (7 << (1 * 4)) | (7 << (2 * 4));  // Set PA9 and PA10 to AF7 (USART)

3. Set Baud Rate

   .. code-block:: c

      USART1->BRR = 16000000 / 9600;  // Assuming 16 MHz clock and 9600 baud rate

4. Enable USART

   .. code-block:: c

      USART1->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;  // Enable USART, TX, and RX

5. Transmit Data

   .. code-block:: c

      while (!(USART1->SR & USART_SR_TXE)); 
      USART1->DR = 'A';  // Send character 'A'

6. Receive Data

   .. code-block:: c

      while (!(USART1->SR & USART_SR_RXNE));  
      USART1->DR;  // Read received data

Summary
-------

USART in STM32F411 supports two modes:

- **Asynchronous Mode:** Simple, widely used for serial communication without a shared clock.

- **Synchronous Mode:** Adds a clock line for precise timing, ideal for high-speed or clock-sensitive applications.

The baud rate is configured using a precise formula to ensure accurate communication timing. This flexibility makes USART highly adaptable for various communication needs.