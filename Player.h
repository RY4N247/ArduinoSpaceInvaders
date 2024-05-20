#ifndef Player_h
#define Player_h
#include "Arduino.h"
#include <LiquidCrystal.h>


class Player{
    public:
      Player();
      void movePlayerRight();
      void movePlayerLeft();
      void shoot();
      void initPlayer(); 
      int getPlayerXPosition();
      void missShot();
    private:
      int playerXPosition = 8;
      int playerYPosition = 1;
      LiquidCrystal lcd;
    
};

#endif