#include "Z80interface.h"

z80i::z80i(bool displayMsg)
{
    _message = displayMsg;
}

void z80i::begin()
{
  //Serial.begin(baudRate);
  Serial.print("Preparing System...");
  sramWriteMode();

  pinMode(BUSREQ, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(readWrite, OUTPUT);
  pinMode(M1, INPUT);

  digitalWrite(BUSREQ, HIGH);
  digitalWrite(readWrite, LOW);
  digitalWrite(RESET, HIGH);
  delay(500);
  if(_message)
  {
    Serial.println("System Ready");
  }

  /*if(digitalRead(bootMode)== HIGH)
  {
    programmerMode(0);
    program();
  }*/
  
}

void z80i::program()
{

  latchAddress(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  latchData(0,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);
  latchAddress(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1);
  latchData(1,1,0,0,0,0,1,1);
  sramWrite();
  //delay(1000);
  
  latchAddress(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0);
  latchData(0,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);

  latchAddress(0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1);
  latchData(1,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);

  latchAddress(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  latchData(0,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);

  latchAddress(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1);
  latchData(1,1,0,0,0,0,1,1);
  sramWrite();
  //delay(1000);
  latchAddress(1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0);
  latchData(0,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);

  latchAddress(1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1);
  latchData(0,0,0,0,0,0,0,0);
  sramWrite();
  //delay(1000);

}

int z80i::programmerMode(int A)
{
  if(A == 0)//PROGRAMMING MODE
{

    modeSwitch = 0;
    sramWriteMode();
    digitalWrite(BUSREQ, LOW);
    digitalWrite(RESET, HIGH);
    clockPulse(200);
    program();

  }
  
  if(A == 1)// RUN MODE
  {
    if(modeSwitch != 1)
    {
    modeSwitch = 1;
    digitalWrite(BUSREQ, HIGH);
    delay(100);
    digitalWrite(RESET, LOW);
    clockPulse(200);
    digitalWrite(RESET, HIGH);
    sramObserve();
    }
    if(digitalRead(M1)==LOW)
    {
    sramRead();
    }
    clockPulse(1);
  }
    if(A == 2)
  {
    if(modeSwitch != 2)
    {
    modeSwitch = 2;
    Serial.println("Switching to Step Mode");
    digitalWrite(BUSREQ, HIGH);
    delay(100);
    digitalWrite(RESET, LOW);
    clockPulse(200);
    digitalWrite(RESET, HIGH);
    sramObserve();
    }
    if(Serial.read()=='\n')
    {
      
      clockPulse(1);
  /*    if(digitalRead(M1) == LOW)
      {
        
      sramRead();
      }*/

      sramRead();
 
    }
  }

}

void z80i::clockPulse(int A)
{
  int i=0;
  while(i < A)
  {
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
    i++;
  }
}

void z80i::sramWriteMode()
{
  pinMode(IO1, OUTPUT);
  pinMode(IO2, OUTPUT);
  pinMode(IO3, OUTPUT);
  pinMode(IO4, OUTPUT);
  pinMode(IO5, OUTPUT);
  pinMode(IO6, OUTPUT);
  pinMode(IO7, OUTPUT);
  pinMode(IO8, OUTPUT);

  pinMode(add0, OUTPUT);
  pinMode(add1, OUTPUT);
  pinMode(add2, OUTPUT);
  pinMode(add3, OUTPUT);
  pinMode(add4, OUTPUT);
  pinMode(add5, OUTPUT);
  pinMode(add6, OUTPUT);
  pinMode(add7, OUTPUT);
  pinMode(add8, OUTPUT);
  pinMode(add9, OUTPUT);
  pinMode(add10, OUTPUT);
  pinMode(add11, OUTPUT);
  pinMode(add12, OUTPUT);
  pinMode(add13, OUTPUT);
  pinMode(add14, OUTPUT);
  pinMode(add15, OUTPUT);

}

void z80i::sramObserve()
{
  pinMode(IO1, INPUT);
  pinMode(IO2, INPUT);
  pinMode(IO3, INPUT);
  pinMode(IO4, INPUT);
  pinMode(IO5, INPUT);
  pinMode(IO6, INPUT);
  pinMode(IO7, INPUT);
  pinMode(IO8, INPUT);

  pinMode(add0, INPUT);
  pinMode(add1, INPUT);
  pinMode(add2, INPUT);
  pinMode(add3, INPUT);
  pinMode(add4, INPUT);
  pinMode(add5, INPUT);
  pinMode(add6, INPUT);
  pinMode(add7, INPUT);
  pinMode(add8, INPUT);
  pinMode(add9, INPUT);
  pinMode(add10, INPUT);
  pinMode(add11, INPUT);
  pinMode(add12, INPUT);
  pinMode(add13, INPUT);
  pinMode(add14, INPUT);
  pinMode(add15, INPUT);
//  pinMode(add16, INPUT);
  //pinMode(readWrite, INPUT);


}

void z80i::sramRead()
{
  Serial.println();
  if (digitalRead(IO8) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

    if (digitalRead(IO7) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO6) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO5) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO4) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO3) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO2) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(IO1) == HIGH)
  {
    Serial.println('1');
  }
  else{Serial.println('0');}


  ///////////////////////////////////
  

    if (digitalRead(add15) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add14) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add13) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add12) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add11) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add10) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add9) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

    if (digitalRead(add8) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

    if (digitalRead(add7) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add6) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add5) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add4) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add3) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add2) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add1) == HIGH)
  {
    Serial.print('1');
  }
  else{Serial.print('0');}

      if (digitalRead(add0) == HIGH)
  {
    Serial.println('1');
  }
  else{Serial.println('0');}
}

