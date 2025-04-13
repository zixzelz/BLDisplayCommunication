#pragma once

#include "../Models/StatusEvent.h"
#include "../Models/PrinterStatusEvent.h"
#include "../Models/ValueEvent.h"
#include "functional"

class ObserverService {
 public:
  using StatusEventCallback = std::function<void(StatusEvent statusEvent)>;
  using PrinterStatusEventCallback = std::function<void(PrinterStatusEvent statusEvent)>;
  using ValueEventCallback = std::function<void(ValueEvent statusEvent)>;

 public:
  virtual void subscribeToLightStatus(StatusEventCallback callback) = 0;
  virtual void subscribeToFanStatus(StatusEventCallback callback) = 0;
  virtual void subscribeToPrinterStatusEvent(PrinterStatusEventCallback callback) = 0;
  virtual void subscribeToTemperatureEvent(ValueEventCallback callback) = 0;
};  // class ObserverService