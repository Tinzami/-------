#include "weather.h"

// const char *ssid = "zhensuo";
// const char *password = "123456789+-";

const char *host = "api.seniverse.com";
const char *privateKey = "SsFqbMsBeHKr-5qWE";
const char *city = "haerbin";
const char *language = "en";
char *weather_city = (char*)"1ASSADD"; 
char *weather_weather =(char*) "1SADWA";
char *weather_humidity = (char*)"1SDA";
char *weather_wind = (char*)"1SAD";
char *weather_high = (char*)"1SAD";
char *weather_low = (char*)"1ADS";
int temo_low = 3;
int temo_high = 10;

WiFiClient client;
struct WeatherData weatherdata = {0};
DynamicJsonDocument doc(1400);
void wether_init(){
    Serial.begin(115200);

    // Serial.print("Connecting to ");
    // Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("");
    Serial.println("WiFi Conected!");



    if (!client.connect(host, 80))
    {
        Serial.println("Connect host failed!");
        return;
    }
    Serial.println("host Conected!");

    String getUrl = "/v3/weather/daily.json?key=";
    getUrl += privateKey;
    getUrl += "&location=";
    getUrl += city;
    getUrl += "&language=";
    getUrl += language;
    client.print(String("GET ") + getUrl + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    Serial.println("Get send");

    char endOfHeaders[] = "\r\n\r\n";
    bool ok = client.find(endOfHeaders);
    if (!ok)
    {
        Serial.println("No response or invalid response!");
    }
    Serial.println("Skip headers");

    String line="";

    line += client.readStringUntil('\n'); 
 
    Serial.println(line);



    DeserializationError error = deserializeJson(doc, line);
    if (error)
    {
        Serial.println("deserialize json failed");
        return;
    }
    Serial.println("deserialize json success");



}
void get_wether(){


    strcpy(weatherdata.city, doc["results"][0]["location"]["name"].as<const char*>());
    strcpy(weatherdata.weather, doc["results"][0]["daily"][0]["text_day"].as<const char*>());
    strcpy(weatherdata.high, doc["results"][0]["daily"][0]["high"].as<const char*>());
    strcpy(weatherdata.low, doc["results"][0]["daily"][0]["low"].as<const char*>());
    strcpy(weatherdata.humi, doc["results"][0]["daily"][0]["humidity"].as<const char*>());
    strcpy(weatherdata.wind_scale, doc["results"][0]["daily"][0]["wind_scale"].as<const char*>());

    // Serial.println("City");
    // Serial.println(weatherdata.city);
    Serial.println("textDay");
    Serial.println(weatherdata.weather);

    client.stop();

    weather_city = weatherdata.city ;
    weather_weather = weatherdata.weather ;
    weather_humidity = weatherdata.humi ;
    strcat(weather_humidity,"%");
    weather_wind = weatherdata.wind_scale ;
    weather_high = weatherdata.high ;
    strcat(weather_high,"*C");
    weather_low = weatherdata.low ;
    strcat(weather_low,"*C");
    temo_low = strtol(weather_low,NULL,10);
    temo_high = strtol(weather_high,NULL,10);
}