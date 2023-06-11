#include "led.h"
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void led(int a){
   pixels.clear();
   if(a==1) {
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 10, 0));
    pixels.show();  
    }
   }
   else if (a==2){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(10, 0, 0));
    pixels.show();   
    }
   }
    else if (a==0){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();   
    }
   }
    else if (a==3){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(10, 10, 0));
    pixels.show();   
    }
    }
    else if (a==4){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(8, 8, 8));
    pixels.show();   
    }
    }    
    
    
   
}

void led_init() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); 
  led(0);
}