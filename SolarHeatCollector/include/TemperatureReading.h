#include <TemperatureSensor.h>

/**
 * @brief Reads the temperature using given sensors.
 * 
 * This function returns the average temperature.
 * 
 * @param sensors Array of TemperatureSensor objects.
 * @param numSensors Number of sensors in the array.
 * @return float The average temperature.
 */
float calculateAverageTemperature(TemperatureSensor sensors[]);
