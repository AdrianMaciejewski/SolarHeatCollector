#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "green_cord_sensor.h"

#define GREEN_CORD_ONE_WIRE_BUS 8
OneWire greenCordOneWire(GREEN_CORD_ONE_WIRE_BUS);
DallasTemperature greenCordSensor(&greenCordOneWire);

void initializeGreenCordTemperatureSensor() {
    greenCordSensor.begin();
    Serial.println("Green Cord Temperature Sensor Ready");
}

float readGreenCordTemperature() {
    greenCordSensor.requestTemperatures();
    float temperatureC = greenCordSensor.getTempCByIndex(0);
    if (temperatureC == DEVICE_DISCONNECTED_C) {
        Serial.println("Error: Green cord sensor disconnected!");
        return NAN;
    } else {
        Serial.print("Temperature (Green Cord): ");
        Serial.print(temperatureC);
        Serial.println(" °C");
        return temperatureC;
    }
}
