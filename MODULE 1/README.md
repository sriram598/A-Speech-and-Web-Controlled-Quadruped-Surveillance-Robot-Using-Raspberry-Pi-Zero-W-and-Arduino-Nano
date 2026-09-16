# MODULE 1 – SPYDER Robot Hardware & Basic Control

## Overview

Module 1 focuses on the **hardware design, servo control, and basic movement** of the SPYDER quadruped robot.

The robot uses an **Arduino Nano** to control 12 servo motors. These servos are arranged as 3 joints for each of the 4 legs.

## Hardware Components

- Arduino Nano
- 12 × Servo Motors
- Quadruped Robot Body
- Battery
- IO Extension Shield
- Connecting Wires

## Leg Configuration

The robot has **4 legs**, and each leg contains **3 servo motors**:

- Coxa joint
- Femur joint
- Tibia joint

Total:

**4 Legs × 3 Servos = 12 Servos**

## Basic Movements

Module 1 supports basic quadruped movements such as:

- Stand
- Sit
- Forward movement
- Backward movement
- Turning
- Leg lifting
- Basic body movements

## Inverse Kinematics

Inverse Kinematics (IK) is used to calculate the required servo angles from the desired position of each leg.

The leg dimensions used in the program are:

- `length_a = 55 mm`
- `length_b = 77.5 mm`
- `length_c = 27.5 mm`

The Arduino calculates the required joint angles using the X, Y and Z coordinates of the foot.

## Servo Control

The 12 servos are controlled using the Arduino Servo library.

Servo pins:

| Leg | Servo 1 | Servo 2 | Servo 3 |
|---|---:|---:|---:|
| Leg 1 | D3 | D4 | D2 |
| Leg 2 | D6 | D7 | D5 |
| Leg 3 | D9 | D8 | D10 |
| Leg 4 | D12 | D11 | D13 |

## Folder Structure

```text
MODULE 1/
│
├── Codes/
│   ├── 90_servo_angle.ino
│   └── Basic moments/
│
├── Circuit diagram1.jpg
│
└── Simulation/
    ├── SPYDER_ROBOT.ino
    ├── diagram.json
    └── wokwi.toml
