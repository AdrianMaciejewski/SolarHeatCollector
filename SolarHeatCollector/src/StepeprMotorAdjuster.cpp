#include "StepperMotor.h"
#include "StepperMotorAdjuster.h"
#include <Arduino.h>
#include <constants.h>

StepperMotorAdjuster::StepperMotorAdjuster(StepperMotor stepperMotor)
    : stepperMotor(stepperMotor) {}

void StepperMotorAdjuster::listenForCommands() {
    if (Serial.available() > 0) {
            String input = Serial.readStringUntil('\n');
            Serial.println("[Echo] input: '" + input + "' .");
            if (input.startsWith("--rotate ")) {
                int degrees = input.substring(9).toInt();
                Serial.print("[DEBUG] Rotating motor, by request, by ");
                Serial.print(degrees);
                Serial.println(" degrees.");
                stepperMotor.rotateByDegrees(degrees, DEFAULT_SPEED);
            }
        }
}