# Joystick Wireless Communication

This folder contains source code for wirelessly transmitting joystick data from one Arduino board to another and controlling LEDs based on the joystick's movements.

## Setup

### Hardware Requirements:
- **Transmitting Board:**
  - Arduino Board
  - Joystick Module
  - 433 MHz Transmitter Module
  - Jumper Wires

- **Receiving Board:**
  - Arduino Board
  - 433 MHz Receiver Module
  - LEDs
  - Jumper Wires

### Pin Configurations:
- **Transmitting Board:**
  - Joystick X-Axis Pin: A7
  - Joystick Y-Axis Pin: A6
  - 433 MHz Transmitter Pin: Defined in code (default: 11)

- **Receiving Board:**
  - 433 MHz Receiver Pin: Defined in code (default: 12)
  - LED Pins: D3 to D7

## Operation

The transmitting board reads analog values from the joystick's X and Y axes, sends the data wirelessly over the 433 MHz frequency, and the receiving board illuminates LEDs based on the joystick's position.

- **Center LED (D7):** Joystick in the center position.
- **Top LED (D3):** Joystick moved to the top.
- **Right LED (D4):** Joystick moved to the right.
- **Bottom LED (D5):** Joystick moved to the bottom.
- **Left LED (D6):** Joystick moved to the left.

Serial monitor on the receiving board displays real-time X and Y values.

## Additional Information
Feel free to customize the code or expand the functionality as needed for your projects.

Happy experimenting!
