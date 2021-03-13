// ROS and node class header file
#include <ros/ros.h>
#include "JointStateMsgPub.h"

int main(int argc, char** argv)
{
  // Initialize ROS and declare node handles
  ros::init(argc, argv, "joint_state_pub");
  ros::NodeHandle n;
  ros::NodeHandle pn("~");
  
  // Instantiate node class
  urdf_example::JointStateMsgPub node(n, pn);
  
  // Spin and process callbacks
  ros::spin();
}
