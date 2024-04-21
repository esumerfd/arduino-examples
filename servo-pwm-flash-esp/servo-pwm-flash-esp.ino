#include <Arduino.h>

#define ESP_LED_PIN 33

void setup() {
  pinMode(ESP_LED_PIN, OUTPUT);
}

void loop() {
  flash();
  delay(500);
}

void flash() {
  for (int flashCount = 0; flashCount < 10; flashCount++) {
    digitalWrite(ESP_LED_PIN, LOW);
    delay(100);
    digitalWrite(ESP_LED_PIN, HIGH);
    delay(100);
  }
}
