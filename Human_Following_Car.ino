// Define constants for the robot
#define Forward_Speed 250
#define Turn_Speed 220

#define Left_IR 3
#define Right_IR 2
#define Middle_IR 4


// Pins for left motor
int enableLeftMotor = 10;
int leftMotorPin1 = 9; //In2 8
int leftMotorPin2 = 8; //In1 9

// Pins for right motor
int enableRightMotor = 5;
int rightMotorPin1 = 7; //In4 7
int rightMotorPin2 = 6; //In3 6


// Setup function
void setup() {

  
  // Initializing serial communication
  Serial.begin(9600);

  // Setting motor pins as outputs
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // Setting IR sensor pins as inputs
  pinMode(Right_IR, INPUT);
  pinMode(Left_IR, INPUT);
  pinMode(Middle_IR, INPUT);
  // Stopping motors initially
  stopMotors();
  
}

// Main loop function
void loop() {

  // Reading values from IR sensors
  int rightIRSensorValue = digitalRead(Right_IR);
  int leftIRSensorValue = digitalRead(Left_IR);
  int Middle_IR_Value = digitalRead(Middle_IR);
  // Controlling the robot based on sensor inputs

  
  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    turnRight();
  } else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    turnLeft();
  } else if (Middle_IR_Value==LOW) {
    goForward();
  } else {
    stopMotors();
  }
}

// Function to control both motors to go forward
void goForward() {
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enableRightMotor, Forward_Speed);
  analogWrite(enableLeftMotor, Forward_Speed);
}

// Function to turn left
void turnLeft() {
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  analogWrite(enableRightMotor, Turn_Speed);
  analogWrite(enableLeftMotor, Turn_Speed);
}

// Function to turn right
void turnRight() {
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(enableRightMotor, Turn_Speed);
  analogWrite(enableLeftMotor, Turn_Speed);
}

// Function to stop both motors
void stopMotors() {
  analogWrite(enableRightMotor, 0);
  analogWrite(enableLeftMotor, 0);
}
