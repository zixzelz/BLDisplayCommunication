#include "PrinterStatusEvent.h"

PrinterStatusEvent::PrinterStatusEvent(JsonObject& json) {
  fromJson(json);
}

PrinterStatusEvent::PrinterStatusEvent(PrinterState state, int ambientTemp)
    : state(state), ambientTemp(ambientTemp) {
}

void PrinterStatusEvent::toJson(JsonObject& json) const {
  json["state"] = static_cast<int>(state);
  json["ambientTemp"] = ambientTemp;
}

void PrinterStatusEvent::fromJson(JsonObject& json) {
  if (json["status"].is<int>()) {
    state = static_cast<PrinterState>(json["state"].as<int>());
  }
  if (json["ambientTemp"].is<int>()) {
    ambientTemp = json["ambientTemp"].as<int>();
  }
}