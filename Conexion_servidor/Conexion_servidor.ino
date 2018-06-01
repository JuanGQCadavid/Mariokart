#include <SPI.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int status_w = WL_IDLE_STATUS;

char ssid[] = "Router_Semillero";
char pass[] = "Semillero123";

unsigned int localPort = 2390;
unsigned int serverPort = 8000;
IPAddress ip_server(192,168,1,101);

char packetBuffer[255];
char ReplyBuffer[] = "acknowledged";

WiFiUDP Udp;



void setup() {
  Serial.begin(9600);
  delay(100);

  if(WiFi.status() == WL_NO_SHIELD){
    Serial.println("WiFi shield not present");
    while(true); //Stop  
  }

  while( status_w != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    status_w = WiFi.begin(ssid,pass);
    delay(5000);
  }

  Serial.println("Connected to WiFi");
  printWiFiStatus();

  Serial.println("Starting connection to server...");
  Udp.begin(localPort);
  
}

void loop() {
  //printWiFiStatus();
  //delay(5000);
  Serial.println("Mandando");
  Udp.beginPacket(ip_server,serverPort);
  Udp.write(ReplyBuffer);
  Udp.endPacket();

  delay(10000);
}


void printWiFiStatus(){
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("Signal Strength (RSSI): ");
  Serial.print(rssi);
  Serial.println(" dBm");
  
}
