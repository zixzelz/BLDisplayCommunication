#pragma once

#include "../global.h"

class TransferServiceDelegate {
 public:
  virtual void didReceive(const String data) = 0;
};

class TransferService {
 public:
  virtual void setupDelegate(TransferServiceDelegate* delegate) = 0;
  virtual void send(const String data) = 0;
};