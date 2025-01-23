#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

const int trigPin = 14;   // Ensure 14 is correct for your board
const int echoPin = 12;

void initUltrasonicSensor();
float measureDistance();

#endif
