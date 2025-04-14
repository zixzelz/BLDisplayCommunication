#include "PrinterStateEvent.h"

PrinterStateEvent::PrinterStateEvent(JsonObject& json) {
  fromJson(json);
}

PrinterStateEvent::PrinterStateEvent(PrinterState state)
    : state(state) {
}

void PrinterStateEvent::toJson(JsonObject& json) const {
  json["state"] = static_cast<int>(state);
}

void PrinterStateEvent::fromJson(JsonObject& json) {
  if (json["status"].is<int>()) {
    state = static_cast<PrinterState>(json["state"].as<int>());
  }
}