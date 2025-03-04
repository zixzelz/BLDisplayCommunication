#pragma once

#include "../Codable/JsonSerializer.h"

enum class CommandEventID : int {
  lightStatus = 0,
  fanStatus = 1,
  printerStatus = 2,
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