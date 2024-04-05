#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <logging.h>

Adafruit_PWMServoDriver myServo = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600

uint8_t servonum = 0;
uint8_t numberOfServos = 4;

void setup() {
  Log::begin();

  myServo.begin();
  myServo.setPWMFreq(60);
  delay(10);
}

void loop() {
  Log::println("loop: servonum %d", servonum);

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    myServo.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    myServo.setPWM(servonum, 0, pulselen);
  }
  delay(500);
  
  servonum ++;
  if (servonum > numberOfServos-1) 
     servonum = 0;
}

