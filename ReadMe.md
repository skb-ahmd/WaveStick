# Joystick Testing

This folder contains source code for testing a joystick and controlling LEDs based on its movements using Arduino.

## Setup

### Hardware Requirements:
- Arduino Board
- Joystick Module
- LEDs
- Jumper Wires

### Pin Configurations:
- Joystick X-Axis Pin: A7
- Joystick Y-Axis Pin: A6
- LED Pins: D3 to D7

## Operation

The code reads analog values from the joystick's X and Y axes and illuminates LEDs based on the joystick's position.

- **Center LED (D7):** Joystick in the center position.
- **Top LED (D3):** Joystick moved to the top.
- **Right LED (D4):** Joystick moved to the right.
- **Bottom LED (D5):** Joystick moved to the bottom.
- **Left LED (D6):** Joystick moved to the left.

Serial monitor displays real-time X and Y values.

## Additional Information
Feel free to customize the code or expand the functionality as needed for your projects.

Happy experimenting!
