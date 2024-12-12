#include "stm32f4xx.h" 
#include "clockinit.h"
#include <stdint.h>

#define TIMEOUT 100        // Timeout in milliseconds
#define MAX_RETRIES 3      // Max retries for error handling

// Function to initialize the system clock
bool init_clock(PLLConfig config) {
    uint32_t start_time, elapsed_time, retry_count = 0;

    while (retry_count < MAX_RETRIES) {
        // Step 1: Enable HSE clock source (High-Speed External oscillator)
        RCC->CR |= RCC_CR_HSEON;

        // : Wait for HSE to stabilize by polling the HSE ready flag
        start_time = SystemCoreClock;
        while (!(RCC->CR & RCC_CR_HSERDY)) {
            elapsed_time = SystemCoreClock - start_time;
            if (elapsed_time >= TIMEOUT) {
                retry_count++;
                // Disable HSE if it fails to stabilize within the timeout period
                RCC->CR &= ~RCC_CR_HSEON;

                if (retry_count == MAX_RETRIES) {
                    // Exit if maximum retries are reached
                    return false;
                }
                break; // Exit inner loop to retry enabling HSE
            }
        }

        // If HSE didn't stabilize, proceed with the next retry
        if (retry_count > 0) continue;

        // : Configure PLL source and parameters
        // Set HSE as the PLL source and configure PLLM, PLLN, and PLLP
        RCC->PLLCFGR = (RCC_PLLCFGR_PLLSRC_HSE) |
                       (config.pll_m << RCC_PLLCFGR_PLLM_Pos) |  // PLLM configuration
                       (config.pll_n << RCC_PLLCFGR_PLLN_Pos) |  // PLLN configuration
                       ((config.pll_p >> 1) - 1) << RCC_PLLCFGR_PLLP_Pos; // PLLP configuration

        // : Configure prescalers for AHB, APB1, and APB2 buses
        RCC->CFGR |= RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV1;

        // : Enable PLL
        RCC->CR |= RCC_CR_PLLON;

        // : Wait for PLL to stabilize by polling the PLL ready flag
        start_time = SystemCoreClock;
        while (!(RCC->CR & RCC_CR_PLLRDY)) {
            elapsed_time = SystemCoreClock - start_time;
            if (elapsed_time >= TIMEOUT) {
                retry_count++;
                // Disable PLL if it fails to stabilize within the timeout period
                RCC->CR &= ~RCC_CR_PLLON;

                if (retry_count == MAX_RETRIES) {
                    // Exit if maximum retries are reached
                    return false;
                }
                break; // Exit inner loop to retry enabling PLL
            }
        }

        // If PLL didn't stabilize, proceed with the next retry
        if (retry_count > 0) continue;

        // : Set the system clock source to PLL
        RCC->CFGR |= RCC_CFGR_SW_PLL;

        // : Verify that the system clock source has switched to PLL
        if ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {
            retry_count++;
            if (retry_count == MAX_RETRIES) {
                // Exit if the system clock switch fails after maximum retries
                return false;
            }
            continue;
        }

        // : Update the SystemCoreClock variable to reflect the new clock settings
        SystemCoreClockUpdate();

        // Clock initialization successful, exit the function
        return true;
    }

    return false;
}

// Global initialization function
void system_init(void) {
    // Example clock configuration
    PLLConfig clock_config = {25, 200, 2}; // PLLM = 25, PLLN = 200, PLLP = 2

    // Initialize the system clock
    init_clock(clock_config);
//FIXED: dodana global function for initialization, dodana pll konfig., Makefile edited i includean clockinit 
    
}
