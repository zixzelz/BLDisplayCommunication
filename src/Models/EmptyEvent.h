#pragma once

#include "../Codable/JsonSerializer.h"

struct EmptyEvent : public JsonSerializable {
  EmptyEvent(JsonObject& json);
  EmptyEvent();

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};