#include "temperture_sensor.ino"
#include "stepper_motor.ino"

void setup() {
  initializeTemperatureSensor();
  initializeStepperMotor();
}

void loop() {
  float temperature = readTemperature();
  if (temperature == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor disconnected!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  rotate()
}
