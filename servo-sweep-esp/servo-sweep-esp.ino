#include <ESP32Servo.h>
#include <logging.h>

Servo myservo;

int pos = 0;    // variable to store the servo position

// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42
// Possible PWM GPIO pins on the ESP32-S3: 0(used by on-board button),1-21,35-45,47,48(used by on-board LED)
// Possible PWM GPIO pins on the ESP32-C3: 0(used by on-board button),1-7,8(used by on-board LED),9-10,18-21
//#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
//int servoPin = 17;
//#elif defined(CONFIG_IDF_TARGET_ESP32C3)
//int servoPin = 7;
//#else
//int servoPin = 18;
//#endif

int servoPin = 12;

void setup() {
  Log::begin();

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 3500);
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  Log::println(".");

  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }
  Log::println(".");
}

