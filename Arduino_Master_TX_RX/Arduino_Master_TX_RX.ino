#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 0); // RX, TX
SoftwareSerial mySerial2(5, 9); // RX, TX
String c = "" , c2 = "";
char buf[9];


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);


  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void loop() { // run over and over
  while (mySerial.available()) { // slave may send less than requested
 c = mySerial.readStringUntil('Z');         // print the character
  }
  String op = "Pressure= " + c.substring(0,9) + "  Flow= " + c.substring(9);
  Serial.println(op);
  delay(100);
  }
