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
    PIDController(ShaderController& shaderController, float Kp, float Ki, float Kd);

    void setTargetTemperature(float temperature); // Set desired temperature
    void update(float currentTemperature);        // Run PID control loop
};

#endif
