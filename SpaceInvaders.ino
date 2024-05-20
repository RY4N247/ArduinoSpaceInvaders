#include <LiquidCrystal.h>
#include <IRremote.hpp>
#include "Player.h"
#include "Alien.h"

//Objects
Player player;
Alien aliens[]{
  Alien(0),
  Alien(2),
  Alien(4),
  Alien(6),
  Alien(8),
  Alien(10),
  Alien(12),
  Alien(14)
};


//liquidcrystal setup 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Ir Remote setup 
const int IrReceiverPin = 8;

//Button Setup 
const unsigned long rightButton = 0xF609FF00;
const unsigned long shootButton = 0xEA15FF00;
const unsigned long leftButton = 0xF807FF00;


//custom characters
byte shoot[] = {
  B00000,
  B00100,
  B00100,
  B00100,
  B00000,
  B00000,
  B11111,
  B00000
};

byte receiveShoot[] = {
  B00100,
  B01010,
  B10001,
  B00000,
  B00100,
  B00100,
  B00100,
  B00000
};

byte explode[] = {
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000,
  B00000,
  B00000
};

int countdown(){
  for (int i = 3; i >= 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting in:");
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(1000); 
  }
}

void setup() {
  //liquidcrystal
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Press Any Button");
  lcd.setCursor(0, 1);
  lcd.print("To Begin");

  //IR
  IrReceiver.begin(IrReceiverPin, ENABLE_LED_FEEDBACK);

  //Create Custom Characters
  lcd.createChar(0, shoot);
  lcd.createChar(1, receiveShoot);
  lcd.createChar(2, explode);

  while (!IrReceiver.decode()) {
    IrReceiver.resume();
  }
  
  countdown();
  lcd.clear();
  player.initPlayer();
   for (Alien& alien : aliens) {
    alien.initAlien();
  }
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long value = IrReceiver.decodedIRData.decodedRawData;
    IrReceiver.resume();
    
    switch (value) {
      case rightButton:
        player.movePlayerRight();
        break;
      case leftButton:
        player.movePlayerLeft();
        break;
      case shootButton:
      bool hit = false;
      for(Alien& alien : aliens){
        if(player.getPlayerXPosition() == alien.getPosition()){
          player.shoot();
          alien.receiveShot();
          hit = true;
          alien.setPositionNULL();
          break;
        }
      }
      if(!hit){
        player.shoot();
        player.missShot();
      }

        break;
      default:
        break;
    }
  }

}

