#include <spk.h>
#include <weather.h>

float hum = 0;
float tem = 0;
byte uart_cmd[7] = {};   //reveived cmd data's lenth is 7  eg aa 55 01 55 aa

byte send_cmd[7] = {};   //sent cmd data's lenth is 9
HardwareSerial Serial_h(2);
void Serial_callback() {

    for(int i=0 ; i<=4; i++){
      uart_cmd[i] =  char(Serial_h.read());
      Serial.print(uart_cmd[i],HEX);
      Serial.print('\n');
    }
  if(uart_cmd[0] == 0xaa && uart_cmd[1] == 0x55 && uart_cmd[3] == 0x55 && uart_cmd[4] == 0xaa){
    Serial.print("check!");
    Serial.print(uart_cmd[2],HEX);
    // client.publish("/smart-light/cmd",String(uart_cmd[2]));
    
        if(uart_cmd[2] == 0x01){       //0x01 cmd to get temp
            //   Serial.println("1234");
            tem=dht1.getTemperature();
            // temperature = dht.getTemperature();
            if (tem != NAN){
        //        int temp_tmp= int(temperature*10);
                // Serial.println(tem);
                send_cmd[2] = 0x01;  // cmd 01 means temperature
                send_cmd[3] = ((int)tem);  // tmp_H
                send_cmd[4] = ((int)(tem*10))%10;   //tmp_L
                Serial_h.write(send_cmd,7);
                // Serial.write(send_cmd,7);
                }
        }
        if(uart_cmd[2] == 0x02){       //0x01 cmd to get temp
            hum = dht1.getHumidity();
            if (hum != NAN){
                send_cmd[2] = 0x02;  // cmd 02 means humidity
                send_cmd[3] = ((int)hum)%256;  // humi
                send_cmd[4] = 0;
                Serial_h.write(send_cmd,7);
                }
        }
        if(uart_cmd[2] == 0x03){       //0x03 cmd to get led red
            led(2);
        }
        if(uart_cmd[2] == 0x04){       //0x04 cmd to get green red
            led(1);
        }
        if(uart_cmd[2] == 0x00){       //0x04 cmd to get green red
            led(0);
        } 
        if(uart_cmd[2] == 0x06){       //0x04 cmd to get green red
            led(3);
        }  
        if(uart_cmd[2] == 0x08){       //0x04 cmd to get green red
            led(4);
        }
        if(uart_cmd[2] == 0x09){       //0x09 weather
        Serial.println(weather_weather[0]);
            if (weather_weather[0] == 'L')
            {
                send_cmd[2] = 0x05;  // cmd 02 means humidity
                send_cmd[3] = 0x00;  // humi
                send_cmd[4] = 0x00;
                Serial_h.write(send_cmd,7);  
            }
            if (weather_weather[0] == 'S')
            {
                send_cmd[2] = 0x07;  // cmd 02 means humidity
                send_cmd[3] = 0x00;  // humi
                send_cmd[4] = 0x00;
                Serial_h.write(send_cmd,7);  
            }     
            }       
        if(uart_cmd[2] == 0x0A){       //0x04 cmd to get green red
            send_cmd[2] = 0x09;  //  
            send_cmd[3] = temo_low;  // humi
            send_cmd[4] = temo_high;       
            Serial_h.write(send_cmd,7); 
            // Serial.println("----------"); 
            // Serial.println(send_cmd[3]);     
            // Serial.println(send_cmd[4]); 
            // Serial.println(send_cmd[5]);       
        }
                   
    }
    // while (Serial.available()) {
    //     Serial.readBytes(data, 2);
    // }
    // Serial.printf("%x,%x", data[0], data[1]);
    // Serial.println();
}

void spk_init() {
  send_cmd[0] = 0xaa;
  send_cmd[1] = 0x55;
  send_cmd[5] = 0x55;
  send_cmd[6] = 0xaa;
  Serial_h.begin(9600,SERIAL_8N1,17,16);
  // Serial2.begin(9600);
  Serial.begin(115200);
  Serial_h.onReceive(Serial_callback);//设置回调函数

  dht11_init();


}