.. _GPIO_requirements:

GPIO requirements
=================

.. req:: label
   :id: REQ_INT3_1732147249
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Informational
   :safety-asil: 
   :references: 
   :verification-and-validation: 

- There is a need to understand the structure of STM32F411's GPIO system, which includes multiple ports (GPIOA, GPIOB, etc.), each with 16 pins (0–15).
- Each pin needs to be configured individually to operate in input, output, alternate function, or analog mode, depending on the application requirements.
- The GPIO ports need their clocks to be enabled through the RCC->AHB1ENR register before any configuration or operation.
- Without enabling the clock, no access to the GPIO configuration registers is possible.
- There is a need to use the MODER register to define the mode of operation for each pin.
- Modes need to be chosen based on the use case: input (00), output (01), alternate function (10), or analog (11).
- The OTYPER register needs to be configured to determine whether a pin operates in push-pull or open-drain mode.
- Push-pull is needed for standard output signals, while open-drain is needed for interfaces like I2C.
- The OSPEEDR register needs to be configured to set the output speed of a pin.
- Speed settings need to align with the application's timing requirements and power considerations, with options for low, medium, high, and very high speeds.
- Internal pull-up or pull-down resistors need to be configured using the PUPDR register to control the default state of the pin.
- Pull-up is needed to keep the pin high, pull-down is needed to keep it low
- For pins configured in alternate function mode, there is a need to use the AFRL register to assign the correct peripheral function.
- Each pin’s alternate function needs to be carefully mapped to its intended peripheral
- The output state of GPIO pins needs to be controlled through the ODR or BSRR 
- The use of atomic operations in the BSRR register is needed to avoid conflicts in multitasking systems.
- GPIO pins need to be correctly configured to work with peripherals such as ADC, UART, SPI
- Alternate functions and modes need to be matched with the peripheral requirements for seamless operation.
- Electrical characteristics like voltage levels, current limits, and protection mechanisms need to be considered during GPIO configuration.




.. req:: label
   :id: REQ_INT3_1732147094
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

- The system shall provide functionality to enable the clock for a specific GPIO port by setting the corresponding bit in the RCC->AHB1ENR register. 
- System must support enabling clocks for all available GPIO ports
- System must ensure the clock enable process is completed before proceeding with any GPIO configuration
- The system shall allow each GPIO pin to be configured in one of four modes by updating the MODER register
- The pin mode configuration must validate the mode value and the pin number before applying changes.
- The system shall allow configuration of the GPIO output type using the OTYPER register, 
- Register shall support Push-pull Mode (0). 
- It shall allow independent configuration of each pin on the port.
- The system shall allow the user to define the output speed for each GPIO pin by updating the OSPEEDR register. 
- Proper speed configuration for specific timing constraints must be ensured.
- The system must support the configuration of internal pull-up by modifying the PUPDR register, 
- The system must support the configuration of internal pull-down resistors by modifying the PUPDR register, 
- The function shall allow independent resistor configuration for each pin.
- For pins configured in alternate function mode, the system shall allow the alternate function to be set by updating the AFRL (for pins 0–7) 
-  A method shall be provided to map a specific alternate function to a pin, based on the pin's alternate function number .
- The system shall allow direct control of the GPIO pin output state by modifying the Output Data Register (ODR) to directly set pin value
- The system shall allow direct control of the GPIO pin output state by modifying the Output Data Register (ODR) to directly reset pin value
- The system shall use Bit Set/Reset Register (BSRR) to atomically set
- The system shall use Bit Set/Reset Register (BSRR) to atomically reset
-  A method for toggling the pin state shall also be provided.
- The system shall encapsulate each configuration step (e.g., enabling the clock, setting the pin mode, configuring pull-up/pull-down) into separate reusable functions. 
- Each function shall validate input parameters and return an appropriate status code for error handling.
- The system shall include a delay function that pauses execution for a specified number of milliseconds. 
- The delay function shall be implemented using a simple loop mechanism or a timer for better accuracy.



.. req:: label
   :id: REQ_INT3_1732147460
   :status: Draft
   :date-released:
   :priority: Low
   :submitted-by: Semin Murtic
   :modified-by:
   :category: Non-Functional
   :safety-asil: 
   :references: 
   :verification-and-validation: 

- The GPIO configuration process should complete in less than 10 milliseconds to ensure the system operates efficiently during initialization.
- Each GPIO function must use no more than 10% of available memory to minimize the impact on system resources.
- Error handling should provide specific status codes (e.g., 0x01 for invalid pin, 0x02 for incorrect mode) to facilitate troubleshooting and debugging.
- The configuration functions should be reusable across at least 80% of different projects, with minimal changes required to accommodate different hardware configuration.
- GPIO pins must function correctly under conditions of up to 10 MHz output speed and handle up to 3.3V logic levels without failures.
- All functions should be documented with clear, concise comments, with a goal of reducing time required for developers to understand or modify the code.
- The GPIO configuration code should work on all 16 pins of each available port (GPIOA, GPIOB, etc.) without any need for port-specific adjustments.
- The system should be capable of providing feedback within 1 second for invalid GPIO configurations or other errors, allowing for rapid diagnosis.
- The GPIO configuration should support up to 4 different peripheral mappings (e.g., UART, SPI, I2C, ADC) per pin to maximize flexibility and usage scenarios.

