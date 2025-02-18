#include <Arduino.h>
#include "TemperatureSensor.h"
#include "StepperMotor.h"
#include "ShaderController.h"
#include "PIDController.h"
#include <DataLogger.h>
#include <constants.h>
#include <Timer.h>
#include "TemperatureReading.h"
#include <StepperMotorAdjuster.h>

// Create instances of the classes
TemperatureSensor rodSensor(ROD_SENSOR_PIN, ROD_TEMPERATURE);
TemperatureSensor greenCordSensor(GREEN_CORD_SENSOR_PIN, GREEN_CORD_TEMPERATURE);
TemperatureSensor sensors[] = { rodSensor, greenCordSensor };

StepperMotor motor(MOTOR_STEPS, MOTOR_PIN1, MOTOR_PIN2, MOTOR_PIN3, MOTOR_PIN4); // Pins for 28BYJ-48
ShaderController shaderController(motor, SHADER_MIN_ANGLE, SHADER_MAX_ANGLE, DEFAULT_SPEED);
PIDController pidController(shaderController, TARGET_TEMPERATURE_VALUE, PID_KP, PID_KI, PID_KD);

StepperMotorAdjuster motorAdjuster(motor);

void setup() {
    Serial.begin(9600);

    // Initialize sensors and stepper motor
    rodSensor.initialize();
    greenCordSensor.initialize();
    motor.initialize();
}

void loop() {
    unsigned long currentTime = timer.retrieveNewCurrentTime();;
    if (!timer.isLoopDelayPassed(LOOP_INTERVAL)) {
        return;   
    }

    motorAdjuster.listenForCommands();

    float averageTemperature = calculateAverageTemperature(sensors);
    pidController.update(averageTemperature, currentTime);

    logger.log();
}
