#pragma once

#include "ObserverService.h"
#include "../TransferServices/TransferService.h"
#include "../Models/StatusEvent.h"
#include "functional"

class JSONObserverService final : public ObserverService, public TransferServiceDelegate {
 public:
  // using StatusEventCallback = std::function<void(StatusEvent statusEvent)>;

 public:
  JSONObserverService(TransferService* transferLayer);

  void subscribeToFanStatus(StatusEventCallback callback) override;
  void subscribeToLightStatus(StatusEventCallback callback) override;
  void subscribeToPrinterStatusEvent(PrinterStateEventCallback callback) override;
  void subscribeToTemperatureEvent(ValueEventCallback callback) override;
  void subscribeToRefreshEvent(EmptyEventCallback callback) override;

 private:
  StatusEventCallback fanStatusCallback_;
  StatusEventCallback lightStatusCallback_;
  PrinterStateEventCallback printerStatusCallback_;
  ValueEventCallback temperatureCallback_;
  EmptyEventCallback emptyCallback_;
  void didReceive(const String data) override;
};  // class JSONObserverService