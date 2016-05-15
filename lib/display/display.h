#include "Arduino.h"

class lcd {
public:
  lcd(int bdrate = 9600);
  void display(const char *s, int wait = 0);
  void clear();
  void hello(const char *s, int wait = 0);
  void lightOn();
  void lightOff();
};
