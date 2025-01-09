#include <Arduino.h>
#include "rod_sensor.h"
#include "green_cord_sensor.h"
#include "stepper_motor.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");

    // Initialize sensors and stepper motor
    initializeRodTemperatureSensor();
    initializeGreenCordTemperatureSensor();
    initializeStepperMotor();
}

void loop() {
    // Read and print temperatures
    float rodTemp = readRodTemperature();
    float greenCordTemp = readGreenCordTemperature();

    if (!isnan(rodTemp) && !isnan(greenCordTemp)) {
        Serial.print("Average Temperature: ");
        Serial.println((rodTemp + greenCordTemp) / 2);
    }

    // Move the stepper motor
    moveStepperClockwise(200);
    delay(1000);
    moveStepperCounterClockwise(200);
    delay(1000);
}