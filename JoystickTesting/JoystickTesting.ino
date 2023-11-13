  const char xPin = A7;
  const char yPin = A6;

  void setup() {
    Serial.begin(9600);
    pinMode(xPin, INPUT);
    pinMode(yPin, INPUT);

    // Set digital pins D3 to D7 as outputs
    for (int i = 3; i <= 7; i++) {
      pinMode(i, OUTPUT);
    }
  }

  void loop() {
    int xData = analogRead(xPin);
    int yData = analogRead(yPin);

    controlLEDs(xData, yData);

    Serial.print("X: ");
    Serial.print(xData);
    Serial.print("\tY: ");
    Serial.println(yData);
  }

  void controlLEDs(int xData, int yData) {
    // Turn off all LEDs
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
