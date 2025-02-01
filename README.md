# Fire Alert System using ESP32

## **Project Description**
This project implements a **fire detection system** using an **ESP32** microcontroller, a **flame sensor**, and a **buzzer**. The system detects flames by reading the sensor’s output (HIGH for flame, LOW for no flame). When a flame is detected, the buzzer is activated to alert users.

## **Project Structure**
- **`src/`**: Contains the source code (`main.c`).
- **`README.md`**: This document with project details and instructions.

## **Hardware Requirements**
- **ESP32** development board.
- **Flame Sensor** connected to GPIO 13.
- **Buzzer** connected to GPIO 15.

## **Software Requirements**
- **ESP-IDF** framework for ESP32 programming.
- **VS Code** for code development.

## **Instructions to Run the Code**

1. Clone the repository or download the source code from the Github.
2. Build the project
3. Flash the code to the ESP32
4. Monitor the output
5. Fire detected: "🔥 Fire detected! Activating alarm..." and the buzzer sounds.
No fire detected: "✅ No fire detected." and the buzzer is off.
   
