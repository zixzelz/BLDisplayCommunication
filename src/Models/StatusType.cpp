#include "StatusType.h"

// Define the array in one place
const char* StatusType_map[] = {"On", "Off", "Auto", nullptr};

int statusTypeRawValue(StatusType mode) {
  int index = static_cast<int>(mode);
  return index;
}

// Convert StatusType to a string
// constexpr const char* toString(StatusType mode) {
//   int index = static_cast<int>(mode);
//   return (index >= 0 && index < 3) ? btnm_map[index] : "Invalid";
// }

// Convert string to StatusType
// StatusType fromString(const char* str) {
//   for (size_t i = 0; btnm_map[i] != nullptr; ++i) {
//     if (strcmp(btnm_map[i], str) == 0) {
//       return static_cast<StatusType>(i);
//     }
//   }
//   return StatusType::Invalid;
// }

// Convert int to StatusType (safe conversion)
StatusType statusTypefromRawValue(int value) {
  return (value >= 0 && value <= 2) ? static_cast<StatusType>(value) : StatusType::Invalid;
}
