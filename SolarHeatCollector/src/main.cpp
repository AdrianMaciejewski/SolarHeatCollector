#include <Arduino.h>
#include "TemperatureSensor.h"
#include "StepperMotor.h"
#include "ShaderController.h"
#include "PIDController.h"

// Create instances for rod and green cord sensors
TemperatureSensor rodSensor(7, "Rod");
TemperatureSensor greenCordSensor(8, "Green Cord");
StepperMotor motor(2048, 10, 11, 12, 13); // Pins for 28BYJ-48
ShaderController shaderController(motor, 10, 90, 10); // Shades operate between 10° and 90°
PIDController pidController(shaderController, 1.5, 0.1, 0.05); // Tuned PID gains

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");

    // Initialize sensors and stepper motor
    rodSensor.initialize();
    greenCordSensor.initialize();
    motor.initialize();
    pidController.setTargetTemperature(25.0); // Target: 25°C
}

void loop() {
    // Read and print temperatures
    float rodTemp = rodSensor.readTemperature();
    float greenCordTemp = greenCordSensor.readTemperature();
    float averageTemperature;

    if (!isnan(rodTemp) && !isnan(greenCordTemp)) {
        averageTemperature = (rodTemp + greenCordTemp) / 2;
    } else if (!isnan(rodTemp)) {
        averageTemperature = rodTemp;
    } else if (!isnan(greenCordTemp)) {
        averageTemperature = greenCordTemp;
    } else {
        averageTemperature = 0;
        Serial.println("Error: Both temperature readings are invalid.");
    }
    Serial.print("Average Temperature: ");
    Serial.println(averageTemperature);

    pidController.update(averageTemperature);

    delay(3000);
}
