# Lab Activity 2: Analog Sequential LED Control

## Project Overview
This project builds upon the previous sequential control concept by implementing `analogWrite` commands and `while` loops to control five LEDs. The system sequentially activates the LEDs to full brightness and then sequentially deactivates them. This activity highlights the use of Pulse Width Modulation (PWM) syntax for output control and alternative loop structures in C++.

## Repository Structure

### `Lab02_AnalogSequential.ino`
This is the main firmware file containing the C++ source code for the Arduino.
* **Pin Configuration:** Declares an array of 5 integers representing the digital pins used (Pins 12, 11, 10, 9, and 8).
* **Setup:** Utilizes a `while` loop to iterate through the array and configure each pin as an `OUTPUT`.
* **Loop:**
    * **Activation Sequence:** Uses a `while` loop to iterate through the pins, turning them on using `analogWrite` with a value of 255 (max brightness) and a 1-second delay.
    * **Deactivation Sequence:** Resets the counter and runs a second `while` loop to turn the LEDs off using `analogWrite` with a value of 0.

### `Lab02_CircuitDiagram.png`
A visual schematic illustrating the hardware connections.
* **Microcontroller:** Arduino Uno.
* **Wiring:** Shows five LEDs connected to digital pins 12, 11, 10, 9, and 8, with current-limiting resistors connected to the ground rail.

## Technical Details

### Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible board)
* **Actuators:** 5x LEDs (Red, Yellow, Blue, Green, Orange)
* **Components:** 5x Resistors, Breadboard, Jumper Wires

### Software & Logic
* **Language:** C++ (Arduino)
* **Key Concepts:**
    * **While Loops:** Unlike the previous activity which used `for` loops, this implementation exclusively uses `while` loops for iteration.
    * **Analog Output:** Uses `analogWrite()` instead of `digitalWrite()`.

### Technical Note: PWM vs. Digital Pins
This project applies `analogWrite` to pins 12, 11, 10, 9, and 8. It is important to note the difference in hardware capabilities between these pins on an Arduino Uno:
* **PWM Pins (11, 10, 9):** Capable of Pulse Width Modulation, allowing for true dimming/fading effects (values 0–255).
* **Non-PWM Pins (12, 8):** These are standard digital pins.
* **Behavior:** The code functions correctly because it uses extreme values. `analogWrite(pin, 255)` behaves exactly like `digitalWrite(pin, HIGH)`, and `analogWrite(pin, 0)` behaves like `digitalWrite(pin, LOW)`. If intermediate values (e.g., 127) were used, pins 12 and 8 would not dim; they would remain fully ON.

## Setup & Usage

1.  **Hardware Assembly:**
    * Connect the LEDs to the breadboard as shown in the circuit diagram.
    * Ensure the cathodes are grounded via resistors and anodes are connected to Pins 12 through 8.
2.  **Software Installation:**
    * Open `Lab02_AnalogSequential.ino` in the Arduino IDE.
3.  **Execution:**
    * Upload the code to the Arduino board.
    * Observe the LEDs turning on in sequence (12 to 8) and then turning off in the same sequence, with a 1-second interval between steps.

## Authors
**Group Activity 2**
* Arrojo, Betina
* Mariano, Jamil
* Mendez, Rachelle
