--------------------------
Informational requirements
--------------------------

.. req:: label
   :id: REQ_INT3_1732092747
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **General information:**

   The clock initialization function is responsible for configuring the system clock to ensure the microcontroller operates at the desired frequency. 
   This process is crucial for synchronizing the core, peripherals, and external interfaces.

.. req:: label
   :id: REQ_INT3_1732230182
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **Design Considerations**

   - **Clock Sources**:

   - Internal and external clock sources should be supported to provide flexibility in application-specific designs.

   The primary sources include:
    - **High-Speed Internal (HSI) Oscillator**: A built-in clock for low-power applications.

    - **High-Speed External (HSE) Oscillator**: An external crystal for precise timing.

    - **Phase-Locked Loop (PLL)**: A frequency multiplier to achieve higher system clock speeds.

.. req:: label
   :id: REQ_INT3_1732230545
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **PLL Configuration Parameters**:
    - **PLLM**: Divides the input clock to a lower frequency.
    - **PLLN**: Multiplies the divided clock to achieve the desired frequency.
    - **PLLP**: Divides the multiplied clock to produce the final system clock frequency.

.. req:: label
   :id: REQ_INT3_1732230707
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **Target Configuration**:

   The system clock can be configured using the following formula:

   .. math::

      PLLCLK = \frac{f_{\text{INPUT}}}{\text{PLLM}} \times \text{PLLN} / \text{PLLP}

   Where:

   - **finput**: Input clock frequency (e.g., HSE or HSI).
   - **PLLM**: Input clock divider.
   - **PLLN**: Multiplier for the intermediate frequency.
   - **PLLP**: Divider to achieve the final output frequency.

.. req:: label
   :id: REQ_INT3_1732231126
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **Clock Tree**:

   - The system clock should be distributed to multiple buses and peripherals, such as the AHB, APB1, and APB2 buses, ensuring each operates within its frequency range.

.. req:: label
   :id: REQ_INT3_1732231183
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Muhibija Kavazovic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   **Technical Background**

   - Clock initialization involves selecting the clock source, configuring parameters like dividers and multipliers, and routing the clock to the system components.

   - The system clock must maintain stability and accuracy across all configurations.
   
   - Error handling should address clock startup failures or misconfigurations.


   