#include <gy30.h>
#include <tft.h>
#include <mq4.h>
#include <mq135.h>
#include <dht11.h>
#include <spk.h>
#include <led.h>
#include <beep.h>
#include <udp.h>
#include <weather.h>
#define motor_pin 13 
#define fire_pin 18
float lux_compare = 0 ;
int fire_state = 1;
extern int fire_state;

void fire_isr()
{
    Serial.println("fire_isr star");
    fire_state = 0;
}

void setup(void) {

  // pinMode(21,OUTPUT);
  gy30_init();
  dht11_init();
  udp_init();
  mq4_init();
  mq135_init();
  tft_init();
  spk_init();
  led_init();
  pinMode(motor_pin,OUTPUT); // moter_init
  pinMode(fire_pin,INPUT); // fire_init
  attachInterrupt(fire_pin, fire_isr, FALLING);    // 设置外部中断
  beep_init();
  wether_init();
  get_wether();
}

void loop() {
  if ( ppm_mq4 >= 0.20)
  {
    beep_135();
    send_cmd[2] = 0x08;  // cmd 02 means humidity
    send_cmd[3] = 0x00;  // humi
    send_cmd[4] = 0x00;
    Serial.println("-------mq4-------");
    Serial_h.write(send_cmd,7);       
  }
  

  if (fire_state == 0)
  {
    beep_1();
    fire_state = 1;
  }
  
  //  ----------------------------------------
  lux_compare = lightMeter.readLightLevel();
  if (lux_compare > 2000.0)  {
    digitalWrite(motor_pin,HIGH);
  }
  else if(lux_compare <= 2000.0 ){
    digitalWrite(motor_pin,LOW);  //motor 
  }
  //  ----------------------------------------
  get_dht11();
  get_gy30();
  get_mq4();
  get_mq135();
  tft_show();
  // digitalWrite(21,HIGH);
  // delay(1);
  // digitalWrite(21,LOW);
  // delay(1);
}
