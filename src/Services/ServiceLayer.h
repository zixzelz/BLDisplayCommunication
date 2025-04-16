#pragma once

#include "../TransferServices/TransferService.h"
#include "../Codable/JsonSerializer.h"
#include "../Models/CommandEvent.h"
#include "../Models/StatusEvent.h"
#include "../Models/PrinterStateEvent.h"
#include "../Models/ValueEvent.h"
#include "../Models/EmptyEvent.h"

class ServiceLayer {
 public:
  ServiceLayer(TransferService* transferService);

  void sendLightStatus(StatusType status);
  void sendFanStatus(StatusType status);
  void sendPrinterState(PrinterState printerState);

  void sendTemperatureValue(float value);

  void sendRequestRefresh();

 private:
  TransferService* transferService;

  void sendValueEvent(ValueEvent value);
  void sendStatus(CommandEventID cmdID, StatusType status);
  void sendEventString(String jsonString);
};  // class ServiceLayer