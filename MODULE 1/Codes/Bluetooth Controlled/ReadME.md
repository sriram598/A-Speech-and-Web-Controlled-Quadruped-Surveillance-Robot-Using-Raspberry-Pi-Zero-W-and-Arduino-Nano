# SPY-DER
## Intelligent Speech and Web-Controlled Quadruped Surveillance Robot Using Raspberry Pi Zero W and Arduino Nano

SPY-DER is an intelligent quadruped robotic platform designed for surveillance, remote operation, and future autonomous navigation. The project combines the real-time control capabilities of an Arduino Nano with the networking and AI capabilities of a Raspberry Pi Zero W.

The robot is built using a custom 3D-printed chassis and 12 servo motors, enabling stable four-legged locomotion. The project is being developed in multiple modules, starting with basic movement control and progressing toward web control, voice interaction, surveillance, and autonomous behavior.

---

# Project Objectives

- Design and assemble a quadruped robotic platform.
- Develop stable walking and movement algorithms.
- Enable wireless robot control.
- Implement web-based remote operation.
- Integrate voice command functionality.
- Create a foundation for surveillance and AI-powered navigation.

---

# Hardware Components

| Component | Quantity |
|------------|------------|
| Raspberry Pi Zero W | 1 |
| Arduino Nano | 1 |
| IO Extension Shield | 1 |
| SG90 Servo Motors | 12 |
| Battery Pack | 1 |
| Custom 3D Printed Body | 1 |

---

# Software and Tools

- Arduino IDE
- Raspberry Pi OS
- Python
- C/C++
- Bluetooth Serial Communication
- HTML/CSS/JavaScript
- Git & GitHub

---

# Project Architecture

```text
                  Voice Commands
                         |
                         v
                Raspberry Pi Zero W
                         |
                  Wi-Fi / Web Server
                         |
                    Serial UART
                         |
                    Arduino Nano
                         |
                 IO Extension Shield
                         |
                    12 Servo Motors
                         |
                 Quadruped Robot
```

---

# MODULE 1
## Robot Assembly, Servo Calibration and Bluetooth Control

### Overview

Module 1 focused on building the robot platform, assembling the hardware, calibrating all servo motors, implementing locomotion algorithms, and establishing Bluetooth-based wireless control.

---

## Hardware Used

- Arduino Nano
- IO Extension Shield
- 12 Servo Motors
- Battery Pack
- Custom 3D Printed Chassis

---

## Work Completed

### 1. 3D Body Assembly

The complete SPY-DER robot body was assembled using custom-designed 3D-printed components.

Tasks Completed:

- Assembled central robot body
- Mounted all leg sections
- Installed 12 servo motors
- Mounted Arduino Nano
- Mounted IO Extension Shield
- Installed battery pack

---

### 2. Servo Calibration

All servos were calibrated to their neutral position before implementing movement algorithms.

Servo Neutral Position:

```cpp
servo.write(90);
```

Benefits:

- Proper mechanical alignment
- Improved movement accuracy
- Reduced servo stress
- Easier gait programming

---

### 3. Basic Movement Development

Developed and tested quadruped movement routines.

Implemented Movements:

- Stand Position
- Forward Movement
- Backward Movement
- Left Turn
- Right Turn

Testing confirmed proper synchronization between all four legs.

---

### 4. Bluetooth Control

Bluetooth communication was integrated to control the robot wirelessly using a smartphone.

Supported Commands:

- Forward
- Backward
- Left
- Right
- Stop

Result:

The robot successfully responded to Bluetooth commands and executed movement actions in real time.

---

## Module 1 Achievements

✅ 3D Body Assembled

✅ Arduino Nano Integrated

✅ IO Extension Shield Integrated

✅ 12 Servos Installed

✅ Servo Calibration Completed

✅ Basic Movements Implemented

✅ Bluetooth Control Functional

---

# MODULE 2
## Web and Voice Controlled Quadruped Robot

### Overview

Module 2 upgrades SPY-DER from Bluetooth-based operation to a Wi-Fi-enabled intelligent robotic platform using Raspberry Pi Zero W.

The Bluetooth module will be removed and replaced with Raspberry Pi Zero W, enabling web control and voice interaction.

---

## Hardware Upgrade

### Existing Components

- Arduino Nano
- IO Extension Shield
- 12 Servo Motors
- Battery Pack

### New Component

- Raspberry Pi Zero W

---

## Planned System Architecture

```text
User Voice Command
        |
        v
 Raspberry Pi Zero W
        |
 Web Server + Voice Engine
        |
     UART Serial
        |
   Arduino Nano
        |
 IO Extension Shield
        |
   12 Servo Motors
```

---

## Planned Features

### 1. Web Control Dashboard

The robot will be controlled through a browser-based dashboard.

Control Options:

- Forward
- Backward
- Left
- Right
- Stop

Accessible From:

- Mobile Phone
- Laptop
- Tablet

---

### 2. Voice Control

Voice recognition will allow hands-free operation.

Supported Commands:

- Move Forward
- Move Backward
- Turn Left
- Turn Right
- Stop

---

### 3. Wi-Fi Communication

Bluetooth communication will be replaced with Wi-Fi communication.

Advantages:

- Longer operating range
- Browser-based control
- Multiple device accessibility
- Future cloud integration

---

### 4. Raspberry Pi Integration

The Raspberry Pi Zero W will act as the high-level controller.

Responsibilities:

- Host web interface
- Process voice commands
- Communicate with Arduino Nano
- Execute user commands

The Arduino Nano will continue handling real-time servo control.

---

## Expected Outcomes

✅ Web-Based Robot Control

✅ Voice-Controlled Navigation

✅ Raspberry Pi Zero W Integration

✅ Wi-Fi-Based Communication

✅ Improved User Interaction

---

# Future Enhancements

### Module 3

Surveillance Features

- Live Video Streaming
- Remote Monitoring
- Image Capture

### Module 4

Artificial Intelligence Features

- Object Detection
- Face Recognition
- Autonomous Patrol

### Module 5

Autonomous Navigation

- Obstacle Avoidance
- Path Planning
- Environment Mapping

---

# Repository Structure

```text
SPY-DER/
│
├── MODULE 1/
│   ├── Codes/
│   ├── Images/
│   ├── Circuit Diagram/
│   └── README.md
│
├── MODULE 2/
│   ├── RaspberryPi/
│   ├── Web Control/
│   ├── Voice Control/
│   └── README.md
│
├── Images/
├── Documents/
├── LICENSE
└── README.md
```

---

# Current Project Status

| Module | Status |
|----------|----------|
| Module 1 – Assembly & Bluetooth Control | ✅ Completed |
| Module 2 – Web & Voice Control | 🔄 In Progress |
| Module 3 – Surveillance System | ⏳ Planned |
| Module 4 – AI Features | ⏳ Planned |
| Module 5 – Autonomous Navigation | ⏳ Planned |

---

# Author

**Sriram Tungala**

B.Tech – Embedded Systems and IoT

KL University

GitHub: https://github.com/sriram598
