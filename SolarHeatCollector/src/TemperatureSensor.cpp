#include "TemperatureSensor.h"
#include <Arduino.h>
#include <DataLogger.h>
#include <DataType.h>

// Constructor
TemperatureSensor::TemperatureSensor(int pin, DataType dataType)
    : dataPin(pin), dataType(dataType), oneWire(pin), sensor(&oneWire) {}

// Initialize the sensor
void TemperatureSensor::initialize() {
    sensor.begin();
    Serial.println(dataTypeToString(dataType) + " Temperature Sensor Ready");
}

// Read temperature in Celsius
float TemperatureSensor::readTemperature() {
    sensor.requestTemperatures();
    float temperatureC = sensor.getTempCByIndex(0);

    if (temperatureC == DEVICE_DISCONNECTED_C) {
        Serial.println(String("Error: ") + dataTypeToString(dataType) + " sensor disconnected!");
        return NAN;
    } else {
        logger.setData(dataType, temperatureC);
        return temperatureC;
    }
}
