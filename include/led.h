#ifndef LED_H
#define LED_H
#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <iostream>

#define LED_PIN 32
#define NUMPIXELS 9 // Popular NeoPixel ring size
#define delay_tim 7000
using namespace std;
void led(int a);
void led_init();

#endif