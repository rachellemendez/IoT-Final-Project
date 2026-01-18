# Lab Activity 6: Bidirectional Control using Arduino and Python

## Project Overview
This project establishes a full **bidirectional communication loop** between an Arduino Uno and a Python script. Unlike previous activities where control was one-way (Python controlling Arduino OR Arduino sending data to Python), this system acts as a responsive feedback loop.

When a user presses a physical button on the Arduino, a signal is sent to the Python script. The Python script processes this signal and immediately sends a command back to the Arduino to toggle a corresponding LED. This demonstrates the capability of Python to act as a logic processor for hardware events triggered by the microcontroller.

## Repository Structure

### `lab_serial.ino`
The firmware for the Arduino Uno.
* **Input Handling:** Monitors 3 pushbuttons (Pins 12, 11, 10) using **Debouncing logic** (50ms delay) to prevent false triggers.
* **Output Control:** Controls 3 LEDs (Red, Green, Blue) on Pins 7, 6, and 5.
* **Communication Protocol:**
    * **Sending:** When Button 1/2/3 is pressed, it sends characters `'R'`, `'G'`, or `'B'` to the computer.
    * **Receiving:** Listens for incoming commands `'1'`, `'2'`, or `'3'`. Upon receipt, it toggles the state of the Red, Green, or Blue LED respectively.
    * **Optimization:** Uses `Serial.setTimeout(10)` to ensure rapid reading of incoming string commands.

### `lab_serial.py`
The "Server-side" Python logic.
* **Library:** Uses `pyserial` to interface with the microcontroller.
* **Logic:** Runs an infinite loop that waits for data.
    * If it receives `'R'`, it prints a confirmation and sends back `'1'`.
    * If it receives `'G'`, it prints a confirmation and sends back `'2'`.
    * If it receives `'B'`, it prints a confirmation and sends back `'3'`.
* **Configuration:** Currently set to connect via **COM4** at 9600 baud.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Inputs:** 3x Pushbuttons (Connected to Pins 12, 11, 10).
    * *Note:* Configured as `INPUT_PULLUP`, meaning buttons connect to Ground when pressed.
* **Outputs:** 3x LEDs (Red, Green, Blue) connected to Pins 7, 6, 5 via resistors.
* **Components:** 3x Resistors (220Ω for LEDs), Breadboard, Jumper Wires.

### Logic Flow (The "Round Trip")
1.  **User Action:** User presses **Button 1** (Pin 12) on the breadboard.
2.  **Arduino:** Debounces the signal and prints char `'R'` to Serial.
3.  **Python:** Reads `'R'`, translates it, and writes char `'1'` back to Serial.
4.  **Arduino:** Reads `'1'`, identifies the command, and **Toggles the Red LED** (Pin 7).

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect Buttons to Pins 12, 11, 10 and Ground.
    * Connect LEDs to Pins 7, 6, 5 and Ground (via resistors).
2.  **Software Configuration:**
    * Upload `lab_serial.ino` to the Arduino.
    * Open `lab_serial.py` and verify the `arduino_port` variable matches your device (currently set to `"COM4"`).
3.  **Execution:**
    * Run the Python script: `python lab_serial.py`.
    * Press the physical buttons on the breadboard.
    * Observe the terminal showing the "Sent back" messages and the LEDs toggling on the breadboard.

---

## Files
1. Arduino Code Sketch File (*.ino)
2. [Breadboard Diagram](https://drive.google.com/file/d/1KUmylDS3eLIGeaacaXLmm_PzmPTtbrf9/view?usp=sharing)
3. [Tinkercad Diagram]()
4. [Video Simulating the Breadboard and its corresponding Circuit Diagram on TinkerCad]()

## AI
1. [Prompts used to transact with your selected Generative AI]()
2. Model used to generate the content: Gemini 3 Pro
3. [Transaction ID or the link of the conversation](https://gemini.google.com/share/2d25879716f8)

## Grades
- **Leader:** Rachelle Yazmhine C. Mendez
### Members 
- Jemuel Chris N. Ambong
- Betina B. Arrojo
- Keren G. Dellosa
- John Harold R. Magma
- Jamil S. Mariano
- Audric P. Pascual
