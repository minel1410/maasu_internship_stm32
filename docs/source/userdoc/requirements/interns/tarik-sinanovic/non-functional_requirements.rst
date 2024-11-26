===================================
Non Funtional Requirements
===================================

1. Performance
====================
- 1.1 The GPIO system should respond quickly to changes in pin states, ideally allowing pin state changes within 1 microsecond for time-sensitive applications.
- 1.2 The BSRR register should allow atomic operations for pin manipulation, ensuring that pin state changes are handled without delay, especially in interrupt-driven applications.
2. Reliability
=====================
- 2.1 The GPIO system should be robust enough to handle at least 100,000 read/write operations without failure, ensuring long-term reliability in embedded systems.
- 2.2 The system must handle GPIO state changes safely under normal operating conditions, protecting the microcontroller from excessive current or voltage.
- 2.3 Proper over-voltage protection must be in place to avoid damaging the GPIO pins from external devices.
3. Usability
==============
- 3.1 The software API for GPIO configuration should be simple and clear, with functions for setting pin modes, reading and writing states, and configuring interrupts.
- 3.2 Documentation should provide examples and explanations for common GPIO tasks, such as reading a button press, controlling an LED, or setting up a PWM signal.
- 3.3 The system should allow easy debugging and monitoring of GPIO states using tools that provide feedback during development.
4. Power Efficiency
=======================
- 4.1 GPIO pins should consume minimal power in idle states, with the ability to enter a low-power mode when not actively used.
- 4.2 The system should allow the programmer to configure GPIO pins to save energy, particularly in battery-operated applications.
5. Flexibility
=================
- 5.1 The system must allow dynamic reconfiguration of GPIO pins to support different functions at different stages of the application. For instance, a pin can be reconfigured from output (LED control) to input (button press) during operation.
- 5.2 GPIO pins should be flexible enough to support different voltage levels or peripherals based on the configuration set in the AFR register.