# Midterm Laboratory Exam: Serial Controlled Light Sensor System

## Project Overview
This project implements a **Dual-Mode Light Sensor System** using an Arduino Uno. The system monitors ambient light intensity via a photoresistor (LDR) and provides visual feedback using a "Traffic Light" LED configuration (Green, Yellow, Red).

The system operates in two distinct modes controlled via the Serial Monitor:
1.  **Manual Mode (Default):** The user can dynamically set the specific light intensity thresholds for the LEDs using text commands.
2.  **Automatic Mode:** The system uses fixed, pre-programmed thresholds to classify the environment (e.g., "Cloudy" vs. "Bright Sunlight").

## Repository Structure

### `midterms_exam.ino`
The main firmware file containing the C++ source code.
* **Hardware Configuration:**
    * **Inputs:** Photoresistor on Pin **A0**.
    * **Outputs:** Green LED (Pin **11**), Yellow LED (Pin **12**), Red LED (Pin **13**).
* **System Logic:**
    * **State Management:** Uses an `enum Mode` (MANUAL, AUTOMATIC) to track the system state.
    * **Serial Command Parsing:** The `checkSerialCommands()` function listens for user inputs to switch modes or update thresholds.
    * **Feedback Loop:** The `printSerialStatus()` function reports real-time statistics every 1000ms, including intensity percentage, the active LED, and the current environmental classification.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Sensors:** 1x Photoresistor (LDR)
* **Actuators:** 3x LEDs (Green, Yellow, Red)
* **Components:** Resistors (10kΩ for LDR voltage divider, 220Ω for LEDs), Breadboard, Jumper Wires.

### Operation Modes & Logic

#### 1. Manual Mode
* **Description:** Allows calibration of the system without re-uploading code.
* **Commands:**
    * `SET LOW <number>`: Sets the boundary between Green and Yellow (0-100).
    * `SET HIGH <number>`: Sets the boundary between Yellow and Red (0-100).
* **Validation:** The code ensures the Low threshold is always lower than the High threshold.

#### 2. Automatic Mode
* **Description:** Autonomous operation with hardcoded values.
* **Thresholds:**
    * **Green (Cloudy):** Intensity ≤ 40%.
    * **Yellow (Normal):** 40% < Intensity ≤ 70%.
    * **Red (Bright Sunlight):** Intensity > 70%.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the **Photoresistor** to Pin **A0**.
    * Connect the **Green LED** to Pin **11**.
    * Connect the **Yellow LED** to Pin **12**.
    * Connect the **Red LED** to Pin **13**.
2.  **Software Installation:**
    * Open `midterms_exam.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino.
    * Open the **Serial Monitor** (Baud Rate: 9600).
    * **Initial State:** The system starts in **MANUAL** mode.
    * **Test Commands:**
        * Type `MODE AUTO` to switch to automatic presets.
        * Type `SET LOW 20` (in Manual Mode) to adjust the sensitivity.

---

## Files
1.  `midterms_exam.ino`

## AI
1.  [Prompts used to transact with your selected Generative AI](https://docs.google.com/document/d/157kyq6bmzsTN36vueSw1yjSqWcjcszTZH0mbGn4xpRg/edit?usp=sharing)
2.  **Model used:** Gemini 3 Pro
3.  [Transaction ID or the link of the conversation](https://gemini.google.com/share/a315dad58546)

### Contributors
-   Arrojo, Betina B.
-   Mariano, Jamil S. 
-   Mendez, Rachelle Yazmhine C. 
-   Pascual, Audric P. 

