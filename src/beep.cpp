#include "beep.h"

long tim;

hw_timer_t *tim1 = NULL;
int tim1_IRQ_count = 0;


// void tim1Interrupt()
// {
//   delay(1000);
//   Serial.println("haha");
//   // tim1_IRQ_count++;
//   digitalWrite(beep,HIGH);
//   delay(1000);
//   digitalWrite(beep,LOW);
//   // Serial.println(timerAlarmEnabled(tim1));
//   timerAlarmDisable(tim1);
// }

void beep_init()
{
  pinMode(beep,OUTPUT);
  Serial.begin(115200);


  digitalWrite(beep,HIGH);
  // timerAlarmEnable(tim1);
}

void beep_1()
{

  send_cmd[2] = 0x06;  // cmd 01 means temperature
  send_cmd[3] = 0x00;  // tmp_H
  send_cmd[4] = 0x00;   //tmp_L
  Serial_h.write(send_cmd,7);
  // tim1 = timerBegin(0, 80, true);
  // timerAttachInterrupt(tim1, tim1Interrupt, true);
  // timerAlarmWrite(tim1, 200000, true);
  digitalWrite(beep,LOW);

  // timerAlarmEnable(tim1);
  delay(500);  
  // tim=millis();
  // delay(300);
  digitalWrite(beep,HIGH);
  
}
void beep_135()
{

//   send_cmd[2] = 0x06;  // cmd 01 means temperature
//   send_cmd[3] = 0x00;  // tmp_H
//   send_cmd[4] = 0x00;   //tmp_L
//   Serial_h.write(send_cmd,7);
  // tim1 = timerBegin(0, 80, true);
  // timerAttachInterrupt(tim1, tim1Interrupt, true);
  // timerAlarmWrite(tim1, 200000, true);
  digitalWrite(beep,LOW);

  // timerAlarmEnable(tim1);
  delay(600);  
  // tim=millis();
  // delay(300);
  digitalWrite(beep,HIGH);
  
}
void beep_0()
{

  digitalWrite(beep,HIGH);

}

// millis()<tim+5000



// void setup()
// {
//   Serial.begin(115200);
//   tim1 = timerBegin(0, 80, true);
//   timerAttachInterrupt(tim1, tim1Interrupt, true);
//   timerAlarmWrite(tim1, 100000, true);
//   timerAlarmEnable(tim1);
// }

// void loop()
// {
//   if (tim1_IRQ_count > 10)
//   {
//     Serial.println("count trigger");
//     tim1_IRQ_count = 0;
//   }
// }