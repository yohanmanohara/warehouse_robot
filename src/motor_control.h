#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor A
#define ENA 5  // Motor A speed (PWM)
#define IN1 18 // Motor A direction
#define IN2 19 // Motor A direction

// Motor B
#define ENB 4  // Motor B speed (PWM)
#define IN3 21 // Motor B direction
#define IN4 22 // Motor B direction

void initMotors();
void moveMotors();
void stopMotors();

#endif
