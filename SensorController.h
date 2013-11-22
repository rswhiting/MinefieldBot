#ifndef __H_SENSOR_CONTROLLER__
#define __H_SENSOR_CONTROLLER__
#include <Bounce.h>

class SensorController {
private:
    static const int RIGHT_WHISKER = 14;
    static const int LEFT_WHISKER = 15;
    static const int GO_BUTTON = 16;
    Bounce goButton;
    //    Bounce rightWhisker;
    //    Bounce leftWhisker;
public:

    enum WhichSensors {
        RIGHT, LEFT, BOTH, NONE
    };

    SensorController();

    WhichSensors whiskerTriggered();

    bool goTriggered();

};

#endif

