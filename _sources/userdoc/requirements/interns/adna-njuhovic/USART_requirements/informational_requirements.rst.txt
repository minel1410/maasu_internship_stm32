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
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART module must provide information about its supported communication modes .  

.. req:: label
   :id: REQ_INT3_1732998760
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 
  
   The USART module must provide information about the full-duplex mode. 

.. req:: label
   :id: REQ_INT3_1733092500
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   In full-duplex mode, both transmission and reception occur simultaneously using separate data lines for TX and RX. 
  
    
      
.. req:: label
   :id: REQ_INT3_1733092858
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational
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
   :category: Informational 
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   The USART module includes built-in error detection for the following conditions: parity, framing and overrun errors.



.. req:: label
   :id: REQ_INT3_1732999465
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Informational 
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
   :category: Informational
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
   :category: Informational
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
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The USART module provides details about the supported data word lengths,  8-bit or 9-bit. 
    

    
  

  

   
      
    
  
