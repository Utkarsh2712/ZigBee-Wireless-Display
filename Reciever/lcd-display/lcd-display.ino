#include <LiquidCrystal.h>
char ch;
String a;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available() > 0 );
  {
    ch=Serial.read();
    if (ch > 30 && ch < 123 )
    {
      lcd.clear();
      Serial.write(ch);
      a = Serial.readString();
      Serial.print("\n");
      Serial.print(a);
      lcd.print(ch);
      lcd.print(a);
     }
  delay(2000);
  }
  
}
