// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __FORCE_TORQUE_BALANCE_HPP__
#define __FORCE_TORQUE_BALANCE_HPP__

#include <yarp/os/all.h>
#include <yarp/dev/all.h>
#include <yarp/dev/IAnalogSensor.h>

#define DEFAULT_RATE_MS 20

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

        yarp::dev::PolyDriver jr3device;
        yarp::dev::IAnalogSensor* iAnalogSensor;

        virtual bool interruptModule();
        virtual double getPeriod();
        virtual bool updateModule();

};

}  // namespace teo

#endif  // __FORCE_TORQUE_BALANCE_HPP__
