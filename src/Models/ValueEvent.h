#pragma once

#include "../Codable/JsonSerializer.h"
#include "ValueEvent.h"

struct ValueEvent : public JsonSerializable {
  float value;

  ValueEvent(JsonObject& json);
  ValueEvent(float value);

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};