#include "Arduino.h"
#include "Alien.h"

Alien::Alien(int alienXPosition) : lcd(12, 11, 5, 4, 3, 2) {
    lcd.begin(16, 2); 
    initAlien();
    this->alienXPosition = alienXPosition;
}

void Alien::initAlien(){
  lcd.setCursor(alienXPosition, alienYPosition);
  lcd.print("^");

}

int Alien::getPosition(){
  return alienXPosition; 
}

void Alien::setPositionNULL(){
  alienXPosition = -1;
}

void Alien::move(){
  
  
}

void Alien::receiveShot(){
  lcd.setCursor(alienXPosition, alienYPosition);
  lcd.write((uint8_t)1);
  delay(200);
  lcd.setCursor(alienXPosition, alienYPosition);
  lcd.write((uint8_t)2);
  delay(150);
  lcd.setCursor(alienXPosition, alienYPosition);
  lcd.print(" ");  
}

