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
  void subscribeToPrinterStatusEvent(PrinterStatusEventCallback callback) override;

 private:
  StatusEventCallback fanStatusCallback_;
  StatusEventCallback lightStatusCallback_;
  PrinterStatusEventCallback printerStatusCallback_;
  void didReceive(const String data) override;
};  // class JSONObserverService