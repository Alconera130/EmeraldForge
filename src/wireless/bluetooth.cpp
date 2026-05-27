#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"

#include "features/features.h"

void bluetooth() {
    onWrite();

    activateHarvest();
    toggleDeepSleep();
    sendData();
}