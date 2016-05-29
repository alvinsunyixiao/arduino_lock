#include "Arduino.h"
#include "display.h"
#include "Servo.h"
#include "rgb.h"

lcd disp;
const int dooropen = 160;
const int doorclosed = 50;
const unsigned long closeTime = 15000;
volatile unsigned long timer;
rgb* l[3];
Servo myServo;
rgb tmp1(2,3,4), tmp2(5,6,7), tmp3(8,9,10);

void breath(int r, int g, int b, int time = 5) {
  for (int i=0;i<255;i++) {
    for (int j=0;j<3;j++) {
      l[j]->color(r*i, g*i, b*i);
      delay(time);
    }
  }
  for (int i=255;i>=1;i--) {
    for (int j=0;j<3;j++) {
      l[j]->color(r*i, g*i, b*i);
      delay(time);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  disp = lcd();
  myServo.attach(30);
  myServo.write(doorclosed);
  l[0] = &tmp1;
  l[1] = &tmp2;
  l[2] = &tmp3;
  randomSeed(millis());
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
        //disp.lightOn();
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
  else {
    int x = random(0,3);
    int a[3] = {0,0,0};
    a[x] = 1;
    breath(a[0],a[1],a[2], 2);
  }


}
