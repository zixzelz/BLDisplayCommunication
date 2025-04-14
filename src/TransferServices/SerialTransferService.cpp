#ifdef ARDUINO

#include "SerialTransferService.h"
#include <Arduino.h>

SerialTransferService::SerialTransferService(uint8_t rxPin, uint8_t txPin) {
  setup(rxPin, txPin);
}

SerialTransferService::SerialTransferService(HardwareSerial& serial) {
  setup(serial);
}

void SerialTransferService::setupDelegate(TransferServiceDelegate* delegate) {
  this->delegate = delegate;
}

void SerialTransferService::setup(uint8_t rxPin, uint8_t txPin) {
  Serial2.begin(115200, SERIAL_8N1, rxPin, txPin);
  hwSerial = &Serial2;
}

void SerialTransferService::setup(HardwareSerial& serial) {
  hwSerial = &serial;
}

void SerialTransferService::loop() {
  if (hwSerial->available() > 0) {
    printf("[SerialTransferService] receive string \n");
    String incomingByte = hwSerial->readStringUntil('\n');

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
  Serial.println("log: " + data);

  String modifiedData = ">>" + data;
  hwSerial->println(modifiedData);
}

#endif