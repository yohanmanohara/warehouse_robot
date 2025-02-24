#include "stepfunction.h"

// Initialize motor pins
void motorSetup() {
    pinMode(PUL_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENA_PIN, OUTPUT);

    digitalWrite(ENA_PIN, LOW);  // Enable motor driver (LOW to enable)
}

// Move motor forward
void moveForward(int steps, int delayTime) {
    digitalWrite(DIR_PIN, HIGH);  
    for (int i = 0; i < steps; i++) {
        digitalWrite(PUL_PIN, HIGH);
        delayMicroseconds(delayTime);
        digitalWrite(PUL_PIN, LOW);
        delayMicroseconds(delayTime);
    }
}

// Move motor backward
void moveBackward(int steps, int delayTime) {
    digitalWrite(DIR_PIN, LOW);  
    for (int i = 0; i < steps; i++) {
        digitalWrite(PUL_PIN, HIGH);
        delayMicroseconds(delayTime);
        digitalWrite(PUL_PIN, LOW);
        delayMicroseconds(delayTime);
    }
}
