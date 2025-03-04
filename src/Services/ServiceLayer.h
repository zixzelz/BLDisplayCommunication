#pragma once

#include "../TransferServices/TransferService.h"
#include "../Codable/JsonSerializer.h"
#include "../Models/CommandEvent.h"
#include "../Models/StatusEvent.h"

class ServiceLayer {
 public:
  ServiceLayer(TransferService* transferService);

  void sendLightStatus(StatusType status);
  void sendFanStatus(StatusType status);

 private:
  TransferService* transferService;

  void sendStatus(CommandEventID cmdID, StatusType status);
};  // class ServiceLayer