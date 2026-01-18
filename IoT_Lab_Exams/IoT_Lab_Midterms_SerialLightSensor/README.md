# Midterm Laboratory Exam: Serial Controlled Light Sensor System

## Project Overview
This project implements a **Dual-Mode Light Sensor System** using an Arduino Uno. It monitors ambient light intensity via a photoresistor and visually indicates the light level using a traffic-light LED system (Green/Yellow/Red).

The system features two distinct operating modes:
1.  **Automatic Mode:** The system autonomously determines the environment state ("Cloudy" vs "Clear") and sets LED indicators based on hardcoded thresholds (40% and 70%).
2.  **Manual Mode:** The user gains full control via the Serial Monitor to dynamically set custom threshold values (`SET LOW` and `SET HIGH`), allowing for calibration to specific environments without re-uploading code.

## Repository Structure

### `sketch_nov8a.ino`
The main firmware file containing the C++ source code for the Arduino.
* **Initialization:** Configures pins for the Photoresistor (A0) and LEDs (11, 12, 13).
* **Core Logic (`loop`):**
    * Reads the sensor value and maps it to a 0-100% intensity scale.
    * Executes the `setLED()` function to update the visual indicators based on the current mode (Auto vs Manual).
    * Prints real-time diagnostics (Intensity, Active LED, Mode) to the Serial Monitor.
* **Command Processing (`checkSerialInput`):**
    * Listens for mode switching commands: `MODE AUTO` and `MODE MANUAL`.
    * Listens for threshold adjustments (Manual Mode only): `SET LOW XX` and `SET HIGH XX`.

### `Lab04_CircuitDiagram.png`
A visual schematic illustrating the hardware connections used for this exam.
* **Microcontroller:** Arduino Uno.
* **Input:** Photoresistor (LDR) connected to Analog Pin A0 with a voltage divider circuit.
* **Output:** Three LEDs (Green, Yellow, Red) connected to Digital Pins 11, 12, and 13 respectively.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Sensors:** 1x Photoresistor (LDR)
* **Actuators:** 3x LEDs (Green, Yellow, Red)
* **Components:** Resistors (10kΩ for LDR divider, 220Ω for LEDs), Breadboard, Jumper Wires

### Logic Flow & Thresholds

#### Automatic Mode Logic
In this mode, the system uses fixed standard values:
* **Green (Low Light):** Intensity ≤ 40% (Environment: "Cloudy").
* **Yellow (Normal Light):** 40% < Intensity ≤ 70%.
* **Red (High Light):** Intensity > 70% (Environment: "Clear").

#### Manual Mode Logic
In this mode, the user defines the breakpoints via Serial commands:
* **Green:** Intensity ≤ `LOW_THRESHOLD` (User defined).
* **Yellow:** `LOW_THRESHOLD` < Intensity ≤ `HIGH_THRESHOLD` (User defined).
* **Red:** Intensity > `HIGH_THRESHOLD`.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the Photoresistor to Pin A0.
    * Connect Green LED to Pin 11, Yellow to Pin 12, and Red to Pin 13.
2.  **Software Installation:**
    * Open `sketch_nov8a.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino.
    * Open the **Serial Monitor** (9600 baud).
    * **Observe:** The system defaults to **Manual Mode**.
    * **Interact:**
        * Type `MODE AUTO` to switch to automatic presets.
        * Type `MODE MANUAL` to return to manual control.
        * Type `SET LOW 30` to change the Green/Yellow boundary to 30%.
        * Type `SET HIGH 80` to change the Yellow/Red boundary to 80%.

---

## Files Description
1.  **sketch_nov8a.ino**: Main Arduino sketch file.
2.  **Lab04_CircuitDiagram.png**: Circuit diagram image.

## Generative AI
1.  [Prompts used to transact with your selected Generative AI](https://docs.google.com/document/d/1DM2Y4li1f3TO6f3GV8G6GQgeIlcYUiep8Qa7PcUrZw0/edit?usp=sharing)
2.  **Model used:** ChatGPT5
3.  [Transaction ID or the link of the conversation](https://chatgpt.com/c/690eca7d-ea0c-8325-a761-d5032e31c679)

## Grades
-   **Leader:** John Harold R. Magma
### Members
-   Jemuel Chris N. Ambong
-   Keren G. Dellosa
-   Johnny Sagal De Asis
-   Zeus Padilla
