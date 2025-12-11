#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <logging.h>
#include <flash.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 545

uint8_t servonum = 0;

void setup() {
  Log::begin();
  Flash::begin();

  // ESP32CAM I2C pins (matching working robot-spider code)
  Log::println("Initializing I2C on SDA=15, SCL=14");
  Wire.begin(15, 14);

  // Initialize PWM driver (matching Adafruit example and working code)
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);  // Calibrate oscillator - CRITICAL!
  pwm.setPWMFreq(50);  // 50 Hz for servos

  delay(10);

  Log::println("PWM driver initialized");
  Flash::flash();
}

void loop() {
  Log::println("Start movement");

  for (int pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++){
    pwm.setPWM(servonum, 0, pulselen);
    delay(10);
  }

  Flash::flash();

  for (int pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--){
    pwm.setPWM(servonum, 0, pulselen);
    delay(10);
  }

  Flash::flash();

  Log::println("Done");
  delay(1000);
}
