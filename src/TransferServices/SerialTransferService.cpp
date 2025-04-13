#ifdef ARDUINO

#include "SerialTransferService.h"
#include <Arduino.h>

SerialTransferService::SerialTransferService(uint8_t rxPin, uint8_t txPin) {
  setup(rxPin, txPin);
}

void SerialTransferService::setupDelegate(TransferServiceDelegate* delegate) {
  this->delegate = delegate;
}

void SerialTransferService::setup(uint8_t rxPin, uint8_t txPin) {
  Serial.begin(115200);
}

void SerialTransferService::loop() {
  if (Serial.available() > 0) {
    printf("[SerialTransferService] receive string \n");
    String incomingByte = Serial.readStringUntil('\n');

    // Check if the message starts with ">>"
    if (incomingByte.startsWith(">>")) {
      printf("[SerialTransferService] process string \n");
      // Remove the ">>" prefix
      incomingByte = incomingByte.substring(2);
      delegate->didReceive(incomingByte);
    }
  }
}

void SerialTransferService::send(const String data) {
  String modifiedData = ">>" + data;
  Serial.println(modifiedData);
}

#endif