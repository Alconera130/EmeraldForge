#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"

#include "features/features.h"

void bluetooth() {
    if (!SerialBT.connected()) return;

    onWrite();

    activateHarvest();
    toggleDeepSleep();
    sendData();
}