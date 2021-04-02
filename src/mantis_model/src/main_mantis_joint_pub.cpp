// ROS and node class header file
#include <ros/ros.h>
#include "MantisJointPub.h"

int main(int argc, char** argv)
{
  // Initialize ROS and declare node handles
  ros::init(argc, argv, "mantis_joint_pub");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");
  
  // Instantiate node class
  mantis_model::MantisJointPub node(n, pn);
  
  // Spin and process callbacks
  ros::spin();
}
