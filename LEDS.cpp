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

void LED::LED(int number){
  this->number = number;
  ostrungstream s;
  s<<LED_PATH<<number;
  path = string(s.str());
}

void LED::writeLED(string filename, string value){
  
  ofstream fs;
  fs.open((path+filename).c_str());
  fs<<value;
  fs.close();
}

void LED::removeTrigger(){
  
  writeLED("/trigger", "none");
}
  
  void LED::turnOn{
    cout<<"Turning the LED"<<number<< "on"<<endl;
    removeTrigger();
    writeLED("/brightness", "1");
  }
  
    void LED::turnOff{
    cout<<"Turning the LED"<<number<< "off"<<endl;
    removeTrigger();
    writeLED("/brightness", "0");
  }
  
  
  void LED::flash(string delayms = "50"){
   cout << "Making LED" << number << " flash." << endl;
   writeLED("/trigger", "timer");
   writeLED("/delay_on", delayms);
   writeLED("/delay_off", delayms);
}

void LED::outputState(){
   ifstream fs;
   fs.open( (path + "/trigger").c_str());
   string line;
   while(getline(fs,line)) cout << line << endl;
   fs.close();
}

LED::~LED(){   // A destructor - called when the object is destroyed
   cout << "destroying the LED with path: " << path << endl;
}

int main(int argc, char* argv[]){
   if(argc!=2){
        cout << "Usage is makeLEDs <command>" << endl;
        cout << "  command is one of: on, off, flash or status" << endl;
        cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);

   // Create four LED objects and put them in an array
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
