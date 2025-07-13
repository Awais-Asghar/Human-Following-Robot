# Human Following Robot

![Project Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)
![Sensors](https://img.shields.io/badge/Sensors-IR%20Sensors-yellow.svg)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue.svg)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-ff69b4.svg)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-9cf.svg)
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
| DC Motors         | 4        |
| Robot Chassis     | 1        |
| Wheels            | 4        |
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

![Image](https://github.com/user-attachments/assets/fc077446-e137-4352-8a82-34e10b2a96f1)

---

## L298N Motor Driver

The **L298N Motor Driver Module** is used to control the two **DC motors** of the robot. It acts as an interface between the low-power Arduino and the high-power motors.

### Features:

- Can control the **direction and speed** of two DC motors.
- Accepts **PWM (Pulse Width Modulation)** signals from Arduino to adjust motor speed.
- Has two enable pins (**ENA, ENB**) and four control pins (**IN1, IN2, IN3, IN4**) connected to the Arduino.

### Working:

- **ENA / ENB**: Used to control the speed of motors via `analogWrite()`.
- **IN1/IN2** (for Motor A) and **IN3/IN4** (for Motor B): Used to control motor direction via `digitalWrite()`.


Example:
```cpp
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);  // Motor moves forward
```

<img width="1016" height="747" alt="Image" src="https://github.com/user-attachments/assets/f7151af1-5946-4e09-8b7e-d96e9a3b8345" />
<img width="1311" height="870" alt="Image" src="https://github.com/user-attachments/assets/e4d59f72-7b72-4451-b27b-134360b59a04" />
<img width="1035" height="852" alt="Image" src="https://github.com/user-attachments/assets/9ce49fdc-ee98-4d96-85a5-db16a9bd71ec" />

---


## How to Charge Lithium-Ion

### What You Need:
- **TP4056 charging module** (with or without protection circuit)
- **Lithium-Ion battery** (typically 3.7V, like an 18650 cell)
- **Power source** (5V via USB cable or 5V adapter)

###  Wiring Connections

| TP4056 Pin | Connects To           | Description                      |
|------------|-----------------------|----------------------------------|
| **BAT+**   | Battery Positive (+)  | Connect to battery's positive terminal |
| **BAT-**   | Battery Negative (–)  | Connect to battery's negative terminal |
| **IN+**    | 5V Power Positive     | USB VCC or 5V adapter            |
| **IN-**    | 5V Power Ground       | USB GND or adapter GND           |
| **OUT+**   | Output Positive (Optional) | Same as BAT+ if present     |
| **OUT-**   | Output Negative (Optional) | Same as BAT– if present     |


### Charging Status (LED Indicators)

- 🔴 **Red LED ON** → Charging
- 🟢 **Blue/Green LED ON** → Fully Charged (approx. 4.2V)

### TP4056 Specifications

- **Input Voltage:** 4.5V – 5.5V (recommended: 5V)
- **Charging Cut-off Voltage:** 4.2V
- **Max Charging Current:** 1A (default, adjustable by changing onboard resistor)

### Charging Steps

1. Connect **BAT+** and **BAT-** to the Lithium-ion battery terminals.
2. Connect **IN+** and **IN-** to a 5V power supply (USB or adapter).
3. Observe LED indicators:
   - Red = Charging
   - Green/Blue = Fully Charged
4. Disconnect power once fully charged (unless using protected module).


### Safety Tips

-  Never leave charging unattended.
-  Use only **genuine 3.7V Li-ion batteries**.
-  Avoid **short circuits** on BAT terminals.
-  **Do not reverse polarity** — it can damage the module and the battery.
-  Use **TP4056 with protection** for safer charging and discharging.

![Image](https://github.com/user-attachments/assets/41a1097a-51ed-4429-9e1f-69d014f84bbe)


---
## Demonstration

The robot will continuously monitor IR input and follow a dark object/person as long as it's in front of the middle sensor.

![Image](https://github.com/user-attachments/assets/db5a8cd0-b382-4457-86eb-360212a6631b)
![Image](https://github.com/user-attachments/assets/2e7a034a-ea8a-472a-95c6-e72cb3c219ac)
![Image](https://github.com/user-attachments/assets/f01996ca-c88c-40b3-aa25-88b4d33d83d6)

---


## Applications

- Human-following carts or luggage  
- Shopping assistants in stores  
- Personal delivery bots  
- Educational robotic kits  


## Future Improvements

 ➕ Implement **PID control** for smoother and more accurate tracking  
 ➕ Add **Bluetooth or Wi-Fi** for remote override control  
 ➕ Upgrade to **vision-based tracking** using OpenCV or AI camera  
 ➕ Use **rechargeable Li-ion batteries** for long runtime  


## Troubleshooting / Common Issues

-  **Robot not moving** → Check motor power supply and enable pins.  
-  **Sensors not responding** → Ensure proper alignment and correct logic levels.  
-  **Wrong turns** → Swap motor direction pins or verify sensor logic.  
-  **Low speed or stalling** → Check battery voltage and motor connections.  

## Demo Video

https://github.com/user-attachments/assets/1a332b06-d684-478d-a12b-91c1f452c24d 

---

##  Credits / Acknowledgements

Developed by **Awais Asghar**  and **Muhammad Abdullah**


## License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute it with attribution.

---
