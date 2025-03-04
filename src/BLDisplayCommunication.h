#include "TransferServices/TransferService.h"

#ifdef ARDUINO
#include "TransferServices/SerialTransferService.h"
#endif

#include "Services/ServiceLayer.h"

#include "Services/ObserverService.h"
#include "Services/JsonObserverService.h"