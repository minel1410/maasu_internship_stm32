==============================
Functional Requirements
==============================

.. req:: label
   :id: REQ_INT3_1733105374
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must enable the clock using the RCC register.


.. req:: label
   :id: REQ_INT3_1733105428
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system should allow the usage of different USART peripherals.


.. req:: label
   :id: REQ_INT3_1733105477
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must ensure that the USART peripheral is enabled by setting the bits in the USART_CR1 register for operation. 


.. req:: label
   :id: REQ_INT3_1733105521
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART module must initialize both the receiver (RX) and transmitter (TX) pins to the input or output configuration.


.. req:: label
   :id: REQ_INT3_1733105581
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART module must configure pins for alternate functions.


.. req:: label
   :id: REQ_INT3_1733105620
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow the user to choose between USART modes.


.. req:: label
   :id: REQ_INT3_1733105665
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must be able to choose between types of oversampling.


.. req:: label
   :id: REQ_INT3_1733105717
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow the selection of baud rate for communication.


.. req:: label
   :id: REQ_INT3_1733105766
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow enabling data sending using CR1.


.. req:: label
   :id: REQ_INT3_1733105806
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must check if the Transmit Data Register is empty and ready to receive a byte for transfer.


.. req:: label
   :id: REQ_INT3_1733105856
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow checking if the data transmission is completed using DR. 


.. req:: label
   :id: REQ_INT3_1733105903
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow receiving data using CR1.


.. req:: label
   :id: REQ_INT3_1733105953
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must allow reception of one byte of data at a time through USART by reading from the data register.


.. req:: label
   :id: REQ_INT3_1733105997
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must check if the byte of data is available on the data register.


.. req:: label
   :id: REQ_INT3_1733082605
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Non Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must ensure that the transmitted and received data remains uncorrupted.


.. req:: label
   :id: REQ_INT3_1733082629
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Non Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART must synchronize with the system clock or external clock source.


.. req:: label
   :id: REQ_INT3_1733082685
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Non Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system should allow simultaneous communication with multiple external devices.


.. req:: label
   :id: REQ_INT3_1733082711
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Tarik Sinanovic
   :modified-by:
   :category: Non Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART configuration must be configurable through software.