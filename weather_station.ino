/*
   Copyright (C) 2019 Anush DP
   License: GPL3

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BigNumbers_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); //size of lcd is 20x4
BigNumbers_I2C bigNum(&lcd);  //bignumbers

void createLoad();      // initialize loading screen characters
void loading();         // loading screen animation
void clear1();          // clear screen animation 1
void displayTemp(int);  // display temperature
void win_welcome();     // cool retro welcome screen
void rain(int);         // cool rainy weather animation
void sun();             // sunny weather   
void chineseTextReveal(byte col,byte row,char * text);  // reveal text with Chinese letter effects
//all display animation related functions are defined in display_fx.ino

void setup() {
  //Wire.begin(D2,D1); //Remove this line if you are using Arduino
  lcd.backlight();
  lcd.begin();
  createLoad();
  loading();
  delay(300);
  clear1();
  delay(300);
  win_welcome();
  lcd.setCursor(0, 3);
  delay(1500);
  lcd.print(F("This isn't Win95 LOL"));
  delay(1000);
}

void loop()
{
  bigNum.begin();
  displayTemp(37);
  delay(4000);
  displayHumidity(45);
  delay(4000);
  displayAQ(400);
  delay(4000);
  rain(3000);
  sun();
  delay(4000);
  lcd.clear();
  lcd.print(F("Credits: DISPLAY ART"));
  chineseTextReveal(5,2,"ANUSH DP");  // text should be 8 letters/characters long
  delay(2000);
}
