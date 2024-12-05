===========================
Informational Requirements
===========================

.. req:: label
   :id: REQ_INT3_1733103223
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   USART is a module that enables serial communication between devices.


.. req:: label
   :id: REQ_INT3_1733103301
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   There are three USART peripherals and their configuration is as follows:
USART1:
  - TX: PA9 or PB6
  - RX: PA10 or PB7
  - Alternate Function: AF7
USART2:
  - TX: PA2 or PD5
  - RX: PA3 or PD6
  - Alternate Function: AF7
USART6:
  - TX: PC6 or PG14
  - RX: PC7 or PG9
  - Alternate Function: AF8


.. req:: label
   :id: REQ_INT3_1733103416
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The two modes of USART are synchronous and asynchronous.


.. req:: label
   :id: REQ_INT3_1733103482
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Asynchronous mode uses start and stop bits to indicate the beginning and end of transmission.


.. req:: label
   :id: REQ_INT3_1733103590
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Asynchronous mode does not require a clock line.


.. req:: label
   :id: REQ_INT3_1733103646
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Synchronous mode uses a clock line between the devices.


.. req:: label
   :id: REQ_INT3_1733103697
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   In synchronous mode both devices send and receive data.


.. req:: label
   :id: REQ_INT3_1733103757
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Baut rate is the speed of data transmission between two devices.
        Baut rate = fplck / (8*(2-OVER8)*USARTDIV)
    In this formula, fplck is our clock frequency, OVER8 is the oversampling configuration and USARTDIV is the value in BRR.


.. req:: label
   :id: REQ_INT3_1733104064
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   BRR: Baud Rate Register, used to set the baud rate for communication.


.. req:: label
   :id: REQ_INT3_1733104129
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Oversampling is a process where the data is sampled multiple times during one bit of transmission.


.. req:: label
   :id: REQ_INT3_1733104213
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Oversampling is used in order to get better accuracy in asynchronous mode.


.. req:: label
   :id: REQ_INT3_1733104268
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   16x oversampling (1) is the standard mode which enables a stable signal.


.. req:: label
   :id: REQ_INT3_1733104313
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   8x oversampling (0) enables a faster data transmission and is not as precise.


.. req:: label
   :id: REQ_INT3_1733104379
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Oversampling is adjusted in CR1.


.. req:: label
   :id: REQ_INT3_1733104430
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   CR1 is used to configure the parameters of USART.


.. req:: label
   :id: REQ_INT3_1733104500
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The bits in CR1 are: UE (USART enable), TE (Transmitter enable), RE (Receiver enable).


.. req:: label
   :id: REQ_INT3_1733104568
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   UE enables or disables USART.


.. req:: label
   :id: REQ_INT3_1733104625
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TE enables or disables data transmission.


.. req:: label
   :id: REQ_INT3_1733104671
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   RE enables or disables data reception.


.. req:: label
   :id: REQ_INT3_1733104728
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   RXNE bit in USART_SR is used to check if the byte of data is available (1) or not available (0).


.. req:: label
   :id: REQ_INT3_1733104807
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   RCC: Reset and Clock Control, used to enable the clock for USART.


.. req:: label
   :id: REQ_INT3_1733104848
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   DR: Data Register, used to hold data to be transmitted.


.. req:: label
   :id: REQ_INT3_1733104896
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   SR: Status Register, used to check the status of the USART, including the TXE (Transmit Data Register Empty) flag.


.. req:: label
   :id: REQ_INT3_1733104950
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TXE (Transfer Data Register Empty) is a bit in the USART_SR.


.. req:: label
   :id: REQ_INT3_1733105027
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   If TXE is 1 the register is empty and a new byte can be sent.


.. req:: label
   :id: REQ_INT3_1733105082
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   TC (Transmission Complete) is a bit in USART_SR.


.. req:: label
   :id: REQ_INT3_1733105145
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   If the value of TC is 1 the byte was successfully sent and the transfer is done.


.. req:: label
   :id: REQ_INT3_1733105209
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Uncorrupted data means that no changes in data occurred in the transmission process.
