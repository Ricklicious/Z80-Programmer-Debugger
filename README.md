# Z80-Programmer-Debugger
An Arduino program which works in conjunction with a Z80 CPU for programming and debugging


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
                    
                    
