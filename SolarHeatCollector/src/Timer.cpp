#include "Timer.h"
#include <Arduino.h>
#include <DataLogger.h>

Timer timer; // Definition of the global instance of Timer

Timer::Timer() : currentTime(millis()), lastLoopExecutionTime(0.0) {}

unsigned long Timer::getLastRetrievedTime() {
    return currentTime;
}

unsigned long Timer::retrieveNewCurrentTime() {
    currentTime = millis();
    logger.setData(TIME_MS, currentTime);
    return currentTime;
}

bool Timer::isLoopDelayPassed(unsigned long delay) {
    if (currentTime - lastLoopExecutionTime >= delay) {
        lastLoopExecutionTime = currentTime;
        return true;
    }
    return false;
}