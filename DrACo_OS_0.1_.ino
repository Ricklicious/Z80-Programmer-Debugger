/**************************************************************************************
DrACo OS v0.1
  Z80 Programming/Debugging interface
  
  EEPROM -> AT28C256
    SRAM -> TC551001CP-70L
    A15 (memory bank switch)

                     __________
                    |          |
                    |EEPROM    |
                    |          |
                    |0000-7FFF |
     MEMORY MAP     |__________|
                    |          |
                    |SRAM      |
                    |          |
                    |8000-7FFF |
                    |__________|
**************************************************************************************/


#include "Z80interface.h"

z80i DrACo(true);
void setup() 
{
  
  Serial.begin(115200);
  DrACo.begin();
  DrACo.programmerMode(0);
  delay(100);

}

void loop() 

{
  DrACo.programmerMode(2);
}
