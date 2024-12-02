Informational Requirements
==========================

.. req:: USART Definition
   :id: REQ_INT3_17310281818
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART (Universal Synchronous and Asynchronous Receiver-Transmitter) is a peripheral module that facilitates serial communication between devices.

.. req:: Serial Protocol
   :id: REQ_INT3_17310281819
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART uses a serial protocol to transmit and receive data bit by bit over a single communication line.
.. req:: USART Registers
   :id: REQ_INT3_173102818200
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The following USART registers are used in configuring and operating the USART peripheral:
   - Status Register (USART_SR)
   - Data Register (USART_DR)
   - Baud Rate Register (USART_BRR)
   - Control Register 2 (USART_CR2)
   - Control Register 3 (USART_CR3)
   - Guard Time and Prescaler Register (USART_GTPR)



.. req:: USART Modes of Operation
   :id: REQ_INT3_17310281820
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART supports two primary modes of operation: asynchronous and synchronous.

.. req:: Asynchronous Mode
   :id: REQ_INT3_17310281821
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   In asynchronous mode, the USART transmits data without a shared clock, using start and stop bits for data synchronization.

.. req:: Synchronous Mode
   :id: REQ_INT3_17310281822
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   In synchronous mode, the USART uses a shared clock between devices for faster and more efficient data transfer.

.. req:: Control Registers
   :id: REQ_INT3_17310281823
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   USART control registers configure settings such as baud rate, data size, mode of operation, parity, and DMA support.

.. req:: Baud Rate
   :id: REQ_INT3_17310281824
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The baud rate determines the speed of data transfer in bits per second and is configurable through the Baud Rate Register (BRR).Formula is fPCLK / (8 * (2-OVER8) * USARTDIV) wjere fPCLK is the frequency of clock, OVER8 configuration of oversampling and USARTDIV value om the BRR register.


.. req:: Parity Control
   :id: REQ_INT3_17310281825
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART provides error detection through parity control, supporting even, odd, and no parity modes.

.. req:: DMA Support
   :id: REQ_INT3_17310281826
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART integrates Direct Memory Access (DMA) to enhance data transfer efficiency and reduce CPU load.

.. req:: Single-Wire Mode
   :id: REQ_INT3_17310281827
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART can operate in single-wire mode, using one pin for both data transmission and reception.

.. req:: Half-Duplex Mode
   :id: REQ_INT3_17310281828
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART supports half-duplex communication, where data transmission and reception occur on the same line but not simultaneously.

.. req:: Shared Clock
   :id: REQ_INT3_17310281829
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The synchronous mode of USART relies on a shared clock signal to synchronize data transfer between devices.

.. req:: USART Transmitter
   :id: REQ_INT3_17310281830
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART transmitter sends data to an external device through the TX (transmit) pin.

.. req:: USART Receiver
   :id: REQ_INT3_17310281831
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART receiver accepts incoming data from an external device through the RX (receive) pin.

.. req:: USART Oversampling
   :id: REQ_INT3_17310281832
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART supports oversampling modes (8x and 16x) to improve signal accuracy and communication reliability.

.. req:: Error Detection
   :id: REQ_INT3_17310281834
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART includes error detection features like frame errors, parity errors, and noise detection for reliable communication.


.. req:: USART Clock Configuration
   :id: REQ_INT3_17310281785
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART peripheral operates with an external clock, which must be enabled before configuration.

.. req:: Pin Configuration for USART1
   :id: REQ_INT3_17310281786
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   For USART1, the TX and RX pins are mapped to PA9 and PA10, respectively.

.. req:: Pin Configuration for USART2
   :id: REQ_INT3_17310281787
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   For USART2, the TX and RX pins are mapped to PA2 and PA3, respectively.

.. req:: Pin Configuration for USART6
   :id: REQ_INT3_17310281788
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   For USART6, the TX and RX pins are mapped to PC6 and PC7, respectively.

.. req:: Alternative Function of USART Pins
   :id: REQ_INT3_17310281789
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART TX and RX pins must be configured as alternate functions for serial communication.


