#include "EmptyEvent.h"

EmptyEvent::EmptyEvent(JsonObject& json) {
  fromJson(json);
}

EmptyEvent::EmptyEvent() {
}

void EmptyEvent::toJson(JsonObject& json) const {
}

void EmptyEvent::fromJson(JsonObject& json) {
}