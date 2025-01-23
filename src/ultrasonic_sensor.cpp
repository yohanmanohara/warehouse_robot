#include <Arduino.h>
#include "ultrasonic_sensor.h"

void initUltrasonicSensor() {
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
}

float measureDistance() {
  long duration;
  float distance;

  // Ensure the trigger pin is LOW before sending a pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin, return the time (in microseconds)
  duration = pulseIn(echoPin, HIGH);

  if (duration > 0) {
    // Convert the time into distance (speed of sound = 34300 cm/s)
    distance = (duration * 0.0343) / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
  } else {
    Serial.println("No echo detected!");
    return -1;  // Return an invalid distance if no echo is detected
  }
}
