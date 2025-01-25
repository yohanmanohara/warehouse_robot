#include <Arduino.h>
#include "motor_control.h"

void initMotors() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void moveMotors() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,  100); // Speed control (0-255)

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Motors running... FORWARD");
}

void stopMotors() {
  // Stop Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); // Set both inputs to LOW to stop the motor
  analogWrite(ENA, 0); // Set speed to 0 to stop

  // Stop Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); // Set both inputs to LOW to stop the motor
  analogWrite(ENB, 0); // Set speed to 0 to stop

  Serial.println("Motors stopped.");
}

void moveback() {
   // Reverse Motor A
  digitalWrite(IN1, LOW);   // Set IN1 LOW
  digitalWrite(IN2, HIGH);  // Set IN2 HIGH to go backward
  analogWrite(ENA, 100);    // Set speed (0-255)

  // Reverse Motor B
  digitalWrite(IN3, LOW);   // Set IN3 LOW
  digitalWrite(IN4, HIGH);  // Set IN4 HIGH to go backward
  analogWrite(ENB, 100);    // Set speed (0-255)

  Serial.println("Motors running... BACKWARD");
}


void turnRight() {
  // Turn Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B reverse (Right turn)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Right");
}

void turnLeft() {
  // Turn Motor A reverse (Left turn)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Left");
}

void turnLeft90() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); 

  Serial.println("Turning Left 90 Degrees");
  
  
  delay(1000);  

  stopMotors();
}

 void turnRight90() {
  // Turn Motor A forward (Right turn)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Right 90 Degrees");
  
  // Wait for the robot to complete a 90-degree turn
  // You may need to adjust the time (in milliseconds) based on your setup
  delay(1000);  // Adjust this delay based on the robot's speed and wheel size

  // Stop the motors after the turn
  stopMotors();
}

  