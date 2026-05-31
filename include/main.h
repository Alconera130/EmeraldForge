#pragma once

#include "BluetoothSerial.h"

extern BluetoothSerial SerialBT;

extern const int pHSensor;
extern const int turbiditySensor;
extern const int activatePump;
extern const int activateSensors;
extern bool isDeepSleepEnabled;

extern float previousMillis;
extern float harvestMillis;

extern String command;
extern String incoming;