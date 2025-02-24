#include <Arduino.h>
#include "./stepermotor/stepfunction.h"

// Configuration settings
const int stepDelay = 20;  // Reduced delay for higher speed
const int stepCount = 3000; // Number of steps per cycle

void setup() {
    motorSetup();
}

void loop() {
    // Move forward
    moveForward(stepCount, stepDelay);
      
}
