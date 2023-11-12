# 433 MHz Testing

This repository contains source code for testing a 433 MHz wireless communication system using the RadioHead library (`RH_ASK`).

## Package Used
- `RH_ASK` Library for Arduino

## Reference
For detailed information and tutorials on 433 MHz RF modules and Arduino, you can refer to [this resource](https://dronebotworkshop.com/433mhz-rf-modules-arduino/).

## Transmitter (TX)
The transmitter code is responsible for sending data wirelessly over the 433 MHz frequency. It sends a simple message ("Welcome to the Workshop!") at regular intervals.

## Receiver (RX)
The receiver code listens for incoming data over the 433 MHz frequency and displays the received messages on the serial monitor.

#### Pin Configurations:
- `TX Pin`: 12
- `RX Pin`: 11

## Additional Assets
Inside the `assets` folder, you can find the required library for this project in the form of a zip file.

