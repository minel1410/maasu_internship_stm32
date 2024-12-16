#ifndef USART_H
#define USART_H

#include "stm32f411xe.h"

namespace USART {

    // Function declarations
    void enableClock(USART_TypeDef* usartBase);
    void setBaudRate(USART_TypeDef* usartBase, uint32_t clockFreq, uint32_t baudRate, bool oversample8 = false);
    void setOversampling(USART_TypeDef* usartBase, bool oversample8);
    void enableUSART(USART_TypeDef* usartBase);
    void disableUSART(USART_TypeDef* usartBase);
    void write_byte(USART_TypeDef* usartBase, uint8_t byte);
    void enableTransmitter(USART_TypeDef* usartBase, bool enable = true);
    void enableReceiver(USART_TypeDef* usartBase, bool enable = true);
    void initUSART(USART_TypeDef* usartBase, uint32_t clockFreq, uint32_t baudRate, bool enableTx = true, bool enableRx = false, bool oversample8 = false);

} // namespace USART

void setActiveUSART(USART_TypeDef* usartBase);
extern "C" int _write(int file, char* ptr, int len);

#endif // USART_H