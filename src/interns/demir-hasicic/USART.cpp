#include "USART.h"
//Funkcija za aktiviranje clocka za specificirani USART
void usart_clock_init(USART_TypeDef* usart){
    //USART1 se nalazi na APB2 pa je potrebno postaviti odgovarajući bit u APB2 registru
    if(usart==USART1){
        RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    }
    //USART2 se nalazi na APB1 pa je potrebno postaviti odgovarajući bit u APB1 registru
    else if(usart==USART2){
        RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    }
    //USART6 se nalazi na APB2 pa je potrebno postaviti odgovarajući bit u APB2 registru
    else if(usart==USART6)
    {
        RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    }
}

void usart_set_state(USART_TypeDef* usart, USART_STATE state) {
    if (state == USART_STATE::ENABLE) {
        usart->CR1 |= USART_CR1_UE;  // Uključivanje USART-a
    } 
    else {
        usart->CR1 &= ~USART_CR1_UE; // Isključivanje USART-a
    }
}

void usart_configure_oversampling(USART_TypeDef* usart, USART_OVERSAMPLING oversampling) {
    if (oversampling == USART_OVERSAMPLING::OVERSAMPLING_8) {
        usart->CR1 |= USART_CR1_OVER8; // Postavljanje na 8x oversampling
    } else {
        usart->CR1 &= ~USART_CR1_OVER8; // Postavljanje na 16x oversampling
    }
}

//Funkcija za određivanje faktora dijeljenja na osnovu vrijednosti prescalera u registru
uint32_t get_prescaler(PPRE ppre_value) {
    if (ppre_value == PPRE::DIV2) {
        return 2;  
    } else if (ppre_value == PPRE::DIV4) {
        return 4;  
    } else if (ppre_value == PPRE::DIV8) {
        return 8;  
    } else if (ppre_value == PPRE::DIV16) {
        return 16; 
    } else {
        return 1; 
    }
}

// Funkcija za postavljanje baud rate-a za specificirani USART
void usart_set_baudrate(USART_TypeDef* usart, uint32_t baudrate)
{
    uint32_t bus_frequency;
    // Određivanje frekvencije busa na osnovu odabranog USART-a
    if(usart==USART2){
    
    //Ekstrakcija prescaler vrijednosti za APB1 bus
    uint32_t ppre1 = (RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos;
    
    // Izračunavanje prescalera za APB1 na osnovu vrijednosti ppre1
    uint32_t apb1_prescaler = get_prescaler(static_cast<PPRE>(ppre1));    
    
    bus_frequency = SystemCoreClock/apb1_prescaler;
    }

    else if(usart==USART1 || usart == USART6){
    
    //Ekstrakcija prescaler vrijednosti za APB2 bus
    uint32_t ppre2 = (RCC->CFGR & RCC_CFGR_PPRE2_Msk)>> RCC_CFGR_PPRE2_Pos;
    
    // Izračunavanje prescalera za APB2 na osnovu vrijednosti ppre2 
    uint32_t apb2_prescaler = get_prescaler(static_cast<PPRE>(ppre2));
    
    bus_frequency = SystemCoreClock/apb2_prescaler;
    }
    
    uint32_t brr;
    
    // Izračunavanje BRR registra na osnovu oversampling faktora
    
    bool is_oversampling_8 = (usart->CR1 & USART_CR1_OVER8);
    
        if(is_oversampling_8)
    {
        brr = bus_frequency / (2* baudrate);
    }
    else {
        brr = bus_frequency / baudrate;
    }
    
    // Postavljanje BRR registra
    usart->BRR = brr;
}

// Funkcija za konfiguraciju načina rada USART-a
void usart_configure_mode(USART_TypeDef* usart, USART_MODE mode) {
    // Aktivacija transmisije
    if (mode == USART_MODE::TRANSMIT || mode == USART_MODE::BOTH) {
        usart->CR1 |= USART_CR1_TE; 
    }
    // Aktivacija prijema
    if (mode == USART_MODE::RECEIVE || mode == USART_MODE::BOTH) {
        usart->CR1 |= USART_CR1_RE; 
    }
}

void usart_write_byte(USART_TypeDef* usart, uint8_t byte)
{	        
    //Čekanje dok TXE postane prazan
    while(!(usart->SR & USART_SR_TXE));
	usart->DR = byte;
}

void usart_write_buffer(USART_TypeDef* usart, char *ptr, int len) {
    for (int i = 0; i < len; ++i) {
        //Čekanje dok TXE postane prazan
        while (!(usart->SR & USART_SR_TXE));
        //Upisivanje bajta u data registar
        usart->DR = ptr[i];
    }
}

void usart_init(USART_TypeDef* usart, uint32_t baudrate, USART_OVERSAMPLING oversampling = USART_OVERSAMPLING::OVERSAMPLING_16, USART_MODE mode = USART_MODE::BOTH)
{
    usart_clock_init(usart);
    usart_set_state(usart, USART_STATE::DISABLE);
    usart_configure_oversampling(usart, oversampling);
    usart_set_baudrate(usart, baudrate);
    usart_configure_mode(usart, mode);
    usart_set_state(usart, USART_STATE::ENABLE);
}
