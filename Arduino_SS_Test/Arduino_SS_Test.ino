#include "SoftwareSerial.h"

SoftwareSerial ard1(10,11);

void setup() {
ard1.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  if(ard1.available())
  {
  Serial.println(ard1.read());
  digitalWrite(13,HIGH);
  delay(100);
  }

digitalWrite(13,LOW);
delay(100);
}
