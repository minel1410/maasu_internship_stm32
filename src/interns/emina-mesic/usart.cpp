#include "usart.h"

namespace USART {

    void enableClock(USART_TypeDef* usartBase) {
        if (usartBase == USART1) 
            RCC->APB2ENR |= RCC_APB2ENR_USART1EN; 
        else if (usartBase == USART2) 
            RCC->APB1ENR |= RCC_APB1ENR_USART2EN; 
        else if (usartBase == USART6) 
            RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    }


    void setOversampling(USART_TypeDef* usartBase, bool oversample8) {
        if (oversample8) 
            usartBase->CR1 |= USART_CR1_OVER8;  // Enable oversampling by 8
        else 
            usartBase->CR1 &= ~USART_CR1_OVER8; // Set oversampling to 16
    }

    void setBaudRate(USART_TypeDef* usartBase, uint32_t clockFreq, uint32_t baudRate, bool oversample8) {
        if (oversample8) 
            usartBase->BRR = clockFreq / (2 * baudRate) + 0.5f;
        else 
            usartBase->BRR = clockFreq / baudRate + 0.5f;
    }

    void enableUSART(USART_TypeDef* usartBase) {
        usartBase->CR1 |= USART_CR1_UE;
    }

    void disableUSART(USART_TypeDef* usartBase) {
        usartBase->CR1 &= ~USART_CR1_UE;
    }


    void write_byte(USART_TypeDef* usartBase, uint8_t byte) {
    // First we have to check if TXE is empty
        while (!(usartBase->SR & USART_SR_TXE));
        usartBase->DR = byte;   
    }

    void write_bytes(USART_TypeDef* usartBase, const uint8_t *word, unsigned int len) {
        for (unsigned int i = 0; i < len; ++i) {
            write_byte(usartBase, word[i]);
        }
    }

    void enableTransmitter(USART_TypeDef* usartBase, bool enable) {
        if (enable) 
            usartBase->CR1 |= USART_CR1_TE;  // Set TE bit to enable transmitter
        else 
            usartBase->CR1 &= ~USART_CR1_TE; // Clear TE bit to disable transmitter
    }

    void enableReceiver(USART_TypeDef* usartBase, bool enable) {
        if (enable)
            usartBase->CR1 |= USART_CR1_RE;  // Set RE bit to enable receiver
        else
            usartBase->CR1 &= ~USART_CR1_RE; // Clear RE bit to disable receiver
    }

    void initUSART(USART_TypeDef* usartBase, uint32_t clockFreq, uint32_t baudRate, bool enableTx, bool enableRx, bool oversample8) {
        // Enable the clock for the specified USART
        enableClock(usartBase);

        // Disable USART during configuration
        disableUSART(usartBase);

        // Set oversampling mode
        setOversampling(usartBase, oversample8);

        // Set the baud rate
        setBaudRate(usartBase, clockFreq, baudRate, oversample8);

        // Enable the transmitter and receiver if needed
        enableTransmitter(usartBase, enableTx);
        enableReceiver(usartBase, enableRx);

        // Enable the USART
        enableUSART(usartBase);

        // If USART2 is not chosen, set the active USART (in syscalls.cpp)
        if (usartBase != USART2) {
            setActiveUSART(usartBase);
        }
    }
} // namespace USART

