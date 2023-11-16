#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const char xPin = A0;
const char yPin = A1;
const int swPin = 2;

void setup() {
  driver.init();
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(13, OUTPUT); // LED Pin
}

void loop() {
  digitalWrite(13, HIGH);
  int xData = analogRead(xPin) + 5000;
  int yData = analogRead(yPin) + 5000;
  int swData = digitalRead(swPin);

  // Use a fixed-size data array to avoid unnecessary dynamic memory allocation
  uint8_t dataPacket[8];
  
  // Convert integers to bytes
  dataPacket[0] = (xData >> 8) & 0xFF;
  dataPacket[1] = xData & 0xFF;
  dataPacket[2] = (yData >> 8) & 0xFF;
  dataPacket[3] = yData & 0xFF;
  dataPacket[4] = swData & 0xFF;

  driver.send(dataPacket, sizeof(dataPacket));
  // Serial.println(dataPacket);
  driver.waitPacketSent();

  Serial.print("xData: ");
  Serial.println(xData);
  Serial.print("yData: ");
  Serial.println(yData);

  // You can add a small delay here to control data sending frequency
  delay(5);
}
