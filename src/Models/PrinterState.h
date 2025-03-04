#pragma once

enum class PrinterState {
  disconnected = 0,
  idle = 1,
  printing = 2,
  no_lights = 3,
  error = 4,
  warning = 5
};

const char* pinterStateToString(PrinterState mode);