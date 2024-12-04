USART Overview
===============

Introduction
-------------

The **Universal Synchronous Asynchronous Receiver Transmitter (USART)** is a peripheral module in microcontrollers that facilitates serial communication. It's commonly used for transmitting data between devices such as microcontrollers, sensors, and computers. USART supports both asynchronous and synchronous communication modes, making it versatile for various applications.
 
- **Asynchronous mode**: No shared clock, relying on start and stop bits for data synchronization
- **Synchronous mode**: Utilizes a shared clock, allowing faster and more efficient communication
 

Key Configurations
-------------------

1. **Baud Rate**: Defines the data transfer speed in bits per second (bps). The baud rate must match between the transmitting and receiving devices. It's configured using the BRR (Baud Rate Register):

      **Baud Rate = f_PCLK / (8 * (2 - OVER8) * USARTDIV)**

  - **PCLK**: Clock frequency

  - **OVER8**: Oversampling mode (8x or 16x)
  
  - **USARTDIV**: Divider value in the BRR register
 

2. **Data Format**:

  - Configurable data size (8-bit or 9-bit)

  - Parity options: None, even, or odd, to enhance error detection

 
3. **Control Registers**:

  - **CR1**: Configures core parameters (USART enable, transmitter/receiver enable, setting the data transfer rate).

  - **CR2**: Additional configurations like stop bits.
 

 
Required Registers and Settings
-------------------------------- 

To set up USART communication, these steps and registers are crucial:
  
  - Disable USART: Turn off USART (USART_CR1_UE = 0) to safely configure registers
  
  - Configure Pins: Assign RX/TX pins and connect them to the microcontroller's ports
  
  - Set Baud Rate & Oversampling: Define data transfer speed and sampling mode  
  
  - Enable RX/TX Mode: Activate the receiver, transmitter, or both as needed
  
  - Re-enable USART: Turn USART back on to start communication  


Example: Setting Up USART for a Serial Monitor
-----------------------------------------------

Here's a practical example of configuring USART to communicate with a serial monitor.
 
Steps:
1. Pin Selection:
   - Select the USART peripheral (e.g., USART2) and configure the pins.
   - Connect TX (PA2) to the RX pin of the serial monitor and RX (PA3) to TX.
 
2. Pin Configuration:
   - Configure PA2 and PA3 as alternate functions (AF7) in GPIO registers.
 
3. Baud Rate Configuration:
 For a baud rate of 9600 bps:
-  f_PCLK= 16 MHz.
-  BRR = 16 MHz / 9600 
 
4. Register Settings:
- Enable USART by setting the UE bit in CR1.
- Enable transmission and reception by setting TE and RE bits in CR1.
 
5. Communication:
- Use USART_DR (Data Register) for transmitting and receiving data.
- Check status bits like TXE (Transmit Data Register Empty) and RXNE (Receive Data Register Not Empty) in USART_SR.