
#include "clock.h"
#include "stm32f4xx.h"

#define TIMEOUT_MS 32000// Vrijeme za stabilizaciju
#define HSE_VALUE 8000000 // Frekvencija HSE oscilatora

//req : The HSEON bit in the RCC_CR register must be set to enable the HSE oscillator.

// Omogućava HSE
ClockStatus enableHSE(void) {
    RCC->CR |= RCC_CR_HSEON; // Postavljanje HSE bita
    return CLOCK_OK;
}



//req: The HSERDY bit in the RCC_CR register must be checked to confirm
//the stability of the HSE oscillator.

// Provjerava stabilnost HSE
ClockStatus verifyHSEStability(void) {
    uint32_t timeout = TIMEOUT_MS;
    while (!(RCC->CR & RCC_CR_HSERDY)) {
        if (--timeout == 0) {
            return CLOCK_HSE_FAIL; // Greška
        }
    }
    return CLOCK_OK;
}

// req: The PLLM field in the RCC_PLLCFGR register must be configured
//to divide the input clock frequency by 25 to achieve a 1 MHz VCO
//input frequency.

// Konfiguriše PLLM
void configurePLLM(uint32_t pllM) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;              // Reset
    RCC->PLLCFGR |= (pllM << RCC_PLLCFGR_PLLM_Pos); // Postavljanje PLLM
}

//req: The PLLN field in the RCC_PLLCFGR register must be configured
//to multiply the VCO input frequency by 200 to achieve a 200 MHz
//VCO output frequency.

// Konfiguriše PLLN
void configurePLLN(uint32_t pllN) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;              // Reset
    RCC->PLLCFGR |= (pllN << RCC_PLLCFGR_PLLN_Pos); // Postavljanje PLLN
}

//req: The PLLP field in the RCC_PLLCFGR register must be
//configured to divide the VCO output frequency by 2 to
//achieve a 100 MHz system clock.

// Konfiguriše PLLP
void configurePLLP(PLLP_Value pllP) {
    RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;                    // Reset PLLP polja
    RCC->PLLCFGR |= ((pllP >> 1) - 1) << RCC_PLLCFGR_PLLP_Pos; // Postavljanje PLLP
}

// Omogućava PLL
ClockStatus enablePLL(void) {
    RCC->CR |= RCC_CR_PLLON; // Postavljanje PLLON bita
    return CLOCK_OK;
}


//req: The PLLRDY bit in the RCC_CR register must be checked to confirm
// that the PLL generates a stable clock signal, with an output frequency of 100 MHz.

// Provjerava stabilnost PLL-a
ClockStatus verifyPLLStability(void) {
    uint32_t timeout = TIMEOUT_MS;
    while (!(RCC->CR & RCC_CR_PLLRDY)) {
        if (--timeout == 0) {
            return CLOCK_PLL_FAIL; // Greška: PLL nije stabilizovan
        }
    }
    return CLOCK_OK;
}
//req:The SW field in the RCC_CFGR register must be set to select
//the PLL as the system clock source.
// Postavlja PLL kao izvor sistemskog takta
ClockStatus setPLLAsSystemClockSource(void) {
    RCC->CFGR &= ~RCC_CFGR_SW; // Resetuje SW polje
    RCC->CFGR |= RCC_CFGR_SW_PLL; // Postavlja PLL kao izvor sistemskog takta
    return CLOCK_OK;
}

// Provjerava da li je PLL aktivni sistemski takt
ClockStatus verifySystemClockSource(void) {
    uint32_t timeout = TIMEOUT_MS;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {
        if (--timeout == 0) {
            return CLOCK_SOURCE_FAIL; // Greška: Sistem nije prešao na PLL
        }
    }
    return CLOCK_OK;
}

// Konfiguriše AHB preskaler
void configureAHBPrescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_HPRE; // Resetuje HPRE polje, postavlja faktor podjele na 1
}

uint32_t AHBClockFrequency(){
    uint32_t actualFrequency = SystemCoreClock;
}
// Provjerava AHB frekvenciju
bool verifyAHBClockFrequency(uint32_t expectedFrequency) {
    
    return (AHBClockFrequency() == expectedFrequency);
}

// Konfiguriše APB1 preskaler
void configureAPB1Prescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_PPRE1;       // Resetuje PPRE1 polje
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;  // Postavlja faktor podjele na 2
}

// Provjerava APB1 frekvenciju
uint32_t APB1Frequency(){
     uint32_t ppre1 = (RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos;
    uint32_t divider = (ppre1 >= 4) ? (1 << (ppre1 - 3)) : 1; 
    uint32_t actualFrequency = SystemCoreClock / divider;
    return actualFrequency ;

}
bool verifyAPB1Frequency(uint32_t expectedFrequency) {
   
    return (APB1Frequency()== expectedFrequency);
}




// Konfiguriše APB2 preskaler
void configureAPB2Prescaler(void) {
    RCC->CFGR &= ~RCC_CFGR_PPRE2; // Resetuje PPRE2 polje (faktor podjele na 1, nema podjele)
}

// Provjerava APB2 frekvenciju
uint32_t APB2Frequency(){
     uint32_t ppre2 = (RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos;
    uint32_t divider = (ppre2 >= 4) ? (1 << (ppre2 - 3)) : 1; // Izračunaj faktor podjele
    uint32_t actualFrequency = SystemCoreClock / divider;
    return actualFrequency;
}
bool verifyAPB2Frequency(uint32_t expectedFrequency) {
   
    return (APB2Frequency()== expectedFrequency);
}

// Ažurira SystemCoreClock varijablu
void updateSystemCoreClock(void) {
    SystemCoreClockUpdate();

}

// Glavna funkcija za inicijalizaciju takta
ClockStatus initializeClock(const PLLConfig *config) {
    if (enableHSE() != CLOCK_OK) return CLOCK_HSE_FAIL;
    if (verifyHSEStability() != CLOCK_OK) return CLOCK_HSE_FAIL;

    configurePLLM(config->pllM);
    configurePLLN(config->pllN);
    configurePLLP(config->pllP);

    if (enablePLL() != CLOCK_OK) return CLOCK_PLL_FAIL;
    if (verifyPLLStability() != CLOCK_OK) return CLOCK_PLL_FAIL;

    if (setPLLAsSystemClockSource() != CLOCK_OK) return CLOCK_SOURCE_FAIL;
    if (verifySystemClockSource() != CLOCK_OK) return CLOCK_SOURCE_FAIL;

    configureAHBPrescaler();
    configureAPB1Prescaler();
    configureAPB2Prescaler();

    updateSystemCoreClock();

    return CLOCK_OK;
}


//preusmjeravanje USART-a na print 
