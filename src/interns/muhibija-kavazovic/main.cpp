#include "gpio.h"
#include "stm32f4xx.h"  

int main() {
    // Inicijalizacija GPIOA, pin 5 
    GPIO gpio(GPIOA, GPIOConfig::Pin::P5);

    // Omogućavanje clock-a za GPIO port
    gpio.enableClock();

    // Konfigurisanje pina kao izlaz (output)
    gpio.setMode(GPIOConfig::Mode::Output);

    // Konfigurisanje pull-up rezistora
    gpio.setPull(GPIOConfig::Pull::None);

    // Postavljanje brzine (High speed)
    gpio.setSpeed(GPIOConfig::Speed::High);

    // Konfigurisanje izlaznog tipa kao push-pull
    gpio.configureOutputType(GPIOConfig::OutputType::PushPull);

    gpio.write(true);

    while (1) {
    
        gpio.toggle();
        for (volatile int i = 0; i < 1000000; ++i) {}
    }

    return 0;
}
