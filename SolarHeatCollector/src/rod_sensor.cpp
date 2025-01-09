#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "rod_sensor.h"

#define ROD_ONE_WIRE_BUS 7
OneWire rodOneWire(ROD_ONE_WIRE_BUS);
DallasTemperature rodSensor(&rodOneWire);

void initializeRodTemperatureSensor() {
    rodSensor.begin();
    Serial.println("Rod Temperature Sensor Ready");
}

float readRodTemperature() {
    rodSensor.requestTemperatures();
    float temperatureC = rodSensor.getTempCByIndex(0);
    if (temperatureC == DEVICE_DISCONNECTED_C) {
        Serial.println("Error: Rod sensor disconnected!");
        return NAN;
    } else {
        Serial.print("Temperature (Rod): ");
        Serial.print(temperatureC);
        Serial.println(" °C");
        return temperatureC;
    }
}
