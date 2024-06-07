# Human-Following Robot

## Overview

This project uses an Arduino to create a human-following robot. The robot uses three IR sensors to detect the path and control the motors to follow the line. Additionally, the robot stops when a human is detected using the IR sensors.

## Features

- **Motor Control**: The robot has precise control over its motors to move forward, turn left, or turn right.
- **Human Detection**: The robot stops when a human is detected using the IR sensors.

## Components

- Arduino
- IR Sensors (3)
- Motor Driver (L298N or similar)
- Motors (2)
- Chassis
- Wheels
- Power Supply (Battery pack)
- Connecting wires

## Pin Configuration

### Motor Control Pins

- **Enable Pins**: These pins control the speed of the motors using PWM (Pulse Width Modulation). The enable pins are connected to the PWM-capable pins on the Arduino.
  - `enableLeftMotor` (Pin 10): Controls the speed of the left motor.
  - `enableRightMotor` (Pin 5): Controls the speed of the right motor.

- **Control Pins**: These pins control the direction of the motors.
  - **Left Motor**:
    - `leftMotorPin1` (Pin 9): Controls the direction of the left motor (connected to motor driver In1).
    - `leftMotorPin2` (Pin 8): Controls the direction of the left motor (connected to motor driver In2).
  - **Right Motor**:
    - `rightMotorPin1` (Pin 7): Controls the direction of the right motor (connected to motor driver In3).
    - `rightMotorPin2` (Pin 6): Controls the direction of the right motor (connected to motor driver In4).

### IR Sensor Pins

- `Left_IR` (Pin 3): Reads the input from the left IR sensor.
- `Right_IR` (Pin 2): Reads the input from the right IR sensor.
- `Middle_IR` (Pin 4): Reads the input from the middle IR sensor.

## Code Explanation

### Define Constants

```cpp
#define Forward_Speed 250
#define Turn_Speed 220

#define Left_IR 3
#define Right_IR 2
#define Middle_IR 4

int enableLeftMotor = 10;
int leftMotorPin1 = 9;
int leftMotorPin2 = 8;

int enableRightMotor = 5;
int rightMotorPin1 = 7;
int rightMotorPin2 = 6;
```

### Setup Function

The `setup()` function initializes the robot by setting up the serial communication, configuring the motor control pins as outputs, and the IR sensor pins as inputs. It also stops the motors initially to ensure the robot does not start moving unexpectedly.

```cpp
void setup() {
  Serial.begin(9600);

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(Right_IR, INPUT);
  pinMode(Left_IR, INPUT);
  pinMode(Middle_IR, INPUT);

  stopMotors();
}
```

### Loop Function

The `loop()` function continuously reads the values from the IR sensors and decides the movement of the robot based on these inputs. If the middle IR sensor detects an obstacle (e.g., a human), the robot stops.

```cpp
void loop() {
  int rightIRSensorValue = digitalRead(Right_IR);
  int leftIRSensorValue = digitalRead(Left_IR);
  int Middle_IR_Value = digitalRead(Middle_IR);

  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    turnRight();
  } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    turnLeft();
  } else if (Middle_IR_Value == LOW) {
    goForward();
  } else {
    stopMotors();
  }
}
```

### Motor Control Functions

#### Move Forward

The `goForward()` function sets the motor control pins to move the robot forward. Both motors are set to rotate in the same direction with the specified speed (`Forward_Speed`).

```cpp
void goForward() {
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enableRightMotor, Forward_Speed);
  analogWrite(enableLeftMotor, Forward_Speed);
}
```

#### Turn Left

The `turnLeft()` function sets the motor control pins to turn the robot left. The right motor moves forward while the left motor moves backward, causing the robot to turn.

```cpp
void turnLeft() {
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  analogWrite(enableRightMotor, Turn_Speed);
  analogWrite(enableLeftMotor, Turn_Speed);
}
```

#### Turn Right

The `turnRight()` function sets the motor control pins to turn the robot right. The left motor moves forward while the right motor moves backward, causing the robot to turn.

```cpp
void turnRight() {
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enableRightMotor, Turn_Speed);
  analogWrite(enableLeftMotor, Turn_Speed);
}
```

#### Stop Motors

The `stopMotors()` function stops both motors by setting the speed to 0.

```cpp
void stopMotors() {
  analogWrite(enableRightMotor, 0);
  analogWrite(enableLeftMotor, 0);
}
```



## Installation

1. **Hardware Setup**:
    - Connect the IR sensors to the specified pins.
    - Connect the motors and motor driver to the Arduino.
    - Ensure the power supply to the motors and the Arduino is correctly set up.

2. **Software Setup**:
    - Install the Arduino IDE.
    - Open the provided `.ino` file in the Arduino IDE.
    - Upload the code to the Arduino board.

## Usage

1. Power on the robot.
2. Place the robot on a line track.
4. The robot will move right if right IR Sensor detects human.
5. The robot will move left if left IR Sensor detects human.
6. The robot will move forward if middle IR Sensor detects human.

## Customization

- **Adjusting Speed**: Modify the `Forward_Speed` and `Turn_Speed` constants to change the robot's speed.
- **Sensor Sensitivity**: Adjust the thresholds in the `loop()` function to fine-tune the sensor readings.

## Troubleshooting

- **Robot Not Moving**: Check the motor connections and ensure the enable pins are correctly configured.
- **Sensors Not Detecting Line**: Verify the sensor connections and adjust the sensor thresholds if necessary.
- **Robot Not Stopping for Obstacles**: Ensure the middle IR sensor is functioning and properly connected.

## License

This project is licensed under the MIT License. Feel free to modify and distribute as per the license terms.

## Acknowledgments

Special thanks to the contributors of the libraries used in this project.
