#ifndef DHT11_H
#define DHT11_H

#include "DHTesp.h" // Click here to get the library: http://librarymanager/All#DHTesp
#include <Arduino.h>

#ifndef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP32 ONLY!)
#error Select ESP32 board.
#endif

//DHTesp dht;
extern DHTesp dht1;
extern float temperature;
extern char humidity_c[20];
extern char temperature_c[20];
void dht11_init();
void get_dht11();

#endif