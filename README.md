# SPY-DER: Speech and Web-Controlled Quadruped Surveillance Robot

SPY-DER is a quadruped surveillance robot developed using **Arduino Nano** and **Raspberry Pi Zero W**. The project focuses on quadruped locomotion, wireless control, and voice-based interaction through a web interface.

The robot uses a custom **3D-printed chassis** and **12 servo motors** to achieve stable four-legged movement.

---

## Hardware Components

- Arduino Nano
- Raspberry Pi Zero W
- IO Extension Shield
- 12 × Servo Motors
- Battery Pack
- Custom 3D Printed Chassis

---

# Module 1: Assembly and Bluetooth Control 

## Overview

In Module 1, the robot chassis was assembled, servo motors were calibrated, and basic locomotion was implemented using Arduino Nano. Bluetooth control was also integrated for wireless operation.

### Completed Tasks

- Designed and assembled the 3D-printed quadruped body
- Installed and connected 12 servo motors
- Mounted Arduino Nano and IO Extension Shield
- Calibrated all servos to the neutral position (90°)
- Developed basic movement functions
- Implemented Bluetooth-based wireless control

### Basic Movements

- Stand Position
- Forward Movement
- Backward Movement
- Left Turn
- Right Turn

### Servo Calibration

All servos were initialized to 90° before movement execution to ensure proper alignment and smooth operation.

```cpp
servo.write(90);
```

### Outcome

The robot successfully performs basic locomotion and responds to Bluetooth commands from a mobile device.

---

# Module 2: Web and Voice Control 

## Overview

Module 2 upgrades the robot from Bluetooth-based control to Wi-Fi-based web and voice control using Raspberry Pi Zero W.

### Current Development

- Integrating Raspberry Pi Zero W
- Removing Bluetooth dependency
- Developing a web-based control dashboard
- Implementing voice command functionality
- Establishing communication between Raspberry Pi and Arduino Nano

### Planned Features

- Web Control
- Voice Control
- Wi-Fi Connectivity
- Remote Operation

### Expected Outcome

Users will be able to control the robot through a web browser or voice commands over a Wi-Fi network.

---

# Future Enhancements

- Live Video Streaming
- Surveillance Camera Integration
- Object Detection
- Autonomous Navigation
- Obstacle Avoidance

---

# Project Status

| Module | Status |
|---------|---------|
| Module 1 – Assembly & Bluetooth Control |  Completed |
| Module 2 – Web & Voice Control |  In Progress |

---


---

# Author

**Sriram Tungala**  
B.Tech – ECE (Embedded Systems and IoT)
KL University
