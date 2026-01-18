# Internet of Things (IoT) Laboratory Portfolio (Final Project)

## Overview
This repository contains the complete collection of laboratory activities, source code, and practical examinations for the **Internet of Things (IoT)** course. The projects progress from fundamental microcontroller basics to advanced bidirectional communication and web-integrated IoT gateways.

The repository is organized into two main categories: **Laboratory Activities** and **Laboratory Exams**.

## 📂 Repository Structure

### 📘 Laboratory Activities (Labs 1-7)
A progressive series of experiments demonstrating key IoT concepts using Arduino and Python.

* **[Lab 01: Sequential LED Control](./Lab01)**
    * *Project Overview:* This project demonstrates the control of five LEDs in a sequential pattern using an Arduino Uno. The system activates the LEDs one by one, maintains their state for a set duration, and then deactivates them in the same sequence. This project serves as a fundamental exercise in digital output control, array manipulation, and loop iterations.

* **[Lab 02: Analog Sequential Control](./Lab02)**
    * *Project Overview:* This project builds upon the previous sequential control concept by implementing `analogWrite` commands and `while` loops to control five LEDs. The system sequentially activates the LEDs to full brightness and then sequentially deactivates them. This activity highlights the use of Pulse Width Modulation (PWM) syntax for output control and alternative loop structures in C++.

* **[Lab 03: Fire Sensor System](./Lab03)**
    * *Project Overview:* This project simulates a fire detection system using an Arduino Uno. Unlike the previous sequential LED activities, this system utilizes input sensors to monitor environmental conditions. It combines data from a photoresistor (light sensor) and a TMP36 (temperature sensor) to detect a "fire" state. The alarm (LED and Buzzer) is triggered only when **both** high light intensity and high temperature are detected simultaneously.

* **[Lab 04: Arduino Serial Control System](./Lab04)**
    * *Project Overview:* This project demonstrates bi-directional serial communication between an Arduino Uno and a computer. The system monitors ambient light levels using a photoresistor and automatically triggers a blinking LED alert when a specific brightness threshold is reached. Uniquely, this project allows for user intervention: the user can send a "stop" command via the Serial Monitor to override the system and permanently disable the blinking alert.

* **[Lab 05: Receiving Serial Connection using Arduino from Python](./Lab05)**
    * *Project Overview:* This project demonstrates **bi-directional serial communication** between a PC and an Arduino Uno. Unlike previous activities that used the Arduino IDE Serial Monitor, this system utilizes a custom **Python script** as the control interface. The Python program sends character commands ('R', 'G', 'B', 'A', 'O') to the Arduino to toggle three specific LEDs (Red, Green, Blue). This activity highlights the integration of high-level programming languages (Python) with low-level hardware control (Arduino) via the UART protocol.

* **[Lab 06: Bidirectional Control using Arduino and Python](./Lab06)**
    * *Project Overview:* This project establishes a full **bidirectional communication loop** between an Arduino Uno and a Python script. Unlike previous activities where control was one-way (Python controlling Arduino OR Arduino sending data to Python), this system acts as a responsive feedback loop. When a user presses a physical button on the Arduino, a signal is sent to the Python script. The Python script processes this signal and immediately sends a command back to the Arduino to toggle a corresponding LED. This demonstrates the capability of Python to act as a logic processor for hardware events triggered by the microcontroller.

* **[Lab 07: Controlling Arduino using FastAPI](./Lab07)**
    * *Project Overview:* This project evolves the previous serial control concepts by introducing a **Web API interface**. Instead of using a command-line interface (CLI), this system uses **FastAPI**, a modern Python web framework, to create a RESTful API. The system allows users to control the Arduino's LEDs by sending HTTP GET requests (e.g., via a web browser, Postman, or Swagger UI). It demonstrates the integration of **IoT hardware** with **Web Standards**, enabling remote control capabilities. Additionally, the system maintains a background thread to listen for physical button presses on the Arduino and report them back to the server console.

---

### 📕 Laboratory Exams
Comprehensive projects integrating multiple concepts from the weekly activities.

* **[Midterm Laboratory Exam: Serial Controlled Light Sensor System](./Exams/Midterm)**
    * *Project Overview:* This project implements a **Dual-Mode Light Sensor System** using an Arduino Uno. It monitors ambient light intensity via a photoresistor and visually indicates the light level using a traffic-light LED system (Green/Yellow/Red). The system features two distinct operating modes:
        * **Automatic Mode:** The system autonomously determines the environment state ("Cloudy" vs "Clear") and sets LED indicators based on hardcoded thresholds (40% and 70%).
        * **Manual Mode:** The user gains full control via the Serial Monitor to dynamically set custom threshold values (`SET LOW` and `SET HIGH`), allowing for calibration to specific environments without re-uploading code.

* **[Finals Laboratory Exam: IoT Button Client](./Exams/Finals)**
    * *Project Overview:* This project demonstrates an **IoT (Internet of Things) Client** system. It acts as a physical interface for a network-connected application. The system consists of an Arduino Uno acting as a physical trigger and a Python script acting as a "Bridge" or Gateway. When a user presses the physical button on the Arduino, a signal is sent via Serial to the computer. The Python script intercepts this signal and instantly translates it into an **HTTP GET Request** sent to a remote API server (http://172.20.10.3:8000). This architecture mimics real-world IoT buttons (like Amazon Dash buttons) that trigger cloud actions from a simple hardware press.

---

## 🛠 Technology Stack
* **Hardware:** Arduino Uno, LEDs, Pushbuttons, Photoresistors (LDR), Temperature Sensors (TMP36), Piezo Buzzers.
* **Firmware:** C++ (Arduino IDE).
* **Software/Middleware:** Python 3.x.
* **Libraries & Frameworks:**
    * `Serial` (Arduino Built-in)
    * `pyserial` (Python UART communication)
    * `fastapi` & `uvicorn` (Python Web Server)
    * `requests` (Python HTTP Client)

## 👥 Contributors
Lab Activity 1-4 Group Members:
* Arrojo, Betina B. 
* Mariano, Jamil S. 
* Mendez, Rachelle Yazmhine C. 

Lab Activity 5-7 and Lab Exams Group Members:
* Ambong, Jemuel Chris N. 
* Arrojo, Betina B. 
* Dellosa, Keren G. 
* Magma, John Harold R. 
* Mariano, Jamil S. 
* Mendez, Rachelle Yazmhine C. 
* Pascual, Audric P. 
