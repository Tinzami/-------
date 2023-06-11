#include "gy30.h"


BH1750 lightMeter;
char light[];



void gy30_init(){
  Serial.begin(115200);
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  
}

void get_gy30() {
  float lux = lightMeter.readLightLevel();
  // Serial.print("Light: ");
  // Serial.print(lux);
  // Serial.println(" lx");

  dtostrf(lux,6,2,light);
  strcat(light,"lux");

}
