#include "huminity_sensor.h"

void collectAndDisplayData() {
    // Simulate collecting data from a temperature sensor
    int rawValue = analogRead(TEMP_SENSOR_PIN); 
    float voltage = rawValue * (5.0 / 1023.0); // Convert to voltage
    float temperatureC = (voltage - 0.5) * 100; // Convert voltage to temperature (Celsius)

    // Display the data in a format similar to IR data representation
    Serial.print("IR Data:");
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.print("C, Raw Value: ");
    Serial.print(rawValue);
    Serial.println(" [End]"); // Indicate end of data packet

    // Optionally, you can represent the data in binary or hexadecimal format
    Serial.print("Binary Representation: ");
    for (int i = 0; i < 10; i++) { // Example: display first 10 bits of raw value
        Serial.print((rawValue >> (9 - i)) & 1); // Extract each bit
    }
    Serial.println();
}
