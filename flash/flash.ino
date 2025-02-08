#include <arduino.h>
#include <flasher.h>

Flasher flasher;

void setup() {
  flasher.begin(1000);
}

void loop() {
  flasher.flash();
  delay(1000);
}
