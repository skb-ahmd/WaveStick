#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const int ledPins[] = { 3, 4, 5, 6, 7 };  // LED pins D3 to D7

void setup() {
  Serial.begin(9600);
  driver.init();

  for (int i = 3; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);
  uint8_t joystickData[8];
  uint8_t buflen = sizeof(joystickData);

  if (driver.recv(joystickData, &buflen)) {
    if (buflen == sizeof(joystickData)) {
      int xData = (joystickData[0] << 8) | joystickData[1];
      int yData = (joystickData[2] << 8) | joystickData[3];
      int swData = joystickData[4];

      Serial.print("xData: ");
      Serial.println(xData);
      Serial.print("yData: ");
      Serial.println(yData);

      controlLEDs(xData-5000, yData-5000);
    }
  }
}

void controlLEDs(int xData, int yData) {
  for (int i = 3; i <= 7; i++) {
    digitalWrite(i, LOW);
  }
  if (isCenter(xData, yData)) {
    digitalWrite(7, HIGH);
  } else if (isTop(xData, yData)) {
    digitalWrite(3, HIGH);
  } else if (isRight(xData, yData)) {
    digitalWrite(4, HIGH);
  } else if (isBottom(xData, yData)) {
    digitalWrite(5, HIGH);
  } else if (isLeft(xData, yData)) {
    digitalWrite(6, HIGH);
  }
}

bool isCenter(int x, int y) {
  return (x > 500 && x < 540) && (y > 480 && y < 520);
}

bool isTop(int x, int y) {
  return (x > 540) && (y > 480 && y < 520);
}

bool isRight(int x, int y) {
  return (x > 500 && x < 540) && (y > 520);
}

bool isBottom(int x, int y) {
  return (x < 500) && (y > 480 && y < 520);
}

bool isLeft(int x, int y) {
  return (y < 480) && (x > 480 && x < 540);
}
