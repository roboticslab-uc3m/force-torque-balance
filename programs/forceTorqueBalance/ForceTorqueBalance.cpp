// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ForceTorqueBalance.hpp"

namespace teo
{

/************************************************************************/

ForceTorqueBalance::ForceTorqueBalance(int rate) : yarp::os::RateThread(rate)
{
}

/************************************************************************/

bool ForceTorqueBalance::configure(yarp::os::ResourceFinder &rf) {

    printf("--------------------------------------------------------------\n");
    if (rf.check("help")) {
        printf("ForceTorqueBalance options:\n");
        printf("\t--help (this help)\t--from [file.ini]\t--context [path]\n");
        //printf("\t--file (default: \"%s\")\n",fileName.c_str());
    }

    printf("--------------------------------------------------------------\n");

    std::string ftDeviceStr = rf.check("ftDevice",yarp::os::Value(DEFAULT_FT_DEVICE),"force torque device").asString();
    std::string leftLegDeviceStr = rf.check("leftLegDevice",yarp::os::Value(DEFAULT_LEFT_LEG_DEVICE),"left leg device").asString();
    std::string leftLegRemoteStr = rf.check("leftLegRemote",yarp::os::Value(DEFAULT_LEFT_LEG_REMOTE),"left leg remote port name").asString();

    //-- f/t
    yarp::os::Property ftOptions;
    ftOptions.put("device",ftDeviceStr);
    if( ! ftDevice.open(ftOptions) )
    {
        fprintf(stderr,"Could not open f/t device: %s.\n", ftDeviceStr.c_str());
        return false;
    }
    printf("Opened f/t device: %s.\n", ftDeviceStr.c_str());

    if( ! ftDevice.view( iAnalogSensor ) )
    {
            fprintf(stderr,"Could not get iAnalogSensor interface from f/t device.\n");
            return false;
    }
    printf("Could get iAnalogSensor interface from f/t device.\n");

    int numChannels = iAnalogSensor->getChannels();
    ftData.resize( numChannels );

    //-- robot
    yarp::os::Property leftLegOptions;
    leftLegOptions.put("device",leftLegDeviceStr);
    leftLegOptions.put("local","/forceTorqueBalance/leftLeg");
    leftLegOptions.put("remote",leftLegRemoteStr);
    if( ! leftLegDevice.open(leftLegOptions) )
    {
        fprintf(stderr,"Could not open left leg device: %s.\n", leftLegDeviceStr.c_str());
        return false;
    }
    printf("Opened left leg device: %s.\n", leftLegDeviceStr.c_str());

    if( ! leftLegDevice.view( leftLegPosition ) )
    {
            fprintf(stderr,"Could not get leftLegPosition interface from left leg device.\n");
            return false;
    }
    printf("Could get leftLegPosition interface from left leg device.\n");



    return true;
}

/************************************************************************/
void ForceTorqueBalance::run() {

    iAnalogSensor->read(ftData);



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

