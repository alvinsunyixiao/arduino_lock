#include "rgb.h"
rgb::rgb() {

}

rgb::rgb(int r, int g, int b) {
  pinr = r;
  ping = g;
  pinb = b;
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void rgb::red() {
  digitalWrite(pinr, HIGH);
  digitalWrite(ping, LOW);
  digitalWrite(pinb, LOW);
}

void rgb::red(unsigned long time) {
  digitalWrite(pinr, HIGH);
  digitalWrite(ping, LOW);
  digitalWrite(pinb, LOW);
  delay(time);
}


void rgb::green() {
  digitalWrite(pinr, LOW);
  digitalWrite(ping, HIGH);
  digitalWrite(pinb, LOW);
}

void rgb::green(unsigned long time) {
  digitalWrite(pinr, LOW);
  digitalWrite(ping, HIGH);
  digitalWrite(pinb, LOW);
  delay(time);
}

void rgb::blue() {
  digitalWrite(pinr, LOW);
  digitalWrite(ping, LOW);
  digitalWrite(pinb, HIGH);
}

void rgb::blue(unsigned long time) {
  digitalWrite(pinr, LOW);
  digitalWrite(ping, LOW);
  digitalWrite(pinb, HIGH);
  delay(time);
}

void rgb::off() {
  digitalWrite(pinr, LOW);
  digitalWrite(ping, LOW);
  digitalWrite(pinb, LOW);
}

void rgb::color(int r, int g, int b) {
  analogWrite(pinr, r);
  analogWrite(ping, g);
  analogWrite(pinb, b);
}

void rgb::breath(int pin) {
  off();
  for (int i=0;i<256;i++) {
    analogWrite(pin, i);
    delay(5);
  }
  for (int i=255;i>=0;i--) {
    analogWrite(pin, i);
    delay(5);
  }
}

void rgb::breathRed() {
  breath(pinr);
}

void rgb::breathBlue() {
  breath(pinb);
}

void rgb::breathGreen() {
  breath(ping);
}
