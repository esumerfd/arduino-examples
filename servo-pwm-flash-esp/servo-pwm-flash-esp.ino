#include <Arduino.h>
#include <flash.h>

void setup() {
  Flash::begin();
}

void loop() {
  Flash::flash();
  delay(500);
}
