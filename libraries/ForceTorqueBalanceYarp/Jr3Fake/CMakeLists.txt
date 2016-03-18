# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Author: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

YARP_PREPARE_DEVICE(Jr3Fake TYPE teo::Jr3Fake INCLUDE Jr3Fake.hpp)

IF (NOT SKIP_Jr3Fake)

  find_package(YARP REQUIRED)

  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${FORCE_TORQUE_BALANCE_INCLUDE_DIRS} ${COLOR_DEBUG_INCLUDE_DIRS})

  yarp_add_plugin(Jr3Fake DeviceDriverImpl.cpp IGenericSensorImpl.cpp )

  TARGET_LINK_LIBRARIES(Jr3Fake ${YARP_LIBRARIES})
  install(TARGETS Jr3Fake DESTINATION lib)

  # Exporting dependencies for FORCE_TORQUE_BALANCEConfig.cmake quite manually for now... 
  set(FORCE_TORQUE_BALANCE_LIBRARIES ${FORCE_TORQUE_BALANCE_LIBRARIES} Jr3Fake CACHE INTERNAL "appended libraries") 

ENDIF (NOT SKIP_Jr3Fake)

