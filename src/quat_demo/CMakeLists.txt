cmake_minimum_required(VERSION 2.8.3)
project(quat_demo)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  tf
  visualization_msgs
)

generate_dynamic_reconfigure_options(
  cfg/QuatDemo.cfg
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(quat_demo src/quat_demo.cpp)
add_dependencies(quat_demo ${PROJECT_NAME}_gencfg)
target_link_libraries(quat_demo
  ${catkin_LIBRARIES}
)

