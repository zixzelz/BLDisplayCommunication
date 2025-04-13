#include "ValueEvent.h"

ValueEvent::ValueEvent(JsonObject& json) {
  fromJson(json);
}

ValueEvent::ValueEvent(float value)
    : value(value) {
}

void ValueEvent::toJson(JsonObject& json) const {
  json["value"] = value;
}

void ValueEvent::fromJson(JsonObject& json) {
  if (json["value"].is<float>()) {
    value = json["value"].as<float>();
  }
}