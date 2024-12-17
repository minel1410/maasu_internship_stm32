#include "stm32f4xx.h"
#include "gpio.h"

class Timer {
private:
    enum class TimerType {
        TIM1, TIM2, TIM3, TIM4, TIM5
    };
    
    TimerType timerType;           // Tip timera koji se koristi
    TIM_TypeDef* timer;           // Pointer na timer registre
    GPIO_TypeDef* gpio;           // Pointer na GPIO registre
    uint32_t channel;             // PWM kanal (1-4)
    uint32_t pin;                 // GPIO pin broj
    uint32_t alternate_function;   // Alternativna funkcija za GPIO pin
    uint32_t bus_freq;           // Frekvencija bus-a na kojem je timer

public:
    // Konstruktor - inicijalizira sve potrebne parametre za timer
    Timer(TimerType tim, GPIO_TypeDef* gp, uint32_t ch, uint32_t p, uint32_t af, uint32_t freq)
        : timerType(tim), gpio(gp), channel(ch), pin(p), alternate_function(af), bus_freq(freq) {
        // Mapiranje enum vrijednosti na konkretne timer instance
        switch(timerType) {
            case TimerType::TIM1: timer = TIM1; break;
            case TimerType::TIM2: timer = TIM2; break;
            case TimerType::TIM3: timer = TIM3; break;
            case TimerType::TIM4: timer = TIM4; break;
            case TimerType::TIM5: timer = TIM5; break;
        }
    }

    // Inicijalizacija PWM-a sa željenom frekvencijom i duty cycle-om
    bool initPWM(uint32_t desired_freq, uint8_t duty_cycle) {
        if (duty_cycle > 100) return false;
        if (desired_freq > bus_freq) return false;

        // 1. Timer clock enable - ostaje isto
        switch(timerType) {
            case TimerType::TIM1:
                RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
                break;
            case TimerType::TIM2:
                RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
                break;
            case TimerType::TIM3:
                RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
                break;
            case TimerType::TIM4:
                RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
                break;
            case TimerType::TIM5:
                RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
                break;
        }

        // 2. GPIO konfiguracija - sa Emininim kodom
        GPIO::GPIOHandler gpioHandler;
        GPIO::Port gpioPort;

        // Mapiranje GPIO porta u Eminin enum
        if (gpio == GPIOA) { 
            gpioHandler.enableClock(GPIO::Port::A); 
            gpioPort = GPIO::Port::A; 
        }
        else if (gpio == GPIOB) { 
            gpioHandler.enableClock(GPIO::Port::B); 
            gpioPort = GPIO::Port::B; 
        }
        else if (gpio == GPIOC) { 
            gpioHandler.enableClock(GPIO::Port::C); 
            gpioPort = GPIO::Port::C; 
        }
        else if (gpio == GPIOD) { 
            gpioHandler.enableClock(GPIO::Port::D); 
            gpioPort = GPIO::Port::D; 
        }
        else if (gpio == GPIOE) { 
            gpioHandler.enableClock(GPIO::Port::E); 
            gpioPort = GPIO::Port::E; 
        }
        else if (gpio == GPIOH) { 
            gpioHandler.enableClock(GPIO::Port::H); 
            gpioPort = GPIO::Port::H; 
        }

        // Konfiguracija pina koristeći Eminin interfejs
        gpioHandler.configurePin(
            gpioPort,                                         // Port iz Emininog enuma
            static_cast<GPIO::Pin>(pin),                     // Konverzija pin broja u Eminin Pin enum
            GPIO::Mode::Alternate,                           // Mode za PWM
            GPIO::Pull::None,                                // Bez pull-up/down
            GPIO::Speed::High,                               // Visoka brzina za PWM
            GPIO::OutputType::PushPull,                      // Push-pull output
            static_cast<GPIO::AlternateFunction>(alternate_function)  // Alternativna funkcija
        );

        // 3. Timer konfiguracija
        uint32_t max_arr = 65535;  // Maksimalna vrijednost auto-reload registra
        // Računanje prescaler i auto-reload vrijednosti za željenu frekvenciju
        uint32_t prescaler = (bus_freq / (desired_freq * max_arr)) + 1;
        uint32_t arr = (bus_freq / (desired_freq * prescaler)) - 1;

        timer->PSC = prescaler - 1;  // Postavljanje prescaler vrijednosti
        timer->ARR = arr;            // Postavljanje auto-reload vrijednosti

        // 4. PWM konfiguracija za odabrani kanal
        switch(channel) {
            case 1:  // Kanal 1
                timer->CCMR1 &= ~TIM_CCMR1_OC1M;     // Brisanje mode bits
                timer->CCMR1 |= (6U << 4);           // PWM mode 1
                timer->CCMR1 |= TIM_CCMR1_OC1PE;     // Enable preload
                timer->CCR1 = (duty_cycle * (arr + 1)) / 100;  // Postavljanje duty cycle-a
                timer->CCER |= TIM_CCER_CC1E;        // Omogućavanje izlaza
                break;
            case 2:  // Kanal 2
                timer->CCMR1 &= ~TIM_CCMR1_OC2M;
                timer->CCMR1 |= (6U << 12);
                timer->CCMR1 |= TIM_CCMR1_OC2PE;
                timer->CCR2 = (duty_cycle * (arr + 1)) / 100;
                timer->CCER |= TIM_CCER_CC2E;
                break;
            case 3:  // Kanal 3
                timer->CCMR2 &= ~TIM_CCMR2_OC3M;
                timer->CCMR2 |= (6U << 4);
                timer->CCMR2 |= TIM_CCMR2_OC3PE;
                timer->CCR3 = (duty_cycle * (arr + 1)) / 100;
                timer->CCER |= TIM_CCER_CC3E;
                break;
            case 4:  // Kanal 4
                timer->CCMR2 &= ~TIM_CCMR2_OC4M;
                timer->CCMR2 |= (6U << 12);
                timer->CCMR2 |= TIM_CCMR2_OC4PE;
                timer->CCR4 = (duty_cycle * (arr + 1)) / 100;
                timer->CCER |= TIM_CCER_CC4E;
                break;
        }

        // 5. Omogućavanje timer-a
        timer->CR1 |= TIM_CR1_CEN;
        
        return true;
    }

    // Promjena duty cycle-a u toku rada
    void setDutyCycle(uint8_t duty_cycle) {
        if (duty_cycle > 100) return;  // Provjera validnosti
        
        uint32_t arr = timer->ARR;
        uint32_t ccr = (duty_cycle * (arr + 1)) / 100;  // Izračun nove CCR vrijednosti
        
        // Postavljanje nove CCR vrijednosti za odgovarajući kanal
        switch(channel) {
            case 1: timer->CCR1 = ccr; break;
            case 2: timer->CCR2 = ccr; break;
            case 3: timer->CCR3 = ccr; break;
            case 4: timer->CCR4 = ccr; break;
        }
    }

    // Provjera da li je timer omogućen
    bool isTimerEnabled() const {
        return (timer->CR1 & TIM_CR1_CEN);
    }

    // Zaustavljanje timer-a
    void stopTimer() {
        timer->CR1 &= ~TIM_CR1_CEN;
    }

    // Dobijanje trenutne frekvencije
    uint32_t getCurrentFrequency() const {
        return bus_freq / ((timer->PSC + 1) * (timer->ARR + 1));
    }
};