===========================
Informational requirements 
===========================
.. req:: label
   :id: REQ_INT3_1732998234
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART module supports the following communication modes:full- duplex and half-duplex. 

  .. req:: label
     :id: REQ_INT3_1732998760
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     Full-duplex mode: Both transmission and reception occur simultaneously using separate data lines for TX (transmit) and RX (receive).

    .. req:: label
       :id: REQ_INT3_1732998795
       :status: Draft
       :date-released:
       :priority: Low
       :submitted-by: Adna Njuhovic
       :modified-by:
       :category: Functional
       :safety-asil: 
       :references: 
       :verification-and-validation: 
    
       Half-duplex mode: Transmission and reception share the same data line, operating in one direction at a time.

      .. req:: label
         :id: REQ_INT3_1732998836
         :status: Draft
         :date-released:
         :priority: Low
         :submitted-by: Adna Njuhovic
         :modified-by:
         :category: Functional
         :safety-asil: 
         :references: 
         :verification-and-validation: 
      
         Parity checking is configured using the PCE (Parity Control Enable) and PS (Parity Selection) bits.

   .. req:: label
      :id: REQ_INT3_1732998902
      :status: Draft
      :date-released:
      :priority: Low
      :submitted-by: Adna Njuhovic
      :modified-by:
      :category: Functional
      :safety-asil: 
      :references: 
      :verification-and-validation: 
   
      The USART module includes built-in error detection for the following conditions: parity, framing and overrun errors.


.. req:: label
   :id: REQ_INT3_1732998967
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Parity error detection must be used when received data does not match the configured parity.


  .. req:: label
     :id: REQ_INT3_1732999003
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     Framing error detection  must be used when validating the integrity of received data in asynchronous communication.

.. req:: label
   :id: REQ_INT3_1732999150
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Overrun error detection must be used when new data is received before the previous data is read. 


  .. req:: label
     :id: REQ_INT3_1732999242
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     Data must be transmitted through the USART_TDR (Transmit Data Register).


    .. req:: label
       :id: REQ_INT3_1732999301
       :status: Draft
       :date-released:
       :priority: Low
       :submitted-by: Adna Njuhovic
       :modified-by:
       :category: Functional
       :safety-asil: 
       :references: 
       :verification-and-validation: 
    
       Data must be received through the USART_RDR (Receive Data Register).


.. req:: label
   :id: REQ_INT3_1732999348
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   Clock phase (CPHA) and clock polarity (CPOL) must be configured using the respective bits in the USART_CR2 register.

  .. req:: label
     :id: REQ_INT3_1732999465
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     Idle line detection is supported through the IDLEIE (Idle Interrupt Enable) bit in the USART_CR1 register. 
  
.. req:: label
   :id: REQ_INT3_1732999575
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART_BRR register is used to set baud rates based on the system clock frequency. 


  .. req:: label
     :id: REQ_INT3_1732999740
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     The USART module requires a stable system clock frequency to generate the correct baud rate for communication. 
  
.. req:: label
   :id: REQ_INT3_1732999842
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock source  must be  enabled before enabling the USART module. 

    
  

  

   
      
    
  
