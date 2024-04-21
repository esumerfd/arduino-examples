#include <Arduino.h>
#include <Servo.h>

Servo servo_1;

int servo_pin = 10;
int pos = 0;

void setup() {
  servo_1.attach(servo_pin);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    servo_1.write(pos);              
  }
  delay(1000); 
 
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo_1.write(pos);             
  }
  delay(1000); 
}
