#include <XBee.h>
XBee xbee = XBee();
void setup() {
  Serial.begin(9600);
  xbee.setSerial(Serial);
}
void loop() {
  uint8_t data[] = {'K','A'};
  XBeeAddress64 addr64 = XBeeAddress64();
  addr64.setMsb(0x0000);//XXXXX -> Msb address of router/end node
  addr64.setLsb(0x0000ffff);//XXXXX -> Lsb address of router/end node 
  ZBTxRequest zbTx = ZBTxRequest(addr64, data, sizeof(data));
  xbee.send(zbTx);
  delay(100);
}



