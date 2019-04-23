/*
   Copyright (C) 2019 Anush DP
   License: GNU GPL3

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BigNumbers_I2C.h>
#include "IOT_WS.h"
#include "LCD_DEF.h"

void setup() {
  Wire.begin(D2, D1); //Remove this line if you are using Arduino
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
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  for (int i = 0; i < 50; i++)
    server.handleClient();
  bigNum.begin();
  server.handleClient();
  displayTemp(Temperature);
  server.handleClient();
  delay(4000);
  server.handleClient();
  displayHumidity(Humidity);
  server.handleClient();
  delay(4000);
  server.handleClient();
  displayAQ(400);
  server.handleClient();
  delay(4000);
  server.handleClient();
  displayWeather(getWeatherData());
  server.handleClient();
  lcd.clear();
  server.handleClient();
  lcd.print(F("Credits: DISPLAY ART"));
  server.handleClient();
  chineseTextReveal(5, 2, "ANUSH DP"); // text should be 8 letters/characters long
  server.handleClient();
  delay(1000);
}
