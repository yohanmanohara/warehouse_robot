#include <Arduino.h>
#include "./stepermotor/stepfunction.h"

// Configuration settings
const int stepDelay = 200;  // Reduced delay for higher speed
const int stepCount = 3000; // Number of steps per cycle

void setup() {
    motorSetup();
}

void loop() {
    // Move forward
    moveForward(stepCount, stepDelay);
    delay(1000);  // Wait 1 second

    // Move backward
    moveBackward(stepCount, stepDelay);
    delay(1000);  // Wait 1 second
}
