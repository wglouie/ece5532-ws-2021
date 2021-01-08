cmake_minimum_required(VERSION 2.8.3)
project(basic_example)
find_package(catkin REQUIRED COMPONENTS
  roscpp
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package()

add_executable(topic_publisher src/topic_publisher.cpp)
target_link_libraries(topic_publisher ${catkin_LIBRARIES})
