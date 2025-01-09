#include <Stepper.h>

// Stepper Motor Setup
const int stepsPerRevolution = 2048; // Adjust for 28BYJ-48
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

// Function to initialize the stepper motor
void initializeStepperMotor() {
  Serial.println("Initializing Stepper Motor...");
  myStepper.setSpeed(60); // Adjust speed as needed
  Serial.println("Stepper Motor Ready.");
}c:\Users\ADMA\Documents\DB3\temperture_reading.ino\temperture_reading.ino

// Function to rotate motor clockwise one revolution
void rotate() {
  Serial.println("Rotating one revolution clockwise...");
  myStepper.setSpeed(60); // Adjust speed as needed
  myStepper.step(2*stepsPerRevolution);
  delay(2000); // Wait for 1 second
}

// Function to rotate motor clockwise one revolution
void rotateMotorClockwise() {
  Serial.println("Rotating one revolution clockwise...");
  myStepper.step(stepsPerRevolution);
}

// Function to rotate motor counterclockwise one revolution
void rotateMotorCounterclockwise() {
  Serial.println("Rotating one revolution counterclockwise...");
  myStepper.step(-stepsPerRevolution);
}
