#pragma once

#include "../Codable/JsonSerializer.h"

enum class CommandEventID : int {
  lightStatus = 0,
  fanStatus = 1,
  printerState = 2,
  temperatureStatus = 3,
  refresh = 250,
  Invalid = 255
};

class CommandEvent : public JsonSerializable {
 public:
  CommandEventID id;
  JsonDocument eventJsonDocument;

  CommandEvent();
  CommandEvent(CommandEventID id, JsonDocument eventJsonDocument);

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};  // class CommandEvent