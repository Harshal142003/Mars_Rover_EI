--SETUP:

->  CLASSES: ROVER,COMMAND,COMMANDEXECUTE
  
->  ROVER: -> datamembers for grid, obstacles storage, initialize position and direction,
             -> methods for turning left, right, move
             -> Get methods to access private member of Rover class to outside functions
    
->  COMMAND-> polymorphism by virtual function where TurnLeft, TurnRight, Move classes overrides method of BASE class

->  CommandExecute -> Store and execute commands

-> Rover.h , Command.h , main.cpp files 

-- RUN: g++ main.cpp
--      .\a 

DEMO: 
![image](https://github.com/Harshal142003/Mars_Rover_EI/assets/104431704/93d04c12-c5a2-4028-951e-0a117d00d453)
