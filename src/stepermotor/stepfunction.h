#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

// Pin definitions
#define PUL_PIN 18  // Pulse (Step equivalent)
#define DIR_PIN 19  // Direction
#define ENA_PIN 5   // Enable motor driver

// Function prototypes
void motorSetup();
void moveForward(int steps, int delayTime);
void moveBackward(int steps, int delayTime);

#endif  // MOTOR_CONTROL_H
