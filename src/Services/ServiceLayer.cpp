#include "ServiceLayer.h"

ServiceLayer::ServiceLayer(TransferService* transferService)
    : transferService(transferService) {
  printf("transferService address: %p\n", transferService);
}

void ServiceLayer::sendLightStatus(StatusType status) {
  sendStatus(CommandEventID::lightStatus, status);
}

void ServiceLayer::sendFanStatus(StatusType status) {
  sendStatus(CommandEventID::fanStatus, status);
}

void ServiceLayer::sendPrinterState(PrinterState printerState) {
  PrinterStateEvent event(printerState);
  JsonDocument valueEventJsonDoc = event.toJsonDocument();
  JsonObject eventJsonObj = valueEventJsonDoc.as<JsonObject>();

  CommandEvent commandEvent(CommandEventID::printerState, eventJsonObj);
  String jsonString = commandEvent.toJsonString();

  sendEventString(jsonString);
}

void ServiceLayer::sendTemperatureValue(float value) {
  ValueEvent valueEvent(value);
  sendValueEvent(valueEvent);
}

void ServiceLayer::sendValueEvent(ValueEvent value) {
  JsonDocument valueEventJsonDoc = value.toJsonDocument();
  JsonObject statusEventJsonObj = valueEventJsonDoc.as<JsonObject>();

  CommandEvent event(CommandEventID::temperatureStatus, statusEventJsonObj);
  String jsonString = event.toJsonString();
  printf("Serialized JSON: %s\n", jsonString.c_str());

  if (!transferService) {
    printf("Error: transferLayer is nullptr!\n");
    return;
  }

  transferService->send(jsonString);
}

void ServiceLayer::sendStatus(CommandEventID cmdID, StatusType status) {
  printf("transferService address: %p\n", transferService);

  StatusEvent statusEvent(status);
  JsonDocument statusEventJsonDoc = statusEvent.toJsonDocument();
  JsonObject statusEventJsonObj = statusEventJsonDoc.as<JsonObject>();

  CommandEvent event(cmdID, statusEventJsonObj);
  String jsonString = event.toJsonString();
  printf("Serialized JSON: %s\n", jsonString.c_str());

  if (!transferService) {
    printf("Error: transferLayer is nullptr!\n");
    return;
  }

  transferService->send(jsonString);
}

void ServiceLayer::sendEventString(String jsonString) {
  printf("Serialized JSON: %s\n", jsonString.c_str());

  if (!transferService) {
    printf("Error: transferLayer is nullptr!\n");
    return;
  }

  transferService->send(jsonString);
}