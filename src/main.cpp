#include <Arduino.h>
#include "./motors/motor_control.h"
#include "./sensors/ultrasonic_sensor.h"
#include "./sensors/huminity_sensor.h"

void setup() {
  Serial.begin(9600);  // Start serial communication
  initUltrasonicSensor();
  collectAndDisplayData(); 
  initMotors();
}

void loop() {
  float distance = measureDistance();
  collectAndDisplayData(); 
   

  if (distance <= 16.0) {
    Serial.println("Object detected! Stopping motors.");
    moveback();
    // stopMotors();
  } else {
    moveMotors();
  }

  delay(500); 
}
