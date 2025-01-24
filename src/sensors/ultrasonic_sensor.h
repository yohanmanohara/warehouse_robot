#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

const int trigPin = 2;   // Ensure 14 is correct for your board
const int echoPin = 15;

void initUltrasonicSensor();
float measureDistance();

#endif
