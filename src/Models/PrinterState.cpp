#include "PrinterState.h"
#include <cstdint>

const char* PinterStateMap[] = {"Disconnected", "idle", "Printing", "No lights", "Error", "Warning", nullptr};

// Convert PinterState to a string
const char* pinterStateToString(PrinterState mode) {
  int index = static_cast<int>(mode);
  return (index >= 0 && index < 6) ? PinterStateMap[index] : "Invalid";
}