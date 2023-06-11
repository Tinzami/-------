#include <tft.h>
#include <gy30.h>
#include <dht11.h>
#include <mq4.h>
#include <mq135.h>
#include <weather.h>
TFT_eSPI tft = TFT_eSPI(128,160);


void tft_init(){
  tft.init();
  tft.fillScreen(TFT_WHITE);
  tft.setRotation(2);
//   tft.loadFont(font_20);
}


void tft_show(){
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("light:",5,5,2);
  tft.drawString(light,45,5,2);
  tft.drawString("temp:",5,20,2);
  tft.drawString(temperature_c,45,20,2);
  tft.drawString("RH:",5,35,2);
  tft.drawString(humidity_c,45,35,2);
  tft.drawString("C6H6:",5,50,2);
  tft.drawString(mq4_ppm,45,50,2);
  tft.drawString("CO:",5,65,2);
  tft.drawString(mq135_ppm,45,65,2);
  tft.drawString("----",0,80,2);
  tft.drawString("----",104,80,2);
  tft.drawString("City:",30,80,2);
  tft.drawString("Harbin",60,80,2);
  // tft.drawString(weather_city,55,80,2);
  tft.drawString("weather:",5,95,2);
  tft.drawString(weather_weather,60,95,2);
  tft.drawString("temp:",5,110,2);
  tft.drawString(weather_low,45,110,2);
  tft.drawString("-",80,110,2);
  tft.drawString(weather_high,90,110,2);
  tft.drawString("humi:",5,125,2);
  tft.drawString(weather_humidity,45,125,2);
  tft.drawString("wind:",5,140,2);
  tft.drawString(weather_wind,45,140,2);

}