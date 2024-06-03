# Arduino IC Tester

This project is an **Arduino-based IC tester** designed to test basic logic gates: **OR, XOR, AND,** and **NAND**. By pressing a corresponding button, the circuit tests the IC and indicates the result using LEDs.



## Overview

The IC tester allows you to test four types of logic gates (**OR, XOR, AND, NAND**) on ICs by connecting the IC to the Arduino and pressing the corresponding button. The tester uses pre-defined truth tables for each gate to verify the IC's functionality and indicates the result through a **green (pass)** or **red (fail)** LED.


## Features

- Tests **OR, XOR, AND,** and **NAND** gates.
- Simple interface with four buttons to select the gate type.
- LED indicators to show test results.
- Supports both positive and negative logic gate tests.

## Components

- Arduino board (e.g., Uno)
- Four push buttons
- Red and green LEDs
- Resistors for LEDs and buttons
- Breadboard and connecting wires

## Wiring Diagram
![WhatsApp Image 2024-06-02 at 18 49 20](https://github.com/TashkeelPasha/IC-Tester---Arduinp-based/assets/152206485/aa5ace97-106b-4187-8f66-f464c0b45bca)


### Button Connections

- **OR button:** Pin A5
- **XOR button:** Pin A2
- **AND button:** Pin A1
- **NAND button:** Pin A0

### LED Connections

- **Red LED:** Pin A4
- **Green LED:** Pin A3

### Logic Gate Pins

- Defined in the code for each test scenario

## Arduino Code

The Arduino code defines the logic for testing each type of gate. The main functions include setting up the pins, running the test based on the selected gate, and displaying the result via LEDs. You can find the complete Arduino code in the [IC_Tester.ino](IC_Tester.ino) file.

## Usage

1. Connect the IC to be tested according to the pin configurations in the code.
2. Upload the Arduino code to your Arduino board.
3. Press the button corresponding to the gate type you want to test (**OR, XOR, AND, NAND**).
4. Observe the LEDs:
   - **Green LED** indicates the IC passed the test.
   - **Red LED** indicates the IC failed the test.

## Notes

This tester is designed specifically for **74LS series ICs**, which have a pin mapping of inputs on pins 1 and 2, and the output on pin 3. For ICs with different pin mappings, the code must be modified accordingly. The test works by comparing the IC's output to the expected values from the truth tables.

## Acknowledgments

This project idea was inspired by resources available on the internet. For more details, refer to https://www.digikey.com/en/maker/projects/how-to-build-a-simple-arduino-based-7400-logic-ic-tester/1216950c437f4f4482a9dde470109985.

## License
Free to use.. :)

---

Feel free to reach out if you have any questions or issues with the project. Happy testing!
