# Lab Activity 4: Arduino Serial Control System

## Project Overview
This project demonstrates bi-directional serial communication between an Arduino Uno and a computer. The system monitors ambient light levels using a photoresistor and automatically triggers a blinking LED alert when a specific brightness threshold is reached. Uniquely, this project allows for user intervention: the user can send a "stop" command via the Serial Monitor to override the system and permanently disable the blinking alert.

## Repository Structure

### `Lab04_ArduinoSerialConn.ino`
This is the main firmware file containing the C++ source code for the Arduino.
* **Initialization:** Configures Pin 8 for the LED and Pin A0 for the photoresistor. Sets a brightness threshold of 220.
* **Setup:** Initializes Serial communication at 9600 baud and sets a short timeout (50ms) for responsive input reading.
* **Loop:**
    * **Sensor Monitoring:** Reads the light sensor, maps the value (0-1023) to a byte range (0-255), and prints it to the Serial Monitor.
    * **State Logic:** Uses boolean flags (`blinking`, `gaveCommand`) to manage the system state. If the threshold is crossed and no stop command has been issued, blinking begins.
    * **Command Processing:** Continually checks for incoming serial data. If the string "stop" is received (case-insensitive), the system sets a flag to permanently disable the alarm.

### `Lab04_CircuitDiagram.png`
A visual schematic illustrating the hardware connections [Image: Lab04_CircuitDiagram.png].
* **Microcontroller:** Arduino Uno.
* **Input:** Photoresistor (LDR) connected to Analog Pin A0 with a voltage divider circuit.
* **Output:** Red LED connected to Digital Pin 8 with a current-limiting resistor.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Sensors:** 1x Photoresistor (LDR)
* **Actuators:** 1x LED (Red)
* **Components:** Resistors (10kΩ for LDR, 220Ω for LED), Breadboard, Jumper Wires

### Software & Logic
* **Language:** C++ (Arduino)
* **Key Concepts:**
    * **Bi-Directional Communication:** The Arduino sends data (Values) and receives data (Commands).
    * [cite_start]**String Manipulation:** Uses `.trim()` and `.toLowerCase()` to sanitize user input, ensuring commands work regardless of extra spaces or capitalization[cite: 54].
    * [cite_start]**State Management:** Relies on boolean variables to track whether the alarm is active or if the user has overridden the system[cite: 43].
    * [cite_start]**Data Mapping:** Uses the `map()` function to convert raw analog input into a standard 8-bit range[cite: 48].

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the Photoresistor to Pin A0 (using a voltage divider).
    * Connect the LED anode to Pin 8 and cathode to GND (via resistor).
2.  **Software Installation:**
    * Open `Lab04_ArduinoSerialConn.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino board.
    * Open the **Serial Monitor** (ensure Baud Rate is **9600** and Line Ending is set to **Newline** or **Both NL & CR**).
    * **Observation:** Shine a light on the sensor to trigger the blinking.
    * **Interaction:** Type `stop` (or `STOP`) into the Serial input field and press Enter. The blinking should cease and not restart, even if the light remains bright.

## Authors
**Group Activity 4**
* Arrojo, Betina
* Mariano, Jamil
* Mendez, Rachelle
