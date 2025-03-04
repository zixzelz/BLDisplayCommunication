#include "JsonObserverService.h"
#include "../Models/CommandEvent.h"

JSONObserverService::JSONObserverService(TransferService* transferLayer) {
  transferLayer->setupDelegate(this);
}

void JSONObserverService::subscribeToLightStatus(StatusEventCallback callback) {
  lightStatusCallback_ = callback;
}

void JSONObserverService::subscribeToFanStatus(StatusEventCallback callback) {
  fanStatusCallback_ = callback;
}

void JSONObserverService::subscribeToPrinterStatusEvent(PrinterStatusEventCallback callback) {
  printerStatusCallback_ = callback;
}

void JSONObserverService::didReceive(const String data) {
  printf("2 \n");
  JsonDocument doc;
  deserializeJson(doc, data);

  CommandEvent event;
  event.fromJsonString(data);

  if (event.id == CommandEventID::fanStatus) {
    printf("3 \n");
    JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
    StatusEvent statusEvent(jsonObject);
    fanStatusCallback_(statusEvent);
  } else if (event.id == CommandEventID::lightStatus) {
    printf("JSONObserverService::didReceive: lightStatus \n");
    JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
    StatusEvent statusEvent(jsonObject);
    lightStatusCallback_(statusEvent);
  } else if (event.id == CommandEventID::printerStatus) {
    printf("JSONObserverService::didReceive: printerStatus \n");
    JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
    PrinterStatusEvent statusEvent(jsonObject);
    printerStatusCallback_(statusEvent);
  } else {
    printf("JSONObserverService::didReceive: Invalid CommandEventID: %i \n", static_cast<int>(event.id));
  }
}