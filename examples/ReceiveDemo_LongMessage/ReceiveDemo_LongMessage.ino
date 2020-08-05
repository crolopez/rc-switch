// Tested on NodeMCU

#include <RCSwitch.h>

#define RF_RX_PIN 0 // D3

RCSwitch mySwitch;
void setup() {
  Serial.begin(9600);

  mySwitch = RCSwitch();
  mySwitch.enableReceive(RF_RX_PIN);

  Serial.println("Starting");
}

void loop() {
  if (mySwitch.available()) {
    process_message();
    delay(1000);
  }
}

void process_message() {
  Serial.println("\n######### Message:");

  print_received_long();
  print_received_long_long();
  print_received_bit_length();
  print_received_string();
  print_received_delay();
  print_received_protocol();

  mySwitch.resetAvailable();
}

void print_received_long() {
  Serial.print("Received long: ");
  Serial.println(mySwitch.getReceivedValue());
}

void print_received_long_long() {
  Serial.print("Received long long: ");
  unsigned long long value = mySwitch.getReceivedLongLongValue();
  char str[20];
  snprintf(str, 20, "%llu", value);
  Serial.println(str);
}

void print_received_bit_length() {
  Serial.print("Received bit length: ");
  Serial.println(mySwitch.getReceivedBitlength());
}

void print_received_string() {
  Serial.print("Received string: ");
  char string[RCSwitchMaximumByteNumber + 1];
  mySwitch.getReceivedString(string, RCSwitchMaximumByteNumber + 1);
  Serial.println(string);
}

void print_received_delay() {
  Serial.print("Received delay: ");
  Serial.println(mySwitch.getReceivedDelay());
}   

void print_received_protocol() {
  Serial.print("Protocol: ");
  Serial.println(mySwitch.getReceivedProtocol());
}
