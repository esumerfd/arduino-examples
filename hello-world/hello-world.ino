#include <arduino.h>

/*
 * Monitor port settings:
 *  baudrate=9600
 *  bits=8
 *  dtr=on
 *  parity=none
 *  rts=on
 *  stop_bits=1
 */
void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  Serial.println("hello world");
  delay(1000);
}
