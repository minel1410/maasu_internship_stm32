===============================================================
Functional Requirements for the Clock Initialization Function
===============================================================
.. req:: label
   :id: REQ_INT3_1732230528
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Emina Mesic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

   The functional requirements specify the steps to configure the STM32F411 microcontroller's clock system for operation at 100 MHz. These include enabling the HSE clock source, configuring the PLL with specific parameters, setting the system clock to PLL, adjusting prescaler settings, verifying clock stability, and handling errors with timeout and retry mechanisms to ensure robust clock initialization.


Enable HSE Clock Source
  1. The function must enable the HSE clock source by setting the ``HSEON`` bit in the ``RCC_CR`` register to 1.

PLL Configuration for 100 MHz
  2. The function must set the ``PLLSRC`` bit in the ``RCC_PLLCFGR`` register to **1** to select HSE as the PLL input source.
  3. The function must set the ``PLLM`` value in the ``RCC_PLLCFGR`` register to **25**.
  4. The function must set the ``PLLN`` value in the ``RCC_PLLCFGR`` register to **200**.
  5. The function must set the ``PLLP`` value in the ``RCC_PLLCFGR`` register to **2**.
  6. The function must enable the PLL by setting the ``PLLON`` bit in the ``RCC_CR`` register to **1**.

Set PLL as System Clock
  7. The function must set the system clock to PLL by setting the ``SW`` bits in the ``RCC_CFGR`` register to **10**.
 
Clock Prescaler Configuration:
  8. The function must configure the ``HPRE`` bits in the ``RCC_CFGR`` register to set the AHB prescaler to **1**.
  9. The function must configure the ``PPRE1`` bits in the ``RCC_CFGR`` register to set the APB1 prescaler to **2**.
  10. The function must configure the ``PPRE2`` bits in the ``RCC_CFGR`` register to set the APB2 prescaler to **1**.

Verify Clock Configuration:
  11. The function shall verify that the ``HSERDY`` bit in the ``RCC_CR`` register is set to **1**.
  12. The function shall verify that the ``PLLRDY`` bit in the ``RCC_CR`` register is set to **1**.
  13. The function shall verify that the ``SWS`` bits in the ``RCC_CFGR`` register are set to **10**.
  14. The function shall call the *SystemCoreClockUpdate()* function.

Error Handling for Clock Stabilization
  15. The function must implement a timeout mechanism of 1 ms to monitor the stabilization of the HSE (``HSERDY`` bit in ``RCC_CR``).
  16. The function must implement a timeout mechanism of 1 ms to monitor the stabilization of the PLL (``PLLRDY`` bit in ``RCC_CR``)
  17. If the ``HSERDY`` bit is not set within the timeout period of 1 ms, the function must trigger an error-handling mechanism that retries the operation up to 3 times.
  18. If the ``PLLRDY`` bit is not set within the timeout period of 1 ms, the function must trigger an error-handling mechanism that retries the operation up to 3 times.
  19. If the error-handling retry attempts fail the 3rd time, the function must return an error code indicating a clock initialization failure.
