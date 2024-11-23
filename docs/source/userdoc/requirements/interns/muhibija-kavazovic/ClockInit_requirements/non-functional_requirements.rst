---------------------------
Non-functional requirements
---------------------------

.. req:: label
   :id: REQ_INT3_1732217804
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock initialization process must complete within a maximum of 5 milliseconds under a temperature range of 0°C to 70°C.

.. req:: label
   :id: REQ_INT3_1732374663
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock initialization process must complete within a maximum of 5 milliseconds when the system operates within a regulated voltage range of 3.3V ± 5%.


.. req:: label
   :id: REQ_INT3_1732229536
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system clock accuracy must be maintained within ±50 ppm (parts per million), ensuring precise timekeeping across all configurations and operating conditions.

.. req:: label
   :id: REQ_INT3_1732229582
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must ensure stable clock operation under power supply variations of ±5% of the nominal voltage (3.3V), without affecting the performance or reliability of the clock functionality.

.. req:: label
   :id: REQ_INT3_1732229641
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must limit power consumption during clock initialization to no more than 10mW to ensure efficient operation during this critical phase.

.. req:: label
   :id: REQ_INT3_1732375246
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must limit power consumption in low-power modes to no more than 10mW to ensure efficient operation in energy-constrained environments.


.. req:: label
   :id: REQ_INT3_1732229721
   :status: Draft
   :date-released:
   :priority: Medium
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must recover from clock initialization failures within a maximum of 10 milliseconds to ensure minimal disruption to overall system performance.
