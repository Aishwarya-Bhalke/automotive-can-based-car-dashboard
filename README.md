🚗 Project Overview :

This project implements a CAN-based automotive dashboard system using three PIC microcontrollers (ECUs). Each ECU performs a specific function and communicates over a CAN bus to simulate real-time vehicle data transfer.

The system demonstrates how modern vehicles use distributed ECUs for efficient and reliable communication.

🧩 System Architecture : The project consists of three ECUs:

🔹 ECU1 – Speed & Gear Node Reads vehicle speed using ADC (potentiometer) Reads gear position using keypad Sends data directly to ECU3

🔹 ECU2 – RPM & Indicator Node Reads engine RPM using ADC (potentiometer) Reads indicator status using digital keypad LEFT, RIGHT, OFF, HAZARD Sends data directly to ECU3

🔹 ECU3 – Dashboard Node Receives data from ECU1 and ECU2 Displays: Speed Gear RPM Indicator status Acts as the final dashboard display unit

🔄 Working Principle : ECU1 reads speed (ADC) and gear (keypad) → sends via CAN ECU2 reads RPM (ADC) and indicator status (keypad) → sends via CAN ECU3 receives both messages Data is decoded and displayed on CLCD

🔌 Hardware Components : PIC Microcontrollers (3 units) CAN Transceiver (e.g., MCP2551) Potentiometers (for speed & RPM) Keypad (gear & indicators) CLCD Display Crystal Oscillator Power Supply

💻 Software Requirements : MPLAB IDE XC8 Compiler Embedded C

📡 CAN Communication : Message-based protocol Multi-node communication Reliable and collision-free transmission Data sent using CAN frames (ID + data bytes)

📊 Data Ranges : Speed: 0 – 99 (ADC scaled) RPM: 0 – 6000 (ADC scaled) Gear: User input via keypad Indicators: LEFT / RIGHT / OFF / HAZARD

🧠 Key Concepts Used : ADC (Analog to Digital Conversion) CAN Protocol Embedded C Programming Multi-node communication Real-time data display

📁 Project Structure (Example) /ECU1 main.c /ECU2 ecu2_main.c /ECU3 main.c /common can_driver.c can_driver.h lcd.c keypad.c

✅ Features : Real-time data transmission Distributed ECU architecture Reliable CAN communication Interactive input using keypad Live dashboard display

⚠️ Limitations : Uses simulated inputs (potentiometers) Basic text display (CLCD) Limited number of parameters

🚀 Future Enhancements : Add more sensors (temperature, fuel level) Use graphical display (GLCD/TFT) Implement fault detection system Integrate IoT/cloud monitoring

🎯 Conclusion : This project successfully demonstrates a multi-ECU automotive system using CAN protocol. It shows how different nodes can independently generate data and communicate efficiently to a central dashboard, similar to real-world automotive systems.

🎯 Conclusion : This project successfully demonstrates a multi-ECU automotive system using CAN protocol. It shows how different nodes can independently generate data and communicate efficiently to a central dashboard, similar to real-world automotive systems.
