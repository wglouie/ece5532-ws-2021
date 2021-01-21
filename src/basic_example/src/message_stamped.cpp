#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>

ros::Publisher pub_twist_stamped;

void recvTwist(const geometry_msgs::TwistConstPtr& msg){
  geometry_msgs::TwistStamped twist_stamped;

  twist_stamped.twist = *msg;
  
  //twist_stamped.twist.angular = msg->angular;
  //twist_stamped.twist.linear = msg->linear;

  twist_stamped.header.frame_id = "";
  twist_stamped.header.stamp = ros::Time::now();

  pub_twist_stamped.publish(twist_stamped);
}

int main(int argc, char** argv){
  ros::init(argc,argv,"message_header_example");
  ros::NodeHandle nh;
  
  pub_twist_stamped = nh.advertise<geometry_msgs::TwistStamped>("twist_stamped",1);
  ros::Subscriber sub_twist = nh.subscribe("twist",1,recvTwist);

  ros::spin();
}