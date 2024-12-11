
#define CLOCK_H

#include "stm32f411xe.h"
#include <stdint.h>

//inicijalizacije

// Enum za PLLP vrijednosti

typedef enum {
    CLOCK_OK = 0,
    CLOCK_HSE_FAIL,
    CLOCK_PLL_FAIL,
    CLOCK_SOURCE_FAIL,
    CLOCK_AHB_FREQ_FAIL,
    CLOCK_APB1_FREQ_FAIL,
    CLOCK_APB2_FREQ_FAIL
} ClockStatus;

typedef enum {
    PLLP_DIV2 = 2,
    PLLP_DIV4 = 4,
    PLLP_DIV6 = 6,
    PLLP_DIV8 = 8
} PLLP_Value;

//  konfiguracija PLL
typedef struct {
    uint32_t pllM; // PLLM vrijednost
    uint32_t pllN; // PLLN vrijednost
    PLLP_Value pllP; // PLLP vrijednost
} PLLConfig;

//  HSE
ClockStatus enableHSE(void);
ClockStatus verifyHSEStability(void);

 //PLL
void configurePLLM(uint32_t pllM);
void configurePLLN(uint32_t pllN);
void configurePLLP(uint32_t pllP);
void configurePLL(const PLLConfig *config);
ClockStatus enablePLL(void);
ClockStatus verifyPLLStability(void);

//  sistemski clock
ClockStatus setSystemClockSource(void);
ClockStatus verifySystemClockSource(void);

//  preskaleri
void configureAHBPrescaler(void);
bool verifyAHBClockFrequency(uint32_t expectedFrequency);
void configureAPB1Prescaler(void);
bool verifyAPB1Frequency(uint32_t expectedFrequency);
void configureAPB2Prescaler(void);
bool verifyAPB2Frequency(uint32_t expectedFrequency);

// ažuriranje i verifikacija frekvencija
void updateSystemCoreClock(void);
uint8_t verifyClockFrequencies(uint32_t ahbFreq, uint32_t apb1Freq, uint32_t apb2Freq);

// inicijalizacija takta
ClockStatus initializeClock(const PLLConfig *config);

/*ClockStatus initializeClockWithRetry(const PLLConfig *config, uint8_t maxRetries);  
#endif // CLOCK_H*/