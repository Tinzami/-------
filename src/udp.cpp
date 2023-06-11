#include "udp.h"
#include "led.h"
#include "dht11.h"
AsyncUDP udp;                     //创建UDP对象
IPAddress remote_IP(192, 168, 43, 21);// 自定义远程监 IP 地址
char udp_buf[15];
unsigned int broadcastPort = remoteUdpPort;

void onPacketCallBack(AsyncUDPPacket packet)
{
  byte a[10] = {1};
  Serial.print("UDP数据包来源类型: ");
  Serial.println(packet.isBroadcast() ? "广播数据" : (packet.isMulticast() ? "组播" : "单播"));
  Serial.print("远端地址及端口号: ");
  Serial.print(packet.remoteIP());
  Serial.print(":");
  Serial.println(packet.remotePort());
  Serial.print("目标地址及端口号: ");
  Serial.print(packet.localIP());
  Serial.print(":");
  Serial.println(packet.localPort());
  Serial.print("数据长度: ");
  Serial.println(packet.length());
  Serial.print("数据内容: ");
  Serial.write(packet.data(), packet.length());
  Serial.println("--------------");

  // led(1);
  if (packet.peek()==1) //绿灯
  {
    led(1);
  }
  else if (packet.peek()==0) //关灯
  {
    led(0);
  }
  else if (packet.peek()==2) //红灯
  {
    led(2);
  }
  else if (packet.peek()==3)
  {
    udp.broadcastTo("Temperature",broadcastPort); //可以使用该方法广播信息
    udp.broadcastTo(temperature_c,broadcastPort); //可以使用该方法广播信息

  }
  else if (packet.peek()==4)
  {
    udp.broadcastTo("Humidity",broadcastPort); //可以使用该方法广播信息
    udp.broadcastTo(humidity_c,broadcastPort); //可以使用该方法广播信息

  }
    Serial.println(packet.peek());

  packet.print("reply data");
  broadcastPort = packet.remotePort();
}

void udp_init()
{
  Serial.begin(115200);
  Serial.println();
	WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password); //连接网络

  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); //打印模块IP

  Serial.print("subnetMask: ");
  Serial.println(WiFi.subnetMask()); //打印子网掩码

  Serial.print("gateway: ");
  Serial.println(WiFi.gatewayIP()); //打印网关地址

  Serial.print("dns: ");
  Serial.println(WiFi.dnsIP()); //打印DNS地址

  Serial.print("mac Address: ");
  Serial.println(WiFi.macAddress()); //打印mac地址

  WiFi.setHostname("Tizami"); //设置主机名
  Serial.print("HostName: ");
  Serial.println(WiFi.getHostname()); //打印主机名
    // Udp.begin(localUdpPort); //启用UDP监听以接收数据
  while (!WiFi.isConnected())
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());





  while (!udp.listen(localUdpPort)) //等待udp监听设置成功
  {
		Serial.print(".");
		delay(500); 
  }
	Serial.println("1");
  udp.onPacket(onPacketCallBack); //注册收到数据包事件
	Serial.println("2");
}

void udp_send(char send_date[])
{
  // delay(1000);
	// boot_time=millis();
  // sprintf(wifi_buf,"hello %d",boot_time);
	
  udp.broadcastTo(send_date,broadcastPort); //可以使用该方法广播信息

  // IPAddress broadcastAddr((~(uint32_t)WiFi.subnetMask())|((uint32_t)WiFi.localIP())); //计算广播地址
  // udp.writeTo(broadcastData, sizeof(broadcastData), broadcastAddr, localUdpPort); //广播数据
}