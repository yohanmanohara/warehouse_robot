#include "battery_monitor.h"

// Function to read the voltage from the analog pin
float readVoltage() {
  int sensorValue = analogRead(VOLTAGE_PIN);  // Read the sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the sensor value to voltage
  return voltage;
}

// Function to calculate battery capacity based on voltage
float calculateBatteryCapacity(float voltage) {
  // Assuming the battery is a 3.7V lithium-ion battery
  // The capacity calculation can be based on voltage ranges
  // This is a basic linear estimation for demonstration purposes
  
  float capacity = 0.0;
  
  if (voltage >= 4.2) {
    capacity = 100.0;  // Fully charged (4.2V)
  } else if (voltage >= 3.7) {
    capacity = (voltage - 3.7) * (100.0 / (4.2 - 3.7));  // Linear estimation between 3.7V and 4.2V
  } else if (voltage >= 3.2) {
    capacity = (voltage - 3.2) * (50.0 / (3.7 - 3.2)) + 50.0;  // Below 3.7V but above 3.2V
  } else {
    capacity = 0.0;  // Very low voltage, indicating a low battery
  }

  return capacity;
}
