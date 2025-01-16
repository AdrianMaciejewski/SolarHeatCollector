#include "PIDController.h"
#include <Arduino.h>
#include <DataLogger.h>


// Constructor
PIDController::PIDController(ShaderController& shaderController, MeasurementSmoother& measurementSmoother, float Kp, float Ki, float Kd)
    : shaderController(shaderController), measurementSmoother(measurementSmoother), targetTemperature(0.0), currentTemperature(0.0),
      previousError(0.0), integral(0.0), Kp(Kp), Ki(Ki), Kd(Kd), lastUpdateTime(0) {}

// Set the desired temperature
void PIDController::setTargetTemperature(float temperature) {
    targetTemperature = temperature;
}

// Run the PID control loop
void PIDController::update(float currentValue, unsigned long currentTime) {
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0; // Convert to seconds

    // Calculate the error
    float error = targetTemperature - currentValue;

    // Calculate the integral
    integral += error * deltaTime;

    // Calculate the derivative
    float derivative = (error - previousError) / deltaTime;

    // Calculate the PID output (new openness level)
    float pidOutput = Kp * error + Ki * integral + Kd * derivative;

    // Adjust openness based on PID output
    float newOpenness = shaderController.getCurrentOpenness() + pidOutput;
    newOpenness = constrain(newOpenness, 0.0, 1.0); // Ensure openness stays in valid range

    // Apply the calculated openness
    shaderController.setShadeOpenness(newOpenness);

    // Update the previous error and time
    previousError = error;
    lastUpdateTime = currentTime;

    logger.setData(TARGET_TEMPERATURE, targetTemperature);
    logger.setData(PID_ERROR, error);
    logger.setData(PID_INTEGRAL, integral);
    logger.setData(PID_DERIVATIVE, derivative);
    logger.setData(PID_OUTPUT, pidOutput);
}
