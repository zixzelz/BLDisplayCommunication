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

void JSONObserverService::subscribeToTemperatureEvent(ValueEventCallback callback) {
  temperatureCallback_ = callback;
}

void JSONObserverService::didReceive(const String data) {
  CommandEvent event;
  event.fromJsonString(data);

  if (event.id == CommandEventID::fanStatus) {
    printf("3 \n");
    if (fanStatusCallback_ != nullptr) {
      JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
      StatusEvent statusEvent(jsonObject);
      fanStatusCallback_(statusEvent);
    }
  } else if (event.id == CommandEventID::lightStatus) {
    printf("JSONObserverService::didReceive: lightStatus \n");
    if (lightStatusCallback_ != nullptr) {
      JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
      StatusEvent statusEvent(jsonObject);
      lightStatusCallback_(statusEvent);
    }
  } else if (event.id == CommandEventID::printerStatus) {
    printf("JSONObserverService::didReceive: printerStatus \n");
    if (printerStatusCallback_ != nullptr) {
      JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
      PrinterStatusEvent statusEvent(jsonObject);
      printerStatusCallback_(statusEvent);
    }
  } else if (event.id == CommandEventID::temperatureStatus) {
    printf("JSONObserverService::didReceive: temperatureStatus \n");
    if (printerStatusCallback_ != nullptr) {
      JsonObject jsonObject = event.eventJsonDocument.as<JsonObject>();
      ValueEvent valueEvent(jsonObject);
      temperatureCallback_(valueEvent);
    }
  } else {
    printf("JSONObserverService::didReceive: Invalid CommandEventID: %i \n", static_cast<int>(event.id));
  }
}