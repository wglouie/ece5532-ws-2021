// Include guard to prevent multiple declarations
#ifndef MANTISJOINTPUB_H
#define MANTISJOINTPUB_H

// ROS header
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

// Namespace matches ROS package name
namespace mantis_model{

class MantisJointPub
{

public:
  MantisJointPub(ros::NodeHandle n, ros::NodeHandle pn);
  
private: 
  ros::Publisher pub_joint_state;
  ros::Timer timer;
  sensor_msgs::JointState joint_state_msg;
  double joint_angle;
  void timerCallback(const ros::TimerEvent& event);
};

}

#endif // NODECLASS_H

