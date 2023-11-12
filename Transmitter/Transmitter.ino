#include <RH_ASK.h>
#include <SPI.h>
RH_ASK driver;

void setup() {
  driver.init();
  Serial.begin(9600);
}

void loop() {
  const char *msg = "Hello world!";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
