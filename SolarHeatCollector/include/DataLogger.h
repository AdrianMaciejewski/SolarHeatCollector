#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <Arduino.h>
#include "DataType.h"


class DataLogger {
public:
    DataLogger();

    // Method to set data
    void setData(DataType key, float value);

    // Method to log data and clear it
    void log();

private:
    float data[DATA_TYPE_COUNT];  // Array to store data values
};

extern DataLogger logger; // Declaration of a global instance of DataLogger

#endif
