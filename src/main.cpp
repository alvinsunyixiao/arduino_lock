#include "Arduino.h"
#include "display.h"
#include "Servo.h"

lcd disp;
const int dooropen = 10;
const int doorclosed = 170;
volatile unsigned long timer;
Servo myServo;
void setup() {
  Serial.begin(9600);
  disp = lcd();
  myServo.attach(40);
  myServo.write(doorclosed);
}

void loop() {

  String name;
  if (millis()-timer > 4000) {
    myServo.write(doorclosed);
    disp.lightOff();
    disp.clear();
  }
  if (Serial.available()) {
    name = Serial.readStringUntil('\n');
    Serial.println("hi");
    Serial.println(name);
    if (name=="unkown") {
      disp.clear();
      disp.display("We don't \rkown you");
    }
    else if (name=="noface") {
      disp.clear();
    }
    else {
      timer = millis();
      myServo.write(dooropen);
      char namebuff[name.length()+1];
      name.toCharArray(namebuff, name.length()+1);
      disp.hello(namebuff);
    }
  }
}
