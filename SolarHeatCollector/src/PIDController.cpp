#include "PIDController.h"
#include <Arduino.h>

// Constructor
PIDController::PIDController(ShaderController& shaderController, float Kp, float Ki, float Kd)
    : shaderController(shaderController), targetTemperature(0.0), currentTemperature(0.0),
      previousError(0.0), integral(0.0), Kp(Kp), Ki(Ki), Kd(Kd), lastUpdateTime(0) {}

// Set the desired temperature
void PIDController::setTargetTemperature(float temperature) {
    targetTemperature = temperature;
    Serial.println("Target temperature set to: " + String(temperature) + " °C");
}

// Run the PID control loop
void PIDController::update(float currentTemperature) {
    this->currentTemperature = currentTemperature;

    unsigned long currentTime = millis();
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0; // Convert to seconds
    if (deltaTime <= 0) return;

    // Calculate the error
    float error = targetTemperature - currentTemperature;

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

    // Print debug information
    Serial.println("PID Debug - Error: " + String(error) +
                   ", Integral: " + String(integral) +
                   ", Derivative: " + String(derivative) +
                   ", PID Output: " + String(pidOutput) +
                   ", New Openness: " + String(newOpenness));

    // Update the previous error and time
    previousError = error;
    lastUpdateTime = currentTime;
}
