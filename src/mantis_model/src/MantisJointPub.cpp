// Header file for the class
#include "MantisJointPub.h"

// Namespace matches ROS package name
namespace mantis_model {

// Constructor with global and private node handle arguments
MantisJointPub::MantisJointPub(ros::NodeHandle n, ros::NodeHandle pn)
{
  joint_angle = 0;
  pub_joint_state = n.advertise<sensor_msgs::JointState>("joint_states",1);
  timer = n.createTimer(ros::Duration(0.02), &MantisJointPub::timerCallback, this); 
  joint_state_msg.position.resize(2);
  joint_state_msg.name.resize(2);
  joint_state_msg.name[1] = "left_wheel_joint";
  joint_state_msg.name[0] = "right_wheel_joint";
}

void MantisJointPub::timerCallback(const ros::TimerEvent& event){
  double constant_speed = 1.0;
  

  joint_state_msg.header.stamp = event.current_real;
  joint_angle += 0.02*constant_speed;
  joint_state_msg.position[0] = joint_angle;
  joint_state_msg.position[1] = -joint_angle;

  
  pub_joint_state.publish(joint_state_msg);
}


}
