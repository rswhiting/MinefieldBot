#ifndef __H_READY_STATE__
#define __H_READY_STATE__

#include <Arduino.h>
#include "BotState.h"
#include "GoState.h"
#include "BotRunner.h"
extern HardwareSerial Serial;

class ReadyState :
public BotState {
public:

    ReadyState(BotRunner *b) : BotState(b) {
        Serial.println("Entering Ready State");
    }

    virtual ~ReadyState() {
    }

    void run() {
        Serial.println("Nothing to do in Ready State");
        moveToGoState();
    }

    void moveToGoState() {
        context->setState(new GoState(context));
        delete this;
    }
};

#endif



