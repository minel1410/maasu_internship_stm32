USART
=====

Introduction
------------

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is a key peripheral in STM32F411 microcontrollers, enabling serial communication between microcontrollers and other devices such as computers, sensors, or peripherals. It supports both synchronous and asynchronous modes, making it highly versatile for various embedded applications.

Common Use Cases:
-----------------
- Debugging or sending logs using a serial terminal (e.g., PuTTY or Tera Term).
- Real-time data exchange with external devices like GPS modules or sensors.

Key Configurations for USART Communication
------------------------------------------

1. **Baud Rate**:
   - Determines the rate at which data is transmitted and received, measured in bits per second (bps).
   - Example:
     - Baud rate = 9600 bps (9600 bits transmitted per second).
     - Higher baud rates like 115200 enable faster transmission but may increase errors over long distances.

2. **Data Format**:
   - Data frames consist of several bits that convey information. Key components include:
     - **Data Bits**: Number of bits in each frame that carry the actual data (commonly 8 bits).
     - **Parity**: Optional error-checking mechanism (e.g., None, Even, Odd).
     - **Stop Bits**: Number of bits used to indicate the end of a frame (commonly 1 or 2).

3. **Control Registers**:
   - Used to configure USART settings like baud rate, enabling transmitter/receiver, and data format.

USART Configuration on STM32F411
--------------------------------

To configure USART for communication, follow these steps:

1. **Enable the USART Peripheral Clock**:
   - Enable the clock for the USART peripheral using the RCC register.

2. **Configure GPIO Pins**:
   - Set the TX and RX pins to Alternate Function mode.
   - Map them to the appropriate Alternate Function (AF) based on the selected USART:
     - **USART1**:
       - TX: PA9 or PB6
       - RX: PA10 or PB7
       - Alternate Function: AF7
     - **USART2**:
       - TX: PA2 or PD5
       - RX: PA3 or PD6
       - Alternate Function: AF7
     - **USART6**:
       - TX: PC6 or PG14
       - RX: PC7 or PG9
       - Alternate Function: AF8

3. **Set Baud Rate**:
   - Calculate the baud rate using the formula:
     - **For oversampling by 16**: ``USARTDIV = Fck / Baudrate``
     - **For oversampling by 8**: ``USARTDIV = Fck / (Baudrate * 2)``
   - Example:
     - Fck = 50 MHz
     - Desired baud rate = 115200
     - Calculated value: ``USARTDIV = 50,000,000 / 115200 = 434.03``

4. **Configure Control Registers**:
   - Enable USART by setting the **UE (USART Enable)** bit in the CR1 register.
   - Enable the transmitter and receiver by setting the **TE (Transmitter Enable)** and **RE (Receiver Enable)** bits in the CR1 register.

Example: Setting Up USART for Communication
-------------------------------------------

This example demonstrates setting up USART2 for communication at 9600 baud with a serial monitor.

.. code-block:: c

   // Enable the USART2 peripheral clock
   RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

   // Configure GPIO Pins for USART2
   // Set PA2 (TX) and PA3 (RX) to Alternate Function mode
   GPIOA->MODER |= (0x2 << (2 * 2)) | (0x2 << (3 * 2));
   GPIOA->AFR[0] |= (0x7 << (4 * 2)) | (0x7 << (4 * 3)); // Alternate Function AF7

   // Configure Baud Rate (9600 bps)
   USART2->BRR = 50000000 / 9600;

   // Enable Transmitter and Receiver
   USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;

   // Enable USART
   USART2->CR1 |= USART_CR1_UE;

Conclusion
----------

USART is a versatile and essential peripheral in STM32 microcontrollers, providing robust solutions for serial communication in both synchronous and asynchronous modes. By properly configuring key parameters such as baud rate, data format, and control registers, USART enables efficient data exchange with external devices like sensors, computers, and other microcontrollers. Mastering the initialization process, pin configurations, and data transmission ensures reliable communication, making USART an indispensable tool for embedded applications.
