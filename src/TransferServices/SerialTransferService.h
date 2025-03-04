#pragma once

#ifdef ARDUINO

#include "TransferService.h"

class SerialTransferService final : public TransferService {
 public:
  SerialTransferService(uint8_t rxPin, uint8_t txPin);

  void setupDelegate(TransferServiceDelegate* delegate);
  void loop();
  void send(const String data);

 private:
  TransferServiceDelegate* delegate;

  void setup(uint8_t rxPin, uint8_t txPin);
};

#endif