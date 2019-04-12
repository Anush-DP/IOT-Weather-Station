/*
   Copyright (C) 2019 Anush DP
   License: GPL3

*/
void clear1()
{
  byte yo[] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
  };
  lcd.createChar(1, yo);
  lcd.setCursor(0, 0);
  for (int i = 0; i < 80; ++i) {
    lcd.write(1);
    delay(20);
  }
  int j = 16;
  for (int i = 0; i < 5; ++i)
  {
    for (int z = 0; z < 8; ++z)
    {
      yo[z] = yo[z] + j;
    }
    j = j >> 1;
    lcd.createChar(1, yo);
    delay(70);
  }
  for (int i = 0; i < 6; ++i)
  {
    for (int z = 0; z < 8; ++z)
    {
      yo[z] = yo[z] >> 1;
    }
    lcd.createChar(1, yo);
    delay(70);
  }
  lcd.clear();
}

void createLoad()
{
  // open braces of the bar
  byte opn[] = {
    0x01,
    0x03,
    0x02,
    0x02,
    0x02,
    0x02,
    0x03,
    0x01
  };
  // close braces of the bar
  byte clo[] = {
    0x10,
    0x18,
    0x08,
    0x08,
    0x08,
    0x08,
    0x18,
    0x10
  };
  byte one[] = {
    0x1F,
    0x00,
    0x10,
    0x10,
    0x10,
    0x10,
    0x00,
    0x1F
  };
  byte two[] = {
    0x1F,
    0x00,
    0x18,
    0x18,
    0x18,
    0x18,
    0x00,
    0x1F
  };
  byte three[] = {
    0x1F,
    0x00,
    0x1c,
    0x1c,
    0x1c,
    0x1c,
    0x00,
    0x1F
  };
  byte four[] = {
    0x1F,
    0x00,
    0x1e,
    0x1e,
    0x1e,
    0x1e,
    0x00,
    0x1F
  };
  byte five[] = {
    0x1F,
    0x00,
    0x1f,
    0x1f,
    0x1f,
    0x1f,
    0x00,
    0x1F
  };
  // empty pipe/bar
  byte pipe[] = {
    0x1F,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1F
  };
  lcd.createChar(0, opn);
  lcd.createChar(1, pipe);
  lcd.createChar(2, one);
  lcd.createChar(3, two);
  lcd.createChar(4, three);
  lcd.createChar(4, four);
  lcd.createChar(5, five);
  lcd.createChar(6, clo);
}
void loading()
{
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print(F("LOADING..."));
  lcd.setCursor(1, 1);
  lcd.write(0);
  for (int i = 2; i < 18; ++i)
    lcd.write(1);
  lcd.write(6);
  for (int i = 2; i < 18; ++i)
  {
    for (int j = 2; j <= 5; ++j)
    {
      lcd.setCursor(i, 1);
      lcd.write(j);
      delay(130);
    }
    lcd.setCursor(0, 3);
    switch (i)
    {
      case 15: lcd.print(F("Repainting screen.."));
        break;
      case 11: lcd.print(F("Reloading Matrix.."));
        break;
      case 3: lcd.print(F("Sensing environment."));
				Temperature = dht.readTemperature();
				Humidity = dht.readHumidity();
        break;
      case 7: lcd.print(F("Setting up server.."));
		WIFISetup();
        break;
    }
  }
}
void win_welcome()
{

  byte CustChar1[] = {
    0x08,
    0x14,
    0x0A,
    0x15,
    0x0B,
    0x05,
    0x13,
    0x08,
  };
  byte CustChar2[] = {
    0x00,
    0x01,
    0x1F,
    0x0F,
    0x1F,
    0x0B,
    0x1F,
    0x0B,
  };
  byte CustChar3[] = {
    0x0F,
    0x1F,
    0x13,
    0x03,
    0x03,
    0x03,
    0x07,
    0x1F,
  };
  byte CustChar4[] = {
    0x1C,
    0x1E,
    0x06,
    0x06,
    0x06,
    0x06,
    0x1E,
    0x1E,
  };
  byte CustChar5[] = {
    0x07,
    0x11,
    0x0B,
    0x15,
    0x03,
    0x08,
    0x03,
    0x00,
  };
  byte CustChar6[] = {
    0x1F,
    0x0F,
    0x1F,
    0x0B,
    0x1F,
    0x0B,
    0x1F,
    0x00,
  };
  byte CustChar7[] = {
    0x13,
    0x03,
    0x03,
    0x03,
    0x0F,
    0x1E,
    0x00,
    0x00,
  };
  byte CustChar8[] = {
    0x06,
    0x06,
    0x06,
    0x06,
    0x1E,
    0x1E,
    0x00,
    0x00,
  };

  lcd.createChar(0, CustChar1);
  lcd.createChar(1, CustChar2);
  lcd.createChar(2, CustChar3);
  lcd.createChar(3, CustChar4);
  lcd.createChar(4, CustChar5);
  lcd.createChar(5, CustChar6);
  lcd.createChar(6, CustChar7);
  lcd.createChar(7, CustChar8);

  for (int i = 0; i < 4; ++i)
  {
    lcd.setCursor(i + 8, 0);
    lcd.write(i);
    lcd.setCursor(i + 8, 1);
    lcd.write(i + 4);
    delay(100);
  }
  char a[] = "WELCOME";

  lcd.setCursor(7, 2);
  for (int i = 0; i < 7; ++i)
  {
    lcd.write(a[i]);
    delay(100);
  }
}
void rain(int n)
{
  lcd.clear();
  byte CustChar5[] = {
    0x02,
    0x0E,
    0x18,
    0x10,
    0x1E,
    0x0F,
    0x07,
    0x03,
  };
  byte CustChar6[] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x0E,
    0x1F,
    0x1F,
    0x19,
  };
  byte CustChar7[] = {
    0x00,
    0x00,
    0x00,
    0x01,
    0x07,
    0x07,
    0x1F,
    0x1C,
  };
  byte CustChar8[] = {
    0x04,
    0x07,
    0x01,
    0x03,
    0x13,
    0x1B,
    0x1F,
    0x1E,
  };
  lcd.createChar(4, CustChar5); // cloud
  lcd.createChar(5, CustChar6);
  lcd.createChar(6, CustChar7);
  lcd.createChar(7, CustChar8);
  lcd.setCursor(15, 0);
  for (int i = 4; i < 8; i++)
    lcd.write(i);               // write cloud
  byte rain[24];                // rainfall
  byte lines[8] = {
    0x00, 0x08, 0x08, 0x0A, 0x0A, 0x02, 0x02, 0x00
  };
  int count = 0;
  lcd.home();
  lcd.print(F("WEATHER:"));
  lcd.setCursor(4, 2);
  lcd.print(F("Rainy"));
  while (count < n / 1200) {
    for ( int falling = 0 ; falling < 24; falling++) { //insert the lines,(rainfall)

      for (int i = 0 ; i < 24; i++) //not 0 because of the  lcd.createChar(0, ) issue
        rain[i] = 0x00;

      for (int j = 0 ; j < 8 ; j++)
      {
        rain[(falling + j) % 24] = lines[j];

        rain[(falling + j + 8) % 24] = lines[j];

        rain[(falling + j + 16) % 24] = lines[j];

        rain[(falling + j + 24) % 24] = lines[j];
      }
      //making four special characters
      for (int i = 0 ; i < 3 ; i++) //not 0 because of the  lcd.createChar(0, ) issue
      {
        byte s1[8];
        for (int j = 0 ; j < 8 ; j++)
          s1[j] = rain[i * 8 + j];
        lcd.createChar(i, s1);
        //make rainfall appear on the screen
        lcd.setCursor(15, i + 1);
        lcd.write(i);
        lcd.setCursor(16, (i + 3) % 3 + 1);
        lcd.write(i);
        lcd.setCursor(17, (i) % 3 + 1);
        lcd.write(i);
        lcd.setCursor(18, (i + 3) % 3 + 1);
        lcd.write(i);
      }
      delay(50);
    }
    ++count;
  }
  lcd.clear();
}
void sun()
{
  lcd.clear();
  byte CustChar1[] = {
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
  };
  byte CustChar2[] = {
    0x00,
    0x00,
    0x00,
    0x03,
    0x0E,
    0x18,
    0x10,
    0x10,
  };
  byte CustChar3[] = {
    0x00,
    0x00,
    0x00,
    0x18,
    0x0E,
    0x02,
    0x03,
    0x01,
  };
  byte CustChar4[] = {
    0x10,
    0x18,
    0x08,
    0x0C,
    0x04,
    0x06,
    0x03,
    0x01,
  };
  byte CustChar5[] = {
    0x01,
    0x03,
    0x06,
    0x04,
    0x0C,
    0x08,
    0x18,
    0x10,
  };
  byte CustChar6[] = {
    0x10,
    0x10,
    0x18,
    0x0E,
    0x03,
    0x00,
    0x00,
    0x00,
  };
  byte CustChar7[] = {
    0x01,
    0x01,
    0x03,
    0x0C,
    0x18,
    0x00,
    0x00,
    0x00,
  };
  byte CustChar8[] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1F,
  };

  lcd.home();
  lcd.print(F("WEATHER:"));
  lcd.setCursor(4, 2);
  lcd.print(F("Sunny"));

  lcd.createChar(0, CustChar1);
  lcd.createChar(1, CustChar2);
  lcd.createChar(2, CustChar3);
  lcd.createChar(3, CustChar4);
  lcd.createChar(4, CustChar5);
  lcd.createChar(5, CustChar6);
  lcd.createChar(6, CustChar7);
  lcd.createChar(7, CustChar8);

  lcd.setCursor(14, 0);
  lcd.write(0);
  lcd.setCursor(14, 3);
  lcd.write(0);
  lcd.setCursor(12, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.setCursor(16, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.setCursor(13, 0);
  lcd.write(3);
  lcd.setCursor(16, 3);
  lcd.write(3);
  lcd.setCursor(16, 0);
  lcd.write(4);
  lcd.setCursor(13, 3);
  lcd.write(4);

  lcd.setCursor(14, 1);
  for (int i = 1; i < 3; i++)
    lcd.write(i);
  lcd.setCursor(14, 2);
  for (int i = 5; i < 7; i++)
    lcd.write(i);
}
void chineseTextReveal(byte col,byte row,char * text)
{
	 for (int j = 0; j < 2; j++)
  {
    for (int i = 0xc8; i <= 0xcf; i++)
    { lcd.setCursor(col, row);
      lcd.write(char(i));
      lcd.setCursor(col+1, row);
      lcd.write(char(i - 0x0f));
      lcd.setCursor(col+2, row);
      lcd.write(char(i - 0x08));
      lcd.setCursor(col+3, row);
      lcd.write(char(i - 0x15));
      lcd.setCursor(col+4, row);
      lcd.write(char(i - 0x0f));
      lcd.setCursor(col+5, row);
      lcd.write(char(i - 0x08));
      lcd.setCursor(col+6, row);
      lcd.write(char(i));
      lcd.setCursor(col+7, row);
      lcd.write(char(i - 0x15));
      delay(110);
    }
  }
  lcd.setCursor(col,row);
  lcd.print(text);
  delay(2000);
}
