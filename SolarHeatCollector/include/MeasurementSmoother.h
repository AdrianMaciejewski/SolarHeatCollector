// MeasurementSmoother.h
#ifndef MEASUREMENTSMOOTHER_H
#define MEASUREMENTSMOOTHER_H

#include <Arduino.h>

class MeasurementSmoother {
public:
    /**
     * @brief Constructor for MeasurementSmoother.
     * @param windowSize The size of the sliding window for smoothing.
     */
    MeasurementSmoother(size_t windowSize);

    /**
     * @brief Destructor for MeasurementSmoother.
     */
    ~MeasurementSmoother();

    /**
     * @brief Adds a new measurement and calculates the smoothed value.
     * @param measurement The new measurement value.
     * @return The smoothed measurement value.
     */
    float addMeasurement(float measurement);

    /**
     * @brief Calculates the average of the current measurements in the buffer.
     * @return The average value.
     */
    float getSmoothedMeasurement() const;

private:
    size_t windowSize; ///< Size of the sliding window
    float* measurements; ///< Circular buffer for measurements
    size_t currentIndex; ///< Current index in the circular buffer
    size_t filledSize; ///< Number of elements currently in the buffer
};

#endif
