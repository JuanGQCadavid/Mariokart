#include <SPI.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int pw1 = 5;
int pw2 = 4;

int motor1F = 7;
int motor1B = 6;
int motor2F = 2;
int motor2B = 3;

int status_w = WL_IDLE_STATUS;

char ssid[] = "Router_Semillero";
char pass[] = "Semillero123";

unsigned int localPort = 2390;
unsigned int serverPort = 8000;
IPAddress ip_server(192, 168, 1, 101);

char packetBuffer[255];
char ReplyBuffer[] = "acknowledged";

WiFiUDP Udp;



void setup() {

  pinMode(pw1, OUTPUT);
  pinMode(pw2, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(motor2B, OUTPUT);

  digitalWrite(pw1, HIGH);
  digitalWrite(pw2, HIGH);
  digitalWrite(motor1F, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2F, LOW);
  digitalWrite(motor2B, LOW);

  Serial.begin(9600);
  delay(100);

  Serial.print("Angela");

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true); //Stop
  }

  while ( status_w != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    status_w = WiFi.begin(ssid, pass);
    delay(5000);
  }

  Serial.println("Connected to WiFi");
  printWiFiStatus();

  Serial.println("Starting connection to server...");
  Udp.begin(localPort);

}

void loop() {

  // if there's data available, read a packet

  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;
    Serial.println(packetBuffer);
    String estado =  String(packetBuffer);

    Serial.print("estado:");
    Serial.println(estado);

    if (estado == "FW") {
      digitalWrite(motor1F, HIGH);
      digitalWrite(motor1B, LOW);
      digitalWrite(motor2F, HIGH);
      digitalWrite(motor2B, LOW);
    } else if (estado == "BACK") {
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1B, HIGH);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2B, HIGH);
    } else if (estado == "RIGHT") {
      digitalWrite(motor1F, HIGH);
      digitalWrite(motor1B, LOW);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2B, LOW);
    } else if (estado == "LEFT") {
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1B, LOW);
      digitalWrite(motor2F, HIGH);
      digitalWrite(motor2B, LOW);
    } else if (estado == "STOP") {
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1B, LOW);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2B, LOW);
    }


  }
}

void printWiFiStatus() {
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
