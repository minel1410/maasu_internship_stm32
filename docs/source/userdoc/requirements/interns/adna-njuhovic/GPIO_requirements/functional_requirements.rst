===============================
Functional Requirements
===============================

FR-01: Pin Configuration
-------------------------
Each GPIO pin must be configurable to one of four modes via the MODER register:
- Input mode: MODER bits = 00.
- Output mode: MODER bits = 01.
- Analog mode: MODER bits = 11.
- Alternate function mode: MODER bits = 10.
The configuration must ensure that selected modes do not interfere with neighboring pins and avoid unintended behavior when switching between modes.

FR-02: Input Mode Functionality
-------------------------------
GPIO pins in input mode must read signals as high (1) or low (0). Internal pull-up or pull-down resistors must be configurable via the PUPDR register:
- No resistor: PUPDR bits = 00.
- Pull-up resistor: PUPDR bits = 01.
- Pull-down resistor: PUPDR bits = 10.
Input functionality must maintain signal accuracy and be resilient to electrical noise. A debouncing mechanism must be implemented for switches or buttons to prevent false triggering.

FR-03: Output Mode Functionality
--------------------------------
GPIO pins in output mode must send logical high (1) or low (0) signals to external devices. Output configuration must support:
- Push-pull: OTYPER bit = 0.
- Open-drain: OTYPER bit = 1.
The GPIO controller must ensure that output signal transitions occur with a latency of no more than 50 nanoseconds from the time the signal is updated in the register to when the physical output on the pin changes.
When multiple output pins are connected to the same line, the system must automatically detect conflicts (e.g., two pins trying to drive opposite states) and resolve them by placing conflicting pins into a high-impedance state.

FR-04: Analog Mode Functionality
--------------------------------
GPIO pins in analog mode must support continuous signal processing for ADC/DAC operations. Digital circuitry must be disabled when analog mode is enabled to minimize noise interference.

FR-05: Alternate Function Mode Functionality
---------------------------------------------
GPIO pins must support alternate functions for peripherals such as UART, SPI, or I2C. The AFR register must be used to configure pins for alternate functions (AF0–AF15). Switching between alternate functions must occur in less than 100 microseconds without disrupting ongoing tasks or peripheral communications. No erroneous behavior (e.g., unintended signal states or data loss) should occur during the switch.

FR-06: Interrupt Handling
-------------------------
GPIO pins must trigger interrupts based on developer-defined conditions:
- Rising edge
- Falling edge
- Both edges
Interrupts must be configured via the EXTI register, with GPIO pins mapped to EXTI lines through the SYSCFG register. Interrupts must trigger within 10 microseconds of a signal transition, and false triggers must be prevented through proper debouncing or filtering mechanisms.

FR-07: Output Speed Control
---------------------------
GPIO pins must support configurable output speed via the OSPEEDR register:
- Low speed: OSPEEDR bits = 00, supporting frequencies up to 1 MHz for low-frequency tasks such as LED control.
- Medium speed: OSPEEDR bits = 01, supporting frequencies between 1 MHz and 10 MHz for most general-purpose applications.
- High speed: OSPEEDR bits = 10, supporting frequencies from 10 MHz up to 100 MHz for high-speed communication protocols like SPI or PWM.
Speed settings must be configurable to ensure the following:
- Low speed: Optimizes power consumption for low-frequency tasks without affecting the performance of the application.
- Medium speed: Balances performance and power usage for most general applications.
- High speed: Minimizes electromagnetic interference (EMI) while ensuring signal integrity and performance in time-critical applications.
