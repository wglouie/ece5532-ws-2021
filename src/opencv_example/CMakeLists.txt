cmake_minimum_required(VERSION 2.8.3)
project(opencv_example)

set(${PROJECT_NAME}_CATKIN_DEPS
  dynamic_reconfigure
  image_transport
  cv_bridge
  roscpp
)

find_package(catkin REQUIRED COMPONENTS ${${PROJECT_NAME}_CATKIN_DEPS})
find_package(OpenCV REQUIRED)

generate_dynamic_reconfigure_options(
  cfg/RgbHough.cfg
  cfg/HsvExample.cfg
)

catkin_package(
  DEPENDS OpenCV
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(rgb_hough_node
  src/rgb_hough_node.cpp
  src/RgbHough.cpp
)
add_dependencies(rgb_hough_node
  ${PROJECT_NAME}_gencfg
)
target_link_libraries(rgb_hough_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)


