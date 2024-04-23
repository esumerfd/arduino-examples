#define ESP_LED_PIN 33

class Flash {
  public:
    static void begin() {
      pinMode(ESP_LED_PIN, OUTPUT);
      digitalWrite(ESP_LED_PIN, HIGH);
    }

    static void flash() {
      for (int flashCount = 0; flashCount < 10; flashCount++) {
        digitalWrite(ESP_LED_PIN, LOW);
        delay(100);
        digitalWrite(ESP_LED_PIN, HIGH);
        delay(100);
      }
    }
};
