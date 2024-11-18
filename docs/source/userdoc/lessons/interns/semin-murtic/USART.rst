.. _USART:
=====
USART
=====

Overview
========

**USART** is a peripheral module in microcontrollers that enables communication between devices via a serial protocol. It is used for data transmission between devices such as microcontrollers, computers, sensors, and other modules. USART is used for serial communication between two devices, where reliable and continuous data exchange is required.

USART – Functional Description
==============================

The functionality of the USART includes modes of operation such as data transmission and reception, controlling transmission speed, operating modes (synchronous or asynchronous), and additional flow control and error detection features.

- **Transmitter**: Sending data.
- **Receiver**: Receiving data.
- **Control Registers**: Configures parameters such as baud rate, operating mode, parity, etc.

USART – Key Features
====================

- Support for asynchronous and synchronous operation modes.
- Configurable baud rate for flexible communication speed.
- Configurable data size (8-bit, 9-bit).
- Parity control (even, odd, no parity) for error detection.
- Support for DMA (Direct Memory Access), speeding up data transmission.
- Single-wire Half-duplex: Uses one pin for both data transmission and reception.

USART Interfaces on STM32F411
=============================

The STM32F411 microcontroller supports three USARTs:

- **USART1**: Connected to the APB2 bus. Uses pins PA9 (TX) and PA10 (RX).
- **USART2**: Connected to the APB1 bus. Uses pins PA2 (TX) and PA3 (RX).
- **USART6**: Connected to the APB2. Uses pins PC6 (TX) and PC7 (RX).

USART Modes
===========

**Asynchronous Mode**:
-------------------------
- No common clock.
- Start and stop bits are used to mark the beginning and end of a data packet.
- Lower data rate: Since no common clock is required.
- Asynchronous mode may be slower and less efficient, but easier to implement.
- Commonly used in situations where simple and flexible communication with lower data flow is needed.

**Synchronous Mode**:
----------------------
- Uses a common clock between devices.
- Both devices send and receive data based on the same clock, enabling faster and more efficient communication.
- Suitable for applications requiring fast and stable communication.

USART Baud Rate
===============

The baud rate represents the speed of data transmission between devices and is measured in bits per second (bps). In USART, the baud rate can be adjusted using the **BRR (Baud Rate Register)**.

**Formula**:

Baud Rate = fPCLK / (8 * (2 - OVER8) * USARTDIV)


Where:

- **fPCLK**: Clock frequency.
- **OVER8**: Oversampling configuration.
- **USARTDIV**: Value in the BRR register.

In USART, the baud rate setting ensures that the transmitting and receiving devices operate at the same speed to maintain reliable communication. The baud rate depends on the peripheral clock frequency (fPCLK) and the configuration of the USART peripheral. The oversampling factor (OVER8) can be adjusted to control the precision and speed of data transmission.

- With **16x oversampling** (default), the signal is more stable.
- With **8x oversampling**, faster data transmission is allowed, but with a potential loss in accuracy.

USART Oversampling
==================

Oversampling is used to improve accuracy in asynchronous mode. It can be set to **8x** or **16x**, where:

- **16x oversampling** is the standard mode, providing a more stable signal.
- **8x oversampling** allows faster data transfer but may reduce accuracy.

Oversampling is set in the **CR1 (Control Register 1)** using the **OVER8** bit.

CR1 (Control Register 1)
=========================

The **CR1** register is crucial for configuring basic parameters for USART communication. It controls various essential functionalities for the operation of the USART peripheral, such as enabling or disabling the USART, setting data transfer speeds, and enabling data reception and transmission.

**Key Bits in CR1**:

1. **UE (USART Enable)**:
   - **Function**: Enables or disables the USART peripheral.
   - **When set**: The USART peripheral is activated and functional, meaning it can transmit and receive data.
   - **When not set**: The USART is disabled, and no data transmission or reception is possible.

2. **TE (Transmitter Enable)**:
   - **Function**: Enables or disables data transmission through the USART.
   - **When set**: The device is ready to transmit data on the TX pin.
   - **When not set**: The USART will not transmit data.

