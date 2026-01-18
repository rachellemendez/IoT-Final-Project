# Lab Activity 7: Controlling Arduino using FastAPI

## Project Overview
This project evolves the previous serial control concepts by introducing a **Web API interface**. Instead of using a command-line interface (CLI), this system uses **FastAPI**, a modern Python web framework, to create a RESTful API.

The system allows users to control the Arduino's LEDs by sending HTTP GET requests (e.g., via a web browser, Postman, or Swagger UI). It demonstrates the integration of **IoT hardware** with **Web Standards**, enabling remote control capabilities. Additionally, the system maintains a background thread to listen for physical button presses on the Arduino and report them back to the server console.

## Repository Structure

### `arduino.ino`
The firmware for the Arduino Uno.
* **Pin Setup:** Configures LEDs on Pins 7, 6, 5 and Buttons on Pins 12, 11, 10.
* **Serial Logic:** Listens for single-character commands (`'1'`, `'2'`, `'3'`, `'o'`, `'f'`) to toggle specific LEDs or control all at once.
* **Physical Control:** Monitors button presses to locally toggle LEDs and sends status messages (e.g., "Button 1 Pressed") back to the Python server.

### `arduino.py`
The "Server-side" Python application using FastAPI.
* **API Framework:** Defines routes (URLs) that trigger hardware actions.
* **Serial Manager:** Opens a connection to `COM7` at 9600 baud.
* **Background Threading:** Uses Python's `threading` module to run a `read_from_arduino` function continuously. This allows the server to receive button press confirmations from the Arduino without blocking the main web server.
* **Endpoints:**
    * `/led/on`: Turns all LEDs ON.
    * `/led/off`: Turns all LEDs OFF.
    * `/led/{color}`: Toggles a specific color (red, green, or blue).

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Actuators:** 3x LEDs (Red, Green, Blue)
* **Inputs:** 3x Pushbuttons
* **Configuration:**
    * **Red LED:** Pin 7
    * **Green LED:** Pin 6
    * **Blue LED:** Pin 5
    * **Buttons:** Pins 12, 11, 10

### API Documentation
Once the server is running, the following endpoints are available:

| Method | Endpoint | Description | Command Sent to Arduino |
| :--- | :--- | :--- | :--- |
| **GET** | `/led/on` | Turns all LEDs ON | `'o'` |
| **GET** | `/led/off` | Turns all LEDs OFF | `'f'` |
| **GET** | `/led/red` | Toggles Red LED | `'1'` |
| **GET** | `/led/green` | Toggles Green LED | `'2'` |
| **GET** | `/led/blue` | Toggles Blue LED | `'3'` |

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the circuit as per the diagram (LEDs on 7, 6, 5; Buttons on 12, 11, 10).
    * *Note:* Ensure the Arduino is connected to the USB port defined in the Python script (default: `COM7`).
2.  **Software Prerequisites:**
    * Install Python 3.x.
    * Install the required libraries:
        ```bash
        pip install fastapi uvicorn pyserial
        ```
3.  **Execution:**
    * **Step 1:** Upload `arduino.ino` to the Arduino board.
    * **Step 2:** Run the API server:
        ```bash
        uvicorn arduino:app --reload
        ```
    * **Step 3:** Open your browser and navigate to the **Swagger UI** to test the controls interactively:
        * URL: `http://127.0.0.1:8000/docs`

---

## Files
1. Arduino Code Sketch File (*.ino)
2. [Breadboard Diagram](https://drive.google.com/file/d/1Q3zFuCz7QvvBWlbJawcrUMuBVxw60YCQ/view?usp=sharing)
3. [Tinkercad Diagram](https://drive.google.com/file/d/1tojCrI2181WEdm6Mzi5x53-089rF7d_4/view?usp=sharing)
4. [Video Simulating the Breadboard and its corresponding Circuit Diagram on TinkerCad](https://drive.google.com/file/d/1DQ9WWUWmo1qZMCe8QqU39jhmn8ZmGocY/view?usp=sharing)

## AI
1. [Prompts used to transact with your selected Generative AI](https://docs.google.com/document/d/1MN57WclmEDDDeA7Bta_moRSLxrkAH41zfC28ILxsMrw/edit?tab=t.0)
2. Model used to generate the content: Gemini 3 Pro
3. [Transaction ID or the link of the conversation](https://gemini.google.com/share/3e477ec98a37)

## Grades
- **Leader:** Betina B. Arrojo
### Members 
- Jemuel Chris N. Ambong
- Betina B. Arrojo
- Keren G. Dellosa
- John Harold R. Magma
- Jamil S. Mariano
- Rachelle Yazmhine C. Mendez
- Audric P. Pascual
