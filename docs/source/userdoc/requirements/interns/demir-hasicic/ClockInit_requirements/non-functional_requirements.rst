==========================
Non-Functional Requirements
==========================
.. req:: label
   :id: REQ_INT3_1732140084
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
   1. **Timing Constraint**
   - The clock initialization process must complete within 2 milliseconds to ensure fast system startup.

   2. **Interference Minimization**
   - The clock initialization must not disrupt ongoing peripheral operations, and any changes to clock sources must gracefully fall back to HSI if needed.

   3. **Fault Tolerance**
   - The system must detect and recover from oscillator failures by switching to HSI and notifying the user through status bits if HSE or PLL initialization fails.
