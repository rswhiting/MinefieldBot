#ifndef GOSTATE_H
#define	GOSTATE_H

#include <Arduino.h>
#include "BotState.h"
extern HardwareSerial Serial;

class GoState :
public BotState {
public:

    GoState() {
        Serial.println("Entering Go State");
    }

    void run(BotRunner *b) {
        Serial.println("Going...");
    }
};


#endif	/* GOSTATE_H */

