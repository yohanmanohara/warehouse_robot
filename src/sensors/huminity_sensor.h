#ifndef HUMINITY_SENSOR_H
#define HUMINITY_SENSOR_H

#include <DHT.h>

#define DPIN 26
#define DTYPE DHT11  // Define DHT11 or DHT22

extern DHT dht;  // Declare dht as an external object to be defined in .cpp file

void collectAndDisplayData();

#endif // HUMINITY_SENSOR_H
