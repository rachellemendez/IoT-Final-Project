# Lab Activity 5: Receiving Serial Connection using Arduino from Python

## Project Overview
This project demonstrates **bi-directional serial communication** between a PC and an Arduino Uno. Unlike previous activities that used the Arduino IDE Serial Monitor, this system utilizes a custom **Python script** as the control interface. The Python program sends character commands ('R', 'G', 'B', 'A', 'O') to the Arduino to toggle three specific LEDs (Red, Green, Blue). This activity highlights the integration of high-level programming languages (Python) with low-level hardware control (Arduino) via the UART protocol.

## Repository Structure

### `LabSerialAssignment.ino`
The main firmware entry point for the Arduino.
* [cite_start]**Setup:** Initializes the Serial connection at 9600 baud and calls the LED initialization function[cite: 76].
* **Loop:** Continuously checks for incoming serial data. [cite_start]It reads characters, filters out newline/carriage return formatting characters, and passes valid inputs to the processing logic[cite: 77, 78].

### `led_control.h`
A modular header file containing the hardware logic, keeping the main sketch clean.
* **Pin Definitions:** Assigns the LEDs to digital pins: Red (8), Green (9), and Blue (10).
* **Logic:**
    * `initLEDs()`: Sets pins to OUTPUT mode and ensures they start in the OFF state.
    * `toggleLED(int pin)`: Reads the current state of a pin and switches it (ON to OFF, or OFF to ON).
    * `processInput(char command)`: A switch-case structure that maps characters ('R', 'G', 'B', 'A', 'O') to their respective LED functions.

### `led_controller.py`
The client-side Python script that runs on the computer.
* **Library:** Uses the `serial` (pySerial) library to communicate with the Arduino.
* **Configuration:** Targets `COM7` at 9600 baud (User must verify their specific port).
* **Interface:** Provides a Command Line Interface (CLI) menu allowing the user to select options to toggle individual LEDs, turn all on, or turn all off.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Actuators:** 3x LEDs (Red, Green, Blue)
* **Connections:**
    * **Red LED:** Pin 8
    * **Green LED:** Pin 9
    * **Blue LED:** Pin 10
* **Components:** 3x Resistors (220Ω), Breadboard, Jumper Wires

### Software & Logic
* **Communication Protocol:** UART Serial (9600 baud).
* **Case Insensitivity:** Both the Python script and Arduino code handle input processing (e.g., converting to uppercase) to ensure commands work regardless of 'r' or 'R' keypresses.
* **State Management:** The `toggleLED` function allows independent control of each LED without needing to track their state in the Python script.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the LEDs to pins 8, 9, and 10 with appropriate resistors to ground.
2.  **Arduino Setup:**
    * Open `LabSerialAssignment.ino` (ensure `led_control.h` is in the same folder).
    * Upload the code to the Arduino.
3.  **Python Setup:**
    * Ensure Python is installed on your machine.
    * Install the `pyserial` library if missing: `pip install pyserial`.
    * **Crucial Step:** Open `led_controller.py` and update the `ARDUINO_PORT` variable (currently `'COM7'`) to match the port your Arduino is connected to.
4.  **Execution:**
    * Run the Python script: `python led_controller.py`.
    * Use the on-screen menu to control the LEDs.

---

## Files
1. Arduino Code Sketch File (*.ino)
2. [Breadboard Diagram](https://drive.google.com/file/d/1WRlwpdoSsAlgfg8KQhOZGyI0N4cBz1ZB/view?usp=sharing)
3. [Tinkercad Diagram](https://drive.google.com/file/d/1wjO8Qyvll-78-F_ShEHeHiPqQ6elUnjd/view?usp=sharing)
4. [Video Simulating the Breadboard and its corresponding Circuit Diagram on TinkerCad](https://drive.google.com/file/d/15RCLJFpSOGnHZq50F7RV-LdF9hiP91E_/view?usp=sharing)

## AI
1. [Prompts used to transact with your selected Generative AI](https://docs.google.com/document/d/1Fe5OqBTM9iATZMIurfX4jmZpX0Domhsl6qaz1dQoqu0/edit?usp=sharing)
2. Model used to generate the content: Gemini 3 Pro
3. [Transaction ID or the link of the conversation](https://gemini.google.com/share/4a584b09de8c)

## Grades
- **Leader:** John Harold R. Magma
### Members 
- Jemuel Chris N. Ambong
- Keren G. Dellosa
- Jamil S. Mariano
- Rachelle Yazmhine C. Mendez
- Betina B. Arrojo
- Audric P. Pascual
