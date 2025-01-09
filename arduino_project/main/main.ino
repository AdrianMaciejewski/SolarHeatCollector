#include <OneWire.h>
#include <DallasTemperature.h>
#include <Stepper.h>

// DS18B20 Temperature Sensor Setup for Rod
#define ROD_ONE_WIRE_BUS 7 // Data pin for the rod temperature sensor
OneWire rodOneWire(ROD_ONE_WIRE_BUS);
DallasTemperature rodSensor(&rodOneWire);

// Function to initialize the DS18B20 temperature sensor for the rod
void initializeRodTemperatureSensor() {
  rodSensor.begin();
  Serial.println("Rod Temperature Sensor Ready");
}

// Function to read and print the temperature from the rod sensor
float readRodTemperature() {
  rodSensor.requestTemperatures();
  float temperatureC = rodSensor.getTempCByIndex(0);

  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Rod sensor disconnected!");
    return NAN; // Return NaN to indicate a failed reading
  } else {
    Serial.print("Temperature (Rod): ");
    Serial.print(temperatureC);
    Serial.println(" °C");
    return temperatureC;
  }
}

// DS18B20 Temperature Sensor Setup for Green Cord
#define GREEN_CORD_ONE_WIRE_BUS 8 // Data pin for the green cord temperature sensor
OneWire greenCordOneWire(GREEN_CORD_ONE_WIRE_BUS);
DallasTemperature greenCordSensor(&greenCordOneWire);

// Function to initialize the DS18B20 temperature sensor for the green cord
void initializeGreenCordTemperatureSensor() {
  greenCordSensor.begin();
  Serial.println("Green Cord Temperature Sensor Ready");
}

// Function to read and print the temperature from the green cord sensor
float readGreenCordTemperature() {
  greenCordSensor.requestTemperatures();
  float temperatureC = greenCordSensor.getTempCByIndex(0);

  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Green cord sensor disconnected!");
    return NAN; // Return NaN to indicate a failed reading
  } else {
    Serial.print("Temperature (Green Cord): ");
    Serial.print(temperatureC);
    Serial.println(" °C");
    return temperatureC;
  }
}

// Stepper Motor Setup
const int stepsPerRevolution = 2048; // Adjust for 28BYJ-48
Stepper myStepper(stepsPerRevolution, 10, 11, 12, 13);

// Function to initialize the stepper motor
void initializeStepperMotor() {
  myStepper.setSpeed(10); // Adjust speed as needed
  Serial.println("Stepper Motor Ready");
}

// Function to rotate the stepper motor clockwise
void rotateClockwise() {
  Serial.println("Rotating one revolution clockwise...");
  myStepper.step(stepsPerRevolution);
}

// Function to rotate the stepper motor counterclockwise
void rotateCounterClockwise() {
  Serial.println("Rotating one revolution counterclockwise...");
  myStepper.step(-stepsPerRevolution);
}

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Initialize components
  initializeRodTemperatureSensor();
  initializeGreenCordTemperatureSensor();
  initializeStepperMotor();
}

void loop() {
  // Read and print temperatures
  readGreenCordTemperature();
  readRodTemperature();

  // Rotate motor clockwise and counterclockwise
  rotateClockwise();
  delay(1000);
  rotateCounterClockwise();
  delay(1000);
}
