#include <arduino.h>

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  Serial.println("hello world");
}
