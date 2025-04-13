#include "PrinterStateEvent.h"

PrinterStateEvent::PrinterStateEvent(JsonObject& json) {
  fromJson(json);
}

PrinterStateEvent::PrinterStateEvent(PrinterState state, int ambientTemp)
    : state(state), ambientTemp(ambientTemp) {
}

void PrinterStateEvent::toJson(JsonObject& json) const {
  json["state"] = static_cast<int>(state);
  json["ambientTemp"] = ambientTemp;
}

void PrinterStateEvent::fromJson(JsonObject& json) {
  if (json["status"].is<int>()) {
    state = static_cast<PrinterState>(json["state"].as<int>());
  }
  if (json["ambientTemp"].is<int>()) {
    ambientTemp = json["ambientTemp"].as<int>();
  }
}