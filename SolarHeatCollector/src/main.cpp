#include <Arduino.h>
#include "TemperatureSensor.h"
#include "StepperMotor.h"

// Create instances for rod and green cord sensors
TemperatureSensor rodSensor(7, "Rod");
TemperatureSensor greenCordSensor(8, "Green Cord");
StepperMotor motor(2048, 10, 11, 12, 13); // Pins for 28BYJ-48

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing...");

    // Initialize sensors and stepper motor
    rodSensor.initialize();
    greenCordSensor.initialize();
    motor.initialize();
}

void loop() {
    // Read and print temperatures
    float rodTemp = rodSensor.readTemperature();
    float greenCordTemp = greenCordSensor.readTemperature();

    if (!isnan(rodTemp) && !isnan(greenCordTemp)) {
        Serial.print("Average Temperature: ");
        Serial.println((rodTemp + greenCordTemp) / 2);
    }

    // Move the stepper motor
    motor.rotateByDegrees(90, 10);
    delay(5000);
    motor.rotateByDegrees(-90, 10);
    delay(5000);
}
