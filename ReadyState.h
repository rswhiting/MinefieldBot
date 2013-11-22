#ifndef __H_READY_STATE__
#define __H_READY_STATE__

#include <Arduino.h>
#include "BotState.h"
#include "GoState.h"
#include "BotRunner.h"
extern HardwareSerial Serial;

class ReadyState :
public BotState {
private:
    static const long MIN_READY_TIME = 1000;
    unsigned long timer;
public:

    ReadyState(BotRunner *b) : BotState(b) {
        Serial.println("Entering Ready State");
        context->getMotorController().setRunModes(MotorController::ALL, RELEASE);
        timer = millis() + MIN_READY_TIME;
    }

    virtual ~ReadyState() {
    }

    void run() {
        if (millis() > timer && context->getSensorController().goTriggered()) {
            Serial.println("Ready State: ok, let's go!");
            moveToGoState();
        }
    }

    void moveToGoState() {
        context->setState(new GoState(context));
        delete this;
    }
};

#endif



