#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <logging.h>
#include <flash.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

uint8_t servonum = 0;

void setup() {
  Log::begin();
  Flash::begin();

  pwm.begin();
  pwm.setPWMFreq(60);
  delay(10);

  Flash::flash();
}

void loop() {
  Log::println("Start movement");

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    pwm.setPWM(servonum, 0, pulselen);
  }

  Flash::flash();

  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    pwm.setPWM(servonum, 0, pulselen);
  }
  Log::println("Done");
  Flash::flash();
}
