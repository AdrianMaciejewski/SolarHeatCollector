#ifndef DATATYPE_H
#define DATATYPE_H

#include <Arduino.h>

// Enum for different data types
enum DataType {
    TIME_MS,
    ROD_TEMPERATURE,
    GREEN_CORD_TEMPERATURE,
    AVERAGE_TEMPERATURE,
    SHADE_OPENNESS,
    TARGET_TEMPERATURE,
    PID_ERROR,
    PID_INTEGRAL,
    PID_DERIVATIVE,
    PID_OUTPUT,
    DATA_TYPE_COUNT // This will give us the count of data types
};

// Utility function to convert DataType enum to a string
inline String dataTypeToString(DataType type) {
    switch(type) {
        case TIME_MS:
            return "Time (ms)";
        case ROD_TEMPERATURE:
            return "Rod Temperature";
        case GREEN_CORD_TEMPERATURE:
            return "Green Cord Temperature";
        case AVERAGE_TEMPERATURE:
            return "Average Temperature";
        case SHADE_OPENNESS:
            return "Shade Openness";
        case TARGET_TEMPERATURE:
            return "Target Temperature";
        case PID_ERROR:
            return "PID Error";
        case PID_INTEGRAL:
            return "PID Integral";
        case PID_DERIVATIVE:
            return "PID Derivative";
        case PID_OUTPUT:
            return "PID Output";
        default:
            return "Unknown Data Type";
    }
}

#endif
