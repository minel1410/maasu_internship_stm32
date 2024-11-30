========================
Functional requirements
========================


.. req:: label
   :id: REQ_INT3_1732999989
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall set the M and CLKEN bits in the USART_CR2 register to select the operating mode for the USART. 


  .. req:: label
     :id: REQ_INT3_1733000284
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     The system shall allow the baud rate to be programmed using the USART_BRR register based on the system clock.


.. req:: label
   :id: REQ_INT3_1733000329
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable or disable parity checking by setting  the PCE (Parity Control Enable) and PS (Parity Selection) bits.


  .. req:: label
     :id: REQ_INT3_1733000553
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     The system shall allow selection of 8-bit or 9-bit word length and 1 or 2 stop bits by setting the M1, M0, and STOP bits.

   .. req:: label
      :id: REQ_INT3_1733000634
      :status: Draft
      :date-released:
      :priority: Low
      :submitted-by: Adna Njuhovic
      :modified-by:
      :category: Functional
      :safety-asil: 
      :references: 
      :verification-and-validation: 
   
      The system shall enable or disable data transmission by setting TE bit. 


.. req:: label
   :id: REQ_INT3_1733000678
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable or disable data reception by setting the RE bit. 

.. req:: label
   :id: REQ_INT3_1733000727
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable transmission complete interrupt by setting the TCIE bit.


.. req:: label
   :id: REQ_INT3_1733000772
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable reception complete interrupt by setting the RXNEIE bit.


  .. req:: label
     :id: REQ_INT3_1733000813
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     The system shall support DMA for data transmission when the DMAT bit in the USART_CR3 register is enabled.

.. req:: label
   :id: REQ_INT3_1733000902
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall support DMA for data reception when the DMAR bit in the USART_CR3 register is enabled. 


  .. req:: label
     :id: REQ_INT3_1733000966
     :status: Draft
     :date-released:
     :priority: Low
     :submitted-by: Adna Njuhovic
     :modified-by:
     :category: Functional
     :safety-asil: 
     :references: 
     :verification-and-validation: 
  
     The system shall enable RTS (Request to Send) and CTS (Clear to Send) hardware flow control by setting the RTSE (RTS Enable) and CTSE (CTS Enable) bits in the USART_CR3 register.


.. req:: label
   :id: REQ_INT3_1733001087
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall enable LIN mode by setting the LINEN bit in the USART_CR2 register.


.. req:: label
   :id: REQ_INT3_1733001146
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Adna Njuhovic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system shall configure the clock polarity and phase for synchronous communication using the CPOL and CPHA bits. 






  

  



   
  

  
