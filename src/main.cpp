#include "Arduino.h"
#include "display.h"
#include "Servo.h"

lcd disp;
const int dooropen = 10;
const int doorclosed = 170;
const unsigned long closeTime = 15000;
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
  if (millis()-timer > closeTime) {
    myServo.write(doorclosed);
    disp.lightOff();
    disp.clear();
  }
  if (Serial.available()) {
    name = Serial.readStringUntil('\n');
    Serial.println("hi");
    Serial.println(name);

    if (name==String("noface")) {
      disp.clear();
    }
    else {
      timer = millis();
      if (name==String("unkown")) {
        disp.clear();
        disp.lightOn();
        disp.display("We don't \rkown you");
      }
      else {
        myServo.write(dooropen);
        char namebuff[name.length()+1];
        name.toCharArray(namebuff, name.length()+1);
        disp.hello(namebuff);
      }
    }
  }
}
