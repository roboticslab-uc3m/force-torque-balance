# Copyright: UC3M 2016
# Author: lpinel
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
# 

find_package(YARP REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpInstallationHelpers)
yarp_configure_external_installation(force-torque-balance)

### Go through single applications

#add_subdirectory(prog)

