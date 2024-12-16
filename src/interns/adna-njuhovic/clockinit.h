#ifndef CLOCKINIT_H
#define CLOCKINIT_H

#include <stdint.h>

// Structure to hold PLL configuration parameters
typedef struct {
    uint32_t pll_m;  // PLLM value (divider for input clock)
    uint32_t pll_n;  // PLLN value (multiplier for VCO output)
    uint32_t pll_p;  // PLLP value (divider for main system clock)
} PLLConfig;

bool init_clock(PLLConfig config);
void system_init(void);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
//ovaj fajl nam sluzi za deklaraciju funkcija za omogucavanje inicijalizacije 