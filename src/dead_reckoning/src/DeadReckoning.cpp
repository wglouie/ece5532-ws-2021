// Header file for the class
#include "DeadReckoning.h"

// Namespace matches ROS package name
namespace dead_reckoning {

// Constructor with global and private node handle arguments
DeadReckoning::DeadReckoning(ros::NodeHandle n, ros::NodeHandle pn)
{
  timer = n.createTimer(ros::Duration(sample_time),&DeadReckoning::timerCallback,this);
  x = 0;
  y = 0;
  psi = 0;

  pub_point = n.advertise<geometry_msgs::Point>("point",1);
  sub_twist = n.subscribe("/roundbot/twist", 1, &DeadReckoning::recvTwist, this);

  sample_time = 0.02;

  pn.param("parent_frame", parent_frame, std::string("odom"));
  pn.param("child_frame", child_frame, std::string("base_footprint"));
}

void DeadReckoning::timerCallback(const ros::TimerEvent& event){
  double v = twist_msg.twist.linear.x;
  double pdot = twist_msg.twist.angular.z;
  
  x = x + sample_time*v*cos(psi);
  y = y + sample_time*v*sin(psi);
  psi = psi + sample_time * pdot;

  geometry_msgs::Point point_msg;
  point_msg.x = x;
  point_msg.y = y;
  pub_point.publish(point_msg);

  tf::StampedTransform transform;
  transform.frame_id_ = parent_frame;
  transform.child_frame_id_ = child_frame;
  transform.setOrigin(tf::Vector3(x,y,0));
  transform.setRotation(tf::createQuaternionFromYaw(psi));
  transform.stamp_ = event.current_real;
  broadcaster.sendTransform(transform);
  
}

void DeadReckoning::recvTwist(const geometry_msgs::TwistStampedConstPtr &msg){
  twist_msg = *msg;
}

}
