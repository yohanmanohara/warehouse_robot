#include "IR_Sensor.h"

IRSensor::IRSensor(int leftPin, int rightPin, int leftMotorF, int leftMotorB, int rightMotorF, int rightMotorB) {
    _leftPin = leftPin;
    _rightPin = rightPin;
    _leftMotorF = leftMotorF;
    _leftMotorB = leftMotorB;
    _rightMotorF = rightMotorF;
    _rightMotorB = rightMotorB;
}

void IRSensor::begin() {
    pinMode(_leftPin, INPUT);
    pinMode(_rightPin, INPUT);
    pinMode(_leftMotorF, OUTPUT);
    pinMode(_leftMotorB, OUTPUT);
    pinMode(_rightMotorF, OUTPUT);
    pinMode(_rightMotorB, OUTPUT);
}

int IRSensor::readLeft() {
    return digitalRead(_leftPin);
}

int IRSensor::readRight() {
    return digitalRead(_rightPin);
}

void IRSensor::followLine() {
    int left = readLeft();
    int right = readRight();

    if (left == 0 && right == 0) {  
        moveForward();  // Move straight
    } 
    else if (left == 1 && right == 0) {  
        turnRight();  // Right sensor on black, turn right
    } 
    else if (left == 0 && right == 1) {  
        turnLeft();  // Left sensor on black, turn left
    } 
    else {  
        stopMotors();  // Stop if no black line detected
    }
}

void IRSensor::moveForward() {
    digitalWrite(_leftMotorF, HIGH);
    digitalWrite(_leftMotorB, LOW);
    digitalWrite(_rightMotorF, HIGH);
    digitalWrite(_rightMotorB, LOW);
}

void IRSensor::turnLeft() {
    digitalWrite(_leftMotorF, LOW);
    digitalWrite(_leftMotorB, HIGH);
    digitalWrite(_rightMotorF, HIGH);
    digitalWrite(_rightMotorB, LOW);
}

void IRSensor::turnRight() {
    digitalWrite(_leftMotorF, HIGH);
    digitalWrite(_leftMotorB, LOW);
    digitalWrite(_rightMotorF, LOW);
    digitalWrite(_rightMotorB, HIGH);
}

void IRSensor::stopMotors() {
    digitalWrite(_leftMotorF, LOW);
    digitalWrite(_leftMotorB, LOW);
    digitalWrite(_rightMotorF, LOW);
    digitalWrite(_rightMotorB, LOW);
}
