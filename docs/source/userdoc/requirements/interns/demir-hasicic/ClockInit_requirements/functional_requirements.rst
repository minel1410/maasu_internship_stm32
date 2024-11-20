==========================
Functional Requirements
==========================
.. req:: label
   :id: REQ_INT3_1732140048
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Demir Hasicic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 
   
1. **EnableHSEOscillator**
   - EnableHSEOscillator must set the HSEON bit in the RCC_CR register to enable the HSE oscillator.

2. **VerifyHSEStability**
   - VerifyHSEStability must confirm that the HSERDY bit in the RCC_CR register is set, indicating that the HSE oscillator is stable and ready.

3. **SetPLLM**
   - SetPLLM must configure the PLLM field in the RCC_PLLCFGR register to 25, dividing the 25 MHz input clock by 25 to achieve a 1 MHz VCO input frequency.

4. **SetPLLN**
   - SetPLLN must configure the PLLN field in the RCC_PLLCFGR register to 200, multiplying the 1 MHz VCO input frequency by 200 to achieve a 200 MHz VCO output frequency.

5. **SetPLLP**
   - SetPLLP must configure the PLLP field in the RCC_PLLCFGR register to 2, dividing the 200 MHz VCO output frequency by 2 to achieve a 100 MHz system clock.

6. **VerifyPLLStability**
   - VerifyPLLStability must confirm that the PLLRDY bit in the RCC_CR register is set, indicating that the PLL generates a stable clock signal with an output frequency of 100 MHz.

7. **SetSystemClockSourceToPLL**
   - SetSystemClockSourceToPLL must set the SW field in the RCC_CFGR register to select the PLL as the system clock source.

8. **VerifySystemClockSourceIsPLL**
   - VerifySystemClockSourceIsPLL must confirm that the SWS field in the RCC_CFGR register indicates that the PLL is the active system clock source.

9. **SetAHBPrescaler**
   - SetAHBPrescaler must configure the HPRE field in the RCC_CFGR register to 0 (no division).

10. **VerifyAHBClockFrequency**
    - VerifyAHBClockFrequency must confirm that the AHB clock operates at 100 MHz.

11. **SetAPB1Prescaler**
    - SetAPB1Prescaler must configure the PPRE1 field in the RCC_CFGR register to 4 (divide by 2).

12. **VerifyAPB1ClockFrequency**
    - VerifyAPB1ClockFrequency must confirm that the APB1 clock operates at 50 MHz.

13. **SetAPB2Prescaler**
    - SetAPB2Prescaler must configure the PPRE2 field in the RCC_CFGR register to 0 (no division).

14. **VerifyAPB2ClockFrequency**
    - VerifyAPB2ClockFrequency must confirm that the APB2 clock operates at 100 MHz.

15. **ValidateHSEConfiguration**
    - ValidateHSEConfiguration must confirm that the HSERDY bit in the RCC_CR register is set, indicating the HSE oscillator is stable.

16. **ValidatePLLConfiguration**
    - ValidatePLLConfiguration must confirm that the PLLRDY bit in the RCC_CR register is set, ensuring that the PLL is stable.

17. **ValidateSystemClockSource**
    - ValidateSystemClockSource must confirm that the SWS field in the RCC_CFGR register indicates that the PLL is the system clock source.

18. **ValidateClockFrequencies**
    - ValidateClockFrequencies must confirm that the AHB clock operates at 100 MHz, the APB1 clock operates at 50 MHz, and the APB2 clock operates at 100 MHz.

19. **SystemCoreClockUpdate**
    - SystemCoreClockUpdate must ensure the variable reflects the actual system clock frequency of 100 MHz by reading the RCC register settings, including the SW, HPRE, PPRE1, and PPRE2 fields, and calculating the resulting clock frequency based on these configurations.
