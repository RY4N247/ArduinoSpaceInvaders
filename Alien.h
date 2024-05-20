#ifndef Alien_h
#define Alien_h
#include "Arduino.h"
#include <LiquidCrystal.h>


class Alien{
    public:
      Alien(int alienXPosition);
      void initAlien();
      void move();
      int getPosition();
      void receiveShot();
      void setPositionNULL();
    private:
      LiquidCrystal lcd;
      int alienXPosition;
      const int alienYPosition = 0;
};

#endif