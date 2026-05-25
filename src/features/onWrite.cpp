#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"
#include "features/features.h"

void CommandCallbacks::onWrite(NimBLECharacteristic* pCharacteristic) {

    std::string value = pCharacteristic->getValue();

    if (value.empty()) return;

    String incoming = String(value.c_str());
    incoming.trim();

    command = incoming;

    Serial.println("CMD: " + command);
}