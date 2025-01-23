#include <Arduino.h>

const int trigPin = 14;   // Ensure 14 is correct for your board
const int echoPin = 12;

// Motor A
#define ENA 5  // Motor A speed (PWM)
#define IN1 18 // Motor A direction
#define IN2 19 // Motor A direction

// Motor B
#define ENB 4  // Motor B speed (PWM)
#define IN3 21 // Motor B direction
#define IN4 22 // Motor B direction

void setup() {
  Serial.begin(9600);       // Start the serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT);  //
   Set echo pin as input

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
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

    // Check if the distance is 16 cm or less, stop motors
    if (distance <= 16.0) {
      Serial.println("Object detected! Stopping motors.");
      stopMotors();
    } else {
      moveMotors();
    }
  } else {
    Serial.println("No echo detected!");
  }

  delay(500); // Wait for half a second before measuring again
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
