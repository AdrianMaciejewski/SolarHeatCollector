#ifndef SHADERCONTROLLER_H
#define SHADERCONTROLLER_H

#include "StepperMotor.h"

class ShaderController {
private:
    StepperMotor& motor;    // Reference to the StepperMotor instance
    float currentAngle;     // Current angle of the shades
    float minAngle;         // Minimum angle (fully closed)
    float maxAngle;         // Maximum angle (fully open)
    int speed;              // Speed in RPM

    float calculateAngle(float openness); // Helper to calculate angle from openness

public:
    ShaderController(StepperMotor& motor, float minAngle, float maxAngle, int speed);

    void setShadeOpenness(float openness); // Set openness (0.0 to 1.0)
    float getCurrentOpenness() const;      // Get current openness (0.0 to 1.0)
};

#endif
