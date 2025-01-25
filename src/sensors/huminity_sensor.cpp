#include "huminity_sensor.h"

DHT dht(DPIN, DTYPE);  // Define the dht object here

void collectAndDisplayData() {
  

  float tc = dht.readTemperature(false);  // Read temperature in Celsius
  if (isnan(tc)) {
    Serial.println("Failed to read temperature!");
    return;
  }

  float tf = dht.readTemperature(true);   // Read temperature in Fahrenheit
  if (isnan(tf)) {
    Serial.println("Failed to read temperature!");
    return;
  }

  float hu = dht.readHumidity();          // Read humidity
  if (isnan(hu)) {
    Serial.println("Failed to read humidity!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(tc);
  Serial.print(" C, ");
  Serial.print(tf);
  Serial.print(" F, Hum: ");
  Serial.print(hu);
  Serial.println("%");
  
}
