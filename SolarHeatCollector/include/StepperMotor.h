#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include <Stepper.h>

class StepperMotor {
private:
    int stepsPerRevolution; // Number of steps for one full revolution
    int pin1, pin2, pin3, pin4; // Motor control pins
    Stepper motor;

public:
    StepperMotor(int steps, int p1, int p3, int p2, int p4);

    void initialize();
    void rotateByDegrees(float degrees, int rpm); // Rotate motor by specific degrees with a given rpm
};

#endif
