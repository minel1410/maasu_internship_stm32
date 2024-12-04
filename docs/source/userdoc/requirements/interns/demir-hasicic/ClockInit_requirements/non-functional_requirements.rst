===========================
Non-Functional Requirements
===========================

.. req:: TimingConstraint
   :id: REQ_INT3_1732140084
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock initialization process must complete within 2 milliseconds.

.. req:: InterferenceMinimization
   :id: REQ_INT3_1732217665
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The clock initialization must not disrupt ongoing peripheral operations.

.. req:: SwitchToHSIOnFailure
   :id: REQ_INT3_1732217305
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   In case of oscillator failure, the system must switch to HSI as the clock source.

.. req:: NotifyUserOnFailure
   :id: REQ_INT3_1732217396
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The system must notify the user of an oscillator failure through status bits.
