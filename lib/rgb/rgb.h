#ifndef rgb_h
#define rgb_h
#include "Arduino.h"
class rgb {
public:
  rgb();
  rgb(int r, int g, int b);
  void red();
  void red(unsigned long time);
  void green();
  void green(unsigned long time);
  void blue();
  void blue(unsigned long time);
  void off();
  void color(int r, int g, int b);
  void breathBlue();
  void breathRed();
  void breathGreen();
private:
  int pinr;
  int ping;
  int pinb;
  void breath(int pin);
};

#endif
