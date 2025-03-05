#pragma once

#include "../Codable/JsonSerializer.h"
#include "PrinterState.h"

struct PrinterStatusEvent : public JsonSerializable {
  PrinterState state;
  int ambientTemp;

  PrinterStatusEvent(JsonObject& json);
  PrinterStatusEvent(PrinterState state, int ambientTemp);

  bool operator==(const PrinterStatusEvent& other) const {
    return state == other.state && ambientTemp == other.ambientTemp;
  }

  bool operator!=(const PrinterStatusEvent& other) const {
    return !(*this == other);
  }

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};