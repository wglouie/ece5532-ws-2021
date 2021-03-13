// Include guard to prevent multiple declarations
#ifndef JOINTSTATEMSGPUB_H
#define JOINTSTATEMSGPUB_H

// ROS header
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>

// Namespace matches ROS package name
namespace urdf_example{

class JointStateMsgPub
{

public:
  JointStateMsgPub(ros::NodeHandle n, ros::NodeHandle pn);
  
private: 
  ros::Publisher pub_joint_state;
  ros::Timer timer;
  double joint_angle;
  void timerCallback(const ros::TimerEvent& event);
};

}

#endif // NODECLASS_H

