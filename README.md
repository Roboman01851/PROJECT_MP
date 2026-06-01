# PROJECT_MP: FPGA Bejeweled Game Clone with Custom Hardware Controller

## Project Overview
This project implements a fully functional clone of the game *Bejeweled* mapped onto an Intel/Altera **DE10-Lite FPGA development board**. The system architecture features a custom, hand-wired physical gamepad built on a **protoboard (breadboard)** that acts as the dedicated game controller, interfacing directly with the FPGA system.

The design leverages an embedded **NIOS II soft-core processor** to handle the core game engine logic, state machine transitions, grid randomizations, and matrix updates.

## System Architecture & File Breakdown
*   **`system.h`**: Serves as the hardware abstraction layer. It contains all system configuration data, register mappings, and input/output base addresses used by the NIOS II processor to scan the physical controller buttons and drive the system video output.
*   **`DIGI_CLOCK.vhd`**: A core hardware description module written in **VHDL**. It manages the real-time game clock logic, frequency dividers, and synchronization blocks required to keep track of match times and render the active countdown clock directly onto the display screen.

## Skills & Technologies Demonstrated
*   **Hardware Description Languages:** Digital system design and timing logic with **VHDL**.
*   **Embedded Processor Design:** Configuration and memory-mapping using Intel **NIOS II**.
*   **Peripheral Interfacing:** Designing custom input hardware on a physical protoboard and managing GPIO debouncing/polling.
*   **Hardware-Software Co-Design:** Integrating low-level hardware structures with high-level game logic.
