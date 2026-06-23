# MODULE 1

## Overview

Module 1 focuses on building the SPY-DER quadruped robot, assembling the hardware, calibrating the servos, implementing basic walking motions, and controlling the robot through Bluetooth.

---

## Hardware Used

- Arduino Nano
- IO Extension Shield
- 12x SG90 Servo Motors
- Battery Pack
- Custom 3D Printed Body

---

## Work Completed

### 1. 3D Body Assembly

- Designed and printed the SPY-DER body.
- Assembled all mechanical parts.
- Mounted servo motors on each leg.
- Installed battery and controller sections.

### 2. Servo Calibration

Before implementing movements, all 12 servos were initialized to their neutral position.

```cpp
servo.write(90);
