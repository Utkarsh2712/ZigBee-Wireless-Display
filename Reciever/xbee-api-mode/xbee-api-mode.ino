// include the library code:
#include <LiquidCrystal.h>
#include <XBee.h>
XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
ZBRxResponse rx = ZBRxResponse();
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  xbee.begin(Serial);
}

void loop() {
  String sample;
  xbee.readPacket(); 
    if (xbee.getResponse().isAvailable()) {
      Serial.println(xbee.getResponse().getApiId());
      if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
        xbee.getResponse().getZBRxResponse(rx);
          sample += (char)rx.getData(i);
        }
        lcd.print(sample);
      }
    }else if (xbee.getResponse().isError()) {
      lcd.print("Error");  
      lcd.print(xbee.getResponse().getErrorCode());
      } 
  delay(100);
}

