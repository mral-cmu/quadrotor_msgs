cmake_minimum_required(VERSION 2.8.3)
project(quadrotor_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  geometry_msgs
  nav_msgs
  sensor_msgs
)

add_message_files(
  FILES
  SO3Command.msg
  PWMCommand.msg
  PDCommand.msg
  Segment.msg
  SegmentedPlan.msg
  CombinedState.msg
  Status.msg
  BatteryVoltage.msg
  AltitudeObservation.msg
  AltitudeInfo.msg
  HeightDelta.msg
  StaticTrimInfo.msg
)

generate_messages(
  DEPENDENCIES
  geometry_msgs
  nav_msgs
  sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime geometry_msgs nav_msgs sensor_msgs
)

find_package(ipc_bridge QUIET)
if(ipc_bridge_FOUND)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ipc_bridge_MODULE_PATH}")
  find_package(IPC REQUIRED)
  find_package(Matlab REQUIRED COMPONENTS mex)
  find_package(catkin REQUIRED roscpp)

  include_directories(
    ${IPC_INCLUDE_DIR}
    ${ipc_bridge_INCLUDE_DIR}
  )

  set(IPC_MATLAB_CFLAGS "-I${CMAKE_CURRENT_LIST_DIR}/ipc/include")
  add_custom_target(generate_xdr_headers)
  add_subdirectory("ipc")

  install(DIRECTORY ipc/include/ipc_bridge/
    DESTINATION include/ipc_bridge
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
    )
endif(ipc_bridge_FOUND)
