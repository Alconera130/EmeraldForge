#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"

#include "features/features.h"

void ServerCallbacks::onConnect(NimBLEServer* pServer) {
    isDeviceConnected = true;
    Serial.println("SCADA CLIENT CONNECTED");
}

void ServerCallbacks::onDisconnect(NimBLEServer* pServer) {
    isDeviceConnected = false;

    Serial.println("SCADA CLIENT DISCONNECTED");

    NimBLEDevice::startAdvertising();
}

void bluetooth() {
    if (isDeviceConnected) {
        activateHarvest();
        toggleDeepSleep();
        sendData();
    }
}