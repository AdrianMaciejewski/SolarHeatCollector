#ifndef CONSTANTS_H
#define CONSTANTS_H

// Pins
const int ROD_SENSOR_PIN = 7;
const int GREEN_CORD_SENSOR_PIN = 8;

// Shader controller
const float SHADER_MIN_ANGLE = 30.0;  // Fully closed
const float SHADER_MAX_ANGLE = 90.0;  // Fully open

// Stepper motor
const int MOTOR_STEPS = 64*32; // Steps per revolution for 28BYJ-48. 64 to 1 gear ratio and 32 steps per revolution.
const int MOTOR_PIN1 = 10;
const int MOTOR_PIN2 = 11;
const int MOTOR_PIN3 = 12;
const int MOTOR_PIN4 = 13;

const int DEFAULT_SPEED = 10;   // Default motor speed in RPM

// PID controller
const float TARGET_TEMPERATURE_VALUE = 60.0; // Target temperature in °C

//  PID values
const float PID_KP = 0.15/3; // Proportional coefficient
const float PID_KI = 0.01/3; // Integral coefficient
const float PID_KD = 0.05/3; // Derivative coefficient

// main
const unsigned long LOOP_INTERVAL = 2000;

#endif
