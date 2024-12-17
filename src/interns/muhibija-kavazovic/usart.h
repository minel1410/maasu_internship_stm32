#include "stm32f411xe.h" 
#include <string>

class USART {
public:
    enum class WordLength { Bits8 = 0, Bits9 = 1 };
    enum class StopBits { Bits1 = 0, Bits2 = 1 };
    enum class Parity { None = 0, Even = 1, Odd = 2 };

    // Konstruktor
    USART(USART_TypeDef* usart, uint32_t clockFreq);

    // Osnovne funkcionalnosti
    void enable();
    void configureBaudRate(uint32_t baudrate); // Verzija bez zaokruživanja
    void configureBaudRateRounded(uint32_t baudrate); // Verzija sa zaokruživanjem
    void configure(WordLength wordLength, StopBits stopBits, Parity parity);
    void sendChar(char c);
    void sendString(const std::string& str);
    char receiveChar();

    // SysClock (ako je potrebno)
    static void configureSysClock();

private:
    USART_TypeDef* m_usart;  // USART instanca (USART1, USART2...)
    uint32_t m_clockFreq;    // Clock frekvencija sistema
};