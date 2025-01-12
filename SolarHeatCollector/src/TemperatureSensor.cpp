#include "TemperatureSensor.h"
#include <Arduino.h>

// Constructor
TemperatureSensor::TemperatureSensor(int pin, const char* sensorName)
    : dataPin(pin), name(sensorName), oneWire(pin), sensor(&oneWire) {}

// Initialize the sensor
void TemperatureSensor::initialize() {
    sensor.begin();
    Serial.println(String(name) + " Temperature Sensor Ready");
}

// Read temperature in Celsius
float TemperatureSensor::readTemperature() {
    sensor.requestTemperatures();
    float temperatureC = sensor.getTempCByIndex(0);

    if (temperatureC == DEVICE_DISCONNECTED_C) {
        Serial.println(String("Error: ") + name + " sensor disconnected!");
        return NAN;
    } else {
        return temperatureC;
    }
}
