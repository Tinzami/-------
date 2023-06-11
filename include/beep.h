#ifndef BEEP_H
#define BEEP_H
#include <Arduino.h>
#include <spk.h>

#define beep 23
extern long tim;

void beep_0();
void beep_1();
void beep_135();
// void tim1Interrupt();
void beep_init();
#endif