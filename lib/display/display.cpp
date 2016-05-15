#include "Arduino.h"
#include "display.h"


lcd::lcd(int bdrate) {
  Serial1.begin(bdrate);
}

void lcd::clear() {
  Serial1.write('\14');
  delay(6);
}

void lcd::display(const char *s, int wait) {
  if (wait != 0) {

  }
  Serial1.write(s);
  delay(wait);
}

void lcd::hello(const char *s, int wait) {
  clear();
  if (wait != 0) {
    lightOn();
  }
  display("Hello\r");
  display(s,wait);
}

void lcd::lightOn() {
  Serial1.write('\21');
}

void lcd::lightOff() {
  Serial1.write('\22');
}
