// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __FORCE_TORQUE_BALANCE_HPP__
#define __FORCE_TORQUE_BALANCE_HPP__

#include <yarp/os/all.h>
#include <yarp/dev/all.h>
#include <yarp/dev/IAnalogSensor.h>

#define DEFAULT_RATE_MS 20
#define DEFAULT_FT_DEVICE "Jr3"
#define DEFAULT_LEFT_LEG_DEVICE "remote_controlboard"
#define DEFAULT_LEFT_LEG_REMOTE "/teo/leftLeg"
#define DEFAULT_RIGHT_LEG_DEVICE "remote_controlboard"
#define DEFAULT_RIGHT_LEG_REMOTE "/teo/rightLeg"

namespace teo
{

/**
 * @ingroup forceTorqueBalance
 *
 * @brief forceTorqueBalance
 *
 */
class ForceTorqueBalance : public yarp::os::RFModule, public yarp::os::RateThread {
    public:
        ForceTorqueBalance(int rate=DEFAULT_RATE_MS);

        bool configure(yarp::os::ResourceFinder &rf);

        void run();

    protected:

        yarp::dev::PolyDriver ftDevice;
        yarp::dev::IAnalogSensor* iAnalogSensor;

        yarp::sig::Vector ftData;

        yarp::dev::PolyDriver leftLegDevice;
        yarp::dev::IPositionDirect* leftLegPosition;

        yarp::dev::PolyDriver rightLegDevice;

        virtual bool interruptModule();
        virtual double getPeriod();
        virtual bool updateModule();

};

}  // namespace teo

#endif  // __FORCE_TORQUE_BALANCE_HPP__
