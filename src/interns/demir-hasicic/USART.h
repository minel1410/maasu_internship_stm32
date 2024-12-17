#include <stdint.h>
#include "stm32f4xx.h"

enum class USART_STATE {
    DISABLE,
    ENABLE
};

enum class USART_OVERSAMPLING {
    OVERSAMPLING_16,
    OVERSAMPLING_8
};

enum class PPRE {
    DIV2 = 4,
    DIV4 = 5,
    DIV8 = 6,
    DIV16 = 7
};

enum class USART_MODE {
    TRANSMIT,
    RECEIVE,
    BOTH
};

void usart_clock_init(USART_TypeDef* usart);
void usart_set_state(USART_TypeDef* usart, USART_STATE state);
void usart_configure_oversampling(USART_TypeDef* usart, USART_OVERSAMPLING oversampling);
void usart_set_baudrate(USART_TypeDef* usart, uint32_t baudrate);
void usart_configure_mode(USART_TypeDef* usart, USART_MODE mode);
void usart_write_byte(USART_TypeDef* usart, uint8_t byte);
void usart_write_buffer(USART_TypeDef* usart, char *ptr, int len);
