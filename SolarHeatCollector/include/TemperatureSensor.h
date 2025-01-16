#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include <DataType.h>

class TemperatureSensor {
private:
    int dataPin;
    DataType dataType;
    OneWire oneWire;
    DallasTemperature sensor;

public:
    // Constructor
    TemperatureSensor(int pin, DataType dataType);
    
    // Initialize the sensor
    void initialize();
    
    // Read temperature in Celsius
    float readTemperature();
};

#endif
