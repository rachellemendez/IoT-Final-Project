# Lab Activity 1: Sequential LED Control

## Project Overview
This project demonstrates the control of five LEDs in a sequential pattern using an Arduino Uno. The system activates the LEDs one by one, maintains their state for a set duration, and then deactivates them in the same sequence. This project serves as a fundamental exercise in digital output control, array manipulation, and loop iterations.

## Repository Structure

### `Lab01_SequentialLEDs.ino`
This is the main firmware file containing the C++ source code for the Arduino.
* **Pin Configuration:** Declares an array of 5 integers representing the digital pins used (Pins 12, 11, 10, 9, and 8).
* **Setup:** Initializes the serial monitor for debugging and configures the specified pins as `OUTPUT`.
* **Loop:** Executes the main logic to sequentially turn pins `HIGH` and `LOW` with a 1000ms (1 second) delay between state changes.

### `Lab01_CircuitDiagram.png`
A visual schematic illustrating the hardware connections.
* **Microcontroller:** Arduino Uno.
* **Wiring:** Shows the connection of five LEDs to the digital pins defined in the code, with corresponding current-limiting resistors connected to the ground rail.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Actuators:** 5x LEDs (Red, Blue, Yellow, Green, Orange)
* **Components:** 5x Resistors, Breadboard, Jumper Wires

### Software & Logic
* **Language:** C++ (Arduino)
* **Key Concepts:**
    * **Arrays:** Uses `int ledPins[5]` to store pin numbers, allowing for efficient iteration.
    * **Debugging:** Includes `Serial.println(ledPins[i])` to verify pin initialization order in the Serial Monitor.
    * **Timing:** Utilizes `delay(1000)` to create a 1-second interval between transitions.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the LEDs to the breadboard as shown in the circuit diagram.
    * Ensure the cathodes are grounded via resistors and anodes are connected to Pins 12 through 8.
2.  **Software Installation:**
    * Open `Lab01_SequentialLEDs.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino board.
    * Open the **Serial Monitor** (9600 baud) to view the debugging output.
    * Observe the LEDs turning on and off in sequence.

## Authors
**Group Activity 1**
* Arrojo, Betina
* Mariano, Jamil
* Mendez, Rachelle
