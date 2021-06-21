#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
String c = "";
char buf[5];


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void loop() { // run over and over
  while (mySerial.available()) { // slave may send less than requested
 c = mySerial.readStringUntil('Z');         // print the character
  }
  Serial.println(c);
  delay(100);
  }
