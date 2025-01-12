#include "StepperMotor.h"
#include <Arduino.h>

// Constructor
StepperMotor::StepperMotor(int steps, int p1, int p2, int p3, int p4)
    : stepsPerRevolution(steps), pin1(p1), pin2(p2), pin3(p3), pin4(p4), motor(steps, p1, p3, p2, p4) {} // the correct order of motor pins is 1,3,2,4

// Initialize the stepper motor
void StepperMotor::initialize() {
    Serial.println("Stepper Motor Ready");
}

// Rotate motor by a specific number of degrees with a given speed
void StepperMotor::rotateByDegrees(float degrees, int rpm) {
    motor.setSpeed(rpm); // Set the speed of the motor in RPM
    int steps = (stepsPerRevolution / 360.0) * degrees; // Calculate the number of steps for the given degrees
    Serial.println("[DEBUG] Rotating " + String(degrees) + " degrees at " + String(rpm) + " RPM.");
    motor.step(steps);
}
