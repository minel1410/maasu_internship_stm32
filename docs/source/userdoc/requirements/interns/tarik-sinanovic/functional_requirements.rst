=========================
Functional Requirements
=========================

1. GPIO Pin Configuration
============================
- 1.1 The GPIO system must support configuring each pin individually as either input, output, analog, or alternate function.
- 1.2 For input pins, the PUPDR register should allow enabling pull-up or pull-down resistors for a stable signal when no external device is connected.
- 1.3 Output pins should be able to function in push-pull or open-drain modes, and the OTYPER register should be used to configure this.
- 1.4 The MODER register must be able to configure the pin's mode accurately for each application.
  - 00: Input
  - 01: General-purpose output
  - 10: Alternate function
  - 11: Analog
2. GPIO Pin States
=====================
- 2.1 The system must allow setting the state of output pins using the ODR register, where a high or low value can be written.
- 2.2 Input pins must be read using the IDR register to determine whether the external signal is high or low.
- 2.3 For atomic operations, the BSRR register should be used to set or reset specific pins without affecting others. Writing to the lower half of BSRR will set pins, and writing to the upper half will reset them.
3. Alternate Functionality
==============================
- 3.1 The GPIO system should support alternate functions, enabling pins to interact with peripherals like USART, SPI, PWM, etc., by configuring the AFR register.
- 3.2 Each pin must have a specific configuration for its alternate function, and the AFR register should allow setting the appropriate function based on project requirements.

