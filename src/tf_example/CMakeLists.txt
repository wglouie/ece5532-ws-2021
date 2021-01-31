cmake_minimum_required(VERSION 2.8.3)
project(tf_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  dynamic_reconfigure
)

generate_dynamic_reconfigure_options(cfg/TFExample.cfg)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tf_example src/tf_example.cpp)
add_dependencies(tf_example ${PROJECT_NAME}_gencfg)
target_link_libraries(tf_example ${catkin_LIBRARIES})

