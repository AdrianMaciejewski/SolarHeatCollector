#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include <TMCStepper.h>

// TMC2208 Pin Configuration
#define DIR_PIN 5
#define STEP_PIN 6
#define ENABLE_PIN 7
#define R_SENSE 0.11f // Sense resistor value for TMC2208

extern TMC2208Stepper driver;

void initializeStepperMotor();
void moveStepperClockwise(int steps);
void moveStepperCounterClockwise(int steps);

#endif
