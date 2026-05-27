#include <Arduino.h>

#include "wireless/bluetooth.h"
#include "main.h"
#include "features/features.h"

void onWrite() {
    while (SerialBT.available()) {
        char c = SerialBT.read();

        if (c == '\n') {
            command = incoming;
            incoming = "";
        } else {
            incoming += c;
        }
    }
}