#ifndef IR_SENSOR_H
#define IR_SENSOR_H

void setupIrSensors();
void readIrSensors();
int getIRSensor(int sensorNumber);

// Expose pin definitions
extern const int pinOUT1;
extern const int pinOUT2;
extern const int pinOUT3;
extern const int pinOUT4;
extern const int pinOUT5;

#endif