// ROS and node class header file
#include <ros/ros.h>
#include "NodeClass.h"

int main(int argc, char** argv)
{
  // Initialize ROS and declare node handles
  ros::init(argc, argv, "node_name");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");
  
  // Instantiate node class
  package_name::NodeClass node(n, pn);
  
  // Spin and process callbacks
  ros::spin();
}
