#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "ShaderController.h"

class PIDController {
private:
    ShaderController& shaderController;

    float targetTemperature;  // Desired temperature
    float currentTemperature; // Current temperature

    float previousError;      // Error from the previous cycle
    float integral;           // Accumulated integral term

    // PID coefficients
    float Kp;                 // Proportional gain
    float Ki;                 // Integral gain
    float Kd;                 // Derivative gain

    unsigned long lastUpdateTime; // Time of the last PID calculation

public:
    PIDController(ShaderController& shaderController, int targetTemperature, float Kp, float Ki, float Kd);

    float calculateSmoothedMeasurement(float measurement);
    void update(float currentTemperature, unsigned long currentTime);        // Run PID control loop
};

#endif
