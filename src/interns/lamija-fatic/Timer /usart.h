#ifndef USART_H
#define USART_H

#include <stdint.h>


void usart2_init(uint32_t baud_rate);
void usart2_send_char(char c);
void usart2_send_string(const char *str);
void usart2_send_number(uint32_t num);

#endif 