// MeasurementSmoother.cpp
#include "MeasurementSmoother.h"

// Constructor
MeasurementSmoother::MeasurementSmoother(size_t windowSize)
    : windowSize(windowSize), currentIndex(0), filledSize(0) {
    measurements = new float[windowSize];
    for (size_t i = 0; i < windowSize; ++i) {
        measurements[i] = 0.0f;
    }
}

// Destructor
MeasurementSmoother::~MeasurementSmoother() {
    delete[] measurements;
}

// Add a new measurement and calculate the smoothed value
float MeasurementSmoother::addMeasurement(float measurement) {
    measurements[currentIndex] = measurement;
    currentIndex = (currentIndex + 1) % windowSize;

    if (filledSize < windowSize) {
        ++filledSize;
    }
}

// Calculate the average of the current measurements in the buffer
float MeasurementSmoother::getSmoothedMeasurement() const {
    float sum = 0.0f;
    for (size_t i = 0; i < filledSize; ++i) {
        sum += measurements[i];
    }
    
    return filledSize > 0 ? sum / filledSize : 0.0f;
}
