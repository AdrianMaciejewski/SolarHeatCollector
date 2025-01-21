#ifndef STEPPERMOTORADJUSTER_H
#define STEPPERMOTORCONTROLLER_H

#include "StepperMotor.h"

class StepperMotorAdjuster {
public:
    StepperMotorAdjuster(StepperMotor stepperMotor);

    /**
     * @brief Listens to serial input and rotates the motor based on commands.
     */
    void listenForCommands();

private:
    StepperMotor stepperMotor; ///< Stepper motor instance
};

#endif

