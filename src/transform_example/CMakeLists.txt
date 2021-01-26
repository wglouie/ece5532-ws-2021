cmake_minimum_required(VERSION 2.8.3)
project(transform_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(transform_example1 src/transform_example1.cpp)
target_link_libraries(transform_example1 ${catkin_LIBRARIES})


add_executable(transform_example2 src/transform_example2.cpp)
target_link_libraries(transform_example2 ${catkin_LIBRARIES})

add_executable(tf_example1 src/tf_example1.cpp)
target_link_libraries(tf_example1 ${catkin_LIBRARIES})

add_executable(tf_example2 src/tf_example2.cpp)
target_link_libraries(tf_example2 ${catkin_LIBRARIES})

add_executable(tf_example_pubsub src/tf_example_pubsub.cpp)
target_link_libraries(tf_example_pubsub ${catkin_LIBRARIES})