# Finals Laboratory Exam: IoT Button Client

## Project Overview
This project demonstrates an **IoT (Internet of Things) Client** system. It acts as a physical interface for a network-connected application. The system consists of an Arduino Uno acting as a physical trigger and a Python script acting as a "Bridge" or Gateway.

When a user presses the physical button on the Arduino, a signal is sent via Serial to the computer. The Python script intercepts this signal and instantly translates it into an **HTTP GET Request** sent to a remote API server (`http://172.20.10.3:8000`). This architecture mimics real-world IoT buttons (like Amazon Dash buttons) that trigger cloud actions from a simple hardware press.

## Repository Structure

### `arduino_sender.ino`
The firmware for the Arduino Uno.
* **Hardware Config:** Sets Pin 2 as `INPUT_PULLUP`, allowing a button to be connected directly to Ground without external resistors.
* **Debouncing Algorithm:** Implements a 50ms software debounce to ensure one physical press results in exactly one signal, preventing "noise" or multiple triggers.
* **Serial Output:** Upon a valid press, it sends the specific group identifier (`"2"`) to the serial port.

### `iot_client.py`
The Gateway software running on the host computer.
* **Serial Listener:** Continuously monitors `COM7` (configurable) for incoming data from the Arduino.
* **API Client:** Uses the `requests` library to construct dynamic URLs based on the received group number.
* **Logic Flow:**
    1.  Receives Group Number (e.g., "2").
    2.  Constructs URL: `http://172.20.10.3:8000/led/group/2/toggle`.
    3.  Sends HTTP GET request to toggle the remote LED.
    4.  Prints server response codes (200 OK, etc.) for debugging.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Input:** 1x Pushbutton
* **Connectivity:** USB Cable (Serial Communication)
* **Wiring:**
    * **Button Pin:** Digital Pin 2
    * **Ground:** GND
    * *Note:* Internal Pull-up resistor is enabled in software.

### Software Stack
* **Microcontroller:** C++ (Arduino)
* **Gateway:** Python 3.x
* **Libraries:**
    * `pyserial`: For UART communication with Arduino.
    * `requests`: For HTTP communication with the API Server.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect one leg of the pushbutton to **Pin 2**.
    * Connect the other leg of the pushbutton to **GND**.
2.  **Arduino Setup:**
    * Open `arduino_sender.ino`.
    * Upload to the board.
3.  **Python Gateway Setup:**
    * Ensure Python 3 is installed.
    * Install dependencies: `pip install pyserial requests`
    * Update the `SERIAL_PORT` variable in `iot_client.py` if your Arduino is not on `COM7`.
4.  **Execution:**
    * Run the script: `python iot_client.py`
    * **Test:** Press the button on the Arduino.
    * **Observe:** The terminal should display "Signal received" followed by "[SUCCESS] Server responded: 200 OK".

---

## Files
1. `arduino_sender.ino`: Arduino firmware for button handling.
2. `iot_client.py`: Python bridge script.

## AI
1. [Prompts used to transact with your selected Generative AI](https://docs.google.com/document/d/1Ph4f8GnvtJRS32F7EDq53SKSUNrVf3dXvfsSIAUVcg0/edit?usp=sharing)
2. Model used to generate the content: Gemini 3 Pro
3. [Transaction ID or the link of the conversation](https://gemini.google.com/share/cd19b5a6c23a)

## Grades
- **Leader:** John Harold R. Magma
### Members 
- Jemuel Chris N. Ambong
- Betina B. Arrojo
- Keren G. Dellosa
- Jamil S. Mariano
- Rachelle Yazmhine C. Mendez
- Audric P. Pascual
