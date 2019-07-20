// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print(Serial.rw);
}

void loop() {
  // Turn off the display:
  //lcd.noDisplay();
  //delay(500);

  if(Serial.available()>0);
  {
    lcd.print(Serial.read());
    
  }
   delay(1000);
  // Turn on the display:
  //lcd.display();
  //delay(100);
}
