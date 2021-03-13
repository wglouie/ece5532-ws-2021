cmake_minimum_required(VERSION 2.8.3)

project(mantis_model)

# List other catkin package dependencies
find_package(catkin REQUIRED COMPONENTS
    roscpp
)

# Include core ROS library directories
include_directories(${catkin_INCLUDE_DIRS})

# Declare catkin package
catkin_package()

# Compile an executable node
add_executable(mantis_joint_pub src/MantisJointPub.cpp src/MantisJointPub.h src/main_mantis_joint_pub.cpp)
target_link_libraries(mantis_joint_pub ${catkin_LIBRARIES})

