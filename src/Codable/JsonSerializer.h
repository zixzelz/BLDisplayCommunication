#pragma once

#include "../global.h"
#include <ArduinoJson.h>

class JsonSerializable {
 public:
  virtual ~JsonSerializable() = default;

  // Convert object to a JSON
  JsonDocument toJsonDocument() const;

  // Convert object to a JSON string
  String toJsonString() const;

  // Populate object from a JSON string
  bool fromJsonString(const String& jsonString);

 protected:
  // Convert object to JSON
  virtual void toJson(JsonObject& json) const = 0;

  // Populate object from JSON
  virtual void fromJson(JsonObject& json) = 0;
};