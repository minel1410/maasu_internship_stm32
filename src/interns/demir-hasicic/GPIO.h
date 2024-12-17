#include <stdint.h>
#include "stm32f4xx.h"

enum class PIN {   
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7,
    PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15
};

enum class GPIOMODE { INPUT, OUTPUT, AFC, ANALOG };
enum class OTYPE { PUSH_PULL, OPEN_DRAIN };
enum class SPEED { LOW, MEDIUM, FAST, HIGH };
enum class PULL { NO_PULL, PULL_UP, PULL_DOWN, RESERVED };
enum class PIN_STATE { LOW, HIGH };
enum class ALT_FUNCTION { AF0, AF1, AF2, AF3, AF4, AF5, AF6, AF7, AF8, AF9, AF10, AF11, AF12, AF13, AF14, AF15 };

void gpio_clock_init(GPIO_TypeDef* port);
void gpio_mode(GPIO_TypeDef* port, PIN pin, GPIOMODE mode);
void gpio_output_type(GPIO_TypeDef* port, PIN pin, OTYPE type);
void gpio_speed(GPIO_TypeDef* port, PIN pin, SPEED speed);
void gpio_pull(GPIO_TypeDef* port, PIN pin, PULL pull);
PIN_STATE gpio_read(GPIO_TypeDef* port, PIN pin);
void gpio_set_state(GPIO_TypeDef* port, PIN pin, PIN_STATE state);
void gpio_AF(GPIO_TypeDef* port, PIN pin, ALT_FUNCTION alt_function);
void gpio_init(GPIO_TypeDef* port, PIN pin, GPIOMODE mode, OTYPE type, SPEED speed, PULL pull, ALT_FUNCTION alt_function);