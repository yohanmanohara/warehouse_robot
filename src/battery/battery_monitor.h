#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <Arduino.h>

// Define the analog pin where the voltage is read
#define VOLTAGE_PIN A0

// Function declarations
float readVoltage();
float calculateBatteryCapacity(float voltage);

#endif
