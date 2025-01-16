#include <TemperatureReader.h>
#include <DataLogger.h>

float calculateAverageTemperature(TemperatureSensor* sensors) {
    float averageTemperature = 0;
    int validSensors = 0;

    for (int i = 0; i < 2; i++) {
        float temperature = sensors[i].readTemperature();
        if (!isnan(temperature)) {
            averageTemperature += temperature;
            validSensors++;
        }
    }

    if (validSensors > 0) {
        averageTemperature /= validSensors;
    } else {
        Serial.println("Error: Both temperature readings are invalid.");
    }


    logger.setData(AVERAGE_TEMPERATURE, averageTemperature);
    return averageTemperature;
}