#include <Arduino.h>
#include <Servo.h>

Servo servo_1;

int servo_pin = 10;
int pos = 0;

void setup() {
  servo_1.attach(servo_pin);
  servo_1.write(pos); // move servo to 0 degrees

  Serial.begin(9600);
  Serial.println("Positioned at 0 Degrees");
  Serial.println("Input Desired Angle and Press Enter");
}

void loop() {
  while (Serial.available()){

    String in_char = Serial.readStringUntil('\n');

    Serial.print("Moving to: ");
    Serial.print(in_char);
    Serial.println(" Degrees");
    servo_1.write(in_char.toInt());
    delay(in_char.toFloat()*(10.0/6.0));
  }
}
