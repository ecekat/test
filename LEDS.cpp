#include <iostream>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

class LED{
  private:
    string path;
    int number;
    virtual void writeLED(string filename, string value);
    virtual void removeTrigger();
  public:
    LED(int number);
    virtual void turnOn();
    virtual void turnOff();
    virtual void flash(string delaynums);
    virtyal void outputState();
    virtual ~LED();
};

  
