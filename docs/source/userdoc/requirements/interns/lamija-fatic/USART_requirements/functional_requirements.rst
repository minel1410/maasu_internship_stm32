Functional Requirements
==========================

.. req:: Enabling the USART peripheral
   :id: REQ_INT3_173102818189
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must enable the USART peripheral by setting the `USART_CR1_UE` bit in the appropriate register.

.. req:: Configuring TX and RX pins
   :id: REQ_INT3_173102818190
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must configure the TX and RX pins as alternate functions on the microcontroller for data transmission and reception.

.. req:: Setting the baud rate
   :id: REQ_INT3_173102818191
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must set the baud rate using the `USART_BRR` register based on the baud rate calculation formula.

.. req:: Enabling or disabling oversampling
   :id: REQ_INT3_173102818192
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must enable oversampling in either 8x or 16x mode by configuring the `USART_CR1_OVER8` bit.

.. req:: Enabling data transmission
   :id: REQ_INT3_173102818193
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must enable data transmission through the TX pin by setting the `USART_CR1_TE` bit in the `CR1` register.

.. req:: Enabling data reception
   :id: REQ_INT3_173102818194
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must enable data reception through the RX pin by setting the `USART_CR1_RE` bit in the `CR1` register.

.. req:: Configuring parity
   :id: REQ_INT3_173102818195
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must configure parity for error detection using the `USART_CR1_PS` and `USART_CR1_PE` bits in the `CR1` register.

.. req:: Setting data word length (8-bit or 9-bit)
   :id: REQ_INT3_173102818196
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must set the data word length to either 8 or 9 bits using the `USART_CR1_M` bit in the `CR1` register.

.. req:: Setting the mode of operation (asynchronous or synchronous)
   :id: REQ_INT3_173102818197
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must configure the mode of operation (asynchronous or synchronous) using the appropriate bits in the `USART_CR1` and `USART_CR2` registers.

.. req:: Enabling DMA for data transfer
   :id: REQ_INT3_173102818198
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must enable Direct Memory Access (DMA) for data transfer by configuring the `USART_CR3_DMAT` and `USART_CR3_DMAR` bits in the `CR3` register.

.. req:: Transmitting data in half-duplex mode
   :id: REQ_INT3_173102818199
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must configure USART to operate in half-duplex mode by enabling the `USART_CR1_HDSEL` bit, allowing the same pin for both transmission and reception.

.. req:: Checking if data is ready for reception
   :id: REQ_INT3_1731028182098
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must check the `RXNE` (Read Data Register Not Empty) bit in the `USART_SR` register to verify if data is ready for reception before reading the `USART_DR` register.

.. req:: Checking if data register is empty for transmission
   :id: REQ_INT3_173102818201
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must check the `TXE` (Transmit Data Register Empty) bit in the `USART_SR` register to ensure the data register is empty before transmitting data.

.. req:: Waiting for transmission completion
   :id: REQ_INT3_173102818202
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must wait for the transmission to complete by checking the `TC` (Transmission Complete) bit in the `USART_SR` register before sending new data.

.. req:: Disabling USART before configuration
   :id: REQ_INT3_173102818203
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must disable the USART by clearing the `USART_CR1_UE` bit before configuring the registers to ensure correct configuration.

.. req:: Re-enabling USART after configuration
   :id: REQ_INT3_173102818204
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must re-enable the USART peripheral by setting the `USART_CR1_UE` bit after configuration is complete to start communication.

.. req:: Ensuring proper TX and RX pin mapping
   :id: REQ_INT3_173102818205
   :status: Draft
   :priority: High
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must ensure proper pin mapping for TX and RX pins according to the microcontroller's specifications, ensuring correct communication.

.. req:: Selecting oversampling mode (8x or 16x)
   :id: REQ_INT3_173102818206
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must allow for the selection of the oversampling mode, either 8x or 16x, by configuring the `USART_CR1_OVER8` bit.

.. req:: Configuring data word length (8 or 9 bits)
   :id: REQ_INT3_173102818207
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must allow the selection of data word length to either 8 or 9 bits by configuring the `USART_CR1_M` bit.

.. req:: Handling framing errors
   :id: REQ_INT3_173102818208
   :status: Draft
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must handle framing errors by checking the `USART_SR_FE` bit and generating an error condition if a framing error occurs.

.. req:: Usability
   :id: REQ_INT3_17310281820880
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must provide a user-friendly interface for configuration and management of USART communication parameters, including baud rate and pin mappings.

.. req:: Maintainability
   :id: REQ_INT3_17310281820881
   :status: Draft
   :date-released: 2024-12-02
   :priority: Medium
   :submitted-by: Lamija Fatić
   :modified-by:
   :category: Functional
   :safety-asil:
   :references:
   :verification-and-validation:

   The system must support easy maintenance, with well-documented configuration parameters and clear error logs for debugging USART communication.

	
