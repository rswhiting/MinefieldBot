#include "GoState.h"
#include "BotRunner.h"
#include "MotorController.h"
#include "TurnState.h"
#include "ReadyState.h"

GoState::GoState(BotRunner *b) : BotState(b) {
    Serial.println("Entering Go State: all engines ahead full");
    timer = millis() + MIN_GO_TIME;
    context->getMotorController().setRunModes(MotorController::ALL, FORWARD);
}

void GoState::run() {
    // check sensors
    if(context->getSensorController().whiskerTriggered() != SensorController::NONE)
    {
        context->setState(new TurnState(context));
        delete this;
    }
    if(millis() > timer && context->getSensorController().goTriggered()) {
        context->setState(new ReadyState(context));
        delete this;
    }
}
