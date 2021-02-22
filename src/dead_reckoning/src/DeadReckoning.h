// Include guard to prevent multiple declarations
#ifndef DEADRECKONING_H
#define DEADRECKONING_H

// ROS header
#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>

// Namespace matches ROS package name
namespace dead_reckoning{

class DeadReckoning
{
public:
  DeadReckoning(ros::NodeHandle n, ros::NodeHandle pn);

private:
  void timerCallback(const ros::TimerEvent& event);
  ros::Timer timer;
  
  double x;
  double y;
  double psi;

  ros::Publisher pub_point;
  ros::Subscriber sub_twist;

  geometry_msgs::TwistStamped twist_msg;
  void recvTwist(const geometry_msgs::TwistStampedConstPtr &msg);

  double sample_time;

  tf::TransformBroadcaster broadcaster;

  std::string child_frame;
  std::string parent_frame;
};

}

#endif // DEADRECKONING_H

