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
    float rotationAngle = targetAngle - currentAngle;
    
    // Invert the angle. This is due to the shader and motor placement.
    // It is not a general solution, but it is required for the condisions of our project.
    rotationAngle = -rotationAngle; 

    motor.rotateByDegrees(rotationAngle, speed);
    currentAngle = targetAngle;

    logger.setData(SHADE_OPENNESS, openness);
    logger.setData(MOTOR_ANGLE, currentAngle);
}

// Get the current openness of the shades
float ShaderController::getCurrentOpenness() const {
    return (currentAngle - minAngle) / (maxAngle - minAngle);
}
