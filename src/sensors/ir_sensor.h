#ifndef IR_SENSOR_H
#define IR_SENSOR_H

#include <Arduino.h>

class IRSensor {
public:
    IRSensor(int leftPin, int rightPin, int leftMotorF, int leftMotorB, int rightMotorF, int rightMotorB);
    void begin();
    void followLine();
    
private:
    int _leftPin, _rightPin;
    int _leftMotorF, _leftMotorB, _rightMotorF, _rightMotorB;
    
    int readLeft();
    int readRight();
    void moveForward();
    void turnLeft();
    void turnRight();
    void stopMotors();
};

#endif
