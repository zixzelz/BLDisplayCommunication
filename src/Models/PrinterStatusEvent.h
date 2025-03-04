#pragma once

#include "../Codable/JsonSerializer.h"
#include "PrinterState.h"

struct PrinterStatusEvent : public JsonSerializable {
  PrinterState state;
  int ambientTemp;

  PrinterStatusEvent(JsonObject& json);
  PrinterStatusEvent(PrinterState state, int ambientTemp);

 protected:
  void toJson(JsonObject& json) const override;
  void fromJson(JsonObject& json) override;
};