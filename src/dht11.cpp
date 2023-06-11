#include <Arduino.h>
#include "dht11.h"
#include "DHTesp.h" 
char humidity_c[];
char temperature_c[];
DHTesp dht1;
float temperature = 0;
void dht11_init(){

//   float humidity = dht.getHumidity();
//   float temperature = dht.getTemperature();
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  String thisBoard= ARDUINO_BOARD;
  Serial.println(thisBoard);

  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);
  // use this instead: 
  dht1.setup(0, DHTesp::DHT11); // Connect DHT sensor to GPIO 0
}

void get_dht11(){
  delay(dht1.getMinimumSamplingPeriod());

  float humidity = dht1.getHumidity();
  float temperature = dht1.getTemperature();

  // Serial.print(dht1.getStatusString());
  // Serial.print("\t");
  // Serial.print(humidity, 1);
  // Serial.print("\t\t");
  // Serial.print(temperature, 1);
  // Serial.print("\t\t");
  // Serial.print(dht1.toFahrenheit(temperature), 1);
  // Serial.print("\t\t");
  // Serial.print(dht1.computeHeatIndex(temperature, humidity, false), 1);
  // Serial.print("\t\t");
  // Serial.println(dht1.computeHeatIndex(dht1.toFahrenheit(temperature), humidity, true), 1);

  dtostrf(temperature,6,1,temperature_c);
  strcat(temperature_c,"*C");
  dtostrf(humidity,6,1,humidity_c);
  strcat(humidity_c,"%");
}