Universal Synchronous Asynchronous Receiver Transmitter (USART)
================================================================

Introduction
------------

USART (Universal Synchronous/Asynchronous Receiver Transmitter) is a crucial peripheral module on microcontrollers that facilitates data exchange using serial communication protocols. It is commonly used for transmitting and receiving data between devices like microcontrollers, computers, sensors, and various modules. 
The module supports both synchronous and asynchronous modes, making it highly versatile for reliable and continuous data transfer. 
USART enables efficient data communication through simple wiring and protocols, which are essential in applications ranging from debugging to interfacing with peripheral devices in embedded systems. Additionally, it features options for configuring data speed, parity, and flow control for optimized communication.

USART Characteristics
----------------------

The functionality of USART encompasses several operating modes, such as data transmission and reception, baud rate control, and selection between synchronous or asynchronous modes.

**Key Features:**

- **Transmitter:** Handles data sending.
- **Receiver:** Manages data reception.
- **Control Registers:** Configure parameters like baud rate, mode, parity, and more.

**Main Characteristics:**

- **Asynchronous and Synchronous Modes:** Supports flexible communication needs.
- **Baud Rate Configuration:** Adjusts data transfer speeds.
- **Data Size:** Supports adjustable data frames (8-bit, 9-bit).
- **Parity Control:** Options for even, odd, or no parity for error detection.
- **DMA Support:** Enhances data transfer efficiency.
- **Single-wire Half-Duplex:** Uses one pin for both transmitting and receiving data.

These features enable reliable and efficient serial communication in various embedded system applications.

**Supported USARTs in STM32F411:**

- **USART1:** Connected to the APB2 bus, using pins PA9 (TX) and PA10 (RX).
- **USART2:** Connected to the APB1 bus, using pins PA2 (TX) and PA3 (RX).
- **USART6:** Connected to the APB2 bus, using pins PC6 (TX) and PC7 (RX).

These USART interfaces enable flexible serial communication, each with dedicated pins for transmitting and receiving data.

USART Modes
-----------

Asynchronous Mode

- Clock Independence: In asynchronous mode, there is no shared clock signal between devices. Instead, communication relies on start and stop bits to delineate data packets, which introduces simplicity but may reduce efficiency.
- Lower Efficiency: The absence of a synchronized clock makes it relatively slower and potentially less efficient compared to synchronous communication.
- Practical Use: Often employed in scenarios where a simple, easy-to-set-up communication method is required, especially for lower-speed data exchanges, such as serial ports in basic microcontroller applications.

Synchronous Mode

- Shared Clock: Synchronous communication uses a common clock signal, ensuring that data transmission is precisely timed between the communicating devices.
- Higher Efficiency: This shared timing enables a more continuous and efficient data flow, resulting in higher transmission speeds and more reliable communication.
- Applications: Ideal for scenarios where high-speed and stable communication are critical, such as data exchange in high-performance peripherals or when transferring data over short distances where timing precision is necessary.

Baud Rate
---------

Baud Rate represents the data transfer speed between devices, measured in bits per second (bps). It is configured using the BRR (Baud Rate Register).

**Formula:**

**BAUD RATE= fpclk / (8*(2-OVER8)*USARTDIV)**

- **fPCLK:** Clock frequency for the peripheral.
- **OVER8:** Oversampling configuration (8x or 16x).
- **USARTDIV:** Division value stored in the BRR register.

Oversampling
------------

In USART communication, oversampling is used to enhance accuracy in asynchronous mode by sampling the incoming data multiple times per bit. It can be set to either 8x or 16x oversampling:
- 16x Oversampling: The default and most common mode, which provides a more stable and reliable signal by sampling each bit 16 times. It offers higher precision and is ideal for environments where signal integrity is crucial.
- 8x Oversampling: This mode allows for higher data transfer speeds but may reduce the precision of signal detection, making it more susceptible to noise.
Configuration: Oversampling is configured in the CR1 (Control Register 1) by setting the OVER8 bit. If OVER8 is set to 1, the USART operates in 8x mode; if it's set to 0, it defaults to 16x mode.

