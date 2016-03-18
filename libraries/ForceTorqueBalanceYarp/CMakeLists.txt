# Copyright: (C) 2013 Universidad Carlos III de Madrid
# Authors: Juan G. Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

cmake_minimum_required(VERSION 2.6)

IF (ENABLE_ForceTorqueBalanceYarp)

  option(ENABLE_launchForceTorqueBalanceYarp "Choose if you want to compile launchForceTorqueBalanceYarp" TRUE)

  find_package(YARP REQUIRED)
  include_directories(${YARP_INCLUDE_DIRS})
  list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})  
  include(YarpPlugin)

  # Exporting dependencies for FORCE_TORQUE_BALANCEConfig.cmake quite manually for now... 
  # Note: Need ICanBusSharer.h, which will also need CanBusHico/*.hpp for now
  set(FORCE_TORQUE_BALANCE_INCLUDE_DIRS ${FORCE_TORQUE_BALANCE_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/CanBusHico CACHE INTERNAL "appended libraries") 
  # Note: ForceTorqueBalanceYarp bodybot works, but bodybot ForceTorqueBalanceYarp fails.
  set(FORCE_TORQUE_BALANCE_LIBRARIES ${FORCE_TORQUE_BALANCE_LIBRARIES} ForceTorqueBalanceYarp CACHE INTERNAL "appended libraries") 

  yarp_begin_plugin_library(ForceTorqueBalanceYarp)
    add_subdirectory(Jr3)
  yarp_end_plugin_library(ForceTorqueBalanceYarp)

  install(TARGETS ForceTorqueBalanceYarp DESTINATION lib)

  IF (ENABLE_launchForceTorqueBalanceYarp)

    YARP_ADD_PLUGIN_YARPDEV_EXECUTABLE(launchForceTorqueBalanceYarp ForceTorqueBalanceYarp)
    install(TARGETS launchForceTorqueBalanceYarp DESTINATION bin)

  ENDIF (ENABLE_launchForceTorqueBalanceYarp)

  # Exporting dependencies for FORCE_TORQUE_BALANCEConfig.cmake quite manually for now... 

ENDIF (ENABLE_ForceTorqueBalanceYarp)

