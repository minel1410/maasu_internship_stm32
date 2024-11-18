
===============
GPIO Overview
===============


A General-Purpose Input/Output (GPIO) port manages digital signals for both input and output. When configured as an input, it can relay ON/OFF signals from switches or digital data from sensors to the CPU. As an output, it allows the microcontroller to control external devices, such as lighting up an LED or sending drive signals to a motor, based on the CPU’s instructions or computations.

The term "general-purpose" highlights the flexibility of GPIO pins, as each pin can be independently configured to act as either an input or an output, depending on the application needs.

On the STM32F411 microcontroller, each GPIO port has the following configurable registers:

- **Mode Register (GPIOx_MODER)**
- **Output Type Register (GPIOx_OTYPER)**
- **Output Speed Register (GPIOx_OSPEEDR)**
- **Pull-up/Pull-down Register (GPIOx_PUPDR)**
- **Input Data Register (GPIOx_IDR)**
- **Output Data Register (GPIOx_ODR)**
- **Bit Set/Reset Register (GPIOx_BSRR)**
- **Lock Register (GPIOx_LCKR)**
- **Alternate Function Registers (GPIOx_AFRL and GPIOx_AFRH)**

GPIO Configuration
-------------------

Each GPIO pin can be configured in one of the following modes:

- **Input Mode**: Reads digital values (0 or 1) from the pin.
- **Output Mode**: Sets the pin to a high (1) or low (0) state.
- **Alternate Function Mode**: Connects the pin to a peripheral (e.g., USART, SPI).
- **Analog Mode**: Used for ADC or DAC operations or to save power.

**Output Types:**

- **Push-Pull**: Standard output configuration, consumes more power
- **Open-Drain**: Allows for multiple devices to connect on a shared line, preventing damage

**Output Speeds:**

- Low, Medium, High, and Very High speed settings control the signal frequency.

**Pull-up/Pull-down Configuration:**

- **No Pull**: No resistor activated.
- **Pull-up**: Connects a resistor to VCC.
- **Pull-down**: Connects a resistor to ground.

GPIO Data Registers
--------------------

- **Input Data Register (GPIOx_IDR)**: Used to read the current state of each pin.

  - Example: Reading the state of PA5 involves checking bit 5 in `GPIOA_IDR`.

- **Output Data Register (GPIOx_ODR)**: Sets the output value for each pin.
  
  - Example: To set PA5 to high, bit 5 in `GPIOA_ODR` should be set to 1.


ODR vs. BSRR Registers
-----------------------

- **Output Data Register (ODR)**:

  - Directly controls the output state of GPIO pins
  - Example: Writing a 1 to bit 5 sets PA5 high; writing a 0 sets it low


- **Bit Set/Reset Register (BSRR)**:

  - Provides a more efficient way to set or reset pins without affecting the entire ODR value
  - The first 16 bits are for setting pins (BSy), and the last 16 bits are for resetting pins (BRy)
  - Example: Writing `0x0020` to `GPIOA_BSRR` sets PA5 high, while writing `0x200000` resets it to low

Example Scenarios
------------------

1. **Configuring a GPIO Pin for an LED on PA9:**

  - Enable the clock for GPIOA using `RCC_AHB1ENR`
  - Set the mode to output in `GPIOA_MODER`
  - Configure the output type as push-pull in `GPIOA_OTYPE`.
  - Set the desired speed in `GPIOA_OSPEEDR`
  - Optionally enable a pull-up resistor in `GPIOA_PUPDR`
  - Toggle the LED state using `GPIOA_ODR` or `GPIOA_BSRR`


2. **Configuring a GPIO Pin for a Button on PA9:**

  - Enable the clock for GPIOA using `RCC_AHB1ENR`.
  - Set the mode to input in `GPIOA_MODER`
  - Configure a pull-up or pull-down resistor in `GPIOA_PUPDR` to prevent floating state
  - Read the button state using `GPIOA_IDR`