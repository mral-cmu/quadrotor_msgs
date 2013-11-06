cmake_minimum_required(VERSION 2.8.3)
project(quadrotor_msgs)

find_package(catkin REQUIRED
  message_generation
  geometry_msgs
  nav_msgs
  sensor_msgs
)

add_message_files(
  FILES
  Command.msg
  Segment.msg
  SegmentedPlan.msg
  CombinedState.msg
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
