#ifndef FLASHER_H
#define FLASHER_H

#include <arduino.h>

#define ESP_LED_PIN 33

class Flasher {
  private:
    bool ledOn = false;

    void toggleLED() {
      digitalWrite(ESP_LED_PIN, ledOn ? LOW : HIGH);
      ledOn = !ledOn;
    }

  public:
    int ledTransitions = 0;
    void begin(int flashers) {
      ledTransitions = flashers * 2;

      pinMode(ESP_LED_PIN, OUTPUT);
    }

    void flash() {
      if (ledTransitions > 0) {
        ledTransitions--;
        toggleLED();
      }
    }
};

#endif
