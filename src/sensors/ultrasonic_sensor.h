#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

const int trigPin = 2;  
const int echoPin = 4;

void initUltrasonicSensor();
float measureDistance();

#endif
