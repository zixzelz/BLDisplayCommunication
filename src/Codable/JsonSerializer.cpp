#include "JsonSerializer.h"

// Convert object to a JSON
JsonDocument JsonSerializable::toJsonDocument() const {
  JsonDocument jsonDoc;
  JsonObject json = jsonDoc.to<JsonObject>();
  toJson(json);
  return jsonDoc;
}

// Convert object to a JSON string
String JsonSerializable::toJsonString() const {
  JsonDocument jsonDoc;
  JsonObject json = jsonDoc.to<JsonObject>();
  toJson(json);

  String output;
  serializeJson(jsonDoc, output);
  return output;
}

// Populate object from a JSON string
bool JsonSerializable::fromJsonString(const String& jsonString) {
  JsonDocument jsonDoc;

  DeserializationError error = deserializeJson(jsonDoc, jsonString);
  if (error) {
    printf("JSON Deserialization failed: %s\n", error.c_str());
    return false;
  }

  JsonObject json = jsonDoc.as<JsonObject>();
  fromJson(json);
  return true;
}
