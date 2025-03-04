#pragma once

#include "../Codable/JsonSerializer.h"
#include "StatusType.h"

struct StatusEvent : public JsonSerializable {
  StatusType status;

  StatusEvent(JsonObject& json);
  StatusEvent(StatusType status);

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};