#ifndef CONSTANTS_H
#define CONSTANTS_H

// Pins
const int ROD_SENSOR_PIN = 7;
const int GREEN_CORD_SENSOR_PIN = 8;
const int MOTOR_STEPS = 2048;

// Shader controller
const float SHADER_MIN_ANGLE = 10.0;  // Fully closed
const float SHADER_MAX_ANGLE = 90.0;  // Fully open

// Stepper motor
const int MOTOR_PIN1 = 10;
const int MOTOR_PIN2 = 11;
const int MOTOR_PIN3 = 12;
const int MOTOR_PIN4 = 13;

const int DEFAULT_SPEED = 10;   // Default motor speed in RPM

// PID controller
const float TARGET_TEMPERATURE_VALUE = 25.0; // Target temperature in °C

//  PID values
const float PID_KP = 0.15; // Proportional coefficient
const float PID_KI = 0.01; // Integral coefficient
const float PID_KD = 0.05; // Derivative coefficient

// Measuremetn smoother
const int SMOOTHING_WINDOW_SIZE = 3;

// main
const unsigned long LOOP_INTERVAL = 3000;

#endif
