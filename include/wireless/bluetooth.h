#pragma once
#include <Arduino.h>

#include <NimBLEDevice.h>

extern NimBLEServer *pServer;
extern NimBLECharacteristic* pCharacteristic;

void bluetooth();

class CommandCallbacks : public NimBLECharacteristicCallbacks {
public:
    void onWrite(NimBLECharacteristic* pCharacteristic);
};

class ServerCallbacks : public NimBLEServerCallbacks {
public:
    void onConnect(NimBLEServer* pServer);
    void onDisconnect(NimBLEServer* pServer);
};