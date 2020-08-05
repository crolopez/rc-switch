// Tested on Arduino UNO

#include <RCSwitch.h>

#define RF_RT_PIN 10

RCSwitch mySwitch;
void setup() {
  mySwitch = RCSwitch();
  mySwitch.enableTransmit(RF_RT_PIN);
}

void loop() {
  delay(3000);
  mySwitch.send(4294967294, 32);
  delay(3000);
  mySwitch.sendString("ABCDE"); // 5 bytes / 40 bits
  delay(3000);
  mySwitch.send("1101"); // 13
  delay(3000);
  mySwitch.send("101111011101100011111011111111110011111101110011"); // 6 bytes / 48 bits / 208739638394739
  delay(3000);
  mySwitch.send("1011110111011000111110111111111100111111011100110010"); // 52 bits / 3339834214315826
}
