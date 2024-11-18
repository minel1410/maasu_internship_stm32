=======================================
USART Functionalities for the STM32F411
=======================================

What is USART? 
--------------

USART (Universal Synchronous/Asynchronous Receiver/Transmitter) is a hardware peripheral used for serial communication between microcontrollers and other devices, such as computers, sensors, or other microcontrollers. It supports both synchronous and asynchronous modes:

- **Synchronous mode:** Data transmission is synchronized using a clock signal. Both the transmitter and receiver share the same clock source, making the communication more reliable in terms of timing.

- **Asynchronous mode:** No clock signal is shared between the transmitter and receiver. Instead, data is sent with start and stop bits to signify the beginning and end of each data frame.

USART is commonly used in embedded systems for tasks such as:

- Serial communication with a computer for debugging or sending logs (e.g., using a terminal program like PuTTY or Tera Term).
- Real-time data exchange between microcontrollers and external peripherals (e.g., sensors, GPS modules, etc.).

Key Configurations for USART Communication
------------------------------------------

1. **Baud Rate:** The baud rate determines the rate at which data is transmitted and received. It is expressed in bits per second (bps). For example:
   
   - A baud rate of 9600 means 9600 bits are transmitted per second.
   - Higher baud rates, like 115200, enable faster data transmission but may be more prone to errors over long distances or noisy communication channels.

2. **Data Format:** Data frames consist of several bits that convey information. Key components include:

   - **Data bits:** The number of bits in each frame that carry the data. Commonly, 8 data bits are used.
   - **Parity:** A simple error-checking mechanism. Options:
     - None: No parity bit is used.
     - Even: Parity bit ensures the total number of 1s in the frame (data + parity bit) is even.
     - Odd: Ensures the total number of 1s is odd.
   - **Stop bits:** Signal the end of a data frame. Common configurations are 1 or 2 stop bits.

3. **Control Registers:** Key registers used to configure USART communication:
   - **USART_BRR (Baud Rate Register):** Sets the baud rate based on the system clock.
   - **USART_CR1 (Control Register 1):** Configures features like enabling the transmitter (TE) and receiver (RE), setting the data frame length (8 or 9 bits), and choosing parity type.
   - **USART_CR2 (Control Register 2):** Configures stop bits and synchronization parameters (if synchronous mode is used).
   - **USART_CR3 (Control Register 3):** Manages advanced features like DMA (Direct Memory Access) support and error handling.

Example: Configuring USART for Serial Monitor Communication
-----------------------------------------------------------

The following example configures USART for communication with a serial monitor using:

- Baud rate: 9600 bps
- Data bits: 8
- Parity: None
- Stop bits: 1

.. code-block:: c

    // Enable the USART peripheral clock
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

    // Set the baud rate
    USART1->BRR = SystemCoreClock / 9600;

    // Enable the transmitter and receiver
    USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;

    // Enable USART
    USART1->CR1 |= USART_CR1_UE;

Explanation:

1. **Enable USART peripheral clock:** The clock for the USART1 peripheral is enabled through the `RCC` register.
2. **Set the baud rate:** Configured via the `USART_BRR` register. The value is calculated as `SystemCoreClock / BaudRate`.
3. **Enable transmitter and receiver:** Controlled by the `USART_CR1` register.
4. **Enable USART:** The USART module is activated by setting the `USART_CR1_UE` bit.

Transmitting Data: Sending a Character Over USART
-------------------------------------------------

The following example demonstrates how to send a character using USART:

.. code-block:: c

    // Function to send a character over USART
    void USART_SendChar(char c) {
        while (!(USART1->SR & USART_SR_TXE));  // Wait until transmit register is empty
        USART1->DR = c;  // Write the character to the data register to send it
    }

    // Example usage: sending a string
    const char *message = "Hello, USART!";
    for (int i = 0; message[i] != '\0'; i++) {
        USART_SendChar(message[i]);  // Send each character one by one
    }

Explanation:

1. **USART_SendChar function:** Sends a single character over USART, waiting until the `TXE` flag indicates readiness.
2. **Sending a string:** Each character of the string is passed to the `USART_SendChar` function.

Conclusion
----------

USART is a versatile protocol for serial communication in embedded systems. Configuring registers like `USART_CR1`, `USART_CR2`, and `USART_BRR` allows control over baud rate, data format, and other communication aspects. This facilitates debugging, logging, and data transfer in many applications.