.. req:: Baud Rate Register 
   :id: REQ_INT3_17310281792
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART_BRR register is used to configure the baud rate by setting the mantissa and fraction bits for accurate timing.

.. req:: USART Data Register 
   :id: REQ_INT3_17310281793
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Data is read from or written to the USART_DR register during the transmission or reception of data.

.. req:: USART Control Register 1 (CR1)
   :id: REQ_INT3_17310281794
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The CR1 register controls essential USART parameters such as enabling transmission (TE) and reception (RE) and enabling the USART itself (UE).

.. req:: USART Control Register 1 (CR1) Bits for TX/RX Enable
   :id: REQ_INT3_17310281795
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The TE bit in CR1 is used to enable the transmitter, and the RE bit is used to enable the receiver for USART operation.

.. req:: Start and Stop Bit Definition
   :id: REQ_INT3_17310281796
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Data transmission through USART starts with a start bit (low level) followed by data and ends with one or two stop bits (high level).

.. req:: USART Frame Format
   :id: REQ_INT3_17310281797
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART frame consists of an idle line, a start bit, data bits (8 or 9 bits), and a configurable stop bit.


.. req:: USART Interrupts
   :id: REQ_INT3_17310281801
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART can generate interrupts based on different events such as data register empty, transmission complete, or error conditions.

.. req:: DMA for USART Communication
   :id: REQ_INT3_17310281802
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Direct Memory Access (DMA) can be used with USART to buffer data for faster data transmission and reception.

.. req:: USART Wakeup Mode
   :id: REQ_INT3_17310281803
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   USART supports wakeup from mute mode through address detection or idle line detection.

.. req:: Multiprocessor Communication Mode
   :id: REQ_INT3_17310281804
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   In multiprocessor communication mode, the USART detects address frames and supports communication with multiple devices.

.. req:: USART Mute Mode
   :id: REQ_INT3_17310281805
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Mute mode allows the USART to ignore incoming data, typically for noise reduction or when the receiver is unavailable.


.. req:: USART FIFO Buffers
   :id: REQ_INT3_17310281807
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART may include FIFO buffers for both transmit and receive operations, improving data throughput by reducing interrupt frequency.

.. req:: USART Low Power Mode
   :id: REQ_INT3_17310281808
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART can operate in low power mode, reducing power consumption when idle or during transmission breaks.

.. req:: USART Wakeup from Stop Mode
   :id: REQ_INT3_17310281809
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART can wake up from stop mode by detecting an active signal on the receiver pin or by address detection.

.. req:: USART Data Frame Length
   :id: REQ_INT3_17310281810
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The length of a data frame is configurable between 7 and 9 data bits, depending on the system's requirements.

.. req:: USART Receiver Time Out
   :id: REQ_INT3_17310281811
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART receiver has an optional time-out feature to stop reception if no data is received for a configured period.

.. req:: USART Clock Polarity and Phase
   :id: REQ_INT3_17310281812
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The clock polarity and phase can be configured for different data transfer modes (e.g., SPI compatibility mode).

.. req:: USART Low-Noise Design
   :id: REQ_INT3_17310281813
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART supports low-noise design with built-in noise suppression to improve data integrity during transmission.

.. req:: USART Mode Selection
   :id: REQ_INT3_17310281814
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART can operate in different modes, including asynchronous, synchronous, and half-duplex modes.

.. req:: USART Communication Protocols
   :id: REQ_INT3_17310281815
   :status: Draft
   :date-released:
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART supports multiple communication protocols, such as full-duplex, half-duplex, and multi-processor communication.

.. req:: USART Flow Control
   :id: REQ_INT3_17310281816
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   Flow control can be enabled in USART to manage data transmission, using either hardware or software control mechanisms.

.. req:: USART End of Frame Detection
   :id: REQ_INT3_17310281817
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Informational
   :safety-asil:
   :references:
   :verification-and-validation:

   The USART is capable of detecting the end of frame conditions, such as the stop bit, for proper synchronization of data communication.


	