Registers
---------

**CR1 Register**

The CR1 register configures fundamental parameters for USART communication.

- **UE (USART Enable):** Activates or deactivates the USART.
- **TE (Transmitter Enable):** Enables data transmission (TX line).
- **RE (Receiver Enable):** Enables data reception (RX line).

**Other Key Bits:**

- **USART_CR1_OVER8:** Manages oversampling (16x or 8x).

**USART_CR1_UE, USART_CR1_TE, USART_CR1_RE**

- **USART_CR1_UE (USART Enable):** Activates the USART peripheral.
- **USART_CR1_TE (Transmitter Enable):** Enables data transmission on the TX pin.
- **USART_CR1_RE (Receiver Enable):** Enables data reception on the RX pin.

### USART Communication Process

#### Data Reception:

- Data Ready Check: Before reading the received data, it is crucial to check if a byte of data is available in the USART Data Register (USART_DR). This is done using the RXNE (Read Data Register Not Empty) bit located in the USART_SR (Status Register). If RXNE is set to 1, it indicates that the data is ready to be read.
- Reading Data: Once RXNE is confirmed as 1, the value from the USART_DR register is read. This register holds the most recent received byte of data.

#### Data Sending:

For data to be transmitted efficiently and reliably, these steps are of big importance:
1. Checking if the Transmit Data Register (TDR) is empty: The first step in sending data is to ensure that the Transmit Data Register is empty and can accept a new byte for transmission. This is verified by reading the TXE (Transmit Data Register Empty) bit in the USART_SR (Status Register). When the TXE bit is set to 1, it indicates that the register is empty and ready for the next byte. The TXE bit is automatically managed by the hardware and ensures that data is not lost or overwritten.
2. Placing the data into the USART Data Register: Once it is confirmed that the TDR is empty, the byte of data to be transmitted is written into the USART_DR (Data Register). Writing to this register triggers the transmission of the data byte over the USART interface. The data in the USART_DR register is serialized and sent bit-by-bit over the TX pin based on the configured baud rate and protocol settings.
3. Monitoring the transmission progress: After writing the data byte to the USART_DR, the transmission begins. During this process, it is essential to monitor the TC (Transmission Complete) bit in the USART_SR register. The TC bit indicates the completion of data transmission, not just when the data has been shifted out of the TDR but when the entire byte, including the stop bit, has been fully transmitted over the USART line. The TC bit is set to 1 when the transmission is complete, signaling that the USART is ready for the next transmission.

USART Initialization Steps
--------------------------

1. **Disable USART:** Set USART_CR1_UE to `0` before configuration.
2. **Pin Configuration:** Assign TX and RX pins to GPIO ports in alternate function mode.
3. **Set Baud Rate and Oversampling:** Configure in BRR and CR1 registers, respectively.
4. **Enable Communication Modes:** Set RE and/or TE bits in CR1.
5. **Enable USART:** Set USART_CR1_UE to `1`.

Example
-------

**Connecting a Serial Monitor to STM32F411**

1. **Hardware Setup:**
   - Connect TX (MCU) to RX (monitor), RX (MCU) to TX (monitor), and ensure a shared ground connection.

2. **Clock Configuration:**
   - Use RCC_AHB1ENR to enable GPIO clocks and RCC_APB1ENR/RCC_APB2ENR for USART clocks.

3. **GPIO Configuration:**
   - Set TX and RX pins in alternate function mode (GPIOx_MODER).

4. **USART Configuration:**
   - Calculate baud rate using the formula and set word length, parity, and stop bits in CR1, CR2, and CR3.

5. **Enable USART:**
   - Set the UE bit in CR1.

6. **Data Transmission:**
   - Check TXE bit and write data to USART_DR.

7. **Data Reception:**
   - Monitor RXNE bit and read data from USART_DR.

8. **Optional: Interrupts:**
   - Configure interrupts for efficient data handling.