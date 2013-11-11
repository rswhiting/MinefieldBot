#include "MotorController.h"
extern HardwareSerial Serial;

MotorController::MotorController() : motor_br(1), motor_bl(2), motor_fl(3), motor_fr(4) {
    Serial.println("Initializing MotorController");
    setSpeeds(ALL, 255);
    setRunModes(ALL, RELEASE);
}

void MotorController::setSpeeds(WhichMotors w, uint8_t spd) {
    switch (w) {
        case LEFT:
            motor_bl.setSpeed(spd);
            motor_fl.setSpeed(spd);
            break;
        case RIGHT:
            motor_br.setSpeed(spd);
            motor_fr.setSpeed(spd);
            break;
        case ALL:
        default:
            motor_br.setSpeed(spd);
            motor_bl.setSpeed(spd);
            motor_fl.setSpeed(spd);
            motor_fr.setSpeed(spd);
    }
}

void MotorController::setRunModes(WhichMotors w, uint8_t mode) {
    switch (w) {
        case LEFT:
            motor_bl.run(mode);
            motor_fl.run(mode);
            break;
        case RIGHT:
            motor_br.run(mode);
            motor_fr.run(mode);
            break;
        case ALL:
        default:
            motor_br.run(mode);
            motor_bl.run(mode);
            motor_fl.run(mode);
            motor_fr.run(mode);
    }
}