// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ForceTorqueBalance.hpp"

namespace teo
{

/************************************************************************/

bool ForceTorqueBalance::configure(yarp::os::ResourceFinder &rf) {

    printf("--------------------------------------------------------------\n");
    if (rf.check("help")) {
        printf("ForceTorqueBalance options:\n");
        printf("\t--help (this help)\t--from [file.ini]\t--context [path]\n");
        //printf("\t--file (default: \"%s\")\n",fileName.c_str());
    }

    printf("--------------------------------------------------------------\n");

    return true;
}

/************************************************************************/
double ForceTorqueBalance::getPeriod() {
    return 2.0;  // Fixed, in seconds, the slow thread that calls updateModule below
}

/************************************************************************/
bool ForceTorqueBalance::updateModule() {
    //printf("StateMachine in state [%d]. ForceTorqueBalance alive...\n", stateMachine.getMachineState());
    return true;
}

/************************************************************************/

bool ForceTorqueBalance::interruptModule() {
    return true;
}

/************************************************************************/

}  // namespace teo

