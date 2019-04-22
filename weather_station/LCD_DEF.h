LiquidCrystal_I2C lcd(0x27, 20, 4); //size of lcd is 20x4
BigNumbers_I2C bigNum(&lcd);  //bignumbers

void createLoad();      // initialize loading screen characters
void loading();         // loading screen animation
void clear1();          // clear screen animation 1
void displayTemp(int);  // display temperature
void win_welcome();     // cool retro welcome screen
void rain(int);         // cool rainy weather animation
void sun();             // sunny weather
void chineseTextReveal(byte col, byte row, char * text); // reveal text with Chinese letter effects
//all display animation related functions are defined in display_fx.ino
