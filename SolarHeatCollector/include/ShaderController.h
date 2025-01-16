/**
 * @file ShaderController.h
 * @brief Header file for the ShaderController class.
 * 
 * This file contains the declaration of the ShaderController class, which is responsible
 * for controlling the angle of shades using a stepper motor.
 */

#ifndef SHADERCONTROLLER_H
#define SHADERCONTROLLER_H

#include "StepperMotor.h"

/**
 * @class ShaderController
 * @brief Controls the angle of shades using a stepper motor.
 * 
 * The ShaderController class provides methods to set and get the openness of shades,
 * which is controlled by a stepper motor. The openness is represented as a value between
 * 0.0 (fully closed) and 1.0 (fully open).
 * 
 * IMPORTANT!: Initial current angle is set to the minimum angle (fully closed).
 */
class ShaderController {
private:
    StepperMotor& motor;    ///< Reference to the StepperMotor instance
    float currentAngle;     ///< Current angle of the shades
    float minAngle;         ///< Minimum angle (fully closed)
    float maxAngle;         ///< Maximum angle (fully open)
    int speed;              ///< Speed in RPM 

    /**
     * @brief Helper function to calculate the angle from openness.
     * 
     * @param openness The desired openness (0.0 to 1.0).
     * @return The calculated angle corresponding to the given openness.
     */
    float calculateAngle(float openness);

public:
    /**
     * @brief Constructs a ShaderController object.
     * 
     * @param motor Reference to the StepperMotor instance.
     * @param minAngle Minimum angle (fully closed).
     * @param maxAngle Maximum angle (fully open).
     * @param speed Speed in RPM.
     */
    ShaderController(StepperMotor& motor, float minAngle, float maxAngle, int speed);

    /**
     * @brief Sets the openness of the shades.
     * 
     * @param openness The desired openness (0.0 to 1.0).
     */
    void setShadeOpenness(float openness);

    /**
     * @brief Gets the current openness of the shades.
     * 
     * @return The current openness (0.0 to 1.0).
     */
    float getCurrentOpenness() const;
};

#endif
