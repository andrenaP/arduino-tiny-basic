# Arduino BASIC Interpreter and Graphics Coprocessor System

This repository details a two-microcontroller embedded system designed to implement a self-contained BASIC programming environment with dedicated graphics output capabilities. The architecture utilizes two Arduino Nano microcontrollers to separate the computational core from the input/output (I/O) processing.

## Project Overview

The system employs a classic coprocessor model to enhance performance and functionality.

* **Main Processor Board (BASIC Interpreter):** An Arduino Nano running a C-based **Tiny BASIC interpreter** firmware. This unit is solely responsible for executing BASIC program logic, managing variables, and performing calculations. All I/O requests are transmitted to the Coprocessor Board.
* **I/O Coprocessor Board (Video and Input):** A second Arduino Nano connected to a host computer (via serial communication) and a small **OLED display module**. This board functions as a dedicated video card and I/O handler. It receives data from the Main Processor and translates it into display output, concurrently managing user input from the host terminal.


### 🎬 Project Demonstrations

The following videos illustrate the functional capabilities of the system and the transition between operational modes.

| Demonstration Name | Description | File Link |
| :--- | :--- | :--- |
| **Random Dots Execution** | Shows the process of sending the BASIC program to the board and the subsequent execution in the graphics mode, displaying random points on the OLED screen. This highlights the responsiveness of the Interpreter/Coprocessor pipeline. | ![View Video: Random Dots (MP4)](https://github.com/andrenaP/arduino-tiny-basic/raw/refs/heads/main/videos/doc_2025-11-23_21-56-03.mp4) |
| **Cube Drawing Primitive** | Focuses on the OLED screen output. The demonstration begins with the full display of the BASIC source code, followed by the execution of the program that successfully draws a $10 \times 10$ geometric cube. | ![View Video: Cube Drawing (MP4)](https://github.com/andrenaP/arduino-tiny-basic/raw/refs/heads/main/videos/doc_2025-11-23_21-56-46.mp4) |

## Functional Capabilities

The system provides robust text and graphics functionality across two selectable modes of operation, managed by the Coprocessor Board.

### 1. Text-Only Mode

This mode is optimized for high-speed serial character transmission and display. It facilitates a command-line interface suitable for programming and executing text-based applications. The Coprocessor processes incoming data as character streams for printing to the OLED display.

### 2. Simple Graphics Mode

This mode extends the system's capabilities to include vector graphics rendering. The Coprocessor receives specific instruction packets (commands) from the Main Processor, which it then executes to manipulate the OLED display buffer.

**Supported Graphical Primitives:**

* Point plotting
* Line drawing
* Circle drawing
* Text rendering at arbitrary screen coordinates

## Hardware Configuration

The system is constructed using the following primary components, as shown in the provided image:

* Two (2) Arduino Nano microcontrollers
* One (1) I2C-compatible OLED Display Module
* Interconnecting breadboard and jumper wires

## Implementation Notes

Communication between the two Arduino Nano boards is conducted via serial protocol. The Main Processor transmits I/O requests and the Coprocessor acknowledges the request, manages the physical display, and handles keyboard input received from the host computer's serial monitor.

