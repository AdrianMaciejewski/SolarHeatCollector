#include "ShaderController.h"
#include <Arduino.h>
#include <DataLogger.h>

// Constructor
ShaderController::ShaderController(StepperMotor& motor, float minAngle, float maxAngle, int speed)
    : motor(motor), currentAngle(minAngle), minAngle(minAngle), maxAngle(maxAngle), speed(speed) {}

// Helper to calculate angle from openness
float ShaderController::calculateAngle(float openness) {
    return minAngle + openness * (maxAngle - minAngle);
}

// Set the openness of the shades
void ShaderController::setShadeOpenness(float openness) {
    if (openness < 0.0 || openness > 1.0) {
        Serial.println("Error: Openness out of bounds (0.0 to 1.0)");
        return;
    }

    float targetAngle = calculateAngle(openness);
    float angleDifference = targetAngle - currentAngle;
    motor.rotateByDegrees(angleDifference, speed);
    currentAngle = targetAngle;

    logger.setData(SHADE_OPENNESS, openness);
}

// Get the current openness of the shades
float ShaderController::getCurrentOpenness() const {
    return (currentAngle - minAngle) / (maxAngle - minAngle);
}
