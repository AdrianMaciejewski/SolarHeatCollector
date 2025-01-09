#include "stepper_motor.h"

TMC2208Stepper driver(&Serial, R_SENSE);

void initializeStepperMotor() {
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    digitalWrite(ENABLE_PIN, LOW); // Enable the driver

    driver.begin();
    driver.rms_current(600); // Set motor current (mA)
    driver.microsteps(16);   // Set microstepping
    Serial.println("Stepper Motor Ready");
}

void moveStepperClockwise(int steps) {
    digitalWrite(DIR_PIN, HIGH); // Set direction to clockwise
    for (int i = 0; i < steps; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(100);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(100);
    }
    Serial.println("Stepper moved clockwise");
}

void moveStepperCounterClockwise(int steps) {
    digitalWrite(DIR_PIN, LOW); // Set direction to counterclockwise
    for (int i = 0; i < steps; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(100);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(100);
    }
    Serial.println("Stepper moved counterclockwise");
}
