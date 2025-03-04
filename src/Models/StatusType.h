#pragma once

#include <cstdint>

enum class StatusType : uint8_t {
  On = 0,
  Off = 1,
  Auto = 2,
  Invalid = 255  // Fallback for invalid values
};

// Button names, matching StatusType values (null-terminated)
extern const char* StatusType_map[];

// Convert string to StatusType
int statusTypeRawValue(StatusType mode);
StatusType statusTypefromRawValue(int value);