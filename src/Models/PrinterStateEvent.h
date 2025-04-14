#pragma once

#include "../Codable/JsonSerializer.h"
#include "PrinterState.h"

struct PrinterStateEvent : public JsonSerializable {
  PrinterState state;

  PrinterStateEvent(JsonObject& json);
  PrinterStateEvent(PrinterState state);

  bool operator==(const PrinterStateEvent& other) const {
    return state == other.state;
  }

  bool operator!=(const PrinterStateEvent& other) const {
    return !(*this == other);
  }

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};