#include <Arduino.h>
#include "TemperatureSensor.h"
#include "StepperMotor.h"
#include "ShaderController.h"
#include "PIDController.h"
#include <DataLogger.h>
#include <constants.h>
#include "TemperatureReader.h"

// Create instances of the classes
TemperatureSensor rodSensor(ROD_SENSOR_PIN, ROD_TEMPERATURE);
TemperatureSensor greenCordSensor(GREEN_CORD_SENSOR_PIN, GREEN_CORD_TEMPERATURE);
StepperMotor motor(MOTOR_STEPS, MOTOR_PIN1, MOTOR_PIN2, MOTOR_PIN3, MOTOR_PIN4); // Pins for 28BYJ-48
ShaderController shaderController(motor, SHADER_MIN_ANGLE, SHADER_MAX_ANGLE, SHADER_MIN_ANGLE);
MeasurementSmoother measurementSmoother(SMOOTHING_WINDOW_SIZE);
PIDController pidController(shaderController, measurementSmoother, PID_KP, PID_KI, PID_KD);

TemperatureSensor sensors[] = { rodSensor, greenCordSensor };

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");

    // Initialize sensors and stepper motor
    rodSensor.initialize();
    greenCordSensor.initialize();
    motor.initialize();
    pidController.setTargetTemperature(TARGET_TEMPERATURE_VALUE); // Target: 25°C
}

void loop() {
    unsigned long time = millis();

    float averageTemperature = calculateAverageTemperature(sensors);
    
    //measurementSmoother.addMeasurement(averageTemperature);
    //float smoothedAverageTemperature = measurementSmoother.getSmoothedMeasurement();
    
    pidController.update(averageTemperature, time);
    
    logger.setData(TIME_MS, time);
    logger.log();

    delay(LOOP_INTERVAL);
}
