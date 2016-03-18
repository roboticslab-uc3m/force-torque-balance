// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "Jr3Fake.hpp"

// -----------------------------------------------------------------------------

int teo::Jr3Fake::read(yarp::sig::Vector &out)
{
    out.resize(3);
    out[0] = 1;
    out[1] = 2;
    out[2] = 3;
    return yarp::dev::IAnalogSensor::AS_OK;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::getState(int ch)
{
    return yarp::dev::IAnalogSensor::AS_OK;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::getChannels()
{
    return 3;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::calibrateSensor()
{
    return true;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::calibrateSensor(const yarp::sig::Vector& value)
{
    return true;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::calibrateChannel(int ch)
{
    return true;
}

// -----------------------------------------------------------------------------

int teo::Jr3Fake::calibrateChannel(int ch, double value)
{
    return true;
}

// -----------------------------------------------------------------------------
