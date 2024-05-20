
#include "Player.h"


Player::Player() : lcd(12, 11, 5, 4, 3, 2) {
    lcd.begin(16, 2); 
    initPlayer();
}

void Player::initPlayer() {
  lcd.setCursor(playerXPosition, playerYPosition);
  lcd.print("_");
}

void Player::movePlayerRight() {
  if(playerXPosition < 15){
    lcd.setCursor(playerXPosition, playerYPosition);
    lcd.print(" ");
    playerXPosition += 1;
    lcd.setCursor(playerXPosition, playerYPosition);
    lcd.print("_"); 
  }
}

void Player::movePlayerLeft() {
  if(playerXPosition > 0){
      lcd.setCursor(playerXPosition, playerYPosition);
      lcd.print(" ");
      playerXPosition -= 1;
      lcd.setCursor(playerXPosition, playerYPosition);
      lcd.print("_"); 
  }
}

void Player::shoot() {
  
   lcd.setCursor(playerXPosition, playerYPosition);
   lcd.write((uint8_t)0);
   delay(150);
   lcd.setCursor(playerXPosition, playerYPosition);
   lcd.print("_");

}
void Player::missShot(){
  playerYPosition = 0;
  lcd.setCursor(playerXPosition, playerYPosition);
  lcd.print("|");
  delay(150);
  lcd.setCursor(playerXPosition, playerYPosition);
  lcd.print(" ");
  playerYPosition = 1;

}

int Player::getPlayerXPosition(){
  return playerXPosition;
}





