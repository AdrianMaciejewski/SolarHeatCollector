#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {
private:
    int dataPin;
    const char* name;
    OneWire oneWire;
    DallasTemperature sensor;

public:
    // Constructor
    TemperatureSensor(int pin, const char* sensorName);
    
    // Initialize the sensor
    void initialize();
    
    // Read temperature in Celsius
    float readTemperature();
};

#endif
