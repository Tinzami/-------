#ifndef WETHER_H
#define WETHER_H

#include <ArduinoJson.h>
#include <WiFi.h>

// extern const char *ssid ;
// extern const char *password ;

extern const char *host ;
extern const char *privateKey ;
extern const char *city ;
extern const char *language ;
extern char *weather_city ;
extern char *weather_weather ;
extern char *weather_humidity ;
extern char *weather_wind ;
extern char *weather_high ;
extern char *weather_low ;
extern int temo_low ;
extern int temo_high ;
struct WeatherData
{
    char city[32];
    char weather[64];
    char high[32];
    char low[32];
    char humi[32];
    char wind_scale[32];
};

void get_wether();
void wether_init();

#endif