#ifndef TIMER_H
#define TIMER_H

class Timer {
public:
    Timer();

    unsigned long getLastRetrievedTime();
    unsigned long retrieveNewCurrentTime();
    bool isLoopDelayPassed(unsigned long delay);

private:
    unsigned long currentTime;
    unsigned long lastLoopExecutionTime;
};

extern Timer timer; // Declaration of a global instance of Timer

#endif // TIMER_H