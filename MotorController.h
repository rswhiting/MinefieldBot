#ifndef __H_MOTOR_CONTROLLER__
#define __H_MOTOR_CONTROLLER__

#include <Arduino.h>
#include <AFMotor.h>

class MotorController {
private:
    AF_DCMotor motor_br;
    AF_DCMotor motor_bl;
    AF_DCMotor motor_fl;
    AF_DCMotor motor_fr;
public:

    enum WhichMotors {
        LEFT, RIGHT, ALL
    };

    MotorController();

    void setSpeeds(WhichMotors w, uint8_t spd);
    void setRunModes(WhichMotors w, uint8_t mode);
};

#endif


