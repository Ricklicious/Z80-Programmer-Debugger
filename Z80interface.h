#ifndef z80I
#define z80I

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


class z80i
{
  public:
    z80i(bool);
    void begin();
    int programmerMode(int);
    
  

  private:
    void boot();
    void sramWriteMode();
    void clockPulse(int);
    void program();
    void sramObserve();
    void sramRead();
    void latchAddress(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
    void latchData(int,int,int,int,int,int,int,int);
    void sramWrite();
    bool _message;
    int bootMode = 38;
    int modeSwitch;
    int BUSREQ = 50;
    int RESET = 52;
    int CLOCK = 8;
    int M1 = 38;
    int readWrite = 4;
    //int baudRate = 115200;

    int add0 = 23, add1 = 25, add2 = 27, add3 = 29, add4 = 31, add5 = 33, add6 = 35, add7 = 37, add8 = 39, add9 = 41, add10 = 43 , add11 = 45, add12 = 47, add13 = 49, add14 = 51, add15 = 53;
    int IO1 = 22, IO2 = 24, IO3 = 26, IO4 = 28, IO5 = 30, IO6 = 32, IO7 = 34, IO8 = 36;
};

#endif
