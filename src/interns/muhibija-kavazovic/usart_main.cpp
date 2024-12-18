#include "usart.h"

int main() {
    USART usart(USART1, 16000000); // USART1 sa System Clock 16 MHz

    usart.configureSysClock();
    usart.enable();
    usart.configure(USART::WordLength::Bits8, USART::StopBits::Bits1, USART::Parity::None);
    usart.configureBaudRate(9600);          // Verzija bez zaokruživanja
    usart.configureBaudRateRounded(9600);   // Verzija sa zaokruživanjem

    usart.sendString("Hello, USART. It's Muhibija.!\n");

    while (true) {
        char received = usart.receiveChar();
        usart.sendChar(received); // Eho karaktera
    }

    return 0;
}
