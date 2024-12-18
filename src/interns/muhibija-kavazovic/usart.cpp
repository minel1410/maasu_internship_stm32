#include "usart.h"

// Konstruktor za inicijalizaciju privatnih članova klase
USART::USART(USART_TypeDef* usart, uint32_t clockFreq)
    : m_usart(usart), m_clockFreq(clockFreq) {}

// Omogućava clock za USART periferiju i aktivira USART
void USART::enable() {
    if (m_usart == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (m_usart == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (m_usart == USART6) RCC->APB2ENR |= RCC_APB2ENR_USART6EN;

    m_usart->CR1 |= USART_CR1_UE; // Omogući USART
}

// Verzija bez zaokruživanja
void USART::configureBaudRate(uint32_t baudrate) {
    uint32_t usartDiv = m_clockFreq / baudrate;
    m_usart->BRR = usartDiv;
}

// Verzija sa zaokruživanjem
void USART::configureBaudRateRounded(uint32_t baudrate) {
    uint32_t usartDiv = (m_clockFreq + (baudrate / 2)) / baudrate;
    m_usart->BRR = usartDiv;
}

// Konfiguracija parametara za USART
void USART::configure(WordLength wordLength, StopBits stopBits, Parity parity) {
    // Konfiguracija dužine riječi
    if (wordLength == WordLength::Bits9) m_usart->CR1 |= USART_CR1_M;
    else m_usart->CR1 &= ~USART_CR1_M;

    // Konfiguracija stop bitova
    m_usart->CR2 &= ~USART_CR2_STOP;
    if (stopBits == StopBits::Bits2) m_usart->CR2 |= (2U << USART_CR2_STOP_Pos);

    // Konfiguracija pariteta
    if (parity == Parity::None) m_usart->CR1 &= ~USART_CR1_PCE;
    else {
        m_usart->CR1 |= USART_CR1_PCE;
        if (parity == Parity::Odd) m_usart->CR1 |= USART_CR1_PS;
        else m_usart->CR1 &= ~USART_CR1_PS;
    }
}

// Slanje jednog karaktera
void USART::sendChar(char c) {
    while (!(m_usart->SR & USART_SR_TXE)); // Čekaj dok je TX buffer prazan
    m_usart->DR = c;
}

// Slanje stringa
void USART::sendString(const std::string& str) {
    for (char c : str) {
        sendChar(c);
    }
}

// Prijem jednog karaktera
char USART::receiveChar() {
    while (!(m_usart->SR & USART_SR_RXNE)); // Čekaj dok RX buffer nije pun
    return static_cast<char>(m_usart->DR);
}

// Konfiguracija System Clock-a 
void USART::configureSysClock() {
    RCC->CR |= RCC_CR_HSION; // Omogući HSI (High-Speed Internal)
    while (!(RCC->CR & RCC_CR_HSIRDY)); // Čekaj da HSI stabilizuje

    RCC->CFGR &= ~RCC_CFGR_SW; // Konfiguracija System Clock na HSI
    RCC->CFGR |= RCC_CFGR_SW_HSI;
}
