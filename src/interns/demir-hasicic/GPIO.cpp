#include "GPIO.h"
//Funkcija za aktiviranje clocka specificiranog GPIO porta 
void gpio_clock_init(GPIO_TypeDef* port) {
    if (port == GPIOA) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;       //Aktivira se clock za GPIOA port
    } else if (port == GPIOB) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    } else if (port == GPIOC) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    } else if (port == GPIOD) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    } else if (port == GPIOE) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    } else if (port == GPIOH) {
        RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
    } else return;
}

// Funkcija za postavljanje moda rada za određeni GPIO pin
void gpio_mode(GPIO_TypeDef* port, PIN pin, GPIOMODE mode)
{
  
        // Reset trenutnog moda rada za specificirani GPIO pin
    port->MODER &= ~(3<<(2*static_cast<uint8_t>(pin)));
        // Postavljanje novog moda rada za specificirani GPIO pin
    port->MODER |= (static_cast<uint8_t>(mode)<<(2*static_cast<uint8_t>(pin)));
}

//Funkcija za postavljanje izlaznog tipa (output type) za određeni GPIO pin
void gpio_output_type(GPIO_TypeDef* port, PIN pin, OTYPE type)

{
  
    //Reset trenutnog izlaznog tipa za specificirani GPIO pin
    port->OTYPER &= ~(1<<static_cast<uint8_t>(pin));
    //Postavljanje specificiranog GPIO pina na određeni izlazni tip
    port->OTYPER |= (static_cast<uint8_t>(type)<<static_cast<uint8_t>(pin));

}

//Funkcija za postavljanje brzine specificiranog GPIO pina
void gpio_speed(GPIO_TypeDef* port, PIN pin, SPEED speed)

{
        // Resetovanje trenutne brzine specificiranog GPIO pina
port->OSPEEDR &= ~(3<<(static_cast<uint8_t>(pin)*2));
        // Postavljanje nove brzine specificiranog GPIO pina
port->OSPEEDR |= (static_cast<uint8_t>(speed)<<(static_cast<uint8_t>(pin)*2));

}

//Funkcija za konfigurisanje pull-up ili pull-down otpornika za određeni GPIO pin
void gpio_pull(GPIO_TypeDef* port, PIN pin, PULL pull)
{
    //Resetovanje bita na specificiranom GPIO pinu
port->PUPDR &= ~(3<<(static_cast<uint8_t>(pin)*2));
    //Postavljanje pull-up/pull-down za specificirani GPIO pin
port->PUPDR |= (static_cast<uint8_t>(pull)<<(static_cast<uint8_t>(pin)*2));
}

//Funkcija za čitanje stanja na ulaznom pinu
PIN_STATE gpio_read(GPIO_TypeDef* port, PIN pin) {
  if(port->IDR & (1<<(static_cast<uint8_t>(pin)))){
    return PIN_STATE::HIGH;
  }
return PIN_STATE::LOW;   
}


// Funkcija za postavljanje stanja GPIO pina (HIGH ili LOW)
void gpio_set_state(GPIO_TypeDef* port, PIN pin, PIN_STATE state) {
    if (state == PIN_STATE::HIGH) {
        port->BSRR = (1 << static_cast<uint8_t>(pin)); // Postavlja pin na HIGH
    } else {
        port->BSRR = (1 << (static_cast<uint8_t>(pin) + 16)); // Postavlja pin na LOW
    }
}

void gpio_AF(GPIO_TypeDef* port, PIN pin, ALT_FUNCTION alt_function)
{
    //Postavljanje alternativne funkcije za pinove 0-7 (AFRL)
    if(static_cast<uint8_t>(pin)<=7){
        //Resetovanje 4 bita za alternativne funkcije na specificiranom pinu
        port->AFR[0] &= ~(15<<(static_cast<uint8_t>(pin)*4)); 
        //Postavljanje alternative funkcije na specificiranom pinu 
        port->AFR[0] |= (static_cast<uint8_t>(alt_function)<<(static_cast<uint8_t>(pin)*4));
}
    //Postavljanje alternativne funkcije za pinove 8-15 (AFRH)
    else if((static_cast<uint8_t>(pin))<=15){
        //Podešavanje offseta pina
        uint8_t adjusted_pin = static_cast<uint8_t>(pin) - 8;
        port->AFR[1] &= ~(15 << adjusted_pin*4);
        port->AFR[1] |= (static_cast<uint8_t>(alt_function) << adjusted_pin*4);
    }
}

void gpio_init(GPIO_TypeDef* port, PIN pin, GPIOMODE mode, OTYPE type, SPEED speed, PULL pull, ALT_FUNCTION alt_function) {
    gpio_clock_init(port);
    gpio_mode(port, pin, mode);
    gpio_output_type(port, pin, type);
    gpio_speed(port, pin, speed);
    gpio_pull(port, pin, pull);

    // Konfigurisanje alternativne funkcije ako je odabran taj mode
    if (mode == GPIOMODE::AFC) {
        gpio_AF(port, pin, alt_function);
    }
}