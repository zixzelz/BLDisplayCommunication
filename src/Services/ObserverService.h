#pragma once

#include "../Models/StatusEvent.h"
#include "../Models/PrinterStateEvent.h"
#include "../Models/ValueEvent.h"
#include "../Models/EmptyEvent.h"
#include "functional"

class ObserverService {
 public:
  using StatusEventCallback = std::function<void(StatusEvent statusEvent)>;
  using PrinterStateEventCallback = std::function<void(PrinterStateEvent statusEvent)>;
  using ValueEventCallback = std::function<void(ValueEvent vakueEvent)>;
  using EmptyEventCallback = std::function<void(EmptyEvent event)>;

 public:
  virtual void subscribeToLightStatus(StatusEventCallback callback) = 0;
  virtual void subscribeToFanStatus(StatusEventCallback callback) = 0;
  virtual void subscribeToPrinterStatusEvent(PrinterStateEventCallback callback) = 0;
  virtual void subscribeToTemperatureEvent(ValueEventCallback callback) = 0;
  virtual void subscribeToRefreshEvent(EmptyEventCallback callback) = 0;
};  // class ObserverService