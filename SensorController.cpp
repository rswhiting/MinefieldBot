#include "SensorController.h"
#include <Arduino.h>
extern HardwareSerial Serial;

SensorController::SensorController() : goButton(GO_BUTTON, 1000)/*: rightWhisker(14, 5), leftWhisker(15, 5) */ {
    Serial.println("Initializing SensorController");
    pinMode(RIGHT_WHISKER, INPUT);
    pinMode(LEFT_WHISKER, INPUT);
    pinMode(GO_BUTTON, INPUT);
}

SensorController::WhichSensors SensorController::whiskerTriggered() {
    //        rightWhisker.update();
    //        leftWhisker.update();
    //        int right = rightWhisker.read();
    //        int left = leftWhisker.read();
    int right = digitalRead(RIGHT_WHISKER);
    int left = digitalRead(LEFT_WHISKER);
    if (right == LOW && left != LOW)
        return RIGHT;
    if (right != LOW && left == LOW)
        return LEFT;
    if (right == LOW && left == LOW)
        return BOTH;
    else
        return NONE;
}

bool SensorController::goTriggered() {
    goButton.update();
    if (goButton.read() == HIGH)
        return true;
    else
        return false;
}