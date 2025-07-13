# Human Following Robot

![Project Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)
![Sensors](https://img.shields.io/badge/Sensors-IR%20Sensors-yellow.svg)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue.svg)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-00599C.svg)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-success.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

<img width="1688" height="1125" alt="Image" src="https://github.com/user-attachments/assets/e807667a-763a-459d-b979-2d9e546bfd37" />

---


##  Overview / Introduction

The **Human Following Robot** is a simple and intelligent robot that uses **three infrared sensors** to follow a person (or any black path/leg) by detecting direction and movement. This project utilizes an Arduino Uno, IR sensors, and a motor driver to dynamically control the robot's motion — forward, left, or right — based on the relative position of a moving object or a central signal detected by the IR sensors.


##  Features

-  Follows a person or object using three IR sensors
-  Smart decision-making: turns left, right, or moves straight
-  Controlled by L298N Motor Driver
-  Real-time detection using digital IR sensors
-  Easy to build and modify


## Hardware Components

| Component          | Quantity |
|-------------------|----------|
| Arduino UNO       | 1        |
| IR Sensors        | 3        |
| L298N Motor Driver| 1        |
| DC Motors         | 2        |
| Robot Chassis     | 1        |
| Wheels            | 2        |
| Jumper Wires      | -        |
| Power Supply (Battery Pack) | 1 |


## Software Requirements

- Arduino IDE
- Arduino Board Library
- USB Cable for Arduino
- Serial Monitor (for debugging, optional)


## Pin Configuration

| Function              | Arduino Pin |
|-----------------------|-------------|
| Left IR Sensor        | D3          |
| Right IR Sensor       | D2          |
| Middle IR Sensor      | D4          |
| Left Motor Enable     | D10         |
| Left Motor IN1        | D9          |
| Left Motor IN2        | D8          |
| Right Motor Enable    | D5          |
| Right Motor IN1       | D7          |
| Right Motor IN2       | D6          |


## Decision-Making Logic

- **Middle IR sensor LOW** → Go **Forward**
- **Left IR sensor LOW**, Right HIGH → Turn **Left**
- **Right IR sensor LOW**, Left HIGH → Turn **Right**
- **All sensors HIGH** → **Stop** (Lost track)


## Function Descriptions

- `goForward()` — Sets both motors to move forward at defined speed
- `turnLeft()` — Rotates the robot to the left
- `turnRight()` — Rotates the robot to the right
- `stopMotors()` — Halts all motor movement


## How to Run

1. Assemble all components as per the wiring table.
2. Open Arduino IDE and paste the code.
3. Upload the code to your Arduino UNO board.
4. Place the robot in front of a human leg or dark object.
5. Power the robot and watch it follow the target!


## Sensors & Motor Driver Explained

### IR Sensors

The robot uses three **IR sensors** (Left, Middle, Right) to detect reflected IR light. These sensors work based on infrared reflection:

- **White/Reflective surface** → Reflects IR → Sensor reads **LOW**
- **Black/Absorptive surface (like clothes)** → Absorbs IR → Sensor reads **HIGH**
- The robot compares values from all three sensors to detect which direction to move in to follow a person or leg.


###  L298N Motor Driver

The **L298N Module** is a dual H-bridge motor driver used to control the speed and direction of two DC motors. It allows independent control of each motor using:

- **Enable Pins (ENA/ENB)** for PWM speed control.
- **IN1, IN2, IN3, IN4** for direction control.

Example:
```cpp
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);  // Motor moves forward
```

## Demonstration

The robot will continuously monitor IR input and follow a dark object/person as long as it's in front of the middle sensor.


## Applications

- Human-following carts or luggage  
- Shopping assistants in stores  
- Personal delivery bots  
- Educational robotic kits  


## Future Improvements

- ➕ Add **Ultrasonic sensors** to avoid obstacles while following  
- ➕ Implement **PID control** for smoother and more accurate tracking  
- ➕ Add **Bluetooth or Wi-Fi** for remote override control  
- ➕ Upgrade to **vision-based tracking** using OpenCV or AI camera  
- ➕ Use **rechargeable Li-ion batteries** for long runtime  


## Troubleshooting / Common Issues

-  **Robot not moving** → Check motor power supply and enable pins.  
-  **Sensors not responding** → Ensure proper alignment and correct logic levels.  
-  **Wrong turns** → Swap motor direction pins or verify sensor logic.  
-  **Low speed or stalling** → Check battery voltage and motor connections.  


##  Credits / Acknowledgements

Developed by **Awais Asghar**  and **Muhammad Abdullah**


## License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute it with attribution.

---
