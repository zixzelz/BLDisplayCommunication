#include "CommandEvent.h"
#include "StatusType.h"

CommandEvent::CommandEvent() {
}

// Parameterized constructor
CommandEvent::CommandEvent(CommandEventID id, JsonDocument eventJsonDocument)
    : id(id), eventJsonDocument(eventJsonDocument) {
}
// Convert object to JSON
void CommandEvent::toJson(JsonObject& json) const {
  json["id"] = static_cast<int>(id);
  json["event"] = eventJsonDocument.as<JsonObjectConst>();
}

// Populate object from JSON
void CommandEvent::fromJson(JsonObject& json) {
  if (json["id"].is<int>()) {
    id = static_cast<CommandEventID>(json["id"].as<int>());
  }
  if (json["event"].is<JsonObject>()) {
    JsonObject jsonObject = json["event"].as<JsonObject>();
    eventJsonDocument = JsonDocument();
    eventJsonDocument.set(jsonObject);
  }
}