#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <logging.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

uint8_t servonum = 0;

void setup() {
  Log::begin();

  pwm.begin();
  pwm.setPWMFreq(60);
  delay(10);

  pinMode(33, OUTPUT);
  digitalWrite(33, HIGH);

  flash();
}

void loop() {
  Log::println("Start movement");

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    pwm.setPWM(servonum, 0, pulselen);
  }

  flash();

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    pwm.setPWM(servonum, 0, pulselen);
  }
  Log::println("Done");
  flash();
}

void flash() {
  for (int flashCount = 0; flashCount < 10; flashCount++) {
    digitalWrite(33, LOW);
    delay(100);
    digitalWrite(33, HIGH);
    delay(100);
  }
}

