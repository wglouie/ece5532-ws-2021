// ROS and node class header file
#include <ros/ros.h>
#include "DeadReckoning.h"

int main(int argc, char** argv)
{
  // Initialize ROS and declare node handles
  ros::init(argc, argv, "dead_reckoning");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");
  
  // Instantiate node class
  dead_reckoning::DeadReckoning node(n, pn);
  
  // Spin and process callbacks
  ros::spin();
}
