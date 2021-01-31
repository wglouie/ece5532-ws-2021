cmake_minimum_required(VERSION 2.8.3)
project(marker_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  visualization_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(marker_example src/marker_example.cpp)
target_link_libraries(marker_example  ${catkin_LIBRARIES})