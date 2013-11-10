#ifndef __H_READY_STATE__
#define __H_READY_STATE__

#include <Arduino.h>
#include "BotState.h"
#include "GoState.h"
extern HardwareSerial Serial;

class ReadyState :
public BotState {
public:

    ReadyState() {
        Serial.println("Entering Ready State");
    }

    virtual ~ReadyState() {
    }

    void run(BotRunner *b) {
        Serial.println("Nothing to do in Ready State");
        moveToGoState(b);
    }

    void moveToGoState(BotRunner *b) {
        b->setState(new GoState());
        delete this;
    }
};

#endif