void z80i::latchData(int A, int B,int C,int D,int E,int F,int G,int H)
{
  if(A == 1)
  {
    digitalWrite(36, HIGH);
  }
  else if(A == 0)
  {
    digitalWrite(36, LOW);
  }

    if(B == 1)
  {
    digitalWrite(34, HIGH);
  }
  else if(B == 0)
  {
    digitalWrite(34, LOW);
  }
    if(C == 1)
  {
    digitalWrite(32, HIGH);
  }
  else if(C == 0)
  {
    digitalWrite(32, LOW);
  }
    if(D == 1)
  {
    digitalWrite(30, HIGH);
  }
  else if(D == 0)
  {
    digitalWrite(30, LOW);
  }
    if(E == 1)
  {
    digitalWrite(28, HIGH);
  }
  else if(E == 0)
  {
    digitalWrite(28, LOW);
  }
    if(F == 1)
  {
    digitalWrite(26, HIGH);
  }
  else if(F == 0)
  {
    digitalWrite(26, LOW);
  }
    if(G == 1)
  {
    digitalWrite(24, HIGH);
  }
  else if(G == 0)
  {
    digitalWrite(24, LOW);
  }
    if(H == 1)
  {
    digitalWrite(22, HIGH);
  }
  else if(H == 0)
  {
    digitalWrite(22, LOW);
  }
}

void z80i::latchAddress(int A, int B,int C,int D,int E,int F,int G,int H, int I, int J,int K,int L,int M,int N,int O,int P)
{
  if(P == 1)
  {
    digitalWrite(add0, HIGH);
  }
  else if(P == 0)
  {
    digitalWrite(add0, LOW);
  }
/////
    if(O == 1)
  {
    digitalWrite(add1, HIGH);
  }
  else if(O == 0)
  {
    digitalWrite(add1, LOW);
  }
  /////
    if(N == 1)
  {
    digitalWrite(add2, HIGH);
  }
  else if(N == 0)
  {
    digitalWrite(add2, LOW);
  }
  /////
    if(M == 1)
  {
    digitalWrite(add3, HIGH);
  }
  else if(M == 0)
  {
    digitalWrite(add3, LOW);
  }
    if(L == 1)
  {
    digitalWrite(add4, HIGH);
  }
  else if(L == 0)
  {
    digitalWrite(add4, LOW);
  }
    if(K == 1)
  {
    digitalWrite(add5, HIGH);
  }
  else if(K == 0)
  {
    digitalWrite(add5, LOW);
  }
    if(J == 1)
  {
    digitalWrite(add6, HIGH);
  }
  else if(J == 0)
  {
    digitalWrite(add6, LOW);
  }
    if(I == 1)
  {
    digitalWrite(add7, HIGH);
  }
  else if(I == 0)
  {
    digitalWrite(add7, LOW);
  }

    if(H == 1)
  {
    digitalWrite(add8, HIGH);
  }
  else if(H == 0)
  {
    digitalWrite(add8, LOW);
  }

    if(G == 1)
  {
    digitalWrite(add9, HIGH);
  }
  else if(G == 0)
  {
    digitalWrite(add9, LOW);
  }
    if(F == 1)
  {
    digitalWrite(add10, HIGH);
  }
  else if(F == 0)
  {
    digitalWrite(add10, LOW);
  }
    if(E == 1)
  {
    digitalWrite(add11, HIGH);
  }
  else if(E == 0)
  {
    digitalWrite(add11, LOW);
  }
    if(D == 1)
  {
    digitalWrite(add12, HIGH);
  }
  else if(D == 0)
  {
    digitalWrite(add12, LOW);
  }
    if(C == 1)
  {
    digitalWrite(add13, HIGH);
  }
  else if(C == 0)
  {
    digitalWrite(add13, LOW);
  }
    if(B == 1)
  {
    digitalWrite(add14, HIGH);
  }
  else if(B == 0)
  {
    digitalWrite(add14, LOW);
  }
    if(A == 1)
  {
    digitalWrite(add15, HIGH);
  }
  else if(A == 0)
  {
    digitalWrite(add15, LOW);
  }
}

void z80i::sramWrite()
{  
  digitalWrite(readWrite, HIGH);
  Serial.print("Writing...");
  delay(10);
  digitalWrite(readWrite, LOW);
  Serial.println("done");
  delay(10);
}
