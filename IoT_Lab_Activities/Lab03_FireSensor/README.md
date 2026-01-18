# Lab Activity 3: Fire Sensor System

## Project Overview
This project simulates a fire detection system using an Arduino Uno. Unlike the previous sequential LED activities, this system utilizes input sensors to monitor environmental conditions. It combines data from a photoresistor (light sensor) and a TMP36 (temperature sensor) to detect a "fire" state. The alarm (LED and Buzzer) is triggered only when **both** high light intensity and high temperature are detected simultaneously.

## Repository Structure

### `Lab03_FireSensor.ino`
This is the main firmware file containing the C++ source code for the Arduino.
* **Initialization:** Uses `#define` macros to assign pins and `const int` for setting sensor threshold limits (Light: 220, Temp: 50°C).
* **Modular Functions:**
    * `brightnessReading()`: Reads the photoresistor on Pin A2. Returns `1` if the value exceeds the limit, otherwise `0`.
    * `temperatureReading()`: Reads the TMP36 sensor on Pin A0, converts the analog signal to Celsius, and returns `1` if the temperature exceeds the limit.
* **Loop Logic:**
    * Polls both sensors using the custom functions.
    * Uses a **Logical AND (`&&`)** operator to verify if *both* conditions are met.
    * Activates the notification pin (LED + Buzzer) with a 1-second interval if the alarm condition is valid.

### `Lab03_CircuitDiagram.png`
A visual schematic illustrating the hardware connections.
* **Microcontroller:** Arduino Uno.
* **Sensors:**
    * **TMP36 Temperature Sensor:** Connected to Analog Pin A0.
    * **Photoresistor (LDR):** Connected to Analog Pin A2 (with a pull-down resistor).
* **Actuators:**
    * **Piezo Buzzer & LED:** Connected in parallel to Digital Pin 12 to provide both visual and audio alerts.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Sensors:** 1x TMP36 Temperature Sensor, 1x Photoresistor (LDR)
* **Actuators:** 1x Red LED, 1x Piezo Buzzer
* **Components:** Resistors (10kΩ for LDR divider, 220Ω for LED), Breadboard, Jumper Wires

### Software & Logic
* **Language:** C++ (Arduino)
* **Key Concepts:**
    * **Sensor Fusion:** The core logic relies on combining two distinct data points (Light + Heat) to create a specific trigger condition.
    * **Analog Input:** Uses `analogRead()` to interpret varying voltage levels from environmental sensors.
    * **Data Mapping:** Uses the `map()` function to convert raw sensor data (0-1023) into readable units (Celsius).
    * **Logical Operators:** Utilizes the `&&` (AND) operator, ensuring the alarm does not trigger on false positives (e.g., just a bright room or just a hot day).

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the **TMP36** sensor output to Pin **A0**.
    * Connect the **Photoresistor** and its voltage divider resistor to Pin **A2**.
    * Connect the **LED** (anode) and **Buzzer** (positive) to Pin **12**.
2.  **Software Installation:**
    * Open `Lab03_FireSensor.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino board.
    * Open the **Serial Monitor** (9600 baud) to view real-time readings ("lightValue" and "thermistorValue").
    * **Test the System:** Apply heat (e.g., finger warmth or simulated fire) to the TMP36 AND shine a bright light on the LDR.
    * Observe the LED flashing and Buzzer sounding only when both thresholds are crossed.

## Authors
**Group Activity 3**
* Arrojo, Betina
* Mariano, Jamil
* Mendez, Rachelle
