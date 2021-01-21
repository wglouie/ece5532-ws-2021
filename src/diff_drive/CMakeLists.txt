cmake_minimum_required(VERSION 2.8.3)
project(diff_drive)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(diff_drive_kinematics src/diff_drive_kinematics.cpp)
target_link_libraries(diff_drive_kinematics ${catkin_LIBRARIES})