3. **RE (Receiver Enable)**:
   - **Function**: Enables or disables data reception through the USART.
   - **When set**: The device is ready to receive data on the RX pin.
   - **When not set**: The USART will not receive data.

These three bits—**UE**, **TE**, and **RE**—are fundamental for controlling the communication process over USART. Without enabling the USART (**UE**), the device cannot function. Likewise, without enabling the transmitter (**TE**) and receiver (**RE**), the device cannot send or receive data, respectively.

USART_CR1_OVER8 (Oversampling Mode)
===================================

The **OVER8** bit in the **CR1** register controls the oversampling mode used for receiving data.

- **Function**: Oversampling refers to taking multiple samples of the data during a single bit cycle to improve the accuracy of the received data.
- **Values**:
  - **OVER8 = 0**: Sets 16x oversampling mode, which provides more accuracy in data reception.
  - **OVER8 = 1**: Sets 8x oversampling mode, which allows faster data transmission but may reduce accuracy.

In summary, **CR1** is crucial for enabling the USART peripheral, managing transmission and reception functionality, and adjusting the oversampling mode for accuracy and speed.

Data Reception
==============

- **Check if data is received**: Before reading data, check if a byte is available in the USART Data Register (**USART_DR**). This check is performed through the **RXNE** (Read Data Register Not Empty) bit in the **USART_SR** (Status Register). If this bit is set to 1, the data is ready to be read.
- **Reading Data**: When data is ready (**RXNE = 1**), the value is read from the **USART_DR** register. This register holds the last received byte of data.

Data Transmission
================

- **Check if the register is empty**: Before sending data, check if the **Transmit Data Register (TDR)** is empty and ready for a new byte to transmit. This check is done through the **TXE** (Transmit Data Register Empty) bit in the **USART_SR** register. If this bit is set to 1, the register is empty and a new byte can be sent.
- **Sending Data**: When the register is empty, the byte to be transmitted is written to the **USART_DR** register. This register is responsible for transmitting data via USART.
- **Waiting for transmission to complete**: After the byte is written to **USART_DR**, wait for the transmission to complete. This is checked using the **TC** (Transmission Complete) bit in the **USART_SR** register. If **TC = 1**, the byte has been successfully sent, and the transmission is complete.

USART Communication Initialization Process
==========================================

1. **Disable USART before configuration**: First, disable USART to avoid issues with settings during configuration. This ensures safe register settings without accidentally starting communication before proper setup. Set the **USART_CR1_UE** value to 0.
2. **Pin Configuration**: After disabling USART, set the appropriate pins for communication. This involves assigning pins for data reception (RX) and data transmission (TX). These pins must be correctly connected to the physical ports of the microcontroller.
3. **Setting Oversampling and Baudrate**: Next, set the parameters for data transmission speed (baudrate) and oversampling mode (sampling rate during one bit cycle).
4. **Set Operating Mode (RX/TX)**: Based on the selected mode (receive-only, transmit-only, or both), activate the corresponding device (receiver or transmitter).
5. **Re-enable USART**: Once all parameters are set, re-enable USART to begin communication.

Connecting a Serial Monitor to the MCU
======================================

1. **Selecting Pins**: First, choose the appropriate pins for **TX** (data transmission) and **RX** (data reception) on the microcontroller. For example, the **TX** pin on the microcontroller is connected to the **RX** pin of the serial monitor (or computer), and the **RX** pin of the microcontroller is connected to the **TX** pin of the monitor.
2. **Pin Configuration**: The pins on the microcontroller must be configured as alternate functions to enable communication via USART. These pins allow data transmission and reception between the microcontroller and the computer.
3. **Selecting Baudrate**: Set the desired data transmission speed (**baudrate**), which must match on both the microcontroller and the serial monitor. Standard baud rates for serial communication include 9600, 115200, etc.
4. **Setting the Operating Mode**: Set the microcontroller to **TX/RX** mode (transmit and receive), ensuring both pins (TX and RX) are active and able to exchange data.