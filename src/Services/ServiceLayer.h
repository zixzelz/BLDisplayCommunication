#pragma once

#include "../TransferServices/TransferService.h"
#include "../Codable/JsonSerializer.h"
#include "../Models/CommandEvent.h"
#include "../Models/StatusEvent.h"
#include "../Models/ValueEvent.h"

class ServiceLayer {
 public:
  ServiceLayer(TransferService* transferService);

  void sendLightStatus(StatusType status);
  void sendFanStatus(StatusType status);

  void sendTemperatureValue(float value);

 private:
  TransferService* transferService;

  void sendValueEvent(ValueEvent value);
  void sendStatus(CommandEventID cmdID, StatusType status);
};  // class ServiceLayer