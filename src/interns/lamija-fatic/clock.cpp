#include "stm32f4xx.h"

#define TIMEOUT_MS 32000 
#define HSE_VALUE 8000000 
#define FLASH_LATENCY 3  


// Omogućava HSE
ClockStatus enableHSE(void) {
    RCC->CR |= RCC_CR_HSEON; // Omogućava HSE oscilator
    uint32_t timeout = TIMEOUT_MS;
    while (!(RCC->CR & RCC_CR_HSERDY)) {
        if (--timeout == 0) {
            return CLOCK_HSE_FAIL; // HSE nije stabilizovan
        }
    }
    return CLOCK_OK;
}

// Konfiguriše PLLM
void configurePLLM(uint32_t pllM) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM; // Resetuje PLLM
    RCC->PLLCFGR |= (pllM << RCC_PLLCFGR_PLLM_Pos); // Postavlja PLLM
}

// Konfiguriše PLLN
void configurePLLN(uint32_t pllN) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN; // Resetuje PLLN
    RCC->PLLCFGR |= (pllN << RCC_PLLCFGR_PLLN_Pos); // Postavlja PLLN
}

// Konfiguriše PLLP
void configurePLLP(uint32_t pllP) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP; // Resetuje PLLP
    RCC->PLLCFGR |= ((pllP >> 1) - 1) << RCC_PLLCFGR_PLLP_Pos; // Postavlja PLLP
}

// Omogućava PLL
ClockStatus enablePLL(void) {
    RCC->CR |= RCC_CR_PLLON; // Omogućava PLL
    uint32_t timeout = TIMEOUT_MS;
    while (!(RCC->CR & RCC_CR_PLLRDY)) {
        if (--timeout == 0) {
            return CLOCK_PLL_FAIL; // PLL nije stabilizovan
        }
    }
    return CLOCK_OK;
}

// Postavlja PLL kao izvor sistemskog takta
ClockStatus setPLLAsSystemClockSource(void) {
    RCC->CFGR &= ~RCC_CFGR_SW; // Resetuje SW polje
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Postavlja PLL kao izvor sistemskog takta
    uint32_t timeout = TIMEOUT_MS;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {
        if (--timeout == 0) {
            return CLOCK_SOURCE_FAIL; // Sistem nije prešao na PLL
        }
    }
    return CLOCK_OK;
}

// Konfiguriše preskaler za AHB (sistemski takt)
void configureAHBPrescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_HPRE; // Resetuje HPRE polje, postavlja faktor podjele na 1
}

// Konfiguriše preskaler za APB1
void configureAPB1Prescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_PPRE1; // Resetuje PPRE1 polje
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // Postavlja faktor podjele na 2
}

// Konfiguriše preskaler za APB2
void configureAPB2Prescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_PPRE2; // Resetuje PPRE2 polje (faktor podjele na 1, nema podjele)
}

// Ažurira SystemCoreClock varijablu
void updateSystemCoreClock(void) {
    SystemCoreClockUpdate();
}

// Glavna funkcija za inicijalizaciju takta
ClockStatus initializeClock(const PLLConfig *config) {
    // Omogućavanje HSE
    if (enableHSE() != CLOCK_OK) return CLOCK_HSE_FAIL;

    // Konfigurišemo PLLM, PLLN, PLLP
    configurePLLM(config->pllM);
    configurePLLN(config->pllN);
    configurePLLP(config->pllP);

    // Omogućavanje PLL
    if (enablePLL() != CLOCK_OK) return CLOCK_PLL_FAIL;

    // Postavljanje PLL-a kao izvor sistemskog takta
    if (setPLLAsSystemClockSource() != CLOCK_OK) return CLOCK_SOURCE_FAIL;

    // Konfiguracija preskaler-a
    configureAHBPrescaler();
    configureAPB1Prescaler();
    configureAPB2Prescaler();


    updateSystemCoreClock();

    return CLOCK_OK;
}


int main(void) {
    // Konfiguracija PLL-a za 100 MHz
    PLLConfig pllConfig = {4, 200, 2}; 

   
    if (initializeClock(&pllConfig) == CLOCK_OK) {
       
        while (1) {
          
        }
    } else {
     
        while (1) {
           
        }
    }
}
