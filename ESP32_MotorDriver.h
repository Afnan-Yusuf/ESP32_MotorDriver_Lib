// MotorController.h



#ifndef MotorController_h
#define MotorController_h
#include <arduino.h>

class MotorController {
private:
    int motLF, motLB, motRF, motRB;
    int freqm = 500; // PWM frequency
    int resolution = 8; // PWM resolution
    int mrfc = 4; // Motor Right Forward Channel
    int mrbc = 4; // Motor Right Backward Channel
    int mlfc = 7; // Motor Left Forward Channel
    int mlbc = 7; // Motor Left Backward Channel
    int defaultSpeed = 100;

public:

    MotorController(int leftForward = 13, int leftBackward = 12, int rightForward = 25, int rightBackward = 33);
    void initialize();
    void stop();
    void forward(int speed);
    void backward(int speed);
    void turnLeft(int speed);
    void turnRight(int speed);
    void leftMotorForward(int speed);
    void leftMotorBackward(int speed);
    void rightMotorForward(int speed);
    void rightMotorBackward(int speed);
    void setFrequency(int pwmFrequency);
    void setResolution(int pwmResolution);
    void setDefaultSpeed(int defaultSpeed);
};

#endif