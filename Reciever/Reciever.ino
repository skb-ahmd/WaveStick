#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup() {
  driver.init();
  Serial.begin(9600);
}

void loop() {
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) {
    Serial.println((char*)buf);
  }

}

