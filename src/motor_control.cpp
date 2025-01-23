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
  analogWrite(ENA, 150); // Speed control (0-255)

  // Motor B reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200); // Speed control (0-255)

  Serial.println("Motors running...");
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  Serial.println("Motors stopped.");
}
