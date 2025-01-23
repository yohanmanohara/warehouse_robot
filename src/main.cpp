#include <Arduino.h>
#include "./motors/motor_control.h"
#include "./sensors/ultrasonic_sensor.h"

void setup() {
  Serial.begin(9600);  // Start serial communication
  initUltrasonicSensor();
  initMotors();
}

void loop() {
  float distance = measureDistance();

  if (distance <= 16.0) {
    Serial.println("Object detected! Stopping motors.");
    stopMotors();
  } else {
    moveMotors();
  }

  delay(500); // Wait for half a second before measuring again
}
