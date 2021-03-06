// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/**
 *
 * @ingroup force-torque-balance_programs
 * \defgroup forceTorqueBalance
 *
 * @brief Creates an instance of teo::ForceTorqueBalance
 *
 * @section forceTorqueBalance_legal Legal
 *
 * Copyright: 2016 (C) Universidad Carlos III de Madrid
 *
 * Author: lpinel
 *
 * CopyPolicy: This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License 3.0 or later
 *
 * <hr>
 *
 * This file can be edited at forceTorqueBalance
 *
 */

#include <yarp/os/all.h>

#include "ForceTorqueBalance.hpp"

using namespace yarp::os;

YARP_DECLARE_PLUGINS(ForceTorqueBalanceYarp)

int main(int argc, char *argv[]) {

    YARP_REGISTER_PLUGINS(ForceTorqueBalanceYarp);
    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefaultContext("forceTorqueBalance");
    rf.setDefaultConfigFile("forceTorqueBalance.ini");
    rf.configure(argc, argv);

    teo::ForceTorqueBalance mod;
    if(rf.check("help")) {
        return mod.runModule(rf);
    }

    printf("Run \"%s --help\" for options.\n",argv[0]);
    printf("%s checking for yarp network... ",argv[0]);
    fflush(stdout);
    Network yarp;
    if (!yarp.checkNetwork()) {
        fprintf(stderr,"[fail]\n%s found no yarp network (try running \"yarpserver &\"), bye!\n",argv[0]);
        return 1;
    } else printf("[ok]\n");

    return mod.runModule(rf);
}

