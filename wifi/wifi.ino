#include <WiFi.h>

char ssid[] = "wifi-test";
char pass[] = "aaaaaaaa";

void setup()
{
  Serial.begin(9600);
  while (!Serial && millis() < 5000);

  delay(100);

  Serial.print(F("Starting: "));
  Serial.println(ssid);

  int status = WiFi.begin(ssid, pass);
  Serial.println(status);

  delay(1000);
}

void loop()
{
    Serial.println(F("Lets Loop"));
    delay(1000);
}

