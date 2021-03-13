cmake_minimum_required(VERSION 2.8.3)

project(urdf_example)

# List other catkin package dependencies
find_package(catkin REQUIRED COMPONENTS
    roscpp
)

# Include core ROS library directories
include_directories(${catkin_INCLUDE_DIRS})

# Declare catkin package
catkin_package()

# Compile an executable node
add_executable(joint_state_msg_pub src/JointStateMsgPub.cpp src/JointStateMsgPub.h src/main_node_jointstate_pub.cpp)
target_link_libraries(joint_state_msg_pub ${catkin_LIBRARIES})

