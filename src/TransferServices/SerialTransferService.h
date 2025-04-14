#pragma once

#ifdef ARDUINO

#include "TransferService.h"

class SerialTransferService final : public TransferService {
 public:
  SerialTransferService(HardwareSerial& serial);
  SerialTransferService(uint8_t rxPin, uint8_t txPin);

  void setupDelegate(TransferServiceDelegate* delegate);
  void loop();
  void send(const String data);

 private:
  HardwareSerial* hwSerial = nullptr;
  TransferServiceDelegate* delegate;

  void setup(HardwareSerial& serial);
  void setup(uint8_t rxPin, uint8_t txPin);
};

#endif