#include "./ir_sensor.h"
#include <Arduino.h>

// Define pin numbers here
const int pinOUT1 = 1; // adjust the pin numbers
const int pinOUT2 = 2;
const int pinOUT3 = 3;
const int pinOUT4 = 4;
const int pinOUT5 = 5;

// IR sensor values
int IRvalue1 = 0;
int IRvalue2 = 0;
int IRvalue3 = 0;
int IRvalue4 = 0;
int IRvalue5 = 0;

void setupIrSensors() {
    pinMode(pinOUT1, INPUT);
    pinMode(pinOUT2, INPUT);
    pinMode(pinOUT3, INPUT);
    pinMode(pinOUT4, INPUT);
    pinMode(pinOUT5, INPUT);
    Serial.println("IR sensors initialized");
}

void readIrSensors() {
    IRvalue1 = digitalRead(pinOUT1);
    IRvalue2 = digitalRead(pinOUT2);
    IRvalue3 = digitalRead(pinOUT3);
    IRvalue4 = digitalRead(pinOUT4);
    IRvalue5 = digitalRead(pinOUT5);

    Serial.print("Digital Readings: ");
    Serial.print(IRvalue1);
    Serial.print(" ");
    Serial.print(IRvalue2);
    Serial.print(" ");
    Serial.print(IRvalue3);
    Serial.print(" ");
    Serial.print(IRvalue4);
    Serial.print(" ");
    Serial.println(IRvalue5);
}

// get individual sensor readings
int getIRSensor(int sensorNumber) {
    switch(sensorNumber) {
        case 1: return IRvalue1;
        case 2: return IRvalue2;
        case 3: return IRvalue3;
        case 4: return IRvalue4;
        case 5: return IRvalue5;
        default: return -1;
    }
}