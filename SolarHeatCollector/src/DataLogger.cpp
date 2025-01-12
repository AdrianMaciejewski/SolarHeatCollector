#include "DataLogger.h"

DataLogger logger; // Definition of the global instance of DataLogger

DataLogger::DataLogger() {
    // Initialize all data to zero
    for (int i = 0; i < DATA_TYPE_COUNT; ++i) {
        data[i] = 0.0;
    }
}

void DataLogger::setData(DataType key, float value) {
    if (key >= 0 && key < DATA_TYPE_COUNT) {
        data[key] = value;  // Set the value for the corresponding key
    }
}

void DataLogger::log() {
    Serial.print("[DATA] ");
    for (int i = 0; i < DATA_TYPE_COUNT; ++i) {
        Serial.print(dataTypeToString(static_cast<DataType>(i)));
        Serial.print(": ");
        Serial.print(data[i]);
        if (i < DATA_TYPE_COUNT - 1) {
            Serial.print(", ");
        }
    }
    Serial.println();
}