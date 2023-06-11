#ifndef UDP_H
#define UDP_H

#include <WiFi.h>
#include <AsyncUDP.h> //引用以使用异步UDP
#include <Arduino.h>
#define  ssid  "Tinzami"        //你的网络名称
#define  password  "147258369"  //你的网络密码
#define remoteUdpPort  37488 // 自定义远程监听端口
#define localUdpPort  2333 //本地端口号

extern unsigned int broadcastPort;
extern char udp_buf[15];

void onPacketCallBack(AsyncUDPPacket packet);
void udp_init();
void udp_send(char send_date[]);



#endif