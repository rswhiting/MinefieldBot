#ifndef __H_SENSOR_CONTROLLER__
#define __H_SENSOR_CONTROLLER__
#include <Bounce.h>
extern HardwareSerial Serial;

class SensorController {
private:
    Bounce rightWhisker;
    Bounce leftWhisker;
public:

    enum WhichSensors {
        LEFT, RIGHT, BOTH, NONE
    };

    SensorController() : rightWhisker(14, 50), leftWhisker(15, 50)
    {
        Serial.println("Initializing SensorController");
    }

    WhichSensors triggered() {
        rightWhisker.update();
        leftWhisker.update();
        int right = rightWhisker.read();
        int left = leftWhisker.read();
        if (right == LOW && left != LOW)
            return RIGHT;
        if (right != LOW && left == LOW)
            return LEFT;
        if (right == LOW && left == LOW)
            return BOTH;
        else
            return NONE;
    }

};

#endif

