#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"
#include "sensors/sensors.h"

#include "features/features.h"

BluetoothSerial SerialBT;

void bluetooth() {
    if (SerialBT.hasClient()) {
        readLine();

        activateHarvest();
        toggleDeepSleep();
        sendData();
    }
}