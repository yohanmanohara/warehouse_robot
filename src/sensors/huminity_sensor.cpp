#include "huminity_sensor.h"

void collectAndDisplayData() {
    
    // Simulate collecting data from a humidity sensor
    int rawHumidityValue = analogRead(HUMIDITY_SENSOR_PIN);
    float voltageHumidity = rawHumidityValue * (5.0 / 1023.0); // Convert to voltage
    float humidityPercent = voltageHumidity * 100; // Assuming the output is between 0V and 5V

  
    Serial.print(", Humidity: ");
    Serial.print(humidityPercent);
    Serial.print("%, Raw Humidity Value: ");
    Serial.print(rawHumidityValue);
    
    Serial.println(" [End]"); // Indicate end of data packet

  
    Serial.print(", Binary Representation (Humidity): ");
    for (int i = 0; i < 10; i++) { // Example: display first 10 bits of raw humidity value
        Serial.print((rawHumidityValue >> (9 - i)) & 1); // Extract each bit
    }
    
    Serial.println();
}
