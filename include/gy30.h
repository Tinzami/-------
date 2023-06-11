#ifndef GY30_H
#define GY30_H
#include <Wire.h>
#include <BH1750.h>
#include <BH1750FVI.h>
#include <Arduino.h>
extern BH1750 lightMeter;
extern char light[20];


void gy30_init();
void get_gy30();

#endif