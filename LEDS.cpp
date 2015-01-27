#include <iostream>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

class LED{
  private:
  string path;
  int number;
  virtual void 
