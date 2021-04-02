cmake_minimum_required(VERSION 2.8.3)
project(imu_demo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  dynamic_reconfigure
)

catkin_package()
