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
  // Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,  100); // Speed control (0-255)

  //Motor B reverse
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





 

  