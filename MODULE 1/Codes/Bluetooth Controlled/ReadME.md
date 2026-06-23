# MODULE 1 - Mechanical Design and Basic Movements

## Overview

Module 1 focuses on the mechanical design, assembly, servo calibration, and basic locomotion of the SPY-DER quadruped robot.

The goal of this module is to create a stable quadruped platform capable of performing fundamental movements before integrating wireless communication, speech control, and surveillance features.

---

## Objectives

- Design the SPY-DER robot chassis using CAD software.
- Assemble servo-driven legs.
- Calibrate all servos to their neutral position.
- Develop basic movement algorithms.
- Test stability and walking motions.

---

## Completed Work

### 1. 3D Model Design

A complete 3D model of SPY-DER was designed.

Features:

- Lightweight body frame
- Four-legged structure
- Servo mounting slots
- Controller mounting space
- Battery compartment

---

### 2. Servo Installation

The robot uses servo motors for leg movement.

Each leg consists of:

- Hip Joint Servo
- Knee Joint Servo

Total Servos Used: 8

---

### 3. Servo Calibration

Before executing any movement, all servos are set to their neutral position (90°).

Benefits:

- Proper alignment of legs
- Reduced servo stress
- Accurate movement execution
- Easier gait development

Example:

```cpp
servo.write(90);
```

---

### 4. Basic Movements Implemented

The following movements were successfully tested:

#### Stand Position

All servos positioned at 90° to maintain a stable standing posture.

#### Forward Movement

Robot performs coordinated leg movement to move forward.

#### Backward Movement

Reverse walking sequence.

#### Left Turn

Adjusts left and right leg movements for turning.

#### Right Turn

Adjusts leg sequence for right-side rotation.

#### Sit Position

Lowers body by changing knee servo angles.

---

## Files Included

### Codes/Basic moments

- BasicMovements.ino
- FlexiTimer2.cpp
- FlexiTimer2.h

### Servo Calibration

- 90_servo_angle.ino

### Circuit Diagram

- Circuit diagram1.jpg

---

## Folder Structure

```text
MODULE 1
│
├── Codes
│   ├── Basic moments
│   │   ├── BasicMovements.ino
│   │   ├── FlexiTimer2.cpp
│   │   └── FlexiTimer2.h
│   │
│   └── Bluetooth Controlled
│
├── 90_servo_angle.ino
├── Circuit diagram1.jpg
├── LICENSE
└── README.md
```

---

## Results

 3D Model Completed

 Servo Mounting Completed

 Servo Calibration Completed

 Basic Movement Testing Completed

 Circuit Design Completed

---

## Next Module

### Module 2: Bluetooth and Web Control

Planned Features:

- Bluetooth control
- Web dashboard
- Wireless command execution
- Raspberry Pi integration

---

## Author

Sriram Tungala

B.Tech - Embedded Systems and IoT

KL University
