#include "TurnState.h"
#include "BotRunner.h"
#include "MotorController.h"
#include "GoState.h"

TurnState::TurnState(BotRunner* b) : BotState(b), lastSensor(SensorController::RIGHT),
subStateTimer(0), subState(HALT) {
    Serial.println("Entering Turn State");
    SensorController::WhichSensors sensor = context->getSensorController().whiskerTriggered();
    Serial.print("Triggered on: ");
    switch (sensor) {
        case SensorController::RIGHT: Serial.println("Right");
            break;
        case SensorController::LEFT: Serial.println("Left");
            break;
        case SensorController::BOTH: Serial.println("Both");
            break;
        case SensorController::NONE: Serial.println("None");
            break;
    }
    // Keep the last r/l sensor recording, both/none doesn't help with directions
    if(sensor == SensorController::RIGHT || sensor == SensorController::LEFT)
        lastSensor = sensor;
}

void TurnState::run() {
    if (millis() > subStateTimer) {
        Serial.print(millis());
        Serial.print(" ");
        switch (subState) {
            case HALT:
                Serial.println("Halting all engines");
                context->getMotorController().setRunModes(MotorController::ALL, RELEASE);
                subStateTimer = millis() + HALT_TIME;
                subState = BACK;
                break;
            case BACK:
                Serial.println("Backing up");
                context->getMotorController().setRunModes(MotorController::ALL, BACKWARD);
                subStateTimer = millis() + BACK_TIME;
                subState = TURN;
                break;
            case TURN:
                Serial.println("Turning");
                if (lastSensor == SensorController::RIGHT) {
                    context->getMotorController().setRunModes(MotorController::RIGHT, FORWARD);
                    context->getMotorController().setRunModes(MotorController::LEFT, BACKWARD);
                } else {
                    context->getMotorController().setRunModes(MotorController::RIGHT, BACKWARD);
                    context->getMotorController().setRunModes(MotorController::LEFT, FORWARD);
                }
                subStateTimer = millis() + TURN_TIME;
                subState = DONE;
                break;
            case DONE:
                Serial.println("Done turning");
                context->getMotorController().setRunModes(MotorController::ALL, RELEASE);
                context->setState(new GoState(context));
                delete this;
        }
    }
}
