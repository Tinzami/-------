#ifndef SPK_H
#define SPK_H

#include <Arduino.h>
#include <dht11.h>
#include <led.h>
extern byte send_cmd[7] ;   //sent cmd data's lenth is 9
extern HardwareSerial Serial_h;
void Serial_callback();
void spk_init();

#endif