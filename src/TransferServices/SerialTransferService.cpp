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
    printf("0 \n");
    String incomingByte = Serial.readStringUntil('\n');
    printf("1 \n");
    delegate->didReceive(incomingByte);
  }
}

void SerialTransferService::send(const String data) {
  Serial.println(data);
}

#endif