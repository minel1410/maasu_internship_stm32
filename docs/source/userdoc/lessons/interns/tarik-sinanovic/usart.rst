==========
USART
==========


Introduction to USART
==========================

Universal Synchronous Asynchronous Receiver Transmitter (USART) is a communication protocol used for transmitting and receiving serial data. It's commonly used to communicate with devices such as serial monitors, GPS modules, and other microcontrollers.

Key Configurations
======================

1. Baud Rate: Determines the speed of communication (e.g., 9600 bits per second). The baud rate is calculated as:
2. USART_DIV=SystemClockBaudRateUSART\_DIV = \frac{SystemClock}{BaudRate}USART_DIV=BaudRateSystemClock
3. This value is programmed into the BRR register.
4. Data Format: Includes settings for word length, stop bits, and parity. These are configured using the CR1 and CR2 registers:
  - Word Length: 8 or 9 bits (configured via M bit in CR1).
  - Stop Bits: 1 or 2 stop bits (configured via STOP bits in CR2).
  - Parity: None, Even, or Odd (configured via PCE and PS bits in CR1).
5. Control Registers:
  - CR1: Enables USART (UE bit) and configures word length, parity, and transmitter/receiver.
  - CR2: Configures stop bits.
  - CR3: Optional features like hardware flow control.


Example
==========

1. Enable USART clock - Enable GPIO clock RCC_AHB1ENR and USART clock RCC_APB1ENR or RCC_APB2ENR.
2. Configure GPIO pins for USART - TX and RX pins are set to alternate function mode.
3. Set Baud rate - We calculate baud rate with the formula and set word length, parity and stop bits.
4. Enable USART - We set the UE bit in CR1.
5. Transmit data - The TXE bit is checked and data is written in USART_DR.
6. Receive data - RXNE is checked and the data is read from USART_DR