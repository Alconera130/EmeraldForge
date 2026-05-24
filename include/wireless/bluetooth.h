#pragma once
#include <Arduino.h>

#include "BluetoothSerial.h"

extern BluetoothSerial SerialBT;

void bluetooth(String command = "");
void readBLT();