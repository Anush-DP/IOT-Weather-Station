/*
   Copyright (C) 2019 Anush DP
   License: GNU GPL3

*/
void displayTemp(int n)//temperature
{
  lcd.clear();
  bigNum.displayLargeInt(n, 9, 1, 3, false);
  lcd.home();
  lcd.print(F("TEMPERATURE: "));
  lcd.setCursor(18, 1);
  lcd.write(char(0xdf));
  lcd.print(F("C"));
  lcd.setCursor(0, 3);
  delay(200);
  lcd.print(F("Code on GITHUB!!"));
}
void displayHumidity(int n)//humidity
{
  lcd.clear();
  bigNum.displayLargeInt(n, 9, 1, 3, false);
  lcd.home();
  lcd.print(F("HUMIDITY: "));
  lcd.setCursor(18, 1);
  lcd.print(F(" %"));
  lcd.setCursor(0, 3);
  delay(200);
  lcd.print(F("tiny.cc/weather"));
}
void displayAQ(int n)//air quality
{
  lcd.clear();
  bigNum.displayLargeInt(n, 8, 1, 3, false);
  lcd.home();
  lcd.print(F("AIR QUALITY: "));
  lcd.setCursor(17, 1);
  lcd.print(F("ppm"));
  lcd.setCursor(0, 2);
  if (n >= 0 && n < 51) lcd.print(F("Clean"));
  else if (n >= 51 && n < 101) lcd.print(F("Good"));
  else if (n >= 101 && n < 201) lcd.print(F("Moderate"));
  else if (n >= 201 && n < 301) lcd.print(F("Poor"));
  else if (n >= 301 && n < 401) lcd.print(F("Very Poor"));
  else if (n >= 401) lcd.print(F("Severe"));
  else lcd.print(F("ERROR"));
}
void displayWeather(int id)
{
  if (id < 800)
  {
    rain(3000);
  }
  else
  {
    sun();
    delay(4000);
  }
}
