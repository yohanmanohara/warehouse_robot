#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor A
#define ENA 19  // Motor A speed (PWM)
#define IN1 21 // Motor A direction
#define IN2 18 // Motor A direction

// Motor B
#define ENB 23  // Motor B speed (PWM)
#define IN3 5 // Motor B direction
#define IN4 22 // Motor B direction

void initMotors();
void moveMotors();
void stopMotors();
void moveback();
#endif
