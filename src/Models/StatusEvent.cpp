#include "StatusEvent.h"

StatusEvent::StatusEvent(JsonObject& json) {
  fromJson(json);
}

StatusEvent::StatusEvent(StatusType status)
    : status(status) {
}

void StatusEvent::toJson(JsonObject& json) const {
  json["status"] = static_cast<int>(status);
}

void StatusEvent::fromJson(JsonObject& json) {
  if (json["status"].is<int>()) {
    status = static_cast<StatusType>(json["status"].as<int>());
  }
}